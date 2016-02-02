#ifndef NON_REF_LIST
#define NON_REF_LIST

#include <iostream>
using namespace std;

template <class T,int i>
class NonRefList
{

private:
	IdObj obj;
public:
	
	NonRefList() {}
	~NonRefList() {}
	int count() {}
	void add(T obj, int index) {}
	void remove(T index) {}
	T get(int index) { return obj; }
		
};
#endif
