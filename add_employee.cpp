#include "WorkerManager.h"
#include "Employee.h"
void WorkerManager::AddEmploy()
{
	cout << "请输入增加职工数量：" << endl;
	int add_num = 0;
	cin >> add_num;
	if (add_num > 0)
	{
		//计算新空间大小
		int new_size = this->MEmpNum + add_num;
		//开辟新空间
		Worker** new_space = new Worker * [new_size];
		//存放旧数据到新空间
		if (this->MEmpArr != NULL)
		{
			for (int i = 0; i < this->MEmpNum; i++)
			{
				new_space[i] = this->MEmpArr[i];
			}
		}
		//存放新数据
		for (int i = 0; i < add_num; i++)
		{
			int id;
			string name;
			int selection;
			cout << "请输入第" << i + 1 << "个新职工的编号："; cin >> id;
			cout << "请输入第" << i + 1 << "个新职工的姓名："; cin >> name;
			cout << "请选择该职工的岗位：" << endl << "1.普通职工" << endl << "2.经理" << endl << "3.老板" << endl;
			cin >> selection;
			Worker* worker = NULL;
			switch (selection)
			{
			case 1:
				worker = new Employee(id, name, selection);
				break;
			case 2:
				worker = new Employee(id, name, selection);
				break;
			case 3:
				worker = new Employee(id, name, selection);
				break;
			default:
				break;
			}
			new_space[this->MEmpNum + i] = worker;
		}
		//释放原有空间
		delete[] this->MEmpArr;
		//更改新空间的指向
		this->MEmpArr = new_space;
		//更新职工数量
		this->MEmpNum = new_size;
		//更新文件不为空标志
		this->FileEmpty = false;
		cout << "成功添加" << add_num << "名新职工" << endl;
		this->save();
	}
	else
	{
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");
}