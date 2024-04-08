#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Función para cambiar el valor de una variable a través de un puntero
// *NO RETORNA*
void cambiarValor(int *p) {
    *p = 100;
}

int main() {
    // Declaración de puntero
    int *p;

    // Asignación de puntero a la dirección de memoria de una variable
    int x = 10;
    p = &x;

    // Acceso al valor almacenado en la dirección de memoria apuntada por el puntero
    int y = *p;

    // Asignación de puntero a la dirección de memoria de otra variable
    int a = 20;
    int *q = &a;

    // Declaración de puntero nulo
    int *r = nullptr;

    // Declaración y asignación de puntero a un array
    int array[5] = {1, 2, 3, 4, 5};
    int *ptr = array;

    // Incremento del puntero para apuntar al siguiente elemento del array
    ptr++;

    // Llamada a la función para cambiar el valor de una variable a través de un puntero
    cambiarValor(&x);

    // Creación de un puntero y asignación de memoria dinámica en el montón
    int *ptr_dinamico = new int;
    *ptr_dinamico = 10;

    // Impresión de los resultados y explicaciones
    cout << "Valor de x: " << x << endl;
    cout << "Valor almacenado en la dirección de memoria apuntada por p: " << y << endl;
    cout << "Dirección de memoria de x: " << &x << endl;
    cout << "Valor apuntado por q: " << *q << endl;
    cout << "Dirección de memoria apuntada por q: " << q << endl;
    cout << "Puntero r: " << r << endl;
    cout << "Puntero ptr ahora apunta al segundo elemento del array: " << *ptr << endl;
    cout << "Valor asignado dinámicamente a través de ptr_dinamico: " << *ptr_dinamico << endl;
    cout << "Direccion de memoria de ptr_dinamico: " << ptr_dinamico << endl;

    // Liberación de la memoria asignada dinámicamente
    delete ptr_dinamico;

    return 0;
}