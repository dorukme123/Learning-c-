#ifndef GAME_GAMEFIELD_H
#define GAME_GAMEFIELD_H

using namespace std;

#include <cstdlib>
#include <iostream>
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */
#include "Unit.h"

class gameField {
protected:
    Unit* u1;
    Unit* u2;

public:
    ~gameField()= default;

    void start(int size) {
        //create map
        srand(time(NULL));
        int numOfObstacles = size + size / 2;
        unsigned char gf[size * size];
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (rand() % 2 == 0 && numOfObstacles > 0) {
                    gf[i * size + j] = 178;
                    numOfObstacles--;
                } else {
                    gf[i * size + j] = 176;
                }
            }
        }


        string type;
        cout << "enter type of first unit: ";
        cin >> type;
        if (type == "Fighter") {
            u1 = new Fighter();
        } else u1 = new Ranger();

        cout << "enter type of second unit: ";
        cin >> type;
        if (type == "Fighter") {
            u2 = new Fighter();
        } else u2 = new Ranger();

        int x = 0, y = 0;
        while (gf[y*size + x] != 176){
            x = rand() % size;
            y = rand() % size;
        }
        u1->coordinateX = x; u1->coordinateY = y;
        do {
            x = rand() % size;
            y = rand() % size;
        } while (gf[y*size + x] != 176 && (x != u1->coordinateX || y != u1->coordinateY));
        u2->coordinateX = x; u2->coordinateY = y;

        startGame(gf, size);
    }

    void printGameField(unsigned char* gameField, int size){
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (i == u1->coordinateY && j == u1->coordinateX)
                    cout << u1->picture;
                else if (i == u2->coordinateY && j == u2->coordinateX)
                    cout << u2->picture;
                else cout << gameField[i*size + j];
            }
            cout << "\n";
        }
    }

    void startGame(unsigned char* gameField, int size){
        cout << "### start disposition ###\n";
        printGameField(gameField, size);
        u1->printState();
        u2->printState();
        cout << "\n### first move ###\n";

        int moves = 100;
        while (moves > 0){
            if (u1->ini > u2->ini){
                if (u1->canAttack(u2))
                    u1->attackUnit(u2);
                else {
                    u1->moveUnit(gameField, size);
                }
            } else {
                if (u2->canAttack(u1))
                    u2->attackUnit(u1);
                else {
                    u2->moveUnit(gameField, size);
                }
            }
            moves--;
            printGameField(gameField, size);
            u1->printState();
            u2->printState();
            u1->ini += rand() % 20;
            u2->ini += rand() % 20;

            if (u1->hp > 0 && u2->hp > 0) {
                cout << "Waiting to proceed to the next turn..";
                string a;
                cin >> a;
            } else {
                cout << "\n### ### ###\n";
                if (u1->hp < 0){
                    cout << "player #2 with " << u2->hp << " HP won! \n";
                } else cout << "player #1 with " << u1->hp << " HP won! \n";
                cout << "### ### ###";
                return;
            }
        }
    }
};

#endif //GAME_GAMEFIELD_H
