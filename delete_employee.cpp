#include "WorkerManager.h"
void WorkerManager::DelEmp()
{
	if (this->FileEmpty)
	{
		cout << "职工数据文件不存在或文件为空" << endl;
	}
	else
	{
		cout << "请输入要删除职工的编号：";
		int id;
		cin >> id;
		int index = this->ExistOrNot(id);
		if (index != -1)//职工存在，删除该职工
		{
			int ret = this->ExistOrNot(id);
			cout << "查找到：" << endl;
			this->MEmpArr[ret]->ShowInfo();
			cout << "是否确认？\n1.是\n2.否" << endl;
			int sel;
			cin >> sel;
			if (sel == 1)
			{
				for (int i = index; i < this->MEmpNum - 1; i++)
				{
					this->MEmpArr[i] = this->MEmpArr[i + 1];//数据前移
				}
				this->MEmpNum--;//更新人数
				this->save();
				cout << "删除成功" << endl;
			}
			else if (sel == 2)
			{
				cout << "已取消" << endl;
			}
			else
			{
				cout << "选项不存在" << endl;
			}
		}
		else
		{
			cout << "未找到该职工" << endl;
		}
	}
	system("pause");
	system("cls");
}