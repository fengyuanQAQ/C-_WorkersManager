#pragma once
#include <iostream>
class Woker
{
public:
	int m_id;//Ա�����
	int m_deptid;//Ա�����ź�
	std::string m_name;//Ա������
	//��ʾ��Ϣ
	virtual void showinfo() = 0;
    //��ò��ű�� �����û�����ʱ������ת��Ϊ��Ӧ����Ϣ
	virtual std::string getdepart() = 0;
};

