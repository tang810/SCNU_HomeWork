#include<iostream>
#include"Address.h"
using namespace std;
int main()
{
	Address Main;
	while (1)
	{
		Main.ShowMenu();
		int Select = 0;
		cin >> Select;
		switch (Select)
		{
		case 0:
			Main.ExitSystem();//�˳�����
			break;
		case 1:
			Main.AddMember();//�����µ���ϵ��
			break;
		case 2:
			Main.DeleteMember();//ɾ����ϵ��
			break;
		case 3:
			Main.FindMember();//������ϵ��
			break;
		case 4:
			Main.ShowAllMember();//�鿴������ϵ��
			break;
		case 5:
			Main.Modify();//�޸�������ϵ��
			break;
		default :
			cout << "�����������������룡" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}