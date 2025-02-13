#ifndef UNIT_H
#define UNIT_H

class Unit {
private:
	int numUnits;
	int hitPts;
	int attackPts;
	int initiative;
	int idNum;
	string attackType;
	string weakness;
	string immunity;
	
public:
	static int groupCnt;

	Unit(int numUnits, int hitPts, int attackPts, int initiative, string attackType, string weakness, string immunity);

	int getId();
	int getInitiative();
	int getDamage(Unit& obj);
 	int effectivePower() const;
	void attacked(int damage);
	int getNumUnits();
	virtual string getTypeOf();

	bool operator>(const Unit& obj) const;
	bool operator<(const Unit& obj) const;

	friend std::ostream& operator<<(std::ostream& out, Unit& obj);
};
class Immune : public Unit {
	public:
	Immune(int numUnits, int hitPts, int attackPts, int initiative, string attackType, string weakness, string immunity);
	string getTypeOf() override;
};

class Infection : public Unit {
	public:
	Infection(int numUnits, int hitPts, int attackPts, int initiative, string attackType, string weakness, string immunity);
	string getTypeOf() override;
};
#endif
