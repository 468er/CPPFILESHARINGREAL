
#include "Ingredient.h"

Ingredient::Ingredient(int capacity, int durability, int flavor, int texture, int calories){
    this->capacity = capacity;
        this->durability = durability;
    this->flavor = flavor;
    this->texture = texture;
    this->calories = calories;

}
const int Ingredient::totalScore(int teaspoons){
        return teaspoons * (capacity + durability + flavor+ texture);
    }
const int Ingredient::totalCalories(int teaspoons){
        return teaspoons * calories;
    }