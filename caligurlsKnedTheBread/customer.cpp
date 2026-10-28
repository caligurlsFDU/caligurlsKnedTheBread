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
	cout << "\n\n\nThe customer's order is:\n\"" << orderPrompt << "\"\n\n\n";
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

vector<Customer> Customer::createCustomers()
{
	vector<Customer> customers;


	customers.emplace_back(
		"I'm feeling like having some pig with Uncle Sam's cheese on that pale stuff. ", 
		vector<string>{"White Bread", "Ham", "American Cheese"}
	);
	customers.emplace_back("Gobble-gobble bird and the cheese full of holes, on the brown grainy slices, please. ",
		vector<string>{"Wheat Bread", "Turkey", "Swiss Cheese"});
	customers.emplace_back("Give me the cow, cooked low and slow, under the holey cheese from the Alps, on ghost-colored slices. ",
		vector<string>{"White Bread", "Roast Beef", "Swiss Cheese"});
	customers.emplace_back("Oink-oink meat, the cheese with holes, and that creamy eggy spread, all on the healthy-looking brown slices. ",
		vector<string>{"Wheat Bread", "Ham", "Swiss Cheese", "Mayo"});
	customers.emplace_back("Thanksgiving bird with rabbit food and the red fruit everyone calls a vegetable, on the plain pasty slices. ",
		vector<string>{"White Bread", "Turkey", "Lettuce", "Tomato"});
	customers.emplace_back("Moo meat, the orange square that melts, and something leafy and green on the grainy brown slices. ",
		vector<string>{"Wheat Bread", "Roast Beef", "American Cheese", "Lettuce"});
	customers.emplace_back("Pig AND Thanksgiving bird, both, on that pale stuff. No cheese, no veggies, no spread. ",
		vector<string>{"White Bread", "Ham", "Turkey"});
	customers.emplace_back("Pink pork, crunchy leaves, red juicy slices, and the creamy eggy spread on the brown grainy kind. ",
		vector<string>{"Wheat Bread", "Ham", "Lettuce", "Tomato", "Mayo"});
	customers.emplace_back("Just Uncle Sam's melty orange square on the pale slices. Nothing else, I'm keeping it simple. ",
		vector<string>{"White Bread", "American Cheese"});
	customers.emplace_back("No meat, no cheese. I just want leaves and the red seedy slices on the brown grainy kind. ",
		vector<string>{"Wheat Bread", "Lettuce", "Tomato"});
	customers.emplace_back("The cow, cooked low and slow, with that creamy eggy spread on ghost-colored slices. ",
		vector<string>{"White Bread", "Roast Beef", "Mayo"});
	customers.emplace_back("Gobbler meat, the stars-and-stripes slice, and creamy eggy spread on the healthy brown slices.  ",
		vector<string>{"Wheat Bread", "Turkey", "American Cheese", "Mayo"});
	customers.emplace_back("Oink-oink, the Alpine cheese with holes, and red seedy slices, all on the pale stuff. ",
		vector<string>{"White Bread", "Ham", "Swiss Cheese", "Tomato"});
	customers.emplace_back("Moo-cow meat, the holey cheese, and the red seedy slices on the brown grainy kind. ",
		vector<string>{"Wheat Bread", "Roast Beef", "Swiss Cheese", "Tomato"});
	customers.emplace_back("The Thanksgiving bird, holey cheese, rabbit food, and the creamy eggy spread on the plain pasty slices.",
		vector<string>{"White Bread", "Turkey", "Swiss Cheese", "Lettuce", "Mayo"});
	customers.emplace_back("I'm feeling like having some pig with Uncle Sam's cheese on that pale stuff. ",
		vector<string>{"White Bread", "Ham", "American Cheese"});
	customers.emplace_back("Pig, bird, AND cow all stacked together on brown grainy slices. Skip the cheese, veggies, and spread.",
		vector<string>{"Wheat Bread", "Ham", "Turkey", "Roast Beef"});
	customers.emplace_back("Two cheeses: the orange square from Uncle Sam and the holey one from the Alps. Pale slices, nothing else.",
		vector<string>{"White Bread", "American Cheese", "Swiss Cheese"});
	customers.emplace_back("Some pig with the red-white-and-blue cheese on the healthy-looking brown slices.",
		vector<string>{"Wheat Bread", "Ham", "American Cheese"});
	customers.emplace_back("Gobble-gobble meat and the creamy eggy spread on ghost-colored slices. That's all.",
		vector<string>{"White Bread", "Turkey", "Mayo"});
	customers.emplace_back("Moo meat, rabbit food, and the creamy eggy spread on the brown grainy kind.",
		vector<string>{"Wheat Bread", "Roast Beef", "Lettuce", "Mayo"});
	customers.emplace_back("Pink pork, crunchy green leaves, and the creamy eggy spread on that pale stuff.",
		vector<string>{"White Bread", "Ham", "Lettuce", "Mayo"});
	customers.emplace_back("Thanksgiving bird and the red slices that are secretly a fruit, on the grainy brown kind.",
		vector<string>{"Wheat Bread", "Turkey", "Tomato"});
	customers.emplace_back("Cow cooked low and slow, Uncle Sam's melty orange square, and red seedy slices on the pale stuff.",
		vector<string>{"White Bread", "Roast Beef", "American Cheese", "Tomato"});
	customers.emplace_back("Pig and gobbler together, the holey cheese, leaves, red seedy slices, and the creamy eggy spread on pale slices. Hold the cow and the orange cheese. ",
		vector<string>{"White Bread", "Ham", "Turkey", "Swiss Cheese", "Lettuce", "Tomato", "Mayo"});




	//orderBook[0].setOrder("I'm feeling like having some pig with Uncle Sam's cheese on that pale stuff. ", { "White Bread", "Ham", "American Cheese" });
	//orderBook[1].setOrder("Gobble-gobble bird and the cheese full of holes, on the brown grainy slices, please. ", { "Wheat Bread", "Turkey", "Swiss Cheese" });
	//orderBook[2].setOrder("Give me the cow, cooked low and slow, under the holey cheese from the Alps, on ghost-colored slices. ", { "White Bread", "Roast Beef", "Swiss Cheese" });
	//orderBook[3].setOrder("Oink-oink meat, the cheese with holes, and that creamy eggy spread, all on the healthy-looking brown slices. ", { "Wheat Bread", "Ham", "Swiss Cheese", "Mayo" });
	//orderBook[4].setOrder("Thanksgiving bird with rabbit food and the red fruit everyone calls a vegetable, on the plain pasty slices. ", { "White Bread", "Turkey", "Lettuce", "Tomato" });
	//orderBook[5].setOrder("Moo meat, the orange square that melts, and something leafy and green on the grainy brown slices. ", { "Wheat Bread", "Roast Beef", "American Cheese", "Lettuce" });
	//orderBook[6].setOrder("Pig AND Thanksgiving bird, both, on that pale stuff. No cheese, no veggies, no spread. ", { "White Bread", "Ham", "Turkey" });
	//orderBook[7].setOrder("Pink pork, crunchy leaves, red juicy slices, and the creamy eggy spread on the brown grainy kind. ", { "Wheat Bread", "Ham", "Lettuce", "Tomato", "Mayo" });
	//orderBook[8].setOrder("Just Uncle Sam's melty orange square on the pale slices. Nothing else, I'm keeping it simple. ", { "White Bread", "American Cheese" });
	//orderBook[9].setOrder("No meat, no cheese. I just want leaves and the red seedy slices on the brown grainy kind. ", { "Wheat Bread", "Lettuce", "Tomato" });
	//orderBook[10].setOrder("The cow, cooked low and slow, with that creamy eggy spread on ghost-colored slices. ", { "White Bread", "Roast Beef", "Mayo" });
	//orderBook[11].setOrder("Gobbler meat, the stars-and-stripes slice, and creamy eggy spread on the healthy brown slices.  ", { "Wheat Bread", "Turkey", "American Cheese", "Mayo" });
	//orderBook[12].setOrder("Oink-oink, the Alpine cheese with holes, and red seedy slices, all on the pale stuff. ", { "White Bread", "Ham", "Swiss Cheese", "Tomato" });
	//orderBook[13].setOrder("Moo-cow meat, the holey cheese, and the red seedy slices on the brown grainy kind. ", { "Wheat Bread", "Roast Beef", "Swiss Cheese", "Tomato" });
	//orderBook[14].setOrder("The Thanksgiving bird, holey cheese, rabbit food, and the creamy eggy spread on the plain pasty slices.", { "White Bread", "Turkey", "Swiss Cheese", "Lettuce", "Mayo" });
	//orderBook[15].setOrder("I'm feeling like having some pig with Uncle Sam's cheese on that pale stuff. ", { "White Bread", "Ham", "American Cheese" });
	//orderBook[16].setOrder("Pig, bird, AND cow all stacked together on brown grainy slices. Skip the cheese, veggies, and spread.", { "Wheat Bread", "Ham", "Turkey", "Roast Beef" });
	//orderBook[17].setOrder("Two cheeses: the orange square from Uncle Sam and the holey one from the Alps. Pale slices, nothing else.", { "White Bread", "American Cheese", "Swiss Cheese" });
	//orderBook[18].setOrder("Some pig with the red-white-and-blue cheese on the healthy-looking brown slices.", { "Wheat Bread", "Ham", "American Cheese" });
	//orderBook[19].setOrder("Gobble-gobble meat and the creamy eggy spread on ghost-colored slices. That's all.", { "White Bread", "Turkey", "Mayo" });
	//orderBook[20].setOrder("Moo meat, rabbit food, and the creamy eggy spread on the brown grainy kind.", { "Wheat Bread", "Roast Beef", "Lettuce", "Mayo" });
	//orderBook[21].setOrder("Pink pork, crunchy green leaves, and the creamy eggy spread on that pale stuff.", { "White Bread", "Ham", "Lettuce", "Mayo" });
	//orderBook[22].setOrder("Thanksgiving bird and the red slices that are secretly a fruit, on the grainy brown kind.", { "Wheat Bread", "Turkey", "Tomato" });
	//orderBook[23].setOrder("Cow cooked low and slow, Uncle Sam's melty orange square, and red seedy slices on the pale stuff.", { "White Bread", "Roast Beef", "American Cheese", "Tomato" });
	//orderBook[24].setOrder("Pig and gobbler together, the holey cheese, leaves, red seedy slices, and the creamy eggy spread on pale slices. Hold the cow and the orange cheese. ", { "White Bread", "Ham", "Turkey", "Swiss Cheese", "Lettuce", "Tomato", "Mayo" });

	return customers;
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
