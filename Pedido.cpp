// Marco Antonio Torres Ramirez
// A00839451
// ITC
// 06/06/2024

#include "Pedido.h"

// Inicializa el arreglo de apuntadores a nullptr y la cantidad de pedidos a 0
Pedido::Pedido() {
    for (int index = 0; index < MAX_PROD; index++){
        arrPtrProductos[index] = nullptr;
    }

    cantidad = 0;
}

void Pedido::leerArchivo(std::string nombre ){
    fstream archivo;
    string row[5];
    string line, word;

    archivo.open(nombre, ios::in);
    cantidad = 0;

    // lee una línea del archivo y la almacena en line
    while ( getline(archivo, line)) {
        stringstream s(line);
        int iR = 0;

        // extrae caracteres de s  y los almacena en word hasta que encuentra el delimitador ','
        while (getline(s, word, ',')) {
            row[iR++] = word;
        }
        if (row[0] == "V"){ // Verdura
            arrPtrProductos[cantidad] = new Verdura( "", 0, 0, row[1]);
            arrPtrProductos[cantidad]->setNombre(row[2]);
            arrPtrProductos[cantidad]->setPrecio( stoi(row[3]));
            arrPtrProductos[cantidad]->setPeso(stoi(row[4]));
        } else if (row[0] == "C"){ // Combo
            arrPtrProductos[cantidad] = new Combo( row[1], stoi(row[2]), stoi(row[3]), stoi(row[4]));
        }
        else if (row[0] == "P"){ // Producto
            arrPtrProductos[cantidad] = new Producto( row[1], stoi(row[2]), stoi(row[3]));
        }
        // incrementar el contador de apuntadores de arrPtrProductos
        cantidad = cantidad + 1;
    }
    archivo.close();
}

// Metodo que imprime el ticket del cliente. Despliega la informacion de todos los productos delarreglo de apuntadores
// de Productos, aqui se plica el polimorfismo, y y dado que las funciones son virtuales, en tiempo de ejecucion de llamara
// al metodo correspondiente, - llama a la funcion str() para desplegar todos los productos que compro el cliente. El metodo
// tambien calcula el total a pagar sumando los totales a pagar de cada producto del pedido - debe llamar a la funcion
// calculaTotalPagar() para calcular el total a pagar de cada uno de los productos de arreglo. Al fianl del ticket muestra
// "Total a pagar&" ____\n
void Pedido::ticketCliente() {
    int total = 0;
    int articulos = 0;
    for (int index = 0; index < cantidad; index++) {
        cout << arrPtrProductos[index]->str() << endl;
        total += arrPtrProductos[index]->calculaTotalPagar();
        articulos++;
    }
    cout << articulos << " articulos" << endl;
    cout << "Total a pagar $" << total << endl;
}