#include "Boss.h"
Boss::Boss(int id, string name, int dID)
{
	this->MID = id;
	this->MName = name;
	this->MDeptID = dID;
}
void Boss::ShowInfo()
{
	cout << "ְ����ţ�" << this->MID << "\tְ��������" << this->MName << "\t��λ��" << this->GetDeptName() << endl;
}
string Boss::GetDeptName()
{
	return string("�ϰ�");
}