#pragma once
#include <iostream>
#include <vector>
#include "Token.h"

class Lexer
{
public:
	void setSequence(const std::string sequence);
	void Lex();
	std::vector<Token> getTokens();
private:
	std::string sequence;
	std::vector<Token> tokens;
	int index = 0;
	bool isNumber();
	bool isOperator();
	bool isSpace();
	char next();
	char peek();
};

