#pragma once
#include <iostream>
using namespace std;
#include "Student.h"
#include <map>
#include <iomanip>
#include <vector>
#include "Student.h"
#include <string>
#include <algorithm>
#include <fstream>
#define FILENAME "NameList.csv" //保存通讯录名单在名为 NameList 的文件中

class Address
{
public:
	Address();						 //构造函数
	void ShowMenu();				 //显示菜单
	void ExitSystem();				 //退出系统
	void AddMember();				 //添加联系人
	void AppSave(Student NewMember); //保存新增联系人
	void AllSave();					 //覆盖保存所有联系人
	void LoadMember();				 //读入所有联系人
	void ShowAllMember();			 //查看所有联系人
	void FindMember();				 //查找联系人
	void DeleteMember();			 //删除联系人
	void Modify();					 //修改联系人信息
	~Address();						 //析构函数

public:
	map<string, Student> MyList; //存储联系人
};