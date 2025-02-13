#include <iostream>
#include <string>
using std::string;
#include "unit.h"


int Unit::groupCnt = 0;

Unit::Unit(int numUnits, int hitPts, int attackPts, int initiative, string attackType, string weakness, string immunity)
	: numUnits(numUnits), hitPts(hitPts), attackPts(attackPts), initiative(initiative), attackType(attackType), weakness(weakness), immunity(immunity) {
	idNum = groupCnt;
	groupCnt++;
}
	

int Unit::effectivePower() const{
	return numUnits * attackPts;
}

	
void Unit::attacked(int damage) {
	int unitsLost = damage/ hitPts;
	numUnits -= unitsLost;
	if (numUnits <= 0) {
		numUnits = 0;
		throw "Error Attacking!";
		//you should throw something here...
	}
}

int Unit::getNumUnits(){
	return numUnits;
}

	// Overloading the insertion operator for Unit class
std::ostream& operator<<(std::ostream& out, Unit& obj) {

	out << "Type:" << obj.getTypeOf() << std::endl//you should add something here
	   <<  "Units:" << obj.numUnits << std::endl
	   << "HitPts:" << obj.hitPts << std::endl
	   << "Weakness:" << obj.weakness << std::endl
	   << "Immunity:" << obj.immunity << std::endl
	   << "AttackPts:" << obj.attackPts << std::endl
	   << "AttackType:" << obj.attackType << std::endl
	   << "Initiative:" << obj.initiative << std::endl
	   << "ID:" << obj.idNum << std::endl;
	return out;
}
//the missing methods go below

int Unit::getId(){
		return idNum;
	}
	int Unit::getInitiative(){
		return initiative;
	}
	int Unit::getDamage(Unit& obj){
		if(attackType == obj.immunity){
			return 0;
		}
		else if(attackType == obj.weakness){
			int reInt = (effectivePower() * 2);
			return reInt;
		}
		else{
			return effectivePower();
		}
	}
	Immune::Immune(int numUnits, int hitPts, int attackPts, int initiative, string attackType, string weakness, string immunity):Unit::Unit( numUnits,  hitPts,  attackPts,  initiative,  attackType,  weakness,  immunity){

}
string Immune::getTypeOf(){
	return "immune";	
}
Infection::Infection(int numUnits, int hitPts, int attackPts, int initiative, string attackType, string weakness, string immunity):Unit::Unit( numUnits,  hitPts,  attackPts,  initiative,  attackType,  weakness,  immunity){

}
string Infection::getTypeOf(){
		return "infection";	

}
	string Unit::getTypeOf(){
	
		return "infection";
	}
	bool Unit::operator>(const Unit &obj) const
	{
		int power = obj.effectivePower();
		if(effectivePower() == power){
				if(initiative > obj.initiative){
					return true;
				}
				return false;
		}
		else if (effectivePower() > power){
			return true;
		}
		else{
			return false;
		}
	}
	bool Unit::operator<(const Unit& obj) const
	{
		
				if(initiative < obj.initiative){
					return true;
				}
				return false;
		
	}

