#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include "genericArray.cpp"
using std::string;
using std::vector;
using std::map;
using std::cout;
using std::endl;

// real autograder

int checkConstructors(){
    int grade=0;
    GenericArray<int> a(2);
    a.data[0] = 4;
    a.data[1] = 2;
    {
        GenericArray<int> b = a;
        if (b.data[0]==4){
            grade+=2;
        } else {
            cout<<"It looks like your copy constructor is not making a copy"<<endl;
        }
        b.data[0]=3;
    }
    if (a.data[0]==4){
        grade+=3;
    } else {
        cout<<"It looks like your copy constructor is not making a deep copy"<<endl;
    }
    GenericArray<string> c(2);
    c.data[0]="cow";
    c.data[1]="moo";
    {
        GenericArray<string> d = c;
    }
    if (c.data[1]=="moo"){
        grade+=5;
    } else {
        cout<<"It looks like your copy constructor is not making a deep copy"<<endl;
    }
    return grade;
}

 int checkOverload(){
    int grade=0;
    GenericArray<int> a(2);
    a.data[0] = 4;
    a.data[1] = 2;
    cout<<"a "<<a.data<<endl;
    GenericArray<int> b(3);
    b.data[0] = 5;
    b.data[1] = 3;
    b.data[2] = 1;
    cout<<"b "<<b.data<<endl;
    GenericArray<int> c(0);
    c=a;
    cout<<"c1 "<<c.data<<endl;
    c+=b;
    //c=a+b;
    cout<<"c2 "<<c.data<<endl;
    cout<<"testing 2"<<endl;
    if (c.size==5){
        grade+=5;
    } else {
        cout<<"Size isn't correct for added arrays, should be 5, was "<<c.size<<endl;
    }
    bool isEqual=true;
    int cShouldBe[]={4,2,5,3,1};
    for (int i=0; i<5; i++){
        cout << c.data[i] << cShouldBe[i] << endl;
        if (c.data[i]==cShouldBe[i]){
            grade++;
        } else {
            isEqual=false;
        }
    }
    if (!isEqual){
        cout<<"Not all elements in added array are correct."<<endl;
    }
    return grade;
} 

int main(){
    int grade=0;
    grade+=checkConstructors();
    cout<<"Finished checking contructors +"<<grade<<endl;
    grade+=checkOverload();
    cout<<"Finished checking overloaded += operator."<<endl;
    std::cout<<"Your likely grade is ";
    cout<<grade;//<<endl;
    cout<<" out of 20"<<endl;
    return 0;
}
