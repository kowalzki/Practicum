#ifndef ORDERER_H
#define ORDERER_H
#include "General.h"
#include <string>
using namespace std;

struct orderer
{
	int orderer_ind; // ��� ���������
	string name;
	struct adress orer_adr;
	int phone;
	int del_good1; // ��� ������������� ������ 1
	int del_good2; // ��� ������������� ������ 2
	int del_good3; // ��� ������������� ������ 3
};
#endif // !ORDERER_H

