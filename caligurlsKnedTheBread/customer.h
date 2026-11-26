#pragma once
#include <string>
#include <vector>
#include "orderGenerator.h"

class Customer
{
public:

	Customer();
	Customer(std::string tempOrder, std::vector<std::string> ingredients);
	void setOrder(std::string tempOrder, std::vector<std::string> ingredients);
	void displayOrder();
	void scrambleOrder();
	std::string getOrder() const;
	std::vector<std::string> getCorrectSandwich() const;
	bool checkOrder(std::vector<std::string> orderToCheck) const;
	static std::vector<Customer> createCustomers(
		orderGenerator& generator, int count, int minMeats = 0,
		bool scrambleText = false);

private:
	std::string orderPrompt;
	std::vector<std::string> customerOrder;
};