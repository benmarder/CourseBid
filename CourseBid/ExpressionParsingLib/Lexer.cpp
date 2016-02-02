
#include "Lexer.h"

Lexer::Lexer(const string &exprString) : exprString(exprString){
	parser = new Parser();
	if (!tokenize())
		setHasError(true);
}
bool Lexer::tokenize() {
	vector<char> string(exprString.begin(), exprString.end());
	return parser->infixToRpn(string, string.size(), tokens);
}

Expression *Lexer::getExpression() {
	if (getHasError()){
		return NULL;
	}
	for (vector<char>::const_iterator i = tokens.begin(); i != tokens.end(); ++i) {
		int x = 0;
		vector<int>num;
		int temp = 0;
		int digit;
		if (isdigit(*i)){
			while (i != tokens.end() && isdigit(*i)) {
				digit = *i - '0';
				num.push_back(digit);
				i++;
			}
			i--;
			for (int y = 0; y < num.size(); ++y){
				temp += pow(10, num.size() - y - 1)*num[y];
			}
			parser->processConst(temp);
		}

		else if (*i == '@') {
			parser->processAt();
		}

		else if (*i == '+' || *i == '-' || *i == '/' || *i == '*') {
			parser->processOperator(*i);
		}
	}
	return parser->getExpression();

}
void Lexer::setHasError(bool flag){ hasError = flag; }
bool Lexer::getHasError(){ return hasError; }