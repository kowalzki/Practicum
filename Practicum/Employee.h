#include <string>
#include <fstream>
#include "General.h"
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
using namespace std;

struct employee
{
	//const string filename = "employee";
	string eploy_ind; // ��� ����������
	struct full_name fio;
	string age;
	string sex;
	struct adress e_adress;
	string phone;
	string passport;
	string position_ind; // ���������
};

#endif // !EMPLOYEE_H
