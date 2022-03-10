#pragma once
#include<iostream>
using namespace std;
#include<string>
class Student
{
public:
	string Name;//姓名
	string PhoneNumber;//电话号码
	string Gender;//性别
	friend ostream& operator <<(ostream& OutPut, Student& Stu);
};
ostream& operator<<(ostream& OutPut, Student& Stu);//重载<<运算符