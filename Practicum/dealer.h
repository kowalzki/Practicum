#ifndef DEALER_H
#define DEALER_H
#include "General.h"
#include <string>
using namespace std;

struct dealer
{
	int dealer_ind; // ��� ����������
	string name;
	struct adress dlr_adr;
	int phone;
	int del_good1; // ��� ������������� ������ 1
	int del_good2; // ��� ������������� ������ 2
	int del_good3; // ��� ������������� ������ 3
};

#endif // !DEALER_H

