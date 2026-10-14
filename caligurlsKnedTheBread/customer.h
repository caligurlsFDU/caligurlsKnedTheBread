#pragma once
#include <string>
#include <vector>

class Customer
{
public:

	Customer();
	Customer(std::string tempOrder, std::vector<std::string> ingredients);
	void setOrder(std::string tempOrder, std::vector<std::string> ingredients);
	void displayOrder();
	std::string getOrder() const;
	std::vector<std::string> getCorrectSandwich() const;
	bool checkOrder(std::vector<std::string> orderToCheck) const;

private:
	std::string orderPrompt;
	std::vector<std::string> correctSandwich;
};