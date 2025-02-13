// File: StackType.cpp

#include "StackType.h"
#include <iostream>
//using namespace std;

StackType::StackType() {
  top = -1;
}

bool StackType::IsEmpty() const {
  return (top == -1);
}

bool StackType::IsFull() const {
  return (top ==  MAX_ITEMS-1);
}

void StackType::Push(ItemType newItem) {
  if(top >= 9 ){
   throw FullStack();
  }
  else{
    top++;
   items[top] = newItem;
  }
 
}

void StackType::Pop() {
  if(top <= -1){
   throw EmptyStack();
  }
  else{
     top--;
  }
}

ItemType StackType::Top() {
   if(top <= -1){
   throw EmptyStack();
  }
  else{
  return items[top];
  }
}
