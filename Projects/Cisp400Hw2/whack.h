#include <iostream>

 const int gridDimension = 10;

bool place(int x, int y, char moleGrid[gridDimension][gridDimension], int &molesLeft);

void whack(int x, int y, char moleGrid[gridDimension][gridDimension], int& score, int& molesLeft, int& attemptsLeft);

void printGridToUser(char moleGrid[gridDimension][gridDimension]);

void printGrid(char moleGrid[gridDimension][gridDimension]);
