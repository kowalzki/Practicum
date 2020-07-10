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
			<< "1: Вывести таблицу на экран\n"
			<< "2: Добавить запись\n"
			<< "3: Создать запрос\n"
			<< "4: Выход\n"
			<< "________________________\n\n"
			<< "Выберите пункт 1-4:  ";
		std::cin >> choise;
		switch (choise)
		{
		case 1:
		{
			system("cls");
			std::cout << "__________MENU__________\n\n"
				<< "1: Сотрудники\n"
				<< "2: Должности\n"
				<< "3: Звания\n"
				<< "4: Марки автомобилей\n"
				<< "5: Водители\n"
				<< "6: Автомобили\n"
				<< "7: Автомобили в угоне\n"
				<< "8: Назад\n"
				<< "________________________\n\n"
				<< "Выберите пункт 1-8:  ";
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
				<< "1: Сотрудники\n"
				<< "2: Должности\n"
				<< "3: Звания\n"
				<< "4: Марки автомобилей\n"
				<< "5: Водители\n"
				<< "6: Автомобили\n"
				<< "7: Автомобили в угоне\n"
				<< "________________________\n\n"
				<< "Выберите пункт 1-7:  ";
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
				<< "1: Отдел кадров\n"
				<< "2: Список автомобилей\n"
				<< "3: Список угонов\n"
				<< "4: Назад\n"
				<< "________________________\n\n"
				<< "Выберите пункт 1-4:  ";
			std::cin >> choise;
			switch (choise)
			{
			case 1:
			{
				system("cls");
				std::cout << "__________MENU__________\n\n"
					<< "1: Без фильтров\n"
					<< "2: Фильтр по должности\n"
					<< "3: Фильтр по званию\n"
					<< "4: Назад\n"
					<< "________________________\n\n"
					<< "Выберите пункт 1-4:  ";
				std::cin >> choise;
				system("cls");
				switch (choise)
				{
				case 1:
				{
					table t("employee");
					std::string farr[2] = { "ID_должности", "ID_звания" };
					std::string sarr[2] = { "position", "rank" };
					t.request(farr, sarr, 2);
					break;
				}
				case 2:
				{
					std::string filter_choise;
					std::cout << "Введите должность:  ";
					std::cin.ignore();
					std::getline(std::cin, filter_choise);
					table t("employee");
					std::string farr[2] = { "ID_должности", "ID_звания" };
					std::string sarr[2] = { "position", "rank" };
					t.request(farr, sarr, 2, "ID_должности", filter_choise, "position", "Наименование");
					break;
				}
				case 3:
				{
					std::string filter_choise;
					std::cout << "Введите звание:  ";
					std::cin.ignore();
					std::getline(std::cin, filter_choise);
					table t("employee");
					std::string farr[2] = { "ID_должности", "ID_звания" };
					std::string sarr[2] = { "position", "rank" };
					t.request(farr, sarr, 2, "ID_звания", filter_choise, "rank", "Наименование");
					break;
				}
				}
				break;
			}
			case 2:
			{
				system("cls");
				std::cout << "__________MENU__________\n\n"
					<< "1: Без фильтров\n"
					<< "2: Фильтр по владельцу\n"
					<< "3: Фильтр по техосмотру\n"
					<< "4: Назад\n"
					<< "________________________\n\n"
					<< "Выберите пункт 1-4:  ";
				std::cin >> choise;
				system("cls");
				switch (choise)
				{
				case 1:
				{
					table t("car");
					std::string farr[3] = { "ID_марки", "ID_водителя", "ID_сотрудника" };
					std::string sarr[3] = { "mark", "driver", "employee" };
					t.request(farr, sarr, 3);
					break;
				}
				case 2:
				{
					std::string filter_choise;
					std::cout << "Введите владельца:  ";
					std::cin.ignore();
					std::getline(std::cin, filter_choise);
					table t("car");
					std::string farr[3] = { "ID_марки", "ID_водителя", "ID_сотрудника" };
					std::string sarr[3] = { "mark", "driver", "employee" };
					t.request(farr, sarr, 3, "ID_владельца", filter_choise, "driver", "ФИО");
					break;
				}
				case 3:
				{
					std::cout << "__________MENU__________\n\n"
						<< "1: Прошедшие техосмотр\n"
						<< "2: Не прошедшие техосмотр\n"
						<< "3: Назад\n"
						<< "________________________\n\n"
						<< "Выберите пункт 1-3:  ";
					std::cin >> choise;
					system("cls");
					switch (choise)
					{
					case 1:
					{
						table t("car");
						std::string farr[3] = { "ID_марки", "ID_водителя", "ID_сотрудника" };
						std::string sarr[3] = { "mark", "driver", "employee" };
						t.request(farr, sarr, 3, "Техосмотр", "Да");
						break;
					}
					case 2:
					{
						table t("car");
						std::string farr[3] = { "ID_марки", "ID_водителя", "ID_сотрудника" };
						std::string sarr[3] = { "mark", "driver", "employee" };
						t.request(farr, sarr, 3, "Техосмотр", "Нет");
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
					<< "1: Без фильтров\n"
					<< "2: Найденные автомобили\n"
					<< "3: Не найденные автомобили\n"
					<< "4: Назад\n"
					<< "________________________\n\n"
					<< "Выберите пункт 1-4:  ";
				std::cin >> choise;
				system("cls");
				switch (choise)
				{
				case 1:
				{
					table t("jacked_car");
					std::string farr[2] = { "ID_автомобиля", "ID_водителя" };
					std::string sarr[2] = { "car", "driver" };
					t.request(farr, sarr, 2);
					break;
				}
				case 2:
				{
					table t("jacked_car");
					std::string farr[2] = { "ID_автомобиля", "ID_водителя" };
					std::string sarr[2] = { "car", "driver" };
					t.request(farr, sarr, 2, "Нахождение_отметка", "Да");
					break;
				}
				case 3:
				{
					table t("jacked_car");
					std::string farr[2] = { "ID_автомобиля", "ID_водителя" };
					std::string sarr[2] = { "car", "driver" };
					t.request(farr, sarr, 2, "Нахождение_отметка", "Нет");
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
			std::cout << "Введены неверные значения\n";
		}
		}
	}

	return 0;
}