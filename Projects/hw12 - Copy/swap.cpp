#include <iostream>
#include <vector>
#include <map>
using std::map;

using std::cout;
using std::cin;
using std::vector;
using std::endl;


int main(){
    long long N;
    int results = 0;
    vector<map<long long, long long>> rAsVectorMap;
    cin >> N;
    std::vector<long long> nums(N);
    for(long long &i: nums){
        cin >> i;
    }
    for(int a = 0; a < N; a++){
        for(int b = a +1; b < N; b++){
            for(int c = b +1; c < N; c++){
                bool identicalFound = false;
                std::vector<long long> NumsToCheck(3);
                NumsToCheck[0] = nums[a];
                NumsToCheck[1] = nums[b];
                NumsToCheck[2] = nums[c];
                if(NumsToCheck[1] == NumsToCheck[2] && NumsToCheck[0] != NumsToCheck[1]){
                    map<long long, long long> tempMap;
                    tempMap[NumsToCheck[0]] = NumsToCheck[1];
                    for(map<long long, long long> i: rAsVectorMap){
                        if(i.begin()->first == tempMap.begin()->first){
                            if(i.begin()->second == tempMap.begin()->second){
                                identicalFound = true;
                            }
                        }
                    }
                    if(identicalFound == false){
                    results++;
                    rAsVectorMap.push_back(tempMap);
                    }
                }
            }   
        } 
    }
    cout << results << endl;
   /* for(long long &i: nums){
        cout << i << endl;
    }
    cout << N << endl;
    for(map<long long, long long> i: rAsVectorMap){
        cout << i.begin()->first << " " << i.begin()->second << endl;
    } */

    return 0;
}
