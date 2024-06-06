// Marco Antonio Torres Ramirez
// A00839451
// ITC
// 06/06/2024

#include "Producto.h"

// Constructor por defecto
Producto::Producto() {
    nombre = "Marco_T";
    precio = 839451;
    peso = 18;
}

// Constructor con parámetros
Producto::Producto(string _nombre, int _precio, int _peso) {
    nombre = _nombre;
    precio = _precio;
    peso = _peso;
}

// Métodos de acceso y modificación de los atributos de la clase
void Producto::setNombre(string _nombre) {
    nombre = _nombre;
}

void Producto::setPrecio(int _precio) {
    precio = _precio;
}

void Producto::setPeso(int _peso) {
    peso = _peso;
}

string Producto::getNombre() {
    return nombre;
}

int Producto::getPrecio() {
    return precio;
}

int Producto::getPeso() {
    return peso;
}

// Despliega la informacion del prsucto en el siquiente formato: P1-$30-10-$300
//o sea nombre, precio, peso y total a pagar
string Producto::str() {
    return nombre + "-$" + to_string(precio) + "-" + to_string(peso) + "-$" + to_string(calculaTotalPagar());
}

// Calcula y retorna el total a pagar multiplicando el precio por el peso
int Producto::calculaTotalPagar() {
    return precio * peso;
}