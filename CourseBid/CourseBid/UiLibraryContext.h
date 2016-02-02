#ifndef UI_LIBRARY_CONTEXT
#define UI_LIBRARY_CONTEXT
class UiLibraryState; // forward declaration

class UiLibraryContext
{
private:
	UiLibraryState* state;
public:
	UiLibraryContext();
	~UiLibraryContext();
	void setState(UiLibraryState*);
};
#endif
