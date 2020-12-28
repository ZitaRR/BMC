#pragma once
#include <iostream>
#include <vector>
#include "Token.h"

class Lexer
{
public:
	void setSequence(const std::string sequence);
	std::vector<Token> tokenize();
private:
	std::string sequence;
	int index = 0;
	bool isNumber();
	bool isOperator();
	bool isSpace();
	Token lex();
};

