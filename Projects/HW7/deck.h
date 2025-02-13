#include <iostream>
#include <vector>
class Card {
    private:
        int cardNum;
        int suitNum;
         const static std::string cardNameList[13];
       const static std::string suitNameList[4];
    public:
        Card(int cardNum, int suitNum);
        std::string toString();
        std::string getCardName();
        std::string getSuit();
        int getValue();
};
class Hand {
    private:
        std::vector<Card> CardList;
    public:
        Hand();
        Hand(std::vector<Card> CardList);
        int getValue();
        std::string toString();
};
class Deck{
    private:
        std::vector<Card> Cards;
    public:
        Deck();
        Hand deal(int handSize);
        std::string toString();
        int getNumCardsLeft();
        void restoreDeck();
        void shuffle();
};