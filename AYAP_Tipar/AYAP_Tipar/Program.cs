using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
//обработка формата datafila
//вшивание ключа
//создание и обработка исключений

namespace AYAP_Tipar
{
    class Program
    {
        static void Main(string[] args)
        {

            Stego st = new Stego();
            char input = '1';
            while (input != '0')
            {
                Console.WriteLine("\nEnter 1 to encrypt information ");
                Console.WriteLine("Enter 2 to decrypt information ");
                Console.WriteLine("Enter 0 to exit the program ");
                input = (char)Console.Read();
                if (input == '1')
                {
                    Console.WriteLine("\nEnter container file name ");
                    Console.ReadLine();
                    st.PathIn = Console.ReadLine();
                    
                    Console.WriteLine("\nEnter datafile name ");
                    st.PathDataIn = Console.ReadLine();
                    st.SteganoEncrypt();
                }
                if (input == '2')
                {
                    Console.WriteLine("\nEnter stegofile name ");
                    Console.ReadLine();
                    st.PathIn = Console.ReadLine();
                    st.SteganoDecrypt();
                }                
                
            }
          
            Console.WriteLine("Done.");
            Console.ReadLine();
        }
    }

    class Stego
    {
        private string pathIn;
        private string pathDataIn;
        public string PathIn
        {
            set
            {
                pathIn = value;  //проверка строки
            }
            get
            {
                return pathIn;
            }
            
        }
        public string PathDataIn
        {
            get
            {
                return pathDataIn;
            }
            set
            {
                pathDataIn = value;  //проверка строки
            }
        }

        private string pathOut;

        public void SteganoEncrypt()
        {
            FileStream fsIn = new FileStream(PathIn, FileMode.OpenOrCreate);
            FileStream fsOut = new FileStream("StegoPicture.bmp", FileMode.Truncate);  //filemod  + if///
            FileStream fsDataIn = new FileStream(PathDataIn, FileMode.OpenOrCreate);

            byte[] containerBlock = new byte[576];
            byte[] dataBlock = new byte[72];
            int length;
            //перепечатать заголовок
            fsIn.Read(containerBlock, 0, 54);
            fsOut.Write(containerBlock, 0, 54);

            if (fsIn.Length / 576 + 1 > fsDataIn.Length / 72 + 1)
                length = (int)fsDataIn.Length / 72 + 1;
            else
                length = (int)fsIn.Length / 576 + 1;

            fsIn.Read(containerBlock, 0, 3);
            SetKey(containerBlock, length);
            fsOut.Write(containerBlock, 0, 3);

            for (int i = 0; i < fsIn.Length / 576 + 1; i++)
            {
                fsIn.Read(containerBlock, 0, 576);
                fsDataIn.Read(dataBlock, 0, 72);
              if(i < length)
                Encrypt(containerBlock, dataBlock);             //шифрование

                fsOut.Write(containerBlock, 0, 576);
            }
            fsDataIn.Close();
            fsIn.Close();
            fsOut.Close();
        }

        public void SteganoDecrypt()
        {
            FileStream fsIn = new FileStream(PathIn, FileMode.OpenOrCreate);
            FileStream fsDataOut = new FileStream("FinalData.txt", FileMode.Truncate);

            byte[] containerBlock = new byte[576];
            byte[] dataBlock = new byte[72];
            
            
            fsIn.Read(containerBlock, 0, 54);  //пропуск заголовка         
            fsIn.Read(containerBlock, 0, 3);   // считывание ключа

            int length = GetKey(containerBlock);


            for (int i = 0; i < fsIn.Length / 576 + 1; i++)
            {
                fsIn.Read(containerBlock, 0, 576);


                if (i < length)
                {                                    
                    Decrypt(containerBlock, dataBlock);             //дешифрование
                    fsDataOut.Write(dataBlock, 0, 72);
                }

              
            }
            fsDataOut.Close();
            fsIn.Close();
        }

        private void Decrypt(byte[] container, byte[] dataArray)
        {
            byte[,] tempContainer = new byte[24, 24];
            byte[] dataBitArray = new byte[576];
            int i, j, k = 0, index = 0;

            for (i = 0; i < 24; i++)
            {
                for (j = 0; j < 24; j++)
                {
                    tempContainer[i, j] = container[i * 24 + j];
                }
            }
            i = j = 0;
          
            for (int iter = 0; iter < 12; iter++)
            {
                for (; i < 24 - k; i++)
                {
                    if (index == 576)
                        break;
                    dataBitArray[index] = GetSmallerBit(tempContainer[i, j]); 
                    index++;

                }
                i--;
                j++;
                for (; j < 24 - k; j++)
                {
                    if (index == 576)
                        break;
                    dataBitArray[index] = GetSmallerBit(tempContainer[i, j]); 
                    index++;
                }
                j--;
                i--;
                for (; i > k; i--)
                {
                    if (index == 576)
                        break;
                    dataBitArray[index] = GetSmallerBit(tempContainer[i, j]); 
                    index++;
                }
                i++;
                j--;
                k++;
                for (; j > k; j--)
                {
                    if (index == 576)
                        break;
                    dataBitArray[index] = GetSmallerBit(tempContainer[i, j]); 
                    index++;
                }
                j++;
                i++;
            }

            BitsToBytes(dataBitArray, dataArray);
        }

        private void Encrypt(byte[] container, byte[] dataArray)
        {
            byte[,] tempContainer = new byte[24, 24];
            byte[] dataBitArray = new byte[576];
            int i, j, k = 0, index = 0;

            for (i = 0; i < 24; i++)
            {
                for (j = 0; j < 24; j++)
                {
                    tempContainer[i, j] = container[i * 24 + j];
                }
            }
            i = j = 0;

            BytesToBits(dataBitArray, dataArray);

            for (int iter = 0; iter < 12; iter++)
            {
                for (; i < 24 - k; i++)
                {
                    if (index == 576)
                        break;
                    tempContainer[i, j] = SetSmallerBit(dataBitArray[index], tempContainer[i, j]); 
                    index++;
                    
                }
                i--;
                j++;
                for (; j < 24 - k; j++)
                {
                    if (index == 576)
                        break;
                    tempContainer[i, j] = SetSmallerBit(dataBitArray[index], tempContainer[i, j]); 
                    index++;
                }
                j--;
                i--;
                for (; i > k; i--)
                {
                    if (index == 576)
                        break;
                    tempContainer[i, j] = SetSmallerBit(dataBitArray[index], tempContainer[i, j]); 
                    index++;
                }
                i++;
                j--;
                k++;
                for (; j > k; j--)
                {
                    if (index == 576)
                        break;
                    tempContainer[i, j] = SetSmallerBit(dataBitArray[index], tempContainer[i, j]);
                    index++;
                }
                j++;
                i++;
            }

            for (i = 0; i < 24; i++)
                for (j = 0; j < 24; j++)
                    container[i * 24 + j] = tempContainer[i, j];

        }


        private void BytesToBits(byte[] bitArray, byte[] byteArray)
        {
            byte temp;
            for (int i = 0; i < byteArray.Length; i++)
            {
                temp = byteArray[i];
                for (int j = 0; j < 8; j++)
                {
                    bitArray[i * 8 + j] = (byte)(temp % 2);
                   temp = (byte)(temp >> 1);
                }
            }
        }

        private void BitsToBytes(byte[] bitArray, byte[] byteArray)
        {
            byte temp;
            for (int i = 0; i < bitArray.Length / 8; i++)
            {
                temp = 0;
                for (int j = 7; j >= 0; j--)
                {
                    temp = (byte)(temp << 1);
                    temp |= bitArray[i * 8 + j];
                }
                byteArray[i] = temp;
            }
        }

        private byte GetSmallerBit(byte value)
        {
            byte num = (byte)(value & 1);
            return num;
        }

        private byte SetSmallerBit(int num, byte value)
        {
            switch (num)
            {
                case 0: value &= (byte)254;
                    break;
                case 1: value |= 1;
                    break;
                default: ;//exception
                    break;

            }
            return value;
        }

        private void SetKey(byte[] array, int length)
        {
            array[2] = (byte)(length % 256);
            length -= array[2];
            array[1] = (byte)(length % (256 * 256));
            length -= array[1];
            array[0] = (byte)(length % (256* 256 * 256));
            length -= array[0];            
        }


        private int GetKey(byte[] array)
        {
            int length = 0;
            length = array[2] + array[1] * 256 + array[0] * 256 * 256;
            return length;    
        }
    }
}

