#pragma once
#include<iostream>
using namespace std;
#include<string>
class Student
{
public:
	string Name;//����
	string PhoneNumber;//�绰����
	string Gender;//�Ա�
	friend ostream& operator <<(ostream& OutPut, Student& Stu);
};
ostream& operator<<(ostream& OutPut, Student& Stu);//����<<�����