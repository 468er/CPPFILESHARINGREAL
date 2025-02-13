//filename: Balanced.cpp
#include "StackType.h"
#include <iostream>
 using namespace std;

bool IsOpen(char symbol);
bool IsClosed(char symbol);
bool Matches(char symbol, char openSymbol);

int main() {
  char symbol=' ';
  int goodCnt=0;
  while (symbol != 'n') {
      StackType stack;
      bool balanced = true;
      char openSymbol;
      cout << "Enter an expression and press return. (enter n to quit)" << endl;
      cin.get(symbol);
      if (symbol=='n') {
          break;
      }
      while (symbol != '\n') {
        try{
            if (IsOpen(symbol)){
          stack.Push(symbol);
          }
        else if (IsClosed(symbol)) {
          if (stack.IsEmpty()){
            balanced = false;
            }
          else {
            openSymbol = stack.Top();
            stack.Pop();
            balanced = Matches(symbol, openSymbol);
          }
        }
        }
        catch(FullStack e){
          cout << "You had an error regarding the stack becoming full!" << endl;
        }
        catch(EmptyStack e){
          cout << "You had an error  trying to do something with an empty stack!" << endl;
        }
        catch(...){
          cout << "elipsies catch "<< endl;
        }
        cin.get(symbol);

      }
      while (!stack.IsEmpty() && balanced){
          if (IsOpen(stack.Top())){
              balanced=false;
          }
          try{
            stack.Pop();

          }
           catch(EmptyStack e){
          cout << "You had an error  trying to do something with an empty stack!" << endl;
          }
           catch(...){
          cout << "elipsies catch "<< endl;
        }
      }
      if (balanced){
        cout << "Expression is well formed." << endl;
        goodCnt++;
      } else
        cout << "Expression is not well formed."  << endl;
    }
  cout << "You entered "<< goodCnt << " well formed expressions."<<endl;
  return 0;
}

bool IsOpen(char symbol)
{
  if ((symbol == '(') || (symbol == '{') || (symbol == '[') || (symbol == '<'))
    return true;
  else
    return false;
}

bool IsClosed(char symbol)
{
  if ((symbol == ')') || (symbol == '}') || (symbol == ']') || (symbol == '>'))
    return true;
  else
    return false;
}

bool Matches(char symbol, char openSymbol)
{
  return  (((openSymbol == '(') && symbol == ')')
        || ((openSymbol == '{') && symbol == '}')
        || ((openSymbol == '[') && symbol == ']')
        || ((openSymbol == '<') && symbol == '>'));
}
