#include <iostream>
#include "Lexer.h"

int main() {
	Lexer lex = Lexer();
	lex.setSequence("45 + 10");
	lex.Lex();
	for (auto token : lex.getTokens()) {
		std::cout << token;
	}
	return 0;
}