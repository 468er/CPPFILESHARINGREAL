#include <iostream>
#include <vector>
#include <map>
using std::map;

using std::cout;
using std::cin;
using std::vector;
using std::endl;

int main(){
    bool impossible = false;
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
         int nab[3];
    int minimumS = 0;
    for(int i = 0; i < 3; i++){
        cin >> nab[i]; 
    }
    int N = nab[0];
    //vector<bool> row(N);
    //vector<vector<bool>> LookBack(N);
        vector<vector<char>> Chars(N, vector<char>(N));
     for(int a = 0; a < N; a++){
        for(int b = 0; b < N; b++){

            cin >> Chars[a][b] ;
           
        }
    }
    
    for(int a = 0; a < N; a++){
        for(int b = 0; b < N; b++){
            char test = Chars[a][b];
            if(test == 'G' && (a+ nab[1] < N && b + nab[2] < N) && (Chars[a + nab[1]][b + nab[2]] == 'B' || Chars[a + nab[1]][b + nab[2]] == 'G')){
                 minimumS++;
            }
            else if(test == 'G' && (a- nab[1] > 0 && b - nab[2] > 0 ) && (Chars[a - nab[1]][b - nab[2]] == 'B' || Chars[a - nab[1]][b - nab[2]] == 'G')){  
                
                              minimumS++;
                            
                
             }
            else if(test == 'B'){
               if(a+ nab[1] < N && b + nab[2] < N){
                    if(Chars[a + nab[1]][b + nab[2]] == 'B' || Chars[a + nab[1]][b + nab[2]] == 'G'){
                        if((a- nab[1] > 0 && b - nab[2] > 0 ) && (Chars[a - nab[1]][b - nab[2]] == 'B' || Chars[a - nab[1]][b - nab[2]] == 'G')){
                                                    impossible = true;

                        }
                    }
                    if(!impossible){
                                                                            minimumS++;

                    }
            }
            
            }
        }
    }
   
    if(impossible == false){
            cout << minimumS  << endl;

    }
    else{
        cout << -1 << endl;
    }
     for(int i = 0; i < 3; i++){
        cout << nab[i] << endl; 
    }
    //vector<bool> row(N);
    //vector<vector<bool>> LookBack(N);
     for(int a = 0; a < N; a++){
        for(int b = 0; b < N; b++){

            cout<<  Chars[a][b] ;
           
        }
        cout << endl;
    }
    }
   
    /*for(int &i: a){
        cout << "a" << i << endl;
    }
     for(int &i: b){
        cout <<"b" <<  i << endl;;
    }*/
    return 0;
}

