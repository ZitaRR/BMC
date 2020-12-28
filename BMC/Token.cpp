#include "Token.h"

Token::Token(Type type, const std::string value) : type{ type }, value{value} {}

std::ostream& operator<<(std::ostream& stream, const Token& token) {
	return stream << "[" << token.type <<  ", " << token.value << "]";
}

std::ostream& operator<<(std::ostream& stream, const Token::Type& type) {
	std::string types[] = {
		"Number", "Operator"
	};
	return stream << types[static_cast<int>(type)];
}