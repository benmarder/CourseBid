#ifndef REMOVE_LOCK
#define REMOVE_LOCK
#include <FileStorage.h>
#include <UILibrary.h>

class RemoveLock
{
private:
	UILibrary ui;
	FileStorage* fs;
public:
	RemoveLock();
	~RemoveLock();
};
#endif