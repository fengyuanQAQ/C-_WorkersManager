//职工管理系统
#include <iostream>
#include "Wokermanager.h"
#include "Woker.h"
#include "employee.h"
#include "Manager.h"
#include "Boss.h"
using namespace std;

int main()
{
	Workermanager wm;
	int choice = 0;//记录用户选择
	while (true)
	{
		wm.showmenu();//显示菜单
		cout << "输入你的选择：";
		cin >> choice;
		switch (choice)
		{
		case 0://退出系统
			wm.exitprogram();
			break;
		case 1://增添员工
			wm.addwokerinfo();
			break;
		case 2://显示员工信息
			wm.showinfo();
			break;
		case 3://删除离职职工
			wm.delemp();
			break;
		case 4://修改职工信息
			wm.modemp();
			break;
		case 5://查找职工信息
			wm.searchemp();
			break;
		case 6://按照编号排序
			wm.sort();
			break;
		case 7://清空所有文档
			wm.clear();
			break;
		default:
			cout << "请输入正确选择" << endl;
			system("cls");//清屏
			break;
		}
	}
	system("pause"); 
	return 0;
}