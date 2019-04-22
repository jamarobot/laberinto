#include "Celda.h"
#include <bitset>

Celda::Celda(int y_, int x_, int tipo_) {
    y = y_;
    x = x_;
    tipo = tipo_;
    std::string binary = std::bitset<4>(tipo_).to_string();
    parent = NULL;
    l = (binary[0] == 0);
    d = (binary[1] == 0);
    r = (binary[2] == 0);
    u = (binary[3] == 0);
}
