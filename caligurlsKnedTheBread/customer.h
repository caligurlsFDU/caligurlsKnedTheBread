#pragma once
#include  <string>
#include <vector>
using namespace std;

class Customer
{
public:
	Customer();
	Customer(string prompt, vector<string> ingredients);
	void displayOrder();
	void setOrder(std::string tempOrder, vector<string> ingredients);

	bool checkOrder(vector<string> orderToCheck);

private:

};