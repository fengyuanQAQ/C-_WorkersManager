#pragma once  //��֤ͷ�ļ�ֻ������һ��
#include <iostream>
#include <string>
#include "Boss.h"
#include "Manager.h"
#include "employee.h"
#include "Woker.h"
#include <fstream>
#define FILENAME "info.txt"

//--------����ϵͳ---------
//ʵ�ָ������ܵĽӿ�
class Workermanager
{
public:
	//��ʾ�˵�
	void showmenu();

	//�˳�����
	void exitprogram();

	//����ְ����Ϣ
	void addwokerinfo();

	//����Ա����Ϣ
	void save();

	//��ʾԱ����Ϣ
	void showinfo();
	//��ȡ�ļ�������
	int getnumber();

	//ɾ��Ա����ְ
	void delemp();
	//�ж�Ա���Ƿ����
	int isexist(int id);
    
	//�޸�ְ����Ϣ
	void modemp();

	//����Ա����Ϣ
	void searchemp();

	//���ձ������
	void sort();

	//����ĵ�
	void clear();
	//���캯��
	Workermanager();
	//��������
    ~Workermanager();

	int m_size;//��ǰԱ��������
	Woker ** m_wokerarray;//ָ��worker�����ָ��
	int m_fileEmpty;
};
