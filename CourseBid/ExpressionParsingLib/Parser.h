//
// Created by dudi on 08/08/2015.
//

#ifndef MATHPARSER_PARSER_H
#define MATHPARSER_PARSER_H

#include <stack>
#include <list>
#include <map>
#include <vector>
#include <iostream>
#include "BinaryPlus.h"
#include "BinaryMinus.h"
#include "UnaryMinus.h"
#include "BinaryMult.h"
#include "BinaryDiv.h"
#include "ConstExpr.h"
#include "At.h"

using namespace std;

class Parser {
public:
	Parser() {
		opMap['+'] = new pair<int, int>(0, 0);
		opMap['-'] = new pair<int, int>(0, 0);
		opMap['*'] = new pair<int, int>(5, 0);
		opMap['/'] = new pair<int, int>(5, 0);
	}
	void processConst(int);
	void processOperator(char);
	void processAt();
	Expression * getExpression();
	bool infixToRpn(vector<char>& input, int size, vector<char> & strArray);


private:
	bool isOperator(char c);
	bool isParanthesis(char c);
	int cmpPrecedence(char op1, char op2);
	bool isAssociative(char op, int size);

	map<char, pair<int, int>*> opMap;
	stack<Expression*> exprStack;

};


#endif //MATHPARSER_PARSER_H
