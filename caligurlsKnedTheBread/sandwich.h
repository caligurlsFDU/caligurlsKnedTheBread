#pragma once
#include <string>
#include <vector>

class Sandwich
{
public:
    Sandwich();

    void addIngredient(const std::string& ingredient);
	void removeIngredient(const std::string& ingredient);

    const std::vector<std::string>& getIngredients() const;

	bool matchesOrder(const std::vector<std::string>& correctIngredients) const;
	bool matchesOrder(const std::string& correctSandwich) const;
    
private:
    std::vector<std::string> ingredients;
};

