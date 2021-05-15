#include "Wokermanager.h" //包含头文件
using namespace std;

Workermanager::Workermanager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	char ch;
	ifs >> ch;//获取文件的eof标志
	if ((!ifs.is_open()) || ifs.eof())//当文件为空或者文件内容为空时
	{
		this->m_fileEmpty = true;
		this->m_size = 0;
		this->m_wokerarray = NULL;
		return;
	}
	ifs.close();
	ifs.open(FILENAME, ios::in);
	this->m_size = this->getnumber();//获取文件的人数
	this->m_wokerarray = new Woker*[this->m_size];//初始化空间
	//拷贝文件的数据
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
	this->m_fileEmpty = false;//此时文件不为空或者数据记录为0
	ifs.close();//关闭文件
	
}
//获取文件的人数
int Workermanager::getnumber()
{
	ifstream ifs(FILENAME, ios::in);
	string name;
	int id;
	int did;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did)//按顺序读取数据
	{
		++num;
	}
	return num;
}
void Workermanager::showmenu()
{
	cout << "***************************************************************" << endl;
	cout << "****************欢迎使用教职工管理系统*************************" << endl;
	cout << "*********************0.退出管理程序****************************" << endl;
	cout << "*********************1.增加职工信息****************************" << endl;
	cout << "*********************2.显示职工信息****************************" << endl;
	cout << "*********************3.删除离职职工****************************" << endl;
	cout << "*********************4.修改职工信息****************************" << endl;
	cout << "*********************5.查找职工信息****************************" << endl;
	cout << "*********************6.按照编号排序****************************" << endl;
	cout << "*********************7.清空所有文档****************************" << endl;
	cout << "***************************************************************" << endl;
}
void Workermanager::exitprogram()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);//程序正常退出
}
void Workermanager::addwokerinfo()//添加员工信息
{
	int num=0;
	cout << "输入添加的人数：";
	cin >> num;
	if (num > 0)
	{
		int new_size = this->m_size + num;//当前应该开辟的空间
		Woker ** new_space = new Woker*[new_size];
		//拷贝一份原来的数据
		if (this->m_wokerarray != NULL)
		{
			for (int i = 0; i != this->m_size; i++)
			{
				new_space[i] = this->m_wokerarray[i];
			}
		}
		//添加新数据
		for (int i = 0; i != num; i++)
		{
			string name;
			int id;
			int did;
			cout << "输入第" << i + 1 << "个人的编号:";
			cin >> id;
			cout << "输入第" << i + 1 << "个人的姓名:";
			cin >> name;
			cout << "选择一个合适的职位" << endl;
			cout << "0、员工" << endl;
			cout << "1、经理" << endl;
			cout << "2、老板" << endl;
			cin >> did;
			//如果id相同
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
				cout << "输入选择错误" << endl;
				--i;
				break;
			}
		}
		delete[] this->m_wokerarray;
		//拷贝现有数据
		this->m_wokerarray = new_space;
		this->m_size = new_size;//保存现在数量
		cout << "成功添加" << num << "个数据" << endl;
		this->m_fileEmpty = false;
		//保存数据到文件中
		this->save();
	}
	else
	{
		cout << "输入数据错误" << endl;
		cin.ignore();
	}
	system("pause");
	system("cls");//清屏
}

void Workermanager::save()
{
	ofstream ofs;
	ofs.open(FILENAME,ios::out);//以写的方式打开文件
	//写数据
	for (int i = 0; i !=this->m_size; i++)
	{
		ofs << this->m_wokerarray[i]->m_id << " " <<
			this->m_wokerarray[i]->m_name << " " <<
			this->m_wokerarray[i]->m_deptid << endl;
	}
	ofs.close();//关闭文件
}
void Workermanager::showinfo()
{
	if (this->m_fileEmpty)
	{
		cout << "当前文件为空或者不存在" << endl;
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
//删除员工离职
void Workermanager::delemp()
{
	//判断文件是否为空
	if (this->m_fileEmpty)
	{
		cout << "文件不存在或者文件为空" << endl;
	}
	else
	{
		cout << "输入删除的员工编号:";
		int id;
		cin >> id;
		int ret = this->isexist(id);
		//判断员工是否存在
		if (ret != -1)
		{
			for (int i = ret; i < this->m_size-1; i++)
			{
				this->m_wokerarray[i] = this->m_wokerarray[i + 1];
			}
			this->m_size--;//数组大小-1
			this->save();//保存至文件
		}
		else//员工不存在
		{
			cout << "当前员工不存在" << endl;
		}
	}
	system("pause");
	system("cls");
}
//判断员工是否存在 默认标号全都不相同
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
	return index;//如果index为-1表示不存在
}

//修改员工信息
void Workermanager::modemp()
{
    //判断文件是否为空
	if (this->m_fileEmpty)
	{
		cout << "文件为空或者记录为空" << endl;
	}
	else
	{
		cout << "输入修改的员工的编号:" ;
		int id;
		cin >> id;
		int ret = this->isexist(id);
		if (ret != -1)
		{
			delete this->m_wokerarray[ret];//删除当前数组索引的内存
			int id;
			string name;
			int did;
			cout << "输入更新信息" << endl;
			cout << "输入编号:";
			cin >> id;
			cout << "输入姓名:";
			cin >> name;
			cout << "选择一个合适的职位" << endl;
			cout << "0、员工" << endl;
			cout << "1、经理" << endl;
			cout << "2、老板" << endl;
			cin >> did;
			while (did != 0 && did != 1 && did != 2)
			{
				cout << "输入错误，重新输入" << endl;
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

//查找员工信息
void Workermanager::searchemp()
{
	//判断文件是否为空
	if (this->m_fileEmpty)
	{
		cout << "文件为空或者记录为空" << endl;
	}
	else
	{
		cout << "输入查找标记:" << endl;
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

//排序
void Workermanager::sort()
{
	if (this->m_fileEmpty)
	{
		cout << "当前文件为空或者不存在" << endl;
		system("pause");
		system("cls");
		return;
	}
	int num;
	cout << "选择排序方式" << endl;
	cout << "0-正序" << endl;
	cout << "1-逆序" << endl;
	cin >> num;
	switch (num)
	{
	case 0:
	{bool swap = true;
	for (int i = 0; i < this->m_size - 1 && swap; i++)//排序的次数
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
		//选择排序
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
		cout << "输入数据不正确 排序失败" << endl;
		break;
	}
	this->save();
	system("pause");
	system("cls");
}

//清空文档
void Workermanager::clear()
{
	if (this->m_fileEmpty)
	{
		cout << "当前文件为空或者不存在" << endl;
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