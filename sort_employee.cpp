#include "WorkerManager.h"
void WorkerManager::SortEmp()
{
	if (this->FileEmpty)
	{
		cout << "职工数据文件不存在或文件为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式：\n1.升序\n2.降序" << endl;
		int sel;
		cin >> sel;
		for (int i = 0; i < this->MEmpNum; i++)
		{
			int m = 1;
			for (int j = i + 1; j < this->MEmpNum; j++)
			{
				if (sel == 1)//升序
				{
					if (this->MEmpArr[m]->MID > this->MEmpArr[j]->MID)
					{
						m = j;
					}
				}
				else//降序
				{
					if (this->MEmpArr[m]->MID < this->MEmpArr[j]->MID)
					{
						m = j;
					}
				}
			}
			if (i != m)
			{
				Worker* temp = this->MEmpArr[i];
				this->MEmpArr[i] = this->MEmpArr[m];
				this->MEmpArr[m] = temp;
			}
		}
		cout << "排序成功" << endl;
		this->save();
		cout << "排序结果为：" << endl;
		this->ShowEmp();
	}
}