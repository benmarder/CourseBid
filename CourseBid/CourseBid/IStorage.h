#ifndef ISTORAGE
#define ISTORAGE
#include <iostream>
using namespace std;
class IStorage 
{
public:
	virtual string get(string id)=0;
	virtual void set(string id, string value)=0;

};
#endif
