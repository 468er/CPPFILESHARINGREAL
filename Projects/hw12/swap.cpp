#include <iostream>
#include "genericArray.cpp"
using std::cout;
using std::endl;

//insert template swap here
template<class T>
void swap(T &a, T &b){
    //cout << "&a: " << &a << "a: " << a << endl;
    T temp = a;
    a = b;
    b = temp;
}
//end template swap


int main(){
    int a=5;
    cout << "&a: " << &a << "a: " << a << endl;

    int b=6;
 //   cout<<"a = "<<a<<" and b = "<<b<<endl;
    swap(a,b);
    cout<<"a = "<<a<<" and b = "<<b<<endl;

   GenericArray<int> GA1(3);
    GA1.data[0] = 1;
    GA1.data[1] = 2;
    GA1.data[2] = 3; 

    cout << "size of: " << sizeof(GA1.data) << " " << sizeof(GA1.data[0]) << endl;
    GenericArray<int> GA2(2);
    GA2.data[0] = 4;
    GA2.data[1] = 5;

    for(int i = 0; i < GA1.size; i++){
        cout << "a = "<< GA1.data[i] << endl;
    } 
    
    for(int i = 0; i < GA2.size; i++){
        cout << " and b = "<< GA2.data[i] << endl;
    } 
    swap(GA1,GA2);

     for(int i = 0; i < GA1.size; i++){
        cout << "a = "<< GA1.data[i] << endl;
    } 
    
    for(int i = 0; i < GA2.size; i++){
        cout << " and b = "<< GA2.data[i] << endl;
    } 
    
}
