#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <Windows.h>
#include "Employee_Class.cpp"
using namespace std;

//void AddElement();
//void PushToFile(Employee_Class* emp);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "");
	cout.setf(ios::left);
	bool flag = true;
	int choice;
	employee empl;
	Employee_Class emplC;
	cout << "����������� ��� � �� �������� ������ :)" << endl;
	Sleep(1000);

	while (flag)
	{
		system("cls");
		cout << " ����" << endl;
		cout << "_____________________" << endl;
		cout << "1: ��������� ����" << endl;
		cout << "2: �������� �������" << endl;
		cout << "3: �������� ���� �� ������" << endl;
		cout << "0: �����" << endl;
		cout << "_____________________" << endl << endl;
		cout << "�������� (__): ";
		cin >> choice;
		switch (choice)
		{
		case 0: cout << "�������� ��� ;)" 
			<< endl; flag = false; break;
		case 1: emplC.AddToFile(); system("pause"); break;
		case 2: emplC.AddElem(); system("pause"); break;
		case 3: emplC.Show(); system("pause"); break;
		default: cout << "��������� ����. " << endl; system("pause"); break;
		}
	}
	system("pause");
	return 0;
}
