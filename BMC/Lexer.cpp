#include "Lexer.h"

void Lexer::setSequence(const std::string sequence) {
	this->sequence = sequence;
}

std::vector<Token> Lexer::tokenize() {
	std::vector<Token> tokens;
	for (; index < sequence.size(); ) {
		auto token = lex();
		tokens.push_back(token);
	}
	return tokens;
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
	case 40:
	case 41:
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
}

Token Lexer::lex() {
	while (isSpace()) index++;
	if (isOperator()) {
		return Token(Token::Type::Operator, sequence[index++]);
	}
	std::string number;
	do {
		number += sequence[index++];
	} while (isNumber());
	return Token(Token::Type::Number, number);
}