#pragma once
#include <string>
#include "customer.h"

class Game
{
public:
	void startGame();
	double serveCustomer(Customer& customer, int shift);
private:
	std::string order;
};