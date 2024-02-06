#ifndef ID_MANAGER_H
#define ID_MANAGER_H

class IdManager
{
public:
	static unsigned char getUID();

private:
	static unsigned char freeUID;
};


#endif