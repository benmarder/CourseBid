#include "IdObjFactory.h"

IdObjFactory::IdObjFactory()
{
}


IdObjFactory::~IdObjFactory()
{
}

template<class T> T IdObjFactory::allocate() 
{
	return 0;
}

template<class T> T IdObjFactory::construct(int id)
{
	return 0;
}

IStorage* IdObjFactory::getStorage() 
{
	return storage;
}
