//customer class. pushing the basics first to keep in the habit of smaller commits.

#include <iostream>
#include <string>
#include "customer.h"
using namespace std;

Customer::Customer(std::string tempOrder, std::string tempAnswer)
{
	order = tempOrder;
	correctSandwich = tempAnswer;
}

std::string Customer::getOrder() const
{
	return order;
}

std::string Customer::getCorrectSandwich() const
{
	return correctSandwich;
}
void Customer::displayOrder()
{
	cout << "\n\n\nThe customer's order is:\n " << order << "\n\n\n";
}