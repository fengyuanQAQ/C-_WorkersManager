#include <iostream>
#include "Manager.h"
#include <string>

using namespace std;

//显示信息
void Manager::showinfo()
{
	cout << "编号：" << this->m_id << "\t姓名：" << this->m_name
		<< "\t岗位：" << this->getdepart() << "\t职责：祭天的" << endl;
}
//获得部门编号 方便用户输入时的数字转换为对应额信息
string Manager::getdepart()
{
	return "经理";
}
//构造函数
Manager::Manager(string name, int id, int did)
{
	this->m_name = name;
	this->m_id = id;
	this->m_deptid = did;
}
