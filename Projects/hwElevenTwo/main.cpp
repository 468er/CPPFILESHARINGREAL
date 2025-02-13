#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;
#include "ships.h"
#include "ocean.h"

int main(){
    Ocean *oceanTwo = new Ocean();
    Ocean oceanp = &oceanTwo;
    cout << oceanp << endl;
    oceanTwo.placeAllShipsRandomly();
    bool deleted = false;
    while(oceanTwo.isGameOver() == false && deleted == false){
        cout << "Where do you want to shoot?" << endl;
        int i = 0;
        int j = 0;
       std::cin >> i ;
       std::cin >> j ;
       if(i == 100 && j == 100){
            deleted = true;
            delete *oceanTwo;
       }
       else{
     if(oceanTwo.shootAt(i, j)){
        cout << "Hit!" << endl;
       }
        else{
            cout << "Miss!" << endl;
        }
        oceanTwo.print();
       }
    
    }
    cout << "End of Game message!" << endl;
    //create an ocean
    //place all ships randomly
    //while not done
        //ask user for i and j
        //shoot at ship
        //report results of shot
        //print ocean
    //repeat
    //end of game message

    return 0;
}
