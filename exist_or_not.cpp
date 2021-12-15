#include "WorkerManager.h"
int WorkerManager::ExistOrNot(int id)
{
	int index = -1;
	for (int i = 0; i < this->MEmpNum; i++)
	{
		if (this->MEmpArr[i]->MID == id)
		{
			index = i;
			break;
		}
	}
	return index;
}