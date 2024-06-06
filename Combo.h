#ifndef COMBO_H
#define COMBO_H

#include <iostream>
#include <string>
#include "Producto.h"

using namespace std;

class Combo : public Producto {
private:
    int clave;

public:
    Combo();
    Combo(string _nombre, int _precio, int _peso, int _clave);

    void setClave(int _clave);
    int getClave();

    string str();
    int calculaTotalPagar();
};

#endif // COMBO_H