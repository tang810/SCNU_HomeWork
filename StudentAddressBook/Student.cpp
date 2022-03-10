#include "Student.h"

ostream &operator<<(ostream &OutPut, Student &Stu)
{
	OutPut << "姓名: " << Stu.Name << " 性别：" << Stu.Gender << " 号码：" << Stu.PhoneNumber << endl;
	return OutPut;
}