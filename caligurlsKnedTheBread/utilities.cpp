#include "utilities.h"
#include <iostream>
#include <iomanip>
#include <random>
using namespace std;

// random number generator setup
static random_device rd;
static mt19937 gen(rd());
// Generates a random cost between min and max (inclusive) with two decimal places
double generateRandomCost(double min, double max)
{
    uniform_int_distribution<int> dist(static_cast<int>(min * 100), static_cast<int>(max * 100));
    return dist(gen) / 100.0;
}
utilities::utilities()
{
}
void utilities::generateCosts(int shift)
{
	rent = generateRandomCost(5, 10);

    water = 0.0;
    electricity = 0.0;
	gas = 0.0;
	internet = 0.0;
	groceries = 0.0;
	miscellaneous = 0.0;

    if (shift >= 2) water = generateRandomCost(5, 10);
    if (shift >= 3) electricity = generateRandomCost(5, 10);
    if (shift >= 4) gas = generateRandomCost(5, 10);
    if (shift >= 5) internet = generateRandomCost(5, 10);
    if (shift >= 6) groceries = generateRandomCost(8, 10);
    if (shift >= 7) miscellaneous = generateRandomCost(5, 10);
}

double utilities::getRent() const
{
	return rent;
}

double utilities::getElectricity() const
{
	return electricity;
}

double utilities::getWater() const
{
	return water;
}

double utilities::getGas() const
{
	return gas;
}
double utilities::getGroceries() const
{
    return groceries;
}
double utilities::getMiscellaneous() const
{
    return miscellaneous;
}

double utilities::getTotalCost() const
{
	return rent + electricity + water + gas + internet + groceries + miscellaneous;
}

void utilities::displayBreakdown() const
{
	cout << fixed << setprecision(2);
    cout << "╔══════════════════════════════════════╗\n";
    cout << "║     K N E D   T H E   B R E A D      ║\n";
    cout << "║         BAKERY UTILITY BILL          ║\n";
    cout << "╠══════════════════════════════════════╣\n";
    cout << "║                                      ║\n";
    cout << "║  BILL SUMMARY                        ║\n";
    cout << "║  ----------------------------------  ║\n";
    cout << "║  Rent:                 -$" << setw(5) << rent << "       ║\n";

    if (water > 0)
        cout << "║  Water:                -$" << setw(5) << water << "       ║\n";

    if (electricity > 0)
        cout << "║  Electricity:          -$" << setw(5) << electricity << "       ║\n";

    if (gas > 0)
        cout << "║  Gas:                  -$" << setw(5) << gas << "       ║\n";

    if (internet > 0)
        cout << "║  Internet:             -$" << setw(5) << internet << "       ║\n";

    if (groceries > 0)
        cout << "║  Groceries:            -$" << setw(5) << groceries << "       ║\n";

    if (miscellaneous > 0)
        cout << "║  Miscellaneous:        -$" << setw(5) << miscellaneous << "       ║\n";

    //cout << "╠══════════════════════════════════════╣\n";
    cout << "║  TOTAL AMOUNT DUE:     -$" << setw(5) << getTotalCost() << "       ║\n";
    cout << "╠══════════════════════════════════════╣\n";      
    cout << "║                                      ║\n";
    cout << "║     THANK YOU FOR YOUR BUSINESS!     ║\n";
    cout << "║                                      ║\n";
    cout << "╚══════════════════════════════════════╝\n";
}