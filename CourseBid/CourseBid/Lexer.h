

#ifndef MATHPARSER_LEXER_H
#define MATHPARSER_LEXER_H

#include <stack>
#include <list>
#include <map>
#include <vector>
#include "Parser.h"

using namespace std;

class Lexer {
public:
	Lexer(const string &);
	bool tokenize();
	Expression * getExpression();
	void setHasError(bool);
	bool getHasError();
private:
	bool hasError = false;
	Parser* parser;
	string exprString;
	vector<char> tokens;
	map<char, pair<int, int>*> opMap;
};



#endif //MATHPARSER_LEXER_H
