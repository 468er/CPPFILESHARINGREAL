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
#include "ocean.h"
// real autograder

int checkDestructors(){
    std::stringstream ss;
    string line;

    // Backup streambuffers of  cout
    std::streambuf* stream_buffer_cout = cout.rdbuf();

    // Get the streambuffer of the sstream
    std::streambuf* stream_buffer_ss = ss.rdbuf();

    // Redirect cout to file
    cout.rdbuf(stream_buffer_ss);

    //create an ocean in a local scope
    {
        Ocean ocean;
        ocean.placeAllShipsRandomly();
    }
    //now ocean is out of scope and all of the destructors have been called

    // Redirect cout back to screen
    cout.rdbuf(stream_buffer_cout);
    int lineCnt=0;
    string boatStrings[]={"empty","battleship","destroyer","submarine","cruiser"};
    int boatTotals[]=    {    100,           1,          3,          4,        2};
    map<string,int> boatMap;
    while(getline(ss,line)){
        for(int i=0; i<5; i++){
            if (line.find(boatStrings[i]) != string::npos){
                boatMap[boatStrings[i]]++;
            }
        }
        //cout<<lineCnt<<endl;
        //cout<<line<<endl;
        lineCnt++;
    }
    int grade=0;
    cout<<"Destroyed:"<<endl;
    for (int i=0; i<5; i++){
        int tempGrade = (boatMap[boatStrings[i]]/boatTotals[i])*4;
        cout<<boatStrings[i]<<" "<<boatMap[boatStrings[i]]<<" out of "<<boatTotals[i]<<" +"<<tempGrade<<endl;
        grade+=tempGrade;
    }
    return grade;
}

int main(){
    int grade=0;
    grade+=checkDestructors();
    cout<<"Finished checking destructors +"<<grade<<endl;
    std::cout<<"Your likely grade is ";
    cout<<grade;//<<endl;
    cout<<" out of 20"<<endl;
    return 0;
}
