#ifndef IDOBJ
#define IDOBJ
#include "IdObjFactory.h"

class IdObj
{
private:
	int id;
	IdObjFactory factory;

public:
	IdObj();
	~IdObj();
	int getId();
	IdObjFactory getFactory();
};
#endif
