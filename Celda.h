
class Celda {
   private:
    int x;
    int y;
    bool u, d, l, r;
    Celda *parent;
    int tipo;

   public:
    int status;
    /*
    no calculada aun 0
    calculada 1
    parte del camino 2
    inicio 3
    fin 4
    */
    int getTipo() { return this->tipo; }
    void setTipo(int tipo_) { this->tipo = tipo_; }
    Celda(int y_, int x_, int tipo_);
    // void propagate(list<Celda *> posibles);
};
