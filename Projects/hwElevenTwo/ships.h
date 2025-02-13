#ifndef SHIPS_H
#define SHIPS_H
#include <string>
#include <iostream>
#include "stdlib.h"
class Ocean;

class Ship{
private:
    int bowRow;
    int bowColumn;
    int length;
    bool horizontal;
protected:
    bool* hit;
public:
    Ship();
    Ship(int len);
    Ship(const Ship&);
    int getLength();
    int getBowRow();
    int getBowColumn();
    bool isHorizontal();
    void setBowRow(int row);
    void setBowColumn(int column);
    void setHorizontal(bool horiz);
    virtual std::string getShipType()=0;
    bool okToPlaceShipAt(int row, int column, bool horiz, const Ocean& ocean);
    void placeShipAt(int row, int column, bool horiz, Ocean& ocean);
    bool shootAt(int row, int column);
    bool isSunk();
    bool wasHit(int row, int column);
    virtual std::string toString();
    virtual ~Ship();
};

class Battleship: public Ship{
public:
    Battleship();
    std::string getShipType() override;
    ~Battleship();
};

class Cruiser: public Ship{
public:
    Cruiser();
    std::string getShipType() override;
    ~Cruiser();
};

class Destroyer: public Ship{
public:
    Destroyer();
    std::string getShipType() override;
    ~Destroyer();
};

class Submarine: public Ship{
public:
    Submarine();
    std::string getShipType() override;
    ~Submarine();
};

class EmptySea: public Ship{
public:
    EmptySea();
    std::string getShipType() override;
    std::string toString() override;
    ~EmptySea();
};
#endif
