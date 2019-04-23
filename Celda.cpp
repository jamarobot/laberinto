#include "Celda.h"
#include <bitset>

extern const int WIDTH;
extern const int HEIGHT;
extern bool found;
extern list<Point*> path;

Celda::Celda(int y_, int x_, int tipo_) {
    y = y_;
    x = x_;
    tipo = tipo_;
    status = 0;
    std::string binary = std::bitset<4>(tipo_).to_string();
    parent = NULL;

    // std::cout << "contsruxtp";
    // std::cout << ((tipo == 4) ? "4" : "no 4");
    this->l = (binary[0] == '0');
    this->d = (binary[1] == '0');
    this->r = (binary[2] == '0');
    this->u = (binary[3] == '0');
    /*if (tipo_ == 6) {
        std::cout << this->d << endl;
        std::cout << this->l << endl;
        std::cout << this->u << endl;
        std::cout << this->r << endl;
    }*/
}
void Celda::propagate(list<Celda*>* posibles, Celda* maze[WIDTH][HEIGHT]) {
    Celda** child;
    /*  std::cout << endl << this->tipo << endl;
      std::cout << this->d << endl;
      std::cout << this->l << endl;
      std::cout << this->u << endl;
      std::cout << this->r << endl;
      */

    if (this->u) {
        child = &maze[y - 1][x];
        registrar(*child, posibles);
    }
    if (this->d) {
        child = &maze[y + 1][x];
        registrar(*child, posibles);
    }
    if (this->r) {
        child = &maze[y][x + 1];
        registrar(*child, posibles);
    }
    if (this->l) {
        child = &maze[y][x - 1];
        registrar(*child, posibles);
    }
}

void Celda::registrar(Celda* child, list<Celda*>* posibles) {
    if ((*child).isFree()) {
        (*posibles).push_back(child);
        (*child).setParent(this);
        (*child).setStatus(SEARCHED);
        cout << "registo" << endl;
    } else if ((*child).isGoal()) {
        cout << "premio" << (*child).getX() << " " << (*child).getY() << endl;

        (*child).setParent(this);
        found = true;
        this->searchBackwards(&path);
    }
}
void Celda::searchBackwards(list<Point*>* path) {
    Point* cords = new Point(x, y);
    (*path).push_back(&*cords);
    cout << "entro en " << x << y;

    if (this->parent != NULL) {
        cout << "tengo padre" << endl;
        this->parent->searchBackwards(path);
    } else {
        cout << this->parent << "*" << endl;
    }
}
