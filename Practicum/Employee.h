#include <string>
#include "General.h"
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
using namespace std;

struct employee
{
	int eploy_ind; // ��� ����������
	struct full_name fio;
	int age;
	char sex;
	struct adress e_adress;
	int phone;
	int passport;
	int position_ind; // ���������
};

#endif // !EMPLOYEE_H
