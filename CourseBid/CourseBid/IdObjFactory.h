#ifndef IDOBJFACTORY
#define IDOBJFACTORY
#include "IStorage.h"
class IdObjFactory
{
private:
	IStorage* storage;
public:
	IdObjFactory();
	~IdObjFactory();
	template<class T> T construct(int id);
	template<class T> T allocate();
	IStorage* getStorage();
};

#endif

