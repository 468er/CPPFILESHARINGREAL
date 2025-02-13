#include "deck.h"
#include <vector>
        const std::string Card::cardNameList[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
        
        const std::string Card::suitNameList[] = {"Spade", "Diamond", "Heart", "Club"};
        Card::Card(int cardNum, int suitNum){
            this->cardNum = cardNum;
            this->suitNum = suitNum;
        }
        std::string Card::toString(){
            std::string outString = "The " + getCardName() + " of " + getSuit() + "s";
            return outString;
        }
        std::string Card::getCardName(){
            
            return cardNameList[cardNum];
        }
        std::string Card::getSuit(){
            return suitNameList[suitNum];

        }
        int Card::getValue(){
            int returnInt = 0;
            if(cardNum == 0){
                returnInt = 4;
            }
            else if(cardNum < 10 && cardNum > 0){
                returnInt = 0;
            }
            else if(cardNum >= 10){
                returnInt = cardNum - 9;
            }
            return returnInt;
        }
        Hand::Hand(){}
        Hand::Hand(std::vector<Card> CardList){
            this->CardList = CardList;
        }
        int Hand::getValue(){
            int returnVal = 0;
            for(Card card : CardList){
                    returnVal += card.getValue();
            }
            return returnVal;
        }
        std::string Hand::toString(){
            std::string outStr = "";
            for(Card card : CardList){
                outStr += card.toString() + ", ";
            }
            outStr = outStr.substr(0, outStr.length() - 2);
            outStr += ".";
            return outStr;
        }

        Deck::Deck(){
            std::vector<Card> theDeck;
            for(int nums = 0; nums < 13; nums++){
                for(int suits = 0; suits < 4; suits++){
                   theDeck.push_back( Card(nums, suits));
                }
            }
            Cards = theDeck;
        }
        Hand Deck::deal(int handSize){
            std::vector<Card> hand;
            for(int i = 0; i < handSize; i++){
                int chosenCard = rand() % getNumCardsLeft();
                hand.push_back(Cards[chosenCard]);
                Cards.erase(Cards.begin() + chosenCard);
            }
            return Hand(hand);
        }
        std::string Deck::toString(){
            std::string outStr = "";
            for(Card card : Cards){
                outStr += card.toString() + ", ";
            }
            outStr = outStr.substr(0, outStr.length() - 2);
            outStr += ".";
            return outStr;
        }
        int Deck::getNumCardsLeft(){
            return Cards.size();
        }
        void Deck::restoreDeck(){
            //had to use the spoiler to do this
            *this = Deck();
        }
        void Deck::shuffle(){
            for(int a = 0; a <getNumCardsLeft(); a++ ){
                int chosenCardNum =rand() % (getNumCardsLeft());
               Card CurrentCard = Cards[a];
               Cards[a] = Cards[chosenCardNum];
               Cards[chosenCardNum] = CurrentCard;
            }
        }