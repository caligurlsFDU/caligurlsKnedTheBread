//customer class. pushing the basics first to keep in the habit of smaller commits.

#include <iostream>
#include <string>
#include <vector>
#include "customer.h"
using namespace std;

string orderPrompt = "example order";
vector<string> customerOrder;

Customer::Customer()
{
	orderPrompt = "blank";
	vector<string> customerOrder = { "example", "order" };
}

Customer::Customer(string prompt, vector<string> ingredients)
{
	orderPrompt = prompt;
	customerOrder = ingredients;
}

void Customer::setOrder(string tempOrder, vector<string> ingredients)
{
	orderPrompt = tempOrder;
	customerOrder = ingredients;
}
void Customer::displayOrder()
{
	cout << "\n\n\nThe customer's order is:\n " << orderPrompt << "\n\n\n";
}

bool Customer::checkOrder(vector<string> orderToCheck)
{
	return true;
}