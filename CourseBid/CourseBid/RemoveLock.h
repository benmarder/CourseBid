#ifndef REMOVE_LOCK
#define REMOVE_LOCK
#include "FileStorage.h"
#include "UILibraryState.h"
#include "Terminal.h"

class RemoveLock
{
private:
	UILibraryState ui;
	FileStorage* fs;
public:
	RemoveLock();
	~RemoveLock();
};
#endif