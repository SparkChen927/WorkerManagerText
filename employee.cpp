#include "Employee.h"
Employee::Employee(int id, string name, int dID)
{
	this->MID = id;
	this->MName = name;
	this->MDeptID = dID;
}
void Employee::ShowInfo()
{
	cout << "职工编号：" << this->MID << "\t职工姓名：" << this->MName << "\t岗位：" << this->GetDeptName() << endl;
}
string Employee::GetDeptName()
{
	return string("员工");
}