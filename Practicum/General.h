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

	int position_ind; // ���������
	int type_ind; // ��� ����
	int good_ind; // ��� ������
	int del_good1; // ��� ������������� ������ 1
	int del_good2; // ��� ������������� ������ 2
	int del_good3; // ��� ������������� ������ 3
	int dealer_ind; // ��� ����������
	int orderer_ind; // ��� ���������
	int eploy_ind; // ��� ����������
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
