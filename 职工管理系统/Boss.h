#pragma once
#include <iostream>
#include "Woker.h"
using namespace std;

class Boss :public Woker 
{
public:
	//��ʾ��Ϣ
	virtual void showinfo();
	//��ò��ű�� �����û�����ʱ������ת��Ϊ��Ӧ����Ϣ
	virtual string getdepart();
	//���캯��
	Boss(string name, int id, int did);
};