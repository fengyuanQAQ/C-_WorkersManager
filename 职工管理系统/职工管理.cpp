//ְ������ϵͳ
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
	int choice = 0;//��¼�û�ѡ��
	while (true)
	{
		wm.showmenu();//��ʾ�˵�
		cout << "�������ѡ��";
		cin >> choice;
		switch (choice)
		{
		case 0://�˳�ϵͳ
			wm.exitprogram();
			break;
		case 1://����Ա��
			wm.addwokerinfo();
			break;
		case 2://��ʾԱ����Ϣ
			wm.showinfo();
			break;
		case 3://ɾ����ְְ��
			wm.delemp();
			break;
		case 4://�޸�ְ����Ϣ
			wm.modemp();
			break;
		case 5://����ְ����Ϣ
			wm.searchemp();
			break;
		case 6://���ձ������
			wm.sort();
			break;
		case 7://��������ĵ�
			wm.clear();
			break;
		default:
			cout << "��������ȷѡ��" << endl;
			system("cls");//����
			break;
		}
	}
	system("pause"); 
	return 0;
}