#include"Student.h"
ostream& operator<<(ostream& OutPut, Student& Stu)
{
	OutPut << "����: " << Stu.Name << " �Ա�" << Stu.Gender << " ���룺" << Stu.PhoneNumber << endl;
	return OutPut;
}