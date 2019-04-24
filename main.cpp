#include "Maze.cpp"
using namespace std;
int main(int n, char** args) {
    
    int plantilla[MAZE_WIDTH][MAZE_HEIGHT] = {{13, 1, 5, 5, 3},
                                    {9, 6, 9, 5, 2},
                                    {10, 11, 10, 9, 6},
                                    {10, 10, 10, 12, 3},
                                    {12, 6, 14, 9, 6}};

    Maze* m=new Maze(plantilla, 1,1,1,1);
    list<Point*>solve=m->solve();  
    cout<<&solve;
    while(!solve.empty()){
        
        cout<< (solve.front())->x<< "-"<<(solve.front())->y<<endl;
        solve.pop_front();
    }
    return 0;
}
/*void printStatus(Celda* maze[WIDTH][HEIGHT]) {
    for (int x = 0; x < 5; x++) {
        for (int k = 0; k < HEIGHT; k++) {
            printf(" %*d", 3, (*maze[x][k]).getStatus());
        }
        cout << endl;
    }
}

void printTipos(Celda* maze[WIDTH][HEIGHT]) {
    for (int x = 0; x < 5; x++) {
        for (int k = 0; k < HEIGHT; k++) {
            printf(" %*d", 3, (*maze[x][k]).getTipo());
        }
        cout << endl;
    }
}

void printAll(Celda* maze[WIDTH][HEIGHT]) {
    for (int x = 0; x < 5; x++) {
        for (int k = 0; k < HEIGHT; k++) {
            printf(" %*d", 3, (*maze[x][k]).getTipo());
            printf("[%*d]", 2, (*maze[x][k]).getStatus());
        }
        cout << endl;
    }
}*/