#include "WorkerManager.h"
void WorkerManager::ChaEmp()
{
	if (this->FileEmpty)
	{
		cout << "ְ�������ļ������ڻ��ļ�Ϊ��" << endl;
	}
	else
	{
		cout << "������Ҫ�޸�ְ���ı�ţ�";
		int id;
		cin >> id;
		int ret = this->ExistOrNot(id);
		if (ret != -1)//����ְ������
		{
			cout << "��ѯ��" << id << "��ְ����" << endl;
			this->MEmpArr[ret]->ShowInfo();
			delete this->MEmpArr[ret];
			int new_id;
			string new_name;
			int new_dID;
			cout << "��������ְ���ţ�"; cin >> new_id;
			cout << "��������������"; cin >> new_name;
			cout << "�������λ��\n1.��ְͨ��\n2.����\n3.�ϰ�" << endl; cin >> new_dID;
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
			this->MEmpArr[ret] = worker;//��������
			cout << "�޸ĳɹ�" << endl;
			this->MEmpArr[ret]->ShowInfo();
			this->save();
		}
		else
		{
			cout << "δ�ҵ���ְ��" << endl;
		}
	}
	system("pasue");
	system("cls");
}