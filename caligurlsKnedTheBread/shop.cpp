#include "shop.h"

int shop::getPriceCents(int ingredient)
{
	switch (ingredient)
	{
    case 1: return 100; // White Bread
    case 2: return 125; // Wheat Bread
    case 3: return 150; // Ham
    case 4: return 175; // Turkey
    case 5: return 200; // Roast Beef
    case 6: return 50;  // American Cheese
    case 7: return 75;  // Swiss Cheese
    case 8: return 25;  // Lettuce
    case 9: return 50;  // Tomato
    case 10: return 25; // Mayo
    default: return -1;
	}
}
int shop::getItemCount()
{
    return 10;
}

bool shop::isValidShopItem(int ingredient)
{
    return ingredient >= 1 && ingredient <= getItemCount();
}