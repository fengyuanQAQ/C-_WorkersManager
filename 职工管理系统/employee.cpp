#include <iostream>
#include <string>
#include "employee.h"

using namespace std;
void Employee::showinfo()
{
	cout << "��ţ�" << this->m_id << "\t������" << this->m_name 
		<<"\t��λ��"<< this->getdepart() << "\tְ�𣺰�ש��" << endl;
}

string Employee::getdepart()
{
	return (string)"����";
}

Employee::Employee(string name, int id, int did)
{
	this->m_name = name;
	this->m_id = id;
	this->m_deptid = did;
}
