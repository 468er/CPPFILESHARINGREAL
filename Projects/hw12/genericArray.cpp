#include <iostream>
using std::cout;
using std::endl;

template <class T>
class GenericArray {
public:
    T *data;
    int size;
    GenericArray(int size) {
        data = new T[size];
        this->size = size;
    }
    GenericArray(GenericArray &o) { //copy constructor
        data = new T[o.size];
        size = o.size;
        for (int i = 0; i < size; ++i){
            data[i] = o.data[i];
        }
    }
     GenericArray operator= (GenericArray &o){
        data = new T[o.size];
        size = o.size;
        for (int i = 0; i < size; ++i){
            data[i] = o.data[i];
        }
        return *this;
     }
      GenericArray operator+= (GenericArray &g){
        T *dataTest = new T[size + g.size];
        for(int a = 0; a < size; a++){
            dataTest[a] = data[a];
        }
        cout << "g.size: " << g.size << endl;
        for(int a= 0; a < g.size; a++){
            cout << "g.data[a]: " << g.data[a] << endl;
            dataTest[a + size] = g.data[a];
        }
        this->size += g.size;
        data = dataTest;
        return *this;

     }
    ~GenericArray(){
        delete[] data;
    }
};
