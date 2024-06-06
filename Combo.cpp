// Marco Antonio Torres Ramirez
// A00839451
// ITC
// 06/06/2024

#include "Combo.h"

// Constructor por defecto
Combo::Combo() {
    clave = 0;
}

// Constructor con parámetros
Combo::Combo(string _nombre, int _precio, int _peso, int _clave) : Producto(_nombre, _precio, _peso) {
    clave = _clave;
}

// Métodos de acceso y modificación de los atributos de la clase
void Combo::setClave(int _clave) {
    clave = _clave;
}

int Combo::getClave() {
    return clave;
}

// metodo que retorna la siguiente informacion separada por '-' y con el $ antes de las cantidades que
// se refieren a dinero
string Combo::str() {
    return getNombre() + "-$" + to_string(getPrecio()) + "-" + to_string(getPeso()) + "-$" + to_string(calculaTotalPagar()) + "-" + to_string(clave);
}

// metodo que calcula y retorna el total a pagar, el calculo se hace de la siguient forma: calcula el total
// a pagar mutiplicando el prcio x peso x la clave del combo, ademas si la clave del combo es 1 se le descontaran
// 25 pesos por cada 100. si la clave del combo es 2 se le decontaran 30 pesos or cada 100. si es cualquier otra
// clave no tendra descuento. 
int Combo::calculaTotalPagar() {
    int total = getPrecio() * getPeso() * clave;
    if (clave == 1) {
        total -= (total / 100) * 25;
    } else if (clave == 2) {
        total -= (total / 100) * 30;
    }
    return total;
}