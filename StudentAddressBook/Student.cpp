#include"Student.h"
ostream& operator<<(ostream& OutPut, Student& Stu)
{
	OutPut << "ÐÕÃû: " << Stu.Name << " ÐÔ±ð£º" << Stu.Gender << " ºÅÂë£º" << Stu.PhoneNumber << endl;
	return OutPut;
}