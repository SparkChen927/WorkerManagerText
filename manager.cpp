#include "Manager.h"
Manager::Manager(int id, string name, int dID)
{
	this->MID = id;
	this->MName = name;
	this->MDeptID = dID;
}
void Manager::ShowInfo()
{
	cout << "职工编号：" << this->MID << "\t职工姓名：" << this->MName << "\t岗位：" << this->GetDeptName() << endl;
}
string Manager::GetDeptName()
{
	return string("经理");
}