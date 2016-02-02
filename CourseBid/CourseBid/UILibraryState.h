#ifndef __courseBid__UILibraryState__
#define __courseBid__UILibraryState__

#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

class UILibraryState {
private:

public:
	UILibraryState();
	~UILibraryState();
	void tooManyPointsAllocated();
	string studentPostBiddingScreen(vector<string>); 
	void terminalIsLocked();
	void errorSyntax(string);
	void errorAuthentication(int);
	string terminalListDisplayState(vector<string>);
	string listOfCoursesSecretary(vector<string>);
	string listOfStudentSecretary(vector<string>);
	string deleteCourseScreen(vector<string>); 
	string deleteStudentScreen(vector<string>); 
	string editStudentChooseScreen(vector<string>); 
	string editCourseChooseScreen(vector<string>);
	string listOfStudentSecretaryPostBidding(vector<string>);
	string listOfCoursesOfStudentPostBidding(vector<string>);
	string studentListOfCoursesToBid(vector<string>);
	string studentStartBidding();
	void addedSuccessfully(); //new
	string studentBiddingScreen(string,string,string);
	vector<string> editStudentScreen(); //changed
	vector<string> editCourseScreen();
	map<string, string> authenticateScreen();
	vector<string> addNewCourseScreen();
	vector<string> addNewStudentScreen(); //changed
	string secretaryOptions();
	string addFormula(); 
	void errorFormula();
};

#endif /* defined(__courseBid__UILibraryState__) */
