
#include <list>



extern const int MAZE_WIDTH =5;
extern const int MAZE_HEIGHT =5;

class Maze {
   public:
    Maze(){};
    Maze(int maze[MAZE_HEIGHT][MAZE_WIDTH], int origenX, int origenY, int goalX,int goalY);
    std::list<Point*> solve();
   
   private:
    int width;
    int height;
    int origenX,origenY;
    int goalX,goalY;
    std::list<Point*> path;
    Celda* maze[MAZE_WIDTH][MAZE_HEIGHT];

   
};