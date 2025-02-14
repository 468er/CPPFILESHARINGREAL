#include <iostream>
#include <vector>
template <typename T>
class Stack {
    
    private:
    std::vector<T> data;
    int top;
    public:  
    Stack(std::vector<T> value){
        data = value;
        top = -1; 
    }
    Stack(){
        top = -1; 
    }
    void push(T value){
        data.push_back(value);
        top += 1;
    }
    T pop(){
        if(is_empty()){
            return NULL;
        }
        else{
            T value = data[top];
            data.pop_back();
            top -= 1;
            return value;
        }
        
    }
    T max(){
        if(is_empty() == false){
            T max = data[0];
            for(T &i: data){
                if(max == NULL){
                    max = i;
                }
                else if(i > max ){
                    max = i;
                }
            }            return max;
        }
        return NULL;
    }
     T peek(){
        if(is_empty()){
            return NULL;
        }
        else{
            T value = data[top];
            return value;
        }
        
     }
     int size(){
        return top;
     }
     bool is_empty(){
        if(data.size() > 0){
            return false;
        }
        else{
            return true;
        }
     }
};
