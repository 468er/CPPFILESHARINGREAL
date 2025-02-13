#include <iostream>
#include <vector>
using namespace std;
class Ship {
    protected:
        int bowRow;
        int bowColumn;
        int length;
        bool horizontal;
        bool hit[4];
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
        virtual string getShipType();
        bool shootAt(int row, int column);
        bool isSunk();
        bool wasHit(int row, int column);
         string toString();

};
class Battleship : public Ship {
    public:
        Battleship();
        /**/ string getShipType();
        /**/ string toString();
};
class Cruiser : public Ship{
  public:
        Cruiser();
        /**/ string getShipType();
        /**/ string toString();
};
class Destroyer : public Ship{
  public:
        Destroyer();
        /**/ string getShipType();
        /**/ string toString();
};

class Submarine : public Ship{
  public:
        Submarine();
        /**/ string getShipType();
        /**/ string toString();
};

class EmptySea : public Ship{
  public:
        EmptySea();
        /**/ string getShipType();
        /**/ string toString();
};
