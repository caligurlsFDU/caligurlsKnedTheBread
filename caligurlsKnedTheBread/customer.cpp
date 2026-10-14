//customer class. pushing the basics first to keep in the habit of smaller commits.
#include <iostream>
#include <string>
#include <vector>
#include "customer.h"

using namespace std;

Customer::Customer()
{
	orderPrompt = "blank";
	customerOrder = {};
}

Customer::Customer(std::string prompt, std::vector<std::string> ingredients)
{
	orderPrompt = prompt;
	customerOrder = ingredients;
}

void Customer::setOrder(std::string tempOrder, std::vector<std::string> ingredients)
{
	orderPrompt = tempOrder;
	customerOrder = ingredients;
}

void Customer::displayOrder()
{
	cout << "\n\n\nThe customer's order is:\n " << orderPrompt << "\n\n\n";
}

std::string Customer::getOrder() const
{
	return orderPrompt;
}

std::vector<std::string> Customer::getCorrectSandwich() const
{
	return customerOrder;
}
bool Customer::checkOrder(std::vector<std::string> orderToCheck) const
{
	return orderToCheck == customerOrder;
}










	//Customer::Customer()
	//{
	//	orderPrompt = "blank";
	//	vector<string> customerOrder = { "example", "order" };
	//}

	//Customer::Customer(string prompt, vector<string> ingredients)
	//{
	//	orderPrompt = prompt;
	//	customerOrder = ingredients;
	//}
	//	std::vector<std::string> Customer::getCorrectSandwich() const
	//	====== =
	//	void Customer::setOrder(string tempOrder, vector<string> ingredients)
	//{
	//	orderPrompt = tempOrder;
	//	customerOrder = ingredients;
	//}
	//	void Customer::displayOrder()
	//{
	//	cout << "\n\n\nThe customer's order is:\n " << orderPrompt << "\n\n\n";
	//}

	//bool Customer::checkOrder(vector<string> orderToCheck)
	//{
	//	if (orderToCheck == customerOrder)
	//	{
	//		return true;
	//	}
	//	else
	//	{
	//		return false;
	//	}
	//	return true;
	//}
