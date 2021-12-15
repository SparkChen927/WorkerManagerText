#include "WorkerManager.h"
void WorkerManager::FindEmp()
{
	if (this->FileEmpty)
	{
		cout << "职工数据文件不存在或文件为空" << endl;
	}
	else
	{
		cout << "请输入查找方式：\n1.按编号查找\n2.按姓名查找" << endl;
		int sel;
		cin >> sel;
		if (sel == 1)
		{
			int id;
			cout << "请输入职工编号："; cin >> id;
			int ret = this->ExistOrNot(id);
			if (ret != -1)
			{
				cout << "查找到：" << endl;
				this->MEmpArr[ret]->ShowInfo();
			}
			else
			{
				cout << "未找到该职工" << endl;
			}
		}
		else if (sel == 2)
		{
			string name;
			cout << "请输入职工姓名："; cin >> name;
			bool flag = false;
			for (int i = 0; i < this->MEmpNum; i++)
			{
				if (this->MEmpArr[i]->MName == name)
				{
					flag = true;
					this->MEmpArr[i]->ShowInfo();
				}
			}
			if (flag == false)
			{
				cout << "未找到该职工" << endl;
			}
		}
		else
		{
			cout << "选项不存在" << endl;
		}
	}
	system("pause");
	system("cls");
}