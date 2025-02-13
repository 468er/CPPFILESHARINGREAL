#include <iostream>
class Ingredient{
    private:
    int capacity;
    int durability;
    int flavor;
    int texture;
    int calories;
    public:
    Ingredient(int capacity, int durability, int flavor, int texture, int calories);
    const int totalScore(int teaspoons);
    const int totalCalories(int teaspoons);
};

