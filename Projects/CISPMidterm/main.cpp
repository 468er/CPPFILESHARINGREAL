#include "Ingredient.h"
#include <list>

#include <vector>
int main(){
    std::vector<int> scoreResults;
    
    std::vector<int> calorieResults;
    int highestScore = 0;
    int highest500Calorie = 0;
    Ingredient Sprinkles(4,-1,0,0,4);
        Ingredient PeanutButter(-1,3,0,0,6);
        int peanutButterCount = 100;
    for(int sprinkleCount = 0; sprinkleCount < 101; sprinkleCount++){
        scoreResults.push_back(Sprinkles.totalScore(sprinkleCount) + PeanutButter.totalScore(peanutButterCount));
        calorieResults.push_back(Sprinkles.totalCalories(sprinkleCount) + PeanutButter.totalCalories(peanutButterCount));
        peanutButterCount--;
    }
    for(int a = 0; a < scoreResults.size(); a++){
            
            if(scoreResults[a] > highestScore){
                highestScore = scoreResults[a];
            }
            if(calorieResults[a] == 500){
                if(scoreResults[a] > highest500Calorie){
                    highest500Calorie = scoreResults[a];
                }
            }
    }
    std::cout << "Highest score cookie is " << highestScore << std::endl;
    std::cout << "Highest score 500 calorie cookie is " << highest500Calorie << std::endl;
}