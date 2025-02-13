// Starter Code
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

template <class T>
class subRange {
    public:
     T lower, upper;
	subRange( T low, T high ) {
	lower = low;
	upper = high;
    }
	T enterValue() {
	T v;
	cout << "Enter value [ " << lower << ", " << upper << " ]: ";
	cin >> v;
    if(v > upper){
        throw std::out_of_range("To Large!");
    }
    else if(v < lower){
        
        throw std::out_of_range("To Small!");
    }
	return v;
    }
};

template <class T>
 void testingRange(T &l, T &u){
    subRange<T> x(l,u);
    bool Success = false;
    while(!Success){
      try{
	    cout << x.enterValue( ) << endl;
        Success = true;
     }
        catch(std::out_of_range Error) {
        Error.what();
        cout << "Try again, Eric Harder!" << endl;
        }
    }
}

template <class T>
 void testingRange(T l, T u){
    subRange<T> x(l,u);
    bool Success = false;
    while(!Success){
      try{
	    cout << x.enterValue( ) << endl;
        Success = true;
     }
        catch(std::out_of_range Error) {
        Error.what();
        cout << "Try again, Eric Harder!" << endl;
        }
    }
}
int main() {
	testingRange(1, 10);
    testingRange(3.14, 7.1238);

   
}
