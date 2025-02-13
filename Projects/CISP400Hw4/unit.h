#ifndef UNIT_H_
#define UNIT_H_
#include <iostream>
class Unit{
    friend std::ostream& operator<<(std::ostream os, const Unit u);
    public: 
         static int groupCnt;
        Unit(int numUnits, int hitPts, int attackPts, int initiative, std::string attackType, std::string weakness, std::string immunity);
        int effectivePower();
        void attacked(int damage);
        int getNumUnits();
    private:
        int numUnits;
        int hitPts;
        int attackPts;
        int initiative;
        int idNum;
        std::string attackType;
        std::string weakness;
        std::string immunity;
    
}
#endif