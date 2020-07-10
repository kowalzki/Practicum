#include <string>
#ifndef GENERAL_H
#define GENERAL_H
using namespace std;

struct full_name
{
	string name;
	string sec_name;
	string surname;
};

struct date
{
	int day;
	int month;
	int year;

	int position_ind; // должность
	int type_ind; // код типа
	int good_ind; // код товара
	int del_good1; // код поставляемого товара 1
	int del_good2; // код поставляемого товара 2
	int del_good3; // код поставляемого товара 3
	int dealer_ind; // код поставщика
	int orderer_ind; // код заказчика
	int eploy_ind; // код сотрудника
};

struct adress
{
	string country;
	string city;
	string street_name;
	int house;
	int flat;
};

#endif
