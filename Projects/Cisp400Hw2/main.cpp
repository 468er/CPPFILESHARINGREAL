#include "whack.h"
int main(){
	int score = 0;
	int molesLeft = 0;
	int attemptsLeft = 50;
	char[][] moleGrid;
	bool gaveUp = false;
	
	moleGrid = moleGrid[gridDimension][gridDimension];
	//randomly place moles
	for(int x = 0; x < gridDimension; x++){
		for(int y = 0; y < gridDimension; y++){
			moleGrid[x][y] = '*';
		}
	}
	for(int a = 0; a < 10){
	if(place(rand() % 9, rand() % 9, moleGrid, molesLeft)){
		a++;
	}
	}
	while(molesLeft > 0 && attemptsLeft > 0){

	int xCoor;
	int yCoor;
	std::cout << "You have a maximum of 50 attempts to get all the moles! You start now!" << std::endl;
	std::cout << "Pick the x coordinate!" << std::endl;
	std::cin >> xCoor;
	std::cout << "Pick the y coordinate!" << std::endl;
	std::cin >> yCoor;
	
	if(xCoor == -1 && yCoor = -1){
		gaveUp = true;
		printGrid(moleGrid);
	}
	else{
			whack(xCoor, yCoor, moleGrid, score, molesLeft, attemptsLeft);	
		}	
	}
	if(gaveUp == false){
	if(molesLeft > 0 ){
	 	std::cout << "You lose because you ran out of attempts!" << std::endl;
	}
	else{
		
			std::cout << "You won because you whacked all the moles in " << 50 - attemptsLeft << " tries!" << std::endl;
		
		
	}
	}
}

