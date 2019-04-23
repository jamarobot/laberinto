
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <list>
const int WIDTH = 5;
const int HEIGHT = 5;
bool found = false;
#include "Point.h"
std::list<Point> path;
#include <bitset>
#include "Celda.cpp"

using namespace std;
Celda* maze[WIDTH][HEIGHT];

int main(int n, char** args) {
    int plantilla[WIDTH][HEIGHT] = {{13, 1, 5, 5, 3},
                                    {9, 6, 9, 5, 2},
                                    {10, 11, 10, 9, 6},
                                    {10, 10, 10, 12, 3},
                                    {12, 6, 14, 9, 6}};

    list<Celda> posibles;
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            maze[i][j] = new Celda(i, j, plantilla[i][j]);
        }
    }

    for (int x = 0; x < 5; x++) {
        for (int k = 0; k < HEIGHT; k++) {
            //   cout << (*matrix[x][k]).getTipo();
            printf(" %*d", 3, (*maze[x][k]).getTipo());
        }
        cout << endl;
    }

    Celda** goal = &maze[4][3];
    (*goal)->setStatus(GOAL);

    Celda** inicio = &maze[1][1];
    (*inicio)->setStatus(BEGIN);
    (*inicio)->propagate(&posibles, maze);

    // cout << sizeof(maze[0]) / sizeof(maze[0][0]) << endl;

    while (!posibles.empty() && !found) {
        // cout << (posibles.front()).getTipo();
        (posibles.front()).propagate(&posibles, maze);
        posibles.pop_front();
    }

    return 0;
}