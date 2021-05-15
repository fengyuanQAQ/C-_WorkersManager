#include <iostream>
#include <string>
#include "Boss.h"
using namespace std;

void Boss::showinfo()
{
	cout << "编号：" << this->m_id << "\t姓名：" << this->m_name
		<< "\t岗位：" << this->getdepart() << "\t职责：收钱的" << endl;
}

string Boss::getdepart()
{
	return (string)"老板";
}

Boss::Boss(string name, int id, int did)
{
	this->m_name = name;
	this->m_id = id;
	this->m_deptid = did;
}