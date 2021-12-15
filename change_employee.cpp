#include "WorkerManager.h"
void WorkerManager::ChaEmp()
{
	if (this->FileEmpty)
	{
		cout << "职工数据文件不存在或文件为空" << endl;
	}
	else
	{
		cout << "请输入要修改职工的编号：";
		int id;
		cin >> id;
		int ret = this->ExistOrNot(id);
		if (ret != -1)//更改职工数据
		{
			cout << "查询到" << id << "号职工：" << endl;
			this->MEmpArr[ret]->ShowInfo();
			delete this->MEmpArr[ret];
			int new_id;
			string new_name;
			int new_dID;
			cout << "请输入新职工号："; cin >> new_id;
			cout << "请输入新姓名："; cin >> new_name;
			cout << "请输入岗位：\n1.普通职工\n2.经理\n3.老板" << endl; cin >> new_dID;
			Worker* worker = NULL;
			switch (new_dID)
			{
			case 1:
				worker = new Employee(new_id, new_name, new_dID);
				break;
			case 2:
				worker = new Manager(new_id, new_name, new_dID);
				break;
			case 3:
				worker = new Boss(new_id, new_name, new_dID);
				break;
			default:
				break;
			}
			this->MEmpArr[ret] = worker;//更新数据
			cout << "修改成功" << endl;
			this->MEmpArr[ret]->ShowInfo();
			this->save();
		}
		else
		{
			cout << "未找到该职工" << endl;
		}
	}
	system("pasue");
	system("cls");
}