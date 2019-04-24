
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <list>
#include "constants.h"
bool found = false;
#include "Point.cpp"


#include "Celda.cpp"
#include "Maze.h"

std::list<Point*> Maze::solve() {

    list<Celda*> posibles;
    Celda** goal = &maze[4][3];
    (*goal)->setStatus(GOAL);

    Celda** inicio = &maze[1][1];
    (*inicio)->setStatus(BEGIN);
    (*inicio)->propagate(&posibles, maze,&path);

    while (!posibles.empty() && !found) {
        (*posibles.front()).propagate(&posibles, maze,&path);
        posibles.pop_front();
    }
    while (!this->path.empty()) {
        cout << (path.front())->x << " " << (this->path.front())->y << endl;
        this->path.pop_front();
    }
    return path;
}

Maze::Maze(int plantilla[cts::MAZE_HEIGHT][cts::MAZE_WIDTH], int origenX, int origenY,int goalX, int goalY) {
    for (int i = 0; i < cts::MAZE_WIDTH; i++) {
        for (int j = 0; j < cts::MAZE_HEIGHT; j++) {
            maze[i][j] = new Celda(i, j, plantilla[i][j]);
        }
    }
    std::cout<<&path<<endl;
}
