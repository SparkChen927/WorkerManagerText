#include "WorkerManager.h"
#include "Employee.h"
void WorkerManager::AddEmploy()
{
	cout << "����������ְ��������" << endl;
	int add_num = 0;
	cin >> add_num;
	if (add_num > 0)
	{
		//�����¿ռ��С
		int new_size = this->MEmpNum + add_num;
		//�����¿ռ�
		Worker** new_space = new Worker * [new_size];
		//��ž����ݵ��¿ռ�
		if (this->MEmpArr != NULL)
		{
			for (int i = 0; i < this->MEmpNum; i++)
			{
				new_space[i] = this->MEmpArr[i];
			}
		}
		//���������
		for (int i = 0; i < add_num; i++)
		{
			int id;
			string name;
			int selection;
			cout << "�������" << i + 1 << "����ְ���ı�ţ�"; cin >> id;
			cout << "�������" << i + 1 << "����ְ����������"; cin >> name;
			cout << "��ѡ���ְ���ĸ�λ��" << endl << "1.��ְͨ��" << endl << "2.����" << endl << "3.�ϰ�" << endl;
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
		//�ͷ�ԭ�пռ�
		delete[] this->MEmpArr;
		//�����¿ռ��ָ��
		this->MEmpArr = new_space;
		//����ְ������
		this->MEmpNum = new_size;
		//�����ļ���Ϊ�ձ�־
		this->FileEmpty = false;
		cout << "�ɹ����" << add_num << "����ְ��" << endl;
		this->save();
	}
	else
	{
		cout << "��������" << endl;
	}
	system("pause");
	system("cls");
}