#pragma once
#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
	string Name;		//姓名
	string PhoneNumber; //电话号码
	string Gender;		//性别
	friend ostream &operator<<(ostream &OutPut, Student &Stu);
};

ostream &operator<<(ostream &OutPut, Student &Stu); //重载<<运算符