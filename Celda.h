#define FREE 0
#define SEARCHED 1
#define PATH 2
#define BEGIN 3
#define GOAL 4
#include <list>
extern const int WIDTH;
extern const int HEIGHT;
using namespace std;
class Celda {
   private:
    int x;
    int y;
    bool u, d, l, r;
    Celda* parent;
    int tipo;
    void registrar(Celda* child, list<Celda*>* posibles);
    int status;

   public:
    void setStatus(int status_) { this->status = status_; }
    int getStatus() { return this->status; }
    int getX() { return this->x; }
    int getY() { return this->y; }
    /*
    no calculada aun 0
    calculada 1
    parte del camino 2
    inicio 3
    fin 4
    */
    bool hasParent() { return (this->parent != NULL); }
    Celda* getParent() { return this->parent; }
    int getTipo() { return this->tipo; }
    void setTipo(int tipo_) { this->tipo = tipo_; }
    Celda(int y_, int x_, int tipo_);
    Celda();
    void setParent(Celda* parent_) {
        this->parent = parent_;
        if (x == y && x == 4) {
            cout << parent_ << " pongo padre en 44 " << parent_ << endl
                 << this->getX() << "-" << this->getY() << endl;
        }

        //  cout << "estoy en " << x << " " << y << " " << this             << "
        //  parent: " << this->parent << endl;
    }
    void propagate(list<Celda*>* posibles, Celda* maze[WIDTH][HEIGHT]);
    bool isFree() { return (this->status == FREE); };
    bool isGoal() { return (this->status == GOAL); }
    void searchBackwards(list<Point*>* path);
};
