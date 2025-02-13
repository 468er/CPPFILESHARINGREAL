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
    std::map<char, char> reverseCodes;
    for(auto& pair : codes){
        reverseCodes[pair.second] = pair.first;
    }
    
    for(int a = 0; a < chars.size(); a++){
       /* for(int b = 0; b < chars[a].size(); b++){
         
        std::vector<char> chunk;
        if(codes[chars[a][b]] != NULL){
            chunk.push_back(chars[a][b]);
        }
        else if(reverseCodes[ chars[a][b]] ==chunk[chunk.size() - 1] ){
            chunk.pop_back();
        }
        else if(reverseCodes[ chars[a][b]] != NULL && reverseCodes[ chars[a][b]] != chunk[chunk.size() - 1]){
            
        }
        }*/
    }
}