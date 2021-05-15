#pragma once  //保证头文件只被包含一次
#include <iostream>
#include <string>
#include "Boss.h"
#include "Manager.h"
#include "employee.h"
#include "Woker.h"
#include <fstream>
#define FILENAME "info.txt"

//--------管理系统---------
//实现各个功能的接口
class Workermanager
{
public:
	//显示菜单
	void showmenu();

	//退出程序
	void exitprogram();

	//增加职工信息
	void addwokerinfo();

	//保存员工信息
	void save();

	//显示员工信息
	void showinfo();
	//获取文件的人数
	int getnumber();

	//删除员工离职
	void delemp();
	//判断员工是否存在
	int isexist(int id);
    
	//修改职工信息
	void modemp();

	//查找员工信息
	void searchemp();

	//按照编号排序
	void sort();

	//清空文档
	void clear();
	//构造函数
	Workermanager();
	//析构函数
    ~Workermanager();

	int m_size;//当前员工的人数
	Woker ** m_wokerarray;//指向worker数组的指针
	int m_fileEmpty;
};
