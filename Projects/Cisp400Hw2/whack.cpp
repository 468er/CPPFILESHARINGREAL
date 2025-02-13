#include "whack.h"

bool place(int x, int y, char moleGrid[gridDimension][gridDimension], int& molesLeft){
	if(x >= 0 && x >= 0){
	if(moleGrid[x][y] != 'M'){
		moleGrid[x][y] = 'M';
		molesLeft += 1;
		
		
		return true;	
		
	}

	}
	return false;
}
void whack(int x, int y, char moleGrid[gridDimension][gridDimension], int &score, int &molesLeft, int &attemptsLeft){
	if( x>= 0 && y >= 0){
		if(moleGrid[x][y] == 'M'){
		score += 1;
		attemptsLeft -= 1;
		molesLeft -= 1;
		moleGrid[x][y] = 'W';
		}
		else{
		attemptsLeft -=1;
		}
	}
	else{
	attemptsLeft -=1;
	}
}
void printGridToUser(char moleGrid[gridDimension][gridDimension]){
	for(int x = 0; x < gridDimension; x++){
		for(int y = 0; y < gridDimension; y++){
			if(moleGrid[x][y] == 'W'){
				std::cout << 'W' << std::flush;
			}
			else{
			std::cout << "*" << std::flush;
			}
		}
//	std::cout << "\n" << std::flush;
	}
}

void printGrid(char moleGrid[gridDimension][gridDimension]){
	for(int x = 0; x < gridDimension; x++){
		for(int y = 0; y < gridDimension; y++){
			std::cout << moleGrid[gridDimension][gridDimension] << std::flush;
		}
//		std::cout << "\n" << std::flush;
	}
}
