#pragma once
#include <iostream>
class Woker
{
public:
	int m_id;//员工编号
	int m_deptid;//员工部门好
	std::string m_name;//员工姓名
	//显示信息
	virtual void showinfo() = 0;
    //获得部门编号 方便用户输入时的数字转换为对应额信息
	virtual std::string getdepart() = 0;
};

