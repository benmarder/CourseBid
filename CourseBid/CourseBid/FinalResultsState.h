#ifndef FINAL_RESULT_STATE
#define FINAL_RESULT_STATE
#include "ListDisplayState.h"
class FinalResultsState :public ListDisplayState
{

public:
	FinalResultsState();
	~FinalResultsState();

	void get(int);
	void select(int);
};

#endif

