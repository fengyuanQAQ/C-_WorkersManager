#include <iostream>
#include "Manager.h"
#include <string>

using namespace std;

//��ʾ��Ϣ
void Manager::showinfo()
{
	cout << "��ţ�" << this->m_id << "\t������" << this->m_name
		<< "\t��λ��" << this->getdepart() << "\tְ�𣺼����" << endl;
}
//��ò��ű�� �����û�����ʱ������ת��Ϊ��Ӧ����Ϣ
string Manager::getdepart()
{
	return "����";
}
//���캯��
Manager::Manager(string name, int id, int did)
{
	this->m_name = name;
	this->m_id = id;
	this->m_deptid = did;
}
