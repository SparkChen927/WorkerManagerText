#include "WorkerManager.h"
int WorkerManager::GetEmpSum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dID;
	int sum = 0;
	while (ifs >> id && ifs >> name && ifs >> dID)
	{
		sum++;
	}
	ifs.close();
	return sum;
}
