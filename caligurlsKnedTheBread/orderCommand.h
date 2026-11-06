#pragma once
#include <string>

/// @class orderCommand
/// @brief Recognizes typed commands that aren't ingredients.
/// Stateless class, all methods are static, no constructor.
/// Methods:
///  -bool isOrderUp(string) - true if ingredients::sanitize(input) == "order up"
///  -bool isBin(string)     - true if ingredients::sanitize(input) == "bin"
class orderCommand
{
public:
	orderCommand() = delete;

	static bool isOrderUp(std::string input);
	static bool isBin(std::string input);
};