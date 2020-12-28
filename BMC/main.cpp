#include <iostream>
#include "Lexer.h"

int main() {
	Lexer lex = Lexer();
	lex.setSequence("456 - 34 * 34");
	for (auto token : lex.tokenize()) {
		std::cout << token << std::endl;
	}
	return 0;
}