

#include "Parser.h"

bool Parser::isOperator(char c) {
	return c == '+' || c == '-' || c == '/' || c == '*';
}

bool Parser::isParanthesis(char c) {
	return c == '(' || c == ')';
}

int Parser::cmpPrecedence(char op1, char op2) {
	return opMap.find(op1)->second->first - opMap.find(op2)->second->first;
}

bool Parser::isAssociative(char op, int side) {
	return opMap.find(op)->second->second == side;
}

bool Parser::infixToRpn(vector<char> &input, int size, vector<char> & strArray) {
	bool success = true;

	list<char> out;
	stack<char> stack;

	for (int i = 0; i < size; i++)
	{
		char token = input[i];

		if (isOperator(token))
		{
			if (i + 1 < size && (input[i + 1] == '*' || input[i + 1] == '/'))  //check for error like num +* num
				return false;
			if (((input[i] == '*' || input[i] == '/') && i == 0) || i == size - 1) //check for errors like "*num" or "num/"
				return false;
			char o1 = token;

			if (!stack.empty())
			{
				char o2 = stack.top();

				while (isOperator(o2) &&
					((isAssociative(o1, 0) && cmpPrecedence(o1, o2) == 0) ||
					(cmpPrecedence(o1, o2) < 0)))
				{

					stack.pop();
					out.push_back(o2);

					if (!stack.empty())
						o2 = stack.top();
					else
						break;
				}
			}

			stack.push(o1);
		}
		else if (token == '(')
		{
			stack.push(token);
		}
		else if (token == ')')
		{
			char topToken = stack.top();

			while (topToken != '(')
			{
				out.push_back(topToken);
				stack.pop();

				if (stack.empty()) break;
				topToken = stack.top();
			}

			if (!stack.empty()) stack.pop();

			if (topToken != '(')
			{
				return false;
			}
		}
		else
		{
			out.push_back(token);
		}
	}

	while (!stack.empty())
	{
		char stackToken = stack.top();

		if (isParanthesis(stackToken))
		{
			return false;
		}

		out.push_back(stackToken);
		stack.pop();
	}

	strArray.assign(out.begin(), out.end());

	return success;
}

void Parser::processConst(int i) {
	exprStack.push(new ConstExpr(i));
}

void Parser::processOperator(char o) {
	Expression* ex1 = exprStack.top();
	exprStack.pop();
	if (exprStack.empty()) {
		exprStack.push(new UnaryMinus(ex1));
	}
	else {

		Expression* ex2 = exprStack.top();
		exprStack.pop();
		switch (o) {
		case '+':
			exprStack.push(new BinaryPlus(ex1, ex2));
			break;
		case '-':
			exprStack.push(new BinaryMinus(ex1, ex2));
			break;
		case '*':
			exprStack.push(new BinaryMult(ex1, ex2));
			break;
		case '/':
			exprStack.push(new BinaryDiv(ex1, ex2));
			break;
		default:
			break;
		}
	}
}

void Parser::processAt() {
	exprStack.push(new At());
}


Expression *Parser::getExpression() {
	return exprStack.top();
}
