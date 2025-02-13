#include "unit.h"

        int Unit::groupCnt = 0;
     
       Unit::Unit(int numUnits, int hitPts, int attackPts, int initiative, std::string attackType, std::string weakness, std::string immunity){
        this->numUnits = numUnits;
        this->hitPts = hitPts;
        this->attackPts = attackPts;
        this->initiative = initiative;
        idNum = groupCnt;
        groupCnt++;
        this->attackType = attackType;
         this->weakness = weakness;
        this->immunity = immunity;
       }
        int Unit::effectivePower(){
            return numUnits * attackPts;
        }
        void Unit::attacked(int damage){
           groupCnt -= damage % hitPts;
        }
        int Unit::getNumUnits(){
            return numUnits;
        }
         std::ostream& operator<<(std::ostream os, const Unit u){
            std::cout << "Unis:" << u.numUnits << std::endl;
            std::cout << "HitPts:" << u.hitPts << std::endl;
            std::cout << "Weakness:" << u.weakness << std::endl;
            std::cout << "Immunities:" << u.immunity << std::endl;
            std::cout << "AttackPts:" << u.attackPts << std::endl;
            std::cout << "AttackType:" << u.attackType << std::endl;
            std::cout << "Initiative:" << u.initiative << std::endl;
            std::cout << "ID:" << u.idNum << std::endl;
            return os;
        }


