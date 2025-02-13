#include <iostream>
#include <vector>
#include <fstream>
#include <map>

int Test(std::vector<char> &chars, int amount){
        std::map<char, int> memorize;
     for (int a = 0; a < chars.size(); a++) {
      // std::cout <<  dictionary[chars[a]] << std::endl;
      char testCase = chars[a];
       if(memorize[testCase] == 0){
            memorize[testCase] = 1;
            if(memorize.size() == amount){
                 std::cout << (a + 1) << std::endl;
                 return 0;
            }
        }
        else{
            a - memorize.size();
            memorize.clear();
        }
    }
   // std::cout << "CharsSize: "<< chars.size() << std::endl;
    //std::cout << "DictionarySize: "<< dictionary.size() << std::endl;
    return 2;

}
int main(){
    std::vector<int> savedOnes;

    std::ifstream file("2.txt"); 
    if (!file) { 
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::vector<char> chars;
    char input;

    while (file >> input) { 
        chars.push_back(input);
    }

    file.close(); // Close the file
    Test(chars, 4);
    Test(chars, 14);

    // Print the numbers
       return 0;
}
