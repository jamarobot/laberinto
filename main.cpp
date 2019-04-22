
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
//#include "Celda.cpp"
#include <bitset>
#include <list>
#include "Celda.cpp"
#define WIDTH 5
#define HEIGHT 5
extern Celda*** c;
using namespace std;
int main(int n, char** args) {
    int plantilla[WIDTH][HEIGHT] = {{13, 1, 5, 5, 3},
                                    {9, 6, 9, 5, 2},
                                    {10, 11, 10, 9, 6},
                                    {10, 10, 10, 12, 3},
                                    {12, 6, 14, 9, 6}};
    Celda* matrix[WIDTH][HEIGHT];
    list<Celda*> posibles;
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            matrix[i][j] = new Celda(i, j, plantilla[i][j]);
        }
    }
    cout << sizeof(matrix[0]) / sizeof(matrix[0][0]) << endl;

    // cout << binary << endl;
    for (int x = 0; x < 5; x++) {
        for (int k = 0; k < HEIGHT; k++) {
            //   cout << (*matrix[x][k]).getTipo();
            printf(" %*d", 3, (*matrix[x][k]).getTipo());
        }
        cout << endl;
    }
    return 0;
}