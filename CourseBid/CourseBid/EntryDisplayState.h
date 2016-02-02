#ifndef ENTRY_DISPLAY_STATE
#define ENTRY_DISPLAY_STATE
#include <iostream>
#include"UiLibraryState.h"
using namespace std;
class EntryDisplayState: public UiLibraryState
{
public:
	EntryDisplayState(){}
	~EntryDisplayState(){}
	void virtual handleInput(char){}
	void virtual display(){}
	int virtual getFieldCount(int)=0;
	string virtual getCaption(int)=0;
	bool virtual getValue(int)= 0;
	void virtual edit(int)=0;

};
#endif
