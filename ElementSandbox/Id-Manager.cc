#include "id-manager.hh"

unsigned char IdManager::freeUID = 0;

unsigned char IdManager::getUID()
{
	return freeUID++;
}