#pragma once
#include<iostream>
using namespace std;
#include"Student.h"
#include<map>
#include<iomanip>
#include<vector>
#include"Student.h"
#include<string>
#include<algorithm>
#include<fstream>
#define  FILENAME "NameList.csv"//����ͨѶ¼��������Ϊ NameList ���ļ���
class Address
{
public:
	Address();//���캯��
	void ShowMenu();//��ʾ�˵�
	void ExitSystem();//�˳�ϵͳ
	void AddMember();//�����ϵ��
	void AppSave(Student NewMember);//����������ϵ��
	void AllSave();//���Ǳ���������ϵ��
	void LoadMember();//����������ϵ��
	void ShowAllMember();//�鿴������ϵ��
	void FindMember();//������ϵ��
	void DeleteMember();//ɾ����ϵ��
	void Modify();//�޸���ϵ����Ϣ
	~Address(); //��������

public:
	map<string, Student>MyList;//�洢��ϵ��

};