#include "WorkerManager.h"
void WorkerManager::ShowEmp()
{
	if (this->FileEmpty)
	{
		cout << "职工数据文件不存在或文件为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->MEmpNum; i++)
		{
			this->MEmpArr[i]->ShowInfo();
		}
	}
	system("pause");
	system("cls");
}