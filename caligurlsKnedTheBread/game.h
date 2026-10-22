#pragma once
#include <string>
#include "customer.h"

class Game
{
public:
	void startGame();
	int serveCustomer(Customer& customer);
private:
	std::string order;
};
