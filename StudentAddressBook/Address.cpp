#include"Address.h"
Address::Address()
{
	this->MyList.clear();//�������
}
void Address::ShowMenu() //��ʾ�˵�
{
	cout  << "----------ѧ��ͨѶ¼---------" << endl;
	cout  << "0���˳�ͨѶ¼ϵͳ" << endl;
	cout  << "1�������ϵ��" << endl;
	cout  << "2��ɾ����ϵ��" << endl;
	cout  << "3��������ϵ��" << endl;
	cout  << "4���鿴������ϵ��" << endl;
	cout  << "5���޸�������ϵ����Ϣ" << endl;
};
void Address::ExitSystem()//�˳�ϵͳ
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	exit(0);
}
void Address::AddMember()//�����ϵ��
{
	Student NewMember;
	cout << "������������" << endl;
	cin.ignore();
	getline(cin, NewMember.Name);
	cout << "������绰���룺" << endl;
	cin >> NewMember.PhoneNumber;
	cout << "�������Ա�(Male or Female)" << endl;
	cin >> NewMember.Gender;
	this->AppSave(NewMember);//����������ϵ��
}
void Address::AppSave(Student NewMember)//����������ϵ��
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out | ios::app);//��׷�ӷ�ʽд�ļ�
	ofs << NewMember.Name << "," << NewMember.Gender << "," << NewMember.PhoneNumber<<"," << endl;
	ofs.close();
	cout << "�����ϵ�˳ɹ���" << endl;
	system("pause");
	system("cls");
}
void Address::LoadMember()//����������ϵ��
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//�ļ����������
	if (!ifs.is_open())
	{
		cout << "�ļ������ڣ�" << endl;
		system("pause");
		system("cls");
		ifs.close();
		return;
	}
	//�ļ���������
	char Check;//�鿴�Ƿ�Ϊ���ļ���
	ifs >> Check;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ�գ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	//�ļ���Ϊ��
	ifs.putback(Check);
	string Information;
	while (getline(ifs,Information))//�����ɴ��ո������
	{
		/*cout << Information<<endl;*///���Դ���
		Student Temp;
		int Start = 0;
		int Pos = -1;
		int index=0;
		string Data[4];
		while (1)
		{
			Pos = Information.find(',',Start);
			if (Pos == -1)
			{
				break;
			}
			Data[index++]= Information.substr(Start, Pos-Start);
			Start = Pos + 1;

		}
		Temp.Name = Data[0];
		Temp.Gender = Data[1];
		Temp.PhoneNumber= Data[2];
		this->MyList[Temp.Name] = Temp;//����Ա��������������
		
	}
	
}
void Address::ShowAllMember()//�鿴������ϵ��
{
	this->LoadMember();
	for (auto It = this->MyList.begin(); It != this->MyList.end(); It++)
	{
		/*cout << "������" << It->second.Name << " �Ա� " << It->second.Gender << " ���룺" << It->second.PhoneNumber << endl;*/
		cout << It->second;
	}
	system("pause");
	system("cls");

}
void Address::FindMember()//������ϵ��
{
	cout << "������Ҫ���ҵ���ϵ�˵�����:" << endl;
	string SearchName;
	cin >> SearchName;
	auto It=this->MyList.find(SearchName);//�����ֲ���
	if (It == MyList.end())
	{
		cout << "���޴���ϵ�ˣ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		cout << "��ѯ������£�" << endl;
		cout << It->second; 
		system("pause");
		system("cls");
	}
	
}
void Address::DeleteMember()//ɾ����ϵ��
{
	cout << "�������ɾ������ϵ�˵�����: " << endl;
	string SearchName;
	cin >> SearchName;
	auto It = this->MyList.find(SearchName);
	if (It == this->MyList.end())
	{
		cout << "���޴���ϵ�ˣ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		this->MyList.erase(It);
		cout << "ɾ���ɹ���" << endl;
		system("pause");
		system("cls");
	}
	this->AllSave();
}
void Address::AllSave()//���Ǳ���������ϵ��
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (auto It = this->MyList.begin(); It != MyList.end(); It++)
	{
		ofs << It->second.Name << "," << It->second.Gender << "," << It->second.PhoneNumber << "," << endl;
	}
	ofs.close();

}
void Address::Modify()//�޸���ϵ����Ϣ
{
	cout << "����������޸ĵ���ϵ�˵�������" << endl;
	string SearchName;
	cin >> SearchName;
	auto It = this->MyList.find(SearchName);
	if (It == this->MyList.end())
	{
		cout << "���޴���ϵ�ˣ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		cout << "��ѯ������£�" << endl;
		cout << It->second;
	}
	this->MyList.erase(It);//ɾ���޸�ǰ����ϵ��
	Student NewMember;
	cout << "������������" << endl;
	cin.ignore();
	getline(cin, NewMember.Name);
	cout << "������绰���룺" << endl;
	cin >> NewMember.PhoneNumber;
	cout << "�������Ա�(Male or Female)" << endl;
	cin >> NewMember.Gender;
	this->MyList.insert(make_pair(NewMember.Name, NewMember));
	cout << "�޸ĳɹ���" << endl;
	this->AllSave();//����
	system("pause");
	system("cls");
	
}
Address::~Address()
{

}