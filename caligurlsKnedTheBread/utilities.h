#pragma once
#ifndef utilities_h
#define utilities_h
class utilities
{
public:
	utilities();
	void generateCosts(int shift);
	double getRent() const;
	double getElectricity() const;
	double getWater() const;
	double getGas() const;
	double getInternet() const;
	double getGroceries() const;
	double getMiscellaneous() const;
	double getTotalCost() const;
	void displayBreakdown() const;

private:
	double rent = 0.0;
	double electricity = 0.0;
	double water = 0.0;
	double gas = 0.0;
	double internet = 0.0;
	double groceries = 0.0;
	double miscellaneous = 0.0;
};


#endif // utilities_h