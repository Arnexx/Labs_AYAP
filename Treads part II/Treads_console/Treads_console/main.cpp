#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <locale.h>

using namespace std;
int main()
{
	HANDLE hEvent; 
	char repeat = 'y';

	setlocale(LC_ALL, "rus");
	hEvent = OpenEvent(EVENT_ALL_ACCESS, TRUE, "Rotation"); 

	if (hEvent == 0)
	{
		cout<<"������ �������� �������";
		_getch();
		return 0;

	}
	while (repeat != '0')
	{
		cout<<"��� ������� �������� ������� ����� �������"<<endl;
		_getch();

		SetEvent(hEvent); // ������-������� ��������
		cout<<"��� ���������� �������� ������� ����� �������"<<endl;
		_getch();

		ResetEvent(hEvent); // ������-������� �����
		cout<<"��� ������ ������� 0"<<endl;

		repeat = _getch();
	}

	return 0;
}
