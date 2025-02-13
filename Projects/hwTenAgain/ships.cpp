
#include "ships.h"
using namespace std;
        Ship::Ship(){
            bowRow = 0;
            bowColumn = 0;
            length = 0;
            horizontal = false;
            for(int a = 0; a < sizeof(hit); a++){
                hit[a] = false;
            }
        }
        Ship::Ship(int len){
            bowRow = 0;
            bowColumn = 0;
            length = len;
            horizontal = false;
            for(int a = 0; a < sizeof(hit); a++){
                hit[a] = false;
            }
        }
       Ship:: Ship(const Ship& ship){
            bowRow = ship.bowRow;
            bowColumn = ship.bowColumn;
            length = ship.length;
            horizontal = ship.horizontal;
//            hit = new bool[4];
            
            for(int a = 0; a < sizeof(hit); a++){
                hit[a] = ship.hit[a];
            }
        }
        int Ship::getLength(){
            return length;
        }
        int Ship::getBowRow(){
            return bowRow;
        }
        int Ship::getBowColumn(){
            return bowColumn;
        }
        bool Ship::isHorizontal(){
            return horizontal;
        }
        void Ship::setBowRow(int row){
            bowRow = row;
        }
        void Ship::setBowColumn(int column){
            bowColumn = column;
        }
        void Ship::setHorizontal(bool horiz){
            horizontal = horiz;
        }
        bool Ship::shootAt(int row, int column){
            if(getShipType() != "empty"){
                int distance = 0;
            if(horizontal){
                distance = column - bowColumn;
            }
            else{
                distance = row - bowRow;
            }
            if(distance < 0){
                distance *= -1;
            }
            if(distance < length){
                if(column + distance == bowColumn || row + distance == bowRow){
                    hit[distance] = true;
                   return hit[distance];

                }
            }   
            return false;
            }
            else{
                hit[3] = true;
                return false;
            }
        }
        bool Ship::isSunk(){
            for(int a = 0; a < length; a++){
                if(hit[a] == false){
                    return false;
                }
            }
            return true;
        }
        bool Ship::wasHit(int row, int column){
            int checkROC = 0;
            int inputCheckROC = 0;
            if(horizontal){
                checkROC = bowColumn ;
                inputCheckROC = column;
            }
            else{
                checkROC = bowRow;
                inputCheckROC = row ;
            }
            for(int a = 0; a < length; a++){
                if(inputCheckROC == checkROC + a){
                    if(horizontal){
                        
                        if(row == bowRow){
                            return hit[a];
                        }
                    }
                    else{
                        if(column == bowColumn){
                              return hit[a];
                        }
                    }
                }
            }
            return false;
        }
         string Ship::getShipType(){
            return "";
        }
         string Ship::toString(){
           if(isSunk()){
                return "x";
           } 
           else{
                if(getShipType() == "empty"){
                    if(hit[3] == true){
                return "-";
            }
            else{
                return ".";
            }
                }
                else{
                    return "S";
           
                }
            }
        }
        Battleship::Battleship():Ship::Ship(){
            length = 4;
        }
         string Battleship::getShipType(){
            return "battleship";
        }


        Cruiser::Cruiser():Ship::Ship(){
            length = 3;

        }
        /**/ string Cruiser::getShipType(){
            return "cruiser";

        }
    
        Destroyer::Destroyer():Ship::Ship(){
            length = 2;

        }
        /**/ string Destroyer::getShipType(){
            return "destroyer";

        }

        Submarine::Submarine():Ship::Ship(){
            length = 1;

        }
        /**/ string Submarine::getShipType(){
            return "submarine";

        }

        EmptySea::EmptySea():Ship::Ship(){
            length = 1;
        }
        /**/ string EmptySea::getShipType(){
            return "empty";

        }
        /**/ string  EmptySea::toString() {
            return ".";
           /* if(hit[3] == true){
                return "-";
            }
            else{
                return ".";
            }*/
        }
