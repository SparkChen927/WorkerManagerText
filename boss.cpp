#include "Boss.h"
Boss::Boss(int id, string name, int dID)
{
	this->MID = id;
	this->MName = name;
	this->MDeptID = dID;
}
void Boss::ShowInfo()
{
	cout << "职工编号：" << this->MID << "\t职工姓名：" << this->MName << "\t岗位：" << this->GetDeptName() << endl;
}
string Boss::GetDeptName()
{
	return string("老板");
}