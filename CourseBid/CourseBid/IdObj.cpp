#include "IdObj.h"
#include "IdObjFactory.h"


IdObj::IdObj()
{
}


IdObj::~IdObj()
{
}


IdObjFactory IdObj::getFactory()
{
	return factory;
}

int IdObj::getId() 
{
	return id;
}
