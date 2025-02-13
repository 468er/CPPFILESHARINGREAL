#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
using std::vector;

class Tools{
public:
     int testingahh123(vector<int> &nums){
    for(int i = 0; i < nums.size(); i++){
        for(int j = i; j < nums.size(); j++){
            if(nums[i] + nums[j] == 2025){
                return nums[i] * nums[j];
            }
        }
    }
    return -1;
}
int secondpart(vector<int> &nums){
    for(int i = 0; i < nums.size(); i++){
        for(int j = i +1 ; j < nums.size(); j++){
            for(int k = j +1; k < nums.size(); k++){
                 if(nums[i] + nums[j] +nums[k] == 2025){
                return nums[i] * nums[j]* nums[k];
              }
            }
           
        }
    }
    return -1;
}
};

int main() {
    std::ifstream file("1_file.txt"); // Open the file for reading

   /* if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }*/
    vector<int> nums = {1,2,3,4,5};
    vector<int> nums2 = {1,2,3,4,5};

    nums.insert(nums.begin() + 4, 8);
    nums.erase(nums.begin() + 5);
    nums.erase(nums.begin() + 2);
    for(int i = 0; i < nums2.size(); i++){
        nums.push_back(nums2[i]);
    }
    while(!file.eof()){
                int input;
            file >> input;
        nums.push_back(input);

    }
    file.close(); // Close the file
    nums.erase(nums.begin() + nums.size()-1);

    for(int i = 0; i < nums.size(); i++){
        std::cout << nums[i] << std::endl;
    }
    /*for(int i = 0; i < nums.size(); i++){
        std::cout << nums[i] << std::endl;
    }*/
    return 0;
}