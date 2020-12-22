#include "Token.h"

Token::Token(Type type, const std::string value) : type{ type }, value{value} {}

std::ostream& operator<<(std::ostream& stream, const Token& token) {
	return stream << token.value;
}