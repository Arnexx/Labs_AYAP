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
		cout<<"Ошибка открытия объекта";
		_getch();
		return 0;

	}
	while (repeat != '0')
	{
		cout<<"Для запуска вращения нажмите любую клавишу"<<endl;
		_getch();

		SetEvent(hEvent); // Объект-событие свободен
		cout<<"Для завершения вращения нажмите любую клавишу"<<endl;
		_getch();

		ResetEvent(hEvent); // Объект-событие занят
		cout<<"Для выхода введите 0"<<endl;

		repeat = _getch();
	}

	return 0;
}
