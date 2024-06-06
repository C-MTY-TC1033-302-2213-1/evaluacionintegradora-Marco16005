// Marco Antonio Torres Ramirez
// A00839451
// ITC
// 06/06/2024

#include "Verdura.h"

// Constructor por defecto
Verdura::Verdura() {
    temporada = "Invierno";
}

// Constructor con parámetros
Verdura::Verdura(string _nombre, int _precio, int _peso, string _temporada) : Producto(_nombre, _precio, _peso) {
    temporada = _temporada;
}

// Métodos de acceso y modificación de los atributos de la clase
void Verdura::setTemporada(string _temporada) {
    temporada = _temporada;
}

string Verdura::getTemporada() {
    return temporada;
}

// retorna la ia informacion sparada por '-' y con el $ antes de las cantidades que 
// se refieren a dinero
string Verdura::str() {
    return getNombre() + "-$" + to_string(getPrecio()) + "-" + to_string(getPeso()) + "-$" + to_string(calculaTotalPagar()) + "-" + temporada;
}

// metodo que calcula y retorna el total a pagar, el calculo se hace de la siguient forma - si temporada es
// "Junio" el total a pagar es la multiplicacion del precio x peso x 2, si temporada es "Regalado" el total a 
// pagar es la multiplicacion del prcio x peso x 3, cualqier otro valor retornara precio x peso x 10 
int Verdura::calculaTotalPagar() {
    if (temporada == "Junio") {
        return getPrecio() * getPeso() * 2;
    } else if (temporada == "Regalado") {
        return getPrecio() * getPeso() * 3;
    } else {
        return getPrecio() * getPeso() * 10;
    }
}