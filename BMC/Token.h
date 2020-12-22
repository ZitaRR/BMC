#pragma once
#include <iostream>

class Token
{
public:
	enum class Type {
		Number,
		Operator
	};
	Token(Type _type, const std::string value);
	friend std::ostream& operator<<(std::ostream& stream, const Token& token);
private:
	std::string value;
	Type type;
};

