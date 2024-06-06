#ifndef VERDURA_H
#define VERDURA_H

#include <iostream>
#include <string>
#include "Producto.h"

using namespace std;

class Verdura : public Producto {
private:
    string temporada;

public:
    Verdura();
    Verdura(string _nombre, int _precio, int _peso, string _temporada);

    void setTemporada(string _temporada);
    string getTemporada();

    string str();
    int calculaTotalPagar();
};

#endif // VERDURA_H