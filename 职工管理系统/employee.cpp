#include <iostream>
#include <string>
#include "employee.h"

using namespace std;
void Employee::showinfo()
{
	cout << "编号：" << this->m_id << "\t姓名：" << this->m_name 
		<<"\t岗位："<< this->getdepart() << "\t职责：搬砖的" << endl;
}

string Employee::getdepart()
{
	return (string)"工人";
}

Employee::Employee(string name, int id, int did)
{
	this->m_name = name;
	this->m_id = id;
	this->m_deptid = did;
}
