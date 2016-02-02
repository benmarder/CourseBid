#ifndef POINTS_ALLOCATION_STATE
#define POINTS_ALLOCATION_STATE
#include"PointsAllocationController.h"
#include"UiLibraryState.h"
class PointaAllocationState : public UiLibraryState
{
private:
	PointsAllocationController pac;
public:
	PointaAllocationState();
	~PointaAllocationState();
	void handleInput(char);
	void display();
};
#endif

