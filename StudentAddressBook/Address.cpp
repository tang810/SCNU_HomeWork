#include "Address.h"

Address::Address()
{
	this->MyList.clear(); //清空容器
}

void Address::ShowMenu() //显示菜单
{
	cout << "----------学生通讯录---------" << endl;
	cout << "0、退出通讯录系统" << endl;
	cout << "1、添加联系人" << endl;
	cout << "2、删除联系人" << endl;
	cout << "3、查找联系人" << endl;
	cout << "4、查看所有联系人" << endl;
	cout << "5、修改已有联系人信息" << endl;
}

void Address::ExitSystem() //退出系统
{
	cout << "欢迎下次使用！" << endl;
	exit(0);
}

void Address::AddMember() //添加联系人
{
	Student NewMember;
	cout << "请输入姓名：" << endl;
	cin.ignore();
	getline(cin, NewMember.Name);
	cout << "请输入电话号码：" << endl;
	cin >> NewMember.PhoneNumber;
	cout << "请输入性别：(Male or Female)" << endl;
	cin >> NewMember.Gender;
	this->AppSave(NewMember); //保存新增联系人
}

void Address::AppSave(Student NewMember) //保存新增联系人
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out | ios::app); //以追加方式写文件
	ofs << NewMember.Name << "," << NewMember.Gender << "," << NewMember.PhoneNumber << "," << endl;
	ofs.close();
	cout << "添加联系人成功！" << endl;
	system("pause");
	system("cls");
}

void Address::LoadMember() //加载已有联系人
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//文件不存在情况
	if (!ifs.is_open())
	{
		cout << "文件不存在！" << endl;
		system("pause");
		system("cls");
		ifs.close();
		return;
	}
	//文件被清空情况
	char Check; //查看是否为空文件夹
	ifs >> Check;
	if (ifs.eof())
	{
		cout << "文件为空！" << endl;
		system("pause");
		system("cls");
		return;
	}
	//文件不为空
	ifs.putback(Check);
	string Information;
	while (getline(ifs, Information)) //姓名可带空格的输入
	{
		/*cout << Information<<endl;*/ //测试代码
		Student Temp;
		int Start = 0;
		int Pos = -1;
		int index = 0;
		string Data[4];
		while (1)
		{
			Pos = Information.find(',', Start);
			if (Pos == -1)
			{
				break;
			}
			Data[index++] = Information.substr(Start, Pos - Start);
			Start = Pos + 1;
		}
		Temp.Name = Data[0];
		Temp.Gender = Data[1];
		Temp.PhoneNumber = Data[2];
		this->MyList[Temp.Name] = Temp; //将成员放入名单容器中
	}
}

void Address::ShowAllMember() //查看所有联系人
{
	this->LoadMember();
	for (auto It = this->MyList.begin(); It != this->MyList.end(); It++)
	{
		/*cout << "姓名：" << It->second.Name << " 性别： " << It->second.Gender << " 号码：" << It->second.PhoneNumber << endl;*/
		cout << It->second;
	}
	system("pause");
	system("cls");
}

void Address::FindMember() //查找联系人
{
	cout << "请输入要查找的联系人的姓名:" << endl;
	string SearchName;
	cin >> SearchName;
	auto It = this->MyList.find(SearchName); //按名字查找
	if (It == MyList.end())
	{
		cout << "查无此联系人！" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		cout << "查询结果如下：" << endl;
		cout << It->second;
		system("pause");
		system("cls");
	}
}

void Address::DeleteMember() //删除联系人
{
	cout << "输入进行删除的联系人的姓名: " << endl;
	string SearchName;
	cin >> SearchName;
	auto It = this->MyList.find(SearchName);
	if (It == this->MyList.end())
	{
		cout << "查无此联系人！" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		this->MyList.erase(It);
		cout << "删除成功！" << endl;
		system("pause");
		system("cls");
	}
	this->AllSave();
}

void Address::AllSave() //覆盖保存所有联系人
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (auto It = this->MyList.begin(); It != MyList.end(); It++)
	{
		ofs << It->second.Name << "," << It->second.Gender << "," << It->second.PhoneNumber << "," << endl;
	}
	ofs.close();
}

void Address::Modify() //修改联系人信息
{
	cout << "请输入进行修改的联系人的姓名：" << endl;
	string SearchName;
	cin >> SearchName;
	auto It = this->MyList.find(SearchName);
	if (It == this->MyList.end())
	{
		cout << "查无此联系人！" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		cout << "查询结果如下：" << endl;
		cout << It->second;
	}
	this->MyList.erase(It); //删除修改前的联系人
	Student NewMember;
	cout << "请输入姓名：" << endl;
	cin.ignore();
	getline(cin, NewMember.Name);
	cout << "请输入电话号码：" << endl;
	cin >> NewMember.PhoneNumber;
	cout << "请输入性别：(Male or Female)" << endl;
	cin >> NewMember.Gender;
	this->MyList.insert(make_pair(NewMember.Name, NewMember));
	cout << "修改成功！" << endl;
	this->AllSave(); //保存
	system("pause");
	system("cls");
}

Address::~Address()
{
}