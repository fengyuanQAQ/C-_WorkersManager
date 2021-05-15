#include "Wokermanager.h" //����ͷ�ļ�
using namespace std;

Workermanager::Workermanager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	char ch;
	ifs >> ch;//��ȡ�ļ���eof��־
	if ((!ifs.is_open()) || ifs.eof())//���ļ�Ϊ�ջ����ļ�����Ϊ��ʱ
	{
		this->m_fileEmpty = true;
		this->m_size = 0;
		this->m_wokerarray = NULL;
		return;
	}
	ifs.close();
	ifs.open(FILENAME, ios::in);
	this->m_size = this->getnumber();//��ȡ�ļ�������
	this->m_wokerarray = new Woker*[this->m_size];//��ʼ���ռ�
	//�����ļ�������
	int id;
	string name;
	int did;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		switch (did)
		{
		case 0:
			this->m_wokerarray[index++] = new Employee(name, id, did);
			break;
		case 1:
			this->m_wokerarray[index++] = new Manager(name, id, did);
			break;
		case 2:
			this->m_wokerarray[index++] = new Boss(name, id, did);
			break;
		default:
			break;
		}
	}
	this->m_fileEmpty = false;//��ʱ�ļ���Ϊ�ջ������ݼ�¼Ϊ0
	ifs.close();//�ر��ļ�
	
}
//��ȡ�ļ�������
int Workermanager::getnumber()
{
	ifstream ifs(FILENAME, ios::in);
	string name;
	int id;
	int did;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did)//��˳���ȡ����
	{
		++num;
	}
	return num;
}
void Workermanager::showmenu()
{
	cout << "***************************************************************" << endl;
	cout << "****************��ӭʹ�ý�ְ������ϵͳ*************************" << endl;
	cout << "*********************0.�˳��������****************************" << endl;
	cout << "*********************1.����ְ����Ϣ****************************" << endl;
	cout << "*********************2.��ʾְ����Ϣ****************************" << endl;
	cout << "*********************3.ɾ����ְְ��****************************" << endl;
	cout << "*********************4.�޸�ְ����Ϣ****************************" << endl;
	cout << "*********************5.����ְ����Ϣ****************************" << endl;
	cout << "*********************6.���ձ������****************************" << endl;
	cout << "*********************7.��������ĵ�****************************" << endl;
	cout << "***************************************************************" << endl;
}
void Workermanager::exitprogram()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);//���������˳�
}
void Workermanager::addwokerinfo()//���Ա����Ϣ
{
	int num=0;
	cout << "������ӵ�������";
	cin >> num;
	if (num > 0)
	{
		int new_size = this->m_size + num;//��ǰӦ�ÿ��ٵĿռ�
		Woker ** new_space = new Woker*[new_size];
		//����һ��ԭ��������
		if (this->m_wokerarray != NULL)
		{
			for (int i = 0; i != this->m_size; i++)
			{
				new_space[i] = this->m_wokerarray[i];
			}
		}
		//���������
		for (int i = 0; i != num; i++)
		{
			string name;
			int id;
			int did;
			cout << "�����" << i + 1 << "���˵ı��:";
			cin >> id;
			cout << "�����" << i + 1 << "���˵�����:";
			cin >> name;
			cout << "ѡ��һ�����ʵ�ְλ" << endl;
			cout << "0��Ա��" << endl;
			cout << "1������" << endl;
			cout << "2���ϰ�" << endl;
			cin >> did;
			//���id��ͬ
			switch (did)
			{
			case 0:
				new_space[i+this->m_size] = new Employee(name, id, did);
				break;
			case 1:
				new_space[i+this->m_size] = new Manager(name, id, did);
				break;
			case 2:
				new_space[i+this->m_size] = new Boss(name, id, did);
				break;
			default:
				cout << "����ѡ�����" << endl;
				--i;
				break;
			}
		}
		delete[] this->m_wokerarray;
		//������������
		this->m_wokerarray = new_space;
		this->m_size = new_size;//������������
		cout << "�ɹ����" << num << "������" << endl;
		this->m_fileEmpty = false;
		//�������ݵ��ļ���
		this->save();
	}
	else
	{
		cout << "�������ݴ���" << endl;
		cin.ignore();
	}
	system("pause");
	system("cls");//����
}

void Workermanager::save()
{
	ofstream ofs;
	ofs.open(FILENAME,ios::out);//��д�ķ�ʽ���ļ�
	//д����
	for (int i = 0; i !=this->m_size; i++)
	{
		ofs << this->m_wokerarray[i]->m_id << " " <<
			this->m_wokerarray[i]->m_name << " " <<
			this->m_wokerarray[i]->m_deptid << endl;
	}
	ofs.close();//�ر��ļ�
}
void Workermanager::showinfo()
{
	if (this->m_fileEmpty)
	{
		cout << "��ǰ�ļ�Ϊ�ջ��߲�����" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < this->m_size; i++)
	{
		this->m_wokerarray[i]->showinfo();
	}
	system("pause");
	system("cls");
}
//ɾ��Ա����ְ
void Workermanager::delemp()
{
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_fileEmpty)
	{
		cout << "�ļ������ڻ����ļ�Ϊ��" << endl;
	}
	else
	{
		cout << "����ɾ����Ա�����:";
		int id;
		cin >> id;
		int ret = this->isexist(id);
		//�ж�Ա���Ƿ����
		if (ret != -1)
		{
			for (int i = ret; i < this->m_size-1; i++)
			{
				this->m_wokerarray[i] = this->m_wokerarray[i + 1];
			}
			this->m_size--;//�����С-1
			this->save();//�������ļ�
		}
		else//Ա��������
		{
			cout << "��ǰԱ��������" << endl;
		}
	}
	system("pause");
	system("cls");
}
//�ж�Ա���Ƿ���� Ĭ�ϱ��ȫ������ͬ
int Workermanager::isexist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_size; i++)
	{
		if (this->m_wokerarray[i]->m_id == id)
		{
			return i;
		}
	}
	return index;//���indexΪ-1��ʾ������
}

//�޸�Ա����Ϣ
void Workermanager::modemp()
{
    //�ж��ļ��Ƿ�Ϊ��
	if (this->m_fileEmpty)
	{
		cout << "�ļ�Ϊ�ջ��߼�¼Ϊ��" << endl;
	}
	else
	{
		cout << "�����޸ĵ�Ա���ı��:" ;
		int id;
		cin >> id;
		int ret = this->isexist(id);
		if (ret != -1)
		{
			delete this->m_wokerarray[ret];//ɾ����ǰ�����������ڴ�
			int id;
			string name;
			int did;
			cout << "���������Ϣ" << endl;
			cout << "������:";
			cin >> id;
			cout << "��������:";
			cin >> name;
			cout << "ѡ��һ�����ʵ�ְλ" << endl;
			cout << "0��Ա��" << endl;
			cout << "1������" << endl;
			cout << "2���ϰ�" << endl;
			cin >> did;
			while (did != 0 && did != 1 && did != 2)
			{
				cout << "���������������" << endl;
				cin >> did;
			}
			switch (did)
			{
			case 0:
				this->m_wokerarray[ret] = new Employee(name, id, did);
				break;
			case 1:
				this->m_wokerarray[ret] = new Manager(name, id, did);
				break;
			case 2:
				this->m_wokerarray[ret] = new Boss(name, id, did);
				break;
			default:

				break;
			}
		}
	}
	system("pause");
	system("cls");

}

//����Ա����Ϣ
void Workermanager::searchemp()
{
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_fileEmpty)
	{
		cout << "�ļ�Ϊ�ջ��߼�¼Ϊ��" << endl;
	}
	else
	{
		cout << "������ұ��:" << endl;
		int flag;
		cin >> flag;
			for (int i = 0; i < this->m_size; i++)
			{
			    if (this->m_wokerarray[i]->m_id == flag)
				{
					this->m_wokerarray[i]->showinfo();
					break;
				}
			}
	}
	system("pause");
	system("cls");
}

//����
void Workermanager::sort()
{
	if (this->m_fileEmpty)
	{
		cout << "��ǰ�ļ�Ϊ�ջ��߲�����" << endl;
		system("pause");
		system("cls");
		return;
	}
	int num;
	cout << "ѡ������ʽ" << endl;
	cout << "0-����" << endl;
	cout << "1-����" << endl;
	cin >> num;
	switch (num)
	{
	case 0:
	{bool swap = true;
	for (int i = 0; i < this->m_size - 1 && swap; i++)//����Ĵ���
	{
		swap = false;
		for (int j = 0; j < this->m_size - i-1; j++)
		{
			if (this->m_wokerarray[j]->m_id > this->m_wokerarray[j + 1]->m_id)
			{
				Woker *temp = NULL;
				temp = this->m_wokerarray[j];
				this->m_wokerarray[j] = this->m_wokerarray[j + 1];
				this->m_wokerarray[j + 1] = temp;
				swap = true;
			}
		}
	}
	}
		break;
	case 1:
		//ѡ������
	{for (int i = 0; i < this->m_size - 1; i++)
	{
		int k = i;
		for (int j = i + 1; j < this->m_size; j++)
		{
			if (this->m_wokerarray[i]->m_id < this->m_wokerarray[j]->m_id)
			{
				k = j;
			}
		}
		if (k != i)
		{
			Woker *temp = NULL;
			temp = this->m_wokerarray[k];
			this->m_wokerarray[k] = this->m_wokerarray[i];
			this->m_wokerarray[i] = temp;
		}
	}
	}
		break;
	default:
		cout << "�������ݲ���ȷ ����ʧ��" << endl;
		break;
	}
	this->save();
	system("pause");
	system("cls");
}

//����ĵ�
void Workermanager::clear()
{
	if (this->m_fileEmpty)
	{
		cout << "��ǰ�ļ�Ϊ�ջ��߲�����" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < this->m_size; i++)
	{
		if (this->m_wokerarray[i] != NULL)
		{
			delete this->m_wokerarray[i];
			this->m_wokerarray[i] = NULL;
		}
	}
	delete[] this->m_wokerarray;
	this->m_size = 0;
	this->save();
	this->m_fileEmpty = true;
	system("pause");
	system("cls");
}
Workermanager::~Workermanager()
{
	for (int i = 0; i < this->m_size; i++)
	{
		if (this->m_wokerarray[i] != NULL)
		{
			delete this->m_wokerarray[i];
			this->m_wokerarray[i] = NULL;
		}
	}
	delete[] this->m_wokerarray;
}