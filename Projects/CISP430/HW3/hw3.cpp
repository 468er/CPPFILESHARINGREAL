#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>
int main(){

    std::ifstream file("3.txt"); 
    if (!file) { 
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }
    
    std::vector<std::string> chars(0);
    std::string input;

    while (std::getline(file, input)) { 
        chars.push_back(input);
    }
    
    file.close();

    std::map<char, char> codes;
    codes['('] = ')';
    codes['['] = ']';
    
    codes['{'] = '}';
    
    codes['<'] = '>';
    int Points = 0;
    std::map<char, char> reverseCodes;
    for(auto& pair : codes){
        reverseCodes[pair.second] = pair.first;
    }
    std::map<char, int> PointCodes;
    PointCodes[')'] = 3;
    PointCodes[']'] = 57;
    PointCodes['}'] = 1197;
    PointCodes['>'] = 25137;
    
    for(int a = 0; a < chars.size(); a++){
        std::vector<std::string> chars2(0);
        auto charsa = chars[a];
        std::cout << "a called" << a << " " << charsa << std::endl;
        for(int b = 0; b < charsa.size(); b++){
         std::cout << "b called" << b << std::endl;
          std::vector<char> chunk(0);
        chunk.push_back('(');
        if(codes[charsa[b]] != NULL){
            chunk.push_back(charsa[b]);
        }
        else if(reverseCodes[ charsa[b]] ==chunk[chunk.size() - 1] ){
            chunk.pop_back();
        }
        else if(reverseCodes[ charsa[b]] != NULL && reverseCodes[ charsa[b]] != chunk[chunk.size() - 1]){

            Points += PointCodes[charsa[b]];
            b = charsa.size();
        }
        
        }
        chars2.push_back(charsa);
    }
    std::cout << Points << std::endl;
}