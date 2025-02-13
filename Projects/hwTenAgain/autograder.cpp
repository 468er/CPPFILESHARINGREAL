#include <iostream>
#include <map>
#include <vector>
#include <sstream>
using std::string;
using std::vector;
using std::map;
using std::cout;
using std::endl;
#include "ships.h"

int checkConstructors(){
    int grade=0;
    Battleship bShip;
    Cruiser cruiser;
    Destroyer destroyer;
    Submarine submarine;
    EmptySea empty;
    Ship* ships[]={&empty,&submarine,&destroyer,&cruiser,&bShip};
    for (int i=0; i<5; i++){
        if ((i>0 && ships[i]->getLength()==i) || (i==0 && ships[i]->getLength()==1)){
            grade++;
        } else {
            cout<<"Length is not correct for "<<ships[i]->getShipType()<<endl;
        }
    }
    return grade;
}

int testOverride(){
    int grade=0;
    Battleship bShip;
    Cruiser cruiser;
    Destroyer destroyer;
    Submarine submarine;
    EmptySea empty;
    Ship* ships[]={&empty,&submarine,&destroyer,&cruiser,&bShip};
    string shipNames[]={"empty","submarine","destroyer","cruiser","battleship"};
    for (int i=0; i<5; i++){
        if (ships[i]->getShipType()==shipNames[i]){
            grade++;
        } else {
            cout<<"Ship type is not correct for "<<shipNames[i]<<endl;
        }
        if ((i>0 && ships[i]->toString()=="S") || (i==0 && ships[i]->toString()==".")){
            grade++;
        } else {
            cout << ships[i]->toString() << endl;
            cout<<"toString is not correct for "<<shipNames[i]<<endl;
        }
    }
    return grade;
}

int testAllShips(){
    int grade=25;
    Battleship bShip;
    Cruiser cruiser;
    Destroyer destroyer;
    Submarine submarine;
    EmptySea empty;
    Ship* ships[]={&empty,&submarine,&destroyer,&cruiser,&bShip};
    bool sunks[]={false,true,false,false,false};
    int row=4;
    int col=5;
    bool horiz=true;
    for (int i=0; i<5; i++){
        int oldGrade=grade;
        cout<<"Testing mutators and accessors on "<<ships[i]->getShipType();
        ships[i]->setBowRow(row);
        if (ships[i]->getBowRow()!=row){
            cout<<", get or set BowRow is not working"<<endl;
            grade-=1;
        }
        ships[i]->setBowColumn(col);
        if (ships[i]->getBowColumn()!=col){
            cout<<", get or set BowColumn is not working";
            grade-=1;
        }
        ships[i]->setHorizontal(horiz);
        if (ships[i]->isHorizontal()!=horiz){
            cout<<", get or set Horizontal is not working";
            grade-=1;
        }
        if ((i>0 && !ships[i]->shootAt(row,col)) || (i==0 && ships[i]->shootAt(row,col))) {
            cout<<", shootAt not working";
            grade-=1;
        }
        if (ships[i]->isSunk()!=sunks[i]){
            cout<<", isSunk not working";
            grade-=1;
        }

        if ((i>0 && !ships[i]->wasHit(row,col)) || (i==0 && ships[i]->wasHit(row,col))){
            cout<<", wasHit not working";
            grade-=1;
        }
        if (oldGrade==grade){
            cout<<"..... success!"<<endl;
        } else {
            cout<<endl;
        }
    }

    return grade/5;
}

int main(){
    int grade=0;
    grade+=checkConstructors();
    cout<<"Finished checking constructors +"<<grade<<endl;
    int overrideGrade=testOverride();
    cout<<"Finished checking override +"<<overrideGrade<<endl;
    grade+=overrideGrade;
    int allShipsGrade=testAllShips();
    cout<<"Finished all ships +"<<allShipsGrade<<endl;
    grade+=allShipsGrade;
    std::cout<<"Your likely grade is ";
    cout<<grade;//<<endl;
    cout<<" out of 20"<<endl;
    return 0;
}
