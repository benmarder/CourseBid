#ifndef CALC_ASSIGNING
#define CALC_ASSIGNING
#include <FileStorage.h>
#include <lemon/lp.h>
#include <lemon/glpk.h>
using namespace lemon;
using namespace std;


class CalcAssigning
{
public:
	CalcAssigning();
	~CalcAssigning();
	void addMinPoints();

};
#endif

