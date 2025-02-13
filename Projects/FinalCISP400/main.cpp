#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;
#include "unit.h"

bool compItGet(const Unit* lhs, const Unit* rhs){
    return (*lhs>*rhs);
}

bool compItAttk(const Unit* lhs, const Unit* rhs){
	return (*rhs<*lhs);
}

bool attack(Unit* attacker, Unit* victim){
	int damage=attacker->getDamage(*victim);
	try{
		victim->attacked(damage);
		return true;
	} catch(...){
		cout<<victim->getId()<<" wiped out"<<endl;
		return false;
	}
}

map<Unit*,Unit*> get_targets(vector<Unit*> units){
	map<Unit*,Unit*> targets;
	map<Unit*,Unit*> reverse_targets;
	std::sort(units.begin(),units.end(),compItGet);
	for (Unit* attacker: units){
		int maxDamage=0;
		Unit* maxVictim=NULL;
		for (Unit* victim: units){
			map<Unit*,Unit*>::iterator it=targets.find(victim);
			if (attacker->getTypeOf()==victim->getTypeOf() || it!=targets.end()){
				continue;
			} else {
				int damage=attacker->getDamage(*victim);
				if (damage>0 &&
					(damage>maxDamage ||
				     (damage==maxDamage && victim->effectivePower()>maxVictim->effectivePower()) ||
				     (damage==maxDamage && victim->effectivePower()==maxVictim->effectivePower() &&
				      victim->getInitiative()>maxVictim->getInitiative()))){
					maxDamage=damage;
					maxVictim=victim;
				}
			}
		}
		if (maxVictim !=NULL){
			targets[maxVictim]=attacker;
			reverse_targets[attacker]=maxVictim;
		}
	}

	return reverse_targets;
}

vector<Unit*> attack_targets(vector<Unit*> units, map<Unit*,Unit*> targets){
	std::sort(units.begin(),units.end(),compItAttk);
	vector<Unit*> remove_units, remaining_units;
	for (Unit* unit: units){
		map<Unit*,Unit*>::iterator it=targets.find(unit);
		if (it!=targets.end()){
			if (!attack(unit,targets[unit])){
				remove_units.push_back(targets[unit]);
			}
		}
	}
	for (Unit* unit: units){
		vector<Unit*>::iterator it=std::find(remove_units.begin(), remove_units.end(),unit);
		if (it==remove_units.end()){
			remaining_units.push_back(unit);
		}
	}
	return remaining_units;
}

bool isDone(vector<Unit*> units){
	bool hasImmune=false;
	bool hasInfection=false;
	for (Unit* unit: units){
		if (unit->getTypeOf()=="immune"){
			hasImmune=true;
		} else {
			hasInfection=true;
		}
	}
	return (!(hasImmune && hasInfection));
}

int count_remaining(vector<Unit*> units){
	int count=0;
	for (Unit* unit: units){
		count+=unit->getNumUnits();
	}
	return count;
}

int main(){

//                                      unit hp   dmg ini  attack      weak to       immune
	vector<Unit*> units={   new Immune (2667,9631, 33, 3, "radiation", "radiation" , "cold" ),
							new Immune (6889,7044, 8, 11, "cold",      "none",       "cold" ),
							new Immune (8030,8956, 8, 5,  "fire",      "magic" ,     "none"),
							new Immune (9278,9654, 10, 9, "radiation", "slashing" ,  "radiation" ),
							new Immune (3472,9606, 26, 14, "cold",     "none",       "none"),
							new Immune (2971,4601, 14, 16, "fire",     "cold" ,      "none"),
							new Immune (2455,6330, 20, 20, "magic",    "none",       "slashing" ),
							new Immune (1896,9385, 48, 19, "slashing", "slashing" ,  "none"),
							new Immune (303,10428, 328, 13, "radiation","none",      "none"),
							new Immune (4380,7040, 16, 8, "slashing",  "slashing" ,  "none"),
							new Infection (3122,52631, 29, 2, "slashing","none",     "slashing" ),
							new Infection (4257,52159, 22, 17, "magic",  "none",     "none"),
							new Infection (721,25099, 60, 15, "slashing","radiation","none"),
							new Infection (1772,44946, 49, 7, "slashing","cold" ,    "none"),
							new Infection (886,22310, 36, 12, "cold",    "slashing" ,"none"),
							new Infection (2804,45281, 30, 10, "slashing","magic" ,  "fire" ),
							new Infection (8739,43560, 9, 1, "cold",      "magic" ,  "radiation" ),
							new Infection (1734,30384, 34, 4, "cold",     "cold" ,   "none"),
							new Infection (5525,14091, 4, 18, "magic",    "cold" ,   "none"),
							new Infection (1975,15393, 15, 6, "fire",     "none",    "none"),};
	for (int i=0; i<units.size(); i++){
		cout<<*units[i]<<endl;
	}
	do {
		map<Unit*,Unit*> targets=get_targets(units);
		units=attack_targets(units,targets);
	} while (!isDone(units));

	cout<<count_remaining(units)<<" (should be 27039)"<<endl;
    return 0;
}
