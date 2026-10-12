#pragma once
#include <string>
#include <vector>

class sandwich
{
public:
    sandwich();
    void add_ingredient(const std::string& ingredient);
    const std::vector<std::string>& get_ingredients() const;
private:
    std::vector<std::string> ingredients;
};

