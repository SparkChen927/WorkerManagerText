#include "Manager.h"
Manager::Manager(int id, string name, int dID)
{
	this->MID = id;
	this->MName = name;
	this->MDeptID = dID;
}
void Manager::ShowInfo()
{
	cout << "ְ����ţ�" << this->MID << "\tְ��������" << this->MName << "\t��λ��" << this->GetDeptName() << endl;
}
string Manager::GetDeptName()
{
	return string("����");
}