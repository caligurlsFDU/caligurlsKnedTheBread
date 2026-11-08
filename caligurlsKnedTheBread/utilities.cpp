#include "utilities.h"
#include <iostream>
#include <iomanip>
#include <random>
using namespace std;

// random number generator setup
static random_device rd;
static mt19937 gen(rd());
// Generates a random cost between min and max (inclusive) with two decimal places
double generateRandomCost(int min, int max)
{
	uniform_real_distribution<int> dist(min * 100, max * 100);
	return dist(gen) / 100.0;
}
utilities::utilities()
{
}
void utilities::generateCosts(int shift)
{
	rent = generateRandomCost(15, 30);

    water = 0.0;
    electricity = 0.0;
	gas = 0.0;
	internet = 0.0;
	groceries = 0.0;
	miscellaneous = 0.0;

    if (shift >= 2) water = generateRandomCost(8, 20);
    if (shift >= 3) electricity = generateRandomCost(15, 30);
    if (shift >= 4) gas = generateRandomCost(12, 25);
    if (shift >= 5) internet = generateRandomCost(8, 18);
    if (shift >= 6) groceries = generateRandomCost(18, 35);
    if (shift >= 7) miscellaneous = generateRandomCost(5, 20);
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
    cout << "║          K N E D   T H E   B R E A D ║\n";
    cout << "║           BAKERY UTILITY BILL        ║\n";
    cout << "╠══════════════════════════════════════╣\n";
    cout << "║                                      ║\n";
    cout << "║  BILL SUMMARY                        ║\n";
    cout << "║  ----------------------------------  ║\n";
    cout << "╔══════════════════════════════════════╗\n";
    cout << "║          K N E D   T H E   B R E A D ║\n";
    cout << "║           BAKERY UTILITY BILL        ║\n";
    cout << "╠══════════════════════════════════════╣\n";
    cout << "║  Rent:                 $" << setw(8) << rent << "       ║\n";

    if (water > 0)
        cout << "║  Water:                $" << setw(8) << water << "       ║\n";

    if (electricity > 0)
        cout << "║  Electricity:          $" << setw(8) << electricity << "       ║\n";

    if (gas > 0)
        cout << "║  Gas:                  $" << setw(8) << gas << "       ║\n";

    if (internet > 0)
        cout << "║  Internet:             $" << setw(8) << internet << "       ║\n";

    if (groceries > 0)
        cout << "║  Groceries:            $" << setw(8) << groceries << "       ║\n";

    if (miscellaneous > 0)
        cout << "║  Miscellaneous:        $" << setw(8) << miscellaneous << "       ║\n";

    cout << "╠══════════════════════════════════════╣\n";
    cout << "║  TOTAL AMOUNT DUE:     $" << setw(8) << getTotalCost() << "       ║\n";
    cout << "╠══════════════════════════════════════╣\n";      
    cout << "║                                      ║\n";
    cout << "║       THANK YOU FOR YOUR BUSINESS!   ║\n";
    cout << "║                                      ║\n";
    cout << "╚══════════════════════════════════════╝\n";
}