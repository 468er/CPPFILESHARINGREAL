#include <iostream>
using namespace std;
class Information {
public:
virtual void displayInfo() = 0;
virtual void addInfo() = 0;
};


//add class definitions below this line

class Chef: public Information{
private:
	string name;
	string cuisine;
	int michelinStars;
public:
   void displayInfo(){
    	cout<<endl;
    	cout<<name<<" is known for ";
    	cout<<cuisine<<" cuisine and has ";
    	cout<<michelinStars<<" Michelin Stars.";
   }
   void addInfo(){
    	cout << endl;
    	string sc2;
    	cout << ("Enter their name: ");
    	getline(cin>>ws, sc2);
    	name = sc2;
    	cout << ("Enter their cuisine: ");
    	getline(cin>>ws, sc2);
    	cuisine = sc2;
    	cout << ("Enter the number of Michelin Stars: ");
    	cin>>michelinStars;
   }
   void addInfo(string name, string cuisine = "null", int michelinStars = 0){

    	this->name = name;
    	this->cuisine = cuisine;
    	this->michelinStars = michelinStars;
   }
};

int main() {
   Chef c1;
c1.addInfo("Marco Pierre White");
Chef c2;
c2.addInfo("Rene Redzepi", "Nordic");
Chef c3;
c3.addInfo("Thomas Keller", "French", 3);
Chef c4;
c4.addInfo();

c1.displayInfo();
c2.displayInfo();
c3.displayInfo();
c4.displayInfo();


}