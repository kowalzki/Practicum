#include <iostream>
#include <clocale>
#include <Windows.h>

//#include "Helpers.h"
#include "Table.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	bool flag = true;
	int choise;
	while (flag)
	{
		system("cls");
		std::cout << "__________MENU__________\n\n"
			<< "1: ������� ������� �� �����\n"
			<< "2: �������� ������\n"
			<< "3: ������� ������\n"
			<< "4: �����\n"
			<< "________________________\n\n"
			<< "�������� ����� 1-4:  ";
		std::cin >> choise;
		switch (choise)
		{
		case 1:
		{
			system("cls");
			std::cout << "__________MENU__________\n\n"
				<< "1: ����������\n"
				<< "2: ���������\n"
				<< "3: ������\n"
				<< "4: ����� �����������\n"
				<< "5: ��������\n"
				<< "6: ����������\n"
				<< "7: ���������� � �����\n"
				<< "8: �����\n"
				<< "________________________\n\n"
				<< "�������� ����� 1-8:  ";
			std::cin >> choise;
			system("cls");
			switch (choise)
			{
			case 1:
			{
				table t("employee");
				t.show();
				break;
			}
			case 2:
			{
				table t("position");
				t.show();
				break;
			}
			case 3:
			{
				table t("rank");
				t.show();
				break;
			}
			case 4:
			{
				table t("mark");
				t.show();
				break;
			}
			case 5:
			{
				table t("driver");
				t.show();
				break;
			}
			case 6:
			{
				table t("car");
				t.show();
				break;
			}
			case 7:
			{
				table t("jacked_car");
				t.show();
				break;
			}
			}
			system("pause");
			break;
		}
		case 2:
		{
			system("cls");
			std::cout << "__________MENU__________\n\n"
				<< "1: ����������\n"
				<< "2: ���������\n"
				<< "3: ������\n"
				<< "4: ����� �����������\n"
				<< "5: ��������\n"
				<< "6: ����������\n"
				<< "7: ���������� � �����\n"
				<< "________________________\n\n"
				<< "�������� ����� 1-7:  ";
			std::cin >> choise;
			system("cls");
			switch (choise)
			{
			case 1:
			{
				table t("employee");
				t.addLine();
				break;
			}
			case 2:
			{
				table t("position");
				t.addLine();
				break;
			}
			case 3:
			{
				table t("rank");
				t.addLine();
				break;
			}
			case 4:
			{
				table t("mark");
				t.addLine();
				break;
			}
			case 5:
			{
				table t("driver");
				t.addLine();
				break;
			}
			case 6:
			{
				table t("car");
				t.addLine();
				break;
			}
			case 7:
			{
				table t("jacked_car");
				t.addLine();
				break;
			}
			}
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			std::cout << "__________MENU__________\n\n"
				<< "1: ����� ������\n"
				<< "2: ������ �����������\n"
				<< "3: ������ ������\n"
				<< "4: �����\n"
				<< "________________________\n\n"
				<< "�������� ����� 1-4:  ";
			std::cin >> choise;
			switch (choise)
			{
			case 1:
			{
				system("cls");
				std::cout << "__________MENU__________\n\n"
					<< "1: ��� ��������\n"
					<< "2: ������ �� ���������\n"
					<< "3: ������ �� ������\n"
					<< "4: �����\n"
					<< "________________________\n\n"
					<< "�������� ����� 1-4:  ";
				std::cin >> choise;
				system("cls");
				switch (choise)
				{
				case 1:
				{
					table t("employee");
					std::string farr[2] = { "ID_���������", "ID_������" };
					std::string sarr[2] = { "position", "rank" };
					t.request(farr, sarr, 2);
					break;
				}
				case 2:
				{
					std::string filter_choise;
					std::cout << "������� ���������:  ";
					std::cin.ignore();
					std::getline(std::cin, filter_choise);
					table t("employee");
					std::string farr[2] = { "ID_���������", "ID_������" };
					std::string sarr[2] = { "position", "rank" };
					t.request(farr, sarr, 2, "ID_���������", filter_choise, "position", "������������");
					break;
				}
				case 3:
				{
					std::string filter_choise;
					std::cout << "������� ������:  ";
					std::cin.ignore();
					std::getline(std::cin, filter_choise);
					table t("employee");
					std::string farr[2] = { "ID_���������", "ID_������" };
					std::string sarr[2] = { "position", "rank" };
					t.request(farr, sarr, 2, "ID_������", filter_choise, "rank", "������������");
					break;
				}
				}
				break;
			}
			case 2:
			{
				system("cls");
				std::cout << "__________MENU__________\n\n"
					<< "1: ��� ��������\n"
					<< "2: ������ �� ���������\n"
					<< "3: ������ �� ����������\n"
					<< "4: �����\n"
					<< "________________________\n\n"
					<< "�������� ����� 1-4:  ";
				std::cin >> choise;
				system("cls");
				switch (choise)
				{
				case 1:
				{
					table t("car");
					std::string farr[3] = { "ID_�����", "ID_��������", "ID_����������" };
					std::string sarr[3] = { "mark", "driver", "employee" };
					t.request(farr, sarr, 3);
					break;
				}
				case 2:
				{
					std::string filter_choise;
					std::cout << "������� ���������:  ";
					std::cin.ignore();
					std::getline(std::cin, filter_choise);
					table t("car");
					std::string farr[3] = { "ID_�����", "ID_��������", "ID_����������" };
					std::string sarr[3] = { "mark", "driver", "employee" };
					t.request(farr, sarr, 3, "ID_���������", filter_choise, "driver", "���");
					break;
				}
				case 3:
				{
					std::cout << "__________MENU__________\n\n"
						<< "1: ��������� ���������\n"
						<< "2: �� ��������� ���������\n"
						<< "3: �����\n"
						<< "________________________\n\n"
						<< "�������� ����� 1-3:  ";
					std::cin >> choise;
					system("cls");
					switch (choise)
					{
					case 1:
					{
						table t("car");
						std::string farr[3] = { "ID_�����", "ID_��������", "ID_����������" };
						std::string sarr[3] = { "mark", "driver", "employee" };
						t.request(farr, sarr, 3, "���������", "��");
						break;
					}
					case 2:
					{
						table t("car");
						std::string farr[3] = { "ID_�����", "ID_��������", "ID_����������" };
						std::string sarr[3] = { "mark", "driver", "employee" };
						t.request(farr, sarr, 3, "���������", "���");
						break;
					}
					}
					break;
				}
				}
				break;
			}
			case 3:
			{
				system("cls");
				std::cout << "__________MENU__________\n\n"
					<< "1: ��� ��������\n"
					<< "2: ��������� ����������\n"
					<< "3: �� ��������� ����������\n"
					<< "4: �����\n"
					<< "________________________\n\n"
					<< "�������� ����� 1-4:  ";
				std::cin >> choise;
				system("cls");
				switch (choise)
				{
				case 1:
				{
					table t("jacked_car");
					std::string farr[2] = { "ID_����������", "ID_��������" };
					std::string sarr[2] = { "car", "driver" };
					t.request(farr, sarr, 2);
					break;
				}
				case 2:
				{
					table t("jacked_car");
					std::string farr[2] = { "ID_����������", "ID_��������" };
					std::string sarr[2] = { "car", "driver" };
					t.request(farr, sarr, 2, "����������_�������", "��");
					break;
				}
				case 3:
				{
					table t("jacked_car");
					std::string farr[2] = { "ID_����������", "ID_��������" };
					std::string sarr[2] = { "car", "driver" };
					t.request(farr, sarr, 2, "����������_�������", "���");
					break;
				}
				}
				break;
			}
			}
			system("pause");
			break;
		}
		case 4:
		{
			flag = false;
			break;
		}
		default:
		{
			std::cout << "������� �������� ��������\n";
		}
		}
	}

	return 0;
}