#include "Lexer.h"

void Lexer::setSequence(const std::string sequence) {
	this->sequence = sequence;
}

void Lexer::Lex() {
	const std::string temp = sequence;
	for (; index < temp.size(); index++) {
		if (isSpace())
			continue;
		if (isOperator()) {
			tokens.push_back(Token(Token::Type::Operator, std::string(1, peek())));
			continue;
		}
		std::string number;
		while (isNumber()) {
			number += peek();
			next();
		}
		tokens.push_back(Token(Token::Type::Number, number));
	}
}

bool Lexer::isNumber() {
	switch (sequence[index])
	{
	case 48:
	case 49:
	case 50:
	case 51:
	case 52:
	case 53:
	case 54:
	case 55:
	case 56:
	case 57:
		return true;
	default:
		return false;
	}
}

bool Lexer::isOperator() {
	switch (sequence[index])
	{
	case 42:
	case 43:
	case 45:
	case 47:
		return true;
	default:
		return false;
	}
}

bool Lexer::isSpace() {
	switch (sequence[index])
	{
	case ' ':
	case '\n':
	case '\t':
	case '\r':
		return true;
	default:
		return false;
	}
	return false;
}

char Lexer::next() {
	return sequence[++index];
}

char Lexer::peek() {
	return sequence[index];
}

std::vector<Token> Lexer::getTokens() {
	return tokens;
}