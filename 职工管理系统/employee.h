#pragma once
#include <iostream>
#include "Woker.h"

class Employee :public Woker
{
public:
	//��ʾ��Ϣ
	 void showinfo() ;
	//��ò��ű�� �����û�����ʱ������ת��Ϊ��Ӧ����Ϣ
	 std::string getdepart();
	 Employee(std::string name, int id, int did);
};

