#pragma once
#include <iostream>
#include "Woker.h"
using namespace std;

class Boss :public Woker 
{
public:
	//显示信息
	virtual void showinfo();
	//获得部门编号 方便用户输入时的数字转换为对应额信息
	virtual string getdepart();
	//构造函数
	Boss(string name, int id, int did);
};