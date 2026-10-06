//customer class. pushing the basics first to keep in the habit of smaller commits.

#include <iostream>
#include <string>
#include "customer.h"
using namespace std;

string order = "example order";

void Customer::setOrder(string tempOrder)
{
	order = tempOrder;
}
void Customer::displayOrder()
{
	cout << "\n\n\nThe customer's order is:\n " << order << "\n\n\n";
}