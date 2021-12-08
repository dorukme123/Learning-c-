#include <iostream>
#include "gameField.h"
#ifndef UNIT_H
#define UNIT_H
using namespace std;


class Unit{
protected:
    int strength;
    int speed;
    int endurance;

public:
    unsigned char picture;
    int hp;
    int ini;
    int coordinateX;
    int coordinateY;

    virtual void moveUnit(unsigned char* field, int size){};

    void setCoordinates(int* coords){
        coordinateX = coords[0];
        coordinateY = coords[1];
    }

    Unit(){
        cout << "Please enter the sign for unit: ";
        cin >> picture;
        cout << "Enter strength: ";
        cin >> strength;
        cout << "Enter speed: ";
        cin >> speed;
        cout <<"Enter endurance: ";
        cin >> endurance;
        cout << endl;

        hp = max(strength*2 / speed, 100);
        ini = max(speed*3 / endurance, 10);
    }

    bool canMove(unsigned char* field, int x, int y, int n){
        return coordinateX + x >= 0 && coordinateX + x < n &&
               coordinateY + y >= 0 && coordinateY + y < n &&
               field[y*n + x] != 178;
    }

    virtual bool canAttack(Unit* toAttack){return false;};
    virtual void attackUnit(Unit* toAttack){};

    virtual void printState(){
        cout << picture << " : hp: " << hp <<", ini: " << ini;
    }
};

class Fighter : public Unit{
public:

    void printState(){
        Unit::printState();
        cout << ", class: Fighter\n";
    }

    void attackUnit(Unit* toAttack){
        toAttack->hp -= ini*2;
        ini -= 5;
    }

    bool canAttack(Unit* toAttack){
        return (abs(toAttack->coordinateY - coordinateY) <= 1 &&
                abs(toAttack->coordinateX - coordinateX) <= 1 &&
                ini >= 5);
    }

    void moveUnit(unsigned char* field, int size){
        if (canMove(field, 1, 0, size)){
            coordinateX++;
            ini -= 2;
        } else if (canMove(field, 0, 1, size)){
            coordinateY++;
            ini -= 2;
        } else if (canMove(field, -1, 0, size)){
            coordinateX--;
            ini -= 2;
        } else if (canMove(field, 0, -1, size)){
            coordinateY--;
            ini -= 2;
        } else if (canMove(field, 1, 1, size)){
            coordinateX++; coordinateY++;
            ini -= 3;
        } else if (canMove(field, 1, -1, size)){
            coordinateX++; coordinateY--;
            ini -= 3;
        } else if (canMove(field, -1, 1, size)){
            coordinateX--; coordinateY++;
            ini -= 3;
        } else if (canMove(field, -1, -1, size)){
            coordinateX--; coordinateY--;
            ini -= 3;
        }
    }
};

class Ranger : public Unit{
public:

    void printState(){
        Unit::printState();
        cout << ", class: Ranger\n";
    }

    void attackUnit(Unit* toAttack){
        toAttack->hp -= ini*2;
        ini -= 5;
    }

    bool canAttack(Unit* toAttack){
        return (ini >= 5);
    }

    void moveUnit(unsigned char* field, int size){
        if (canMove(field, 1, 0, size)){
            coordinateX++;
            ini -= 2;
        } else if (canMove(field, 0, 1, size)){
            coordinateY++;
            ini -= 2;
        } else if (canMove(field, -1, 0, size)){
            coordinateX--;
            ini -= 2;
        } else if (canMove(field, 0, -1, size)){
            coordinateY--;
            ini -= 2;
        } else if (canMove(field, 1, 1, size)){
            coordinateX++; coordinateY++;
            ini -= 3;
        } else if (canMove(field, 1, -1, size)){
            coordinateX++; coordinateY--;
            ini -= 3;
        } else if (canMove(field, -1, 1, size)){
            coordinateX--; coordinateY++;
            ini -= 3;
        } else if (canMove(field, -1, -1, size)){
            coordinateX--; coordinateY--;
            ini -= 3;
        }
    }
};
#endif //UNIT_H


