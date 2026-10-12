#pragma once
#include <string>
#include <vector>

class Sandwich
{
public:
    Sandwich();

    void add_ingredient(const std::string& ingredient);
	void remove_ingredient(const std::string& ingredient);

    const std::vector<std::string>& get_ingredients() const;

	bool matches_order(const std::vector<std::string>& correctIngredients) const;
    
private:
    std::vector<std::string> ingredients;
};

