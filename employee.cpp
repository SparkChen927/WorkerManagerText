#include "Employee.h"
Employee::Employee(int id, string name, int dID)
{
	this->MID = id;
	this->MName = name;
	this->MDeptID = dID;
}
void Employee::ShowInfo()
{
	cout << "ְ����ţ�" << this->MID << "\tְ��������" << this->MName << "\t��λ��" << this->GetDeptName() << endl;
}
string Employee::GetDeptName()
{
	return string("Ա��");
}