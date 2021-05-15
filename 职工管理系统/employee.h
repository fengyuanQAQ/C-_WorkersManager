#pragma once
#include <iostream>
#include "Woker.h"

class Employee :public Woker
{
public:
	//显示信息
	 void showinfo() ;
	//获得部门编号 方便用户输入时的数字转换为对应额信息
	 std::string getdepart();
	 Employee(std::string name, int id, int did);
};

