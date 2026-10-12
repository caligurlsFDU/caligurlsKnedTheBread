#pragma once
#include  <string>

class Customer
{
public:
	Customer(std::string tempOrder, std::string tempAnswer);

	void displayOrder();
	std::string getOrder() const;
	std::string getCorrectSandwich() const;
private:
    std::string order;
    std::string correctSandwich;
};