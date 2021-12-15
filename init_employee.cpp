#include "WorkerManager.h"
void WorkerManager::InitEmp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dID;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dID)
	{
		Worker* worker = NULL;
		//���ݲ�ͬ���Ŵ�����ͬ����
		if (dID == 1)
		{
			worker = new Employee(id, name, dID);
		}
		else if (dID == 2)
		{
			worker = new Manager(id, name, dID);
		}
		else if (dID == 3)
		{
			worker = new Boss(id, name, dID);
		}
		//�����������
		this->MEmpArr[index] = worker;
		index++;
	}
	ifs.close();
}