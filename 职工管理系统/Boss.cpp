#include <iostream>
#include <string>
#include "Boss.h"
using namespace std;

void Boss::showinfo()
{
	cout << "��ţ�" << this->m_id << "\t������" << this->m_name
		<< "\t��λ��" << this->getdepart() << "\tְ����Ǯ��" << endl;
}

string Boss::getdepart()
{
	return (string)"�ϰ�";
}

Boss::Boss(string name, int id, int did)
{
	this->m_name = name;
	this->m_id = id;
	this->m_deptid = did;
}