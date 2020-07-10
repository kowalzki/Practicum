#ifndef STORAGE_H
#define STORAGE_H
#include "General.h"
#include <string>
using namespace std;

struct storage
{
	struct date in_date;
	struct date ord_date;
	struct date out_date;
	int good_ind; // ��� ������
	int dealer_ind; // ��� ����������
	int orderer_ind; // ��� ���������
	string delivery_type;
	int size;
	int price;
	int eploy_ind; // ��� ����������
};

#endif // !STORAGE_H

