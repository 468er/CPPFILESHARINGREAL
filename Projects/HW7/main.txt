#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
#include "deck.h"

int main() {
    srand(time(0));
    Deck deck;
    Hand hand;
    int handSize, playerScore, progScore;
    char choice;
    cout << "How many cards in a hand? ";
    cin >> handSize;
    do {
        hand = deck.deal(handSize);
        cout << "Here is Eric's hand:" << endl;
        cout << hand.toString() << endl;
        playerScore = hand.getValue();
        cout << "Eric's score is: "<<playerScore<<" points." << endl;
        // Now a hand for the dealer:
        hand = deck.deal(handSize);
        progScore = hand.getValue();
        cout << "Here is my hand:" << endl;
        cout << hand.toString() << endl;
        cout << "My score is: "<< progScore <<" points." << endl;
        string winner=(playerScore > progScore)?"Eric's":"I";
        cout <<  winner << " win!!" << endl;
        cout << "Play again (y/n)?";
        cin >> choice;
    } while (choice=='y' || choice=='Y');
}