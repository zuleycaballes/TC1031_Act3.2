#include "priority_queue.h"
#include <iostream>
#include <stdexcept>

using namespace std;

// Constructor: Inicializa la cola priorizada con raíz nula y cantidad cero.
// Complejidad: O(1) - Solo inicializa dos variables.
priority_queue::priority_queue() : raiz(nullptr), cantidad(0) {}

// Destructor: Elimina todos los nodos de la cola priorizada.
// Complejidad: O(n log n) - Llama a pop() repetidamente, cada llamada a pop() es O(log n).
priority_queue::~priority_queue() {
    while (!empty()) {
        pop();
    }
}

// Función para reordenar el heap hacia arriba.
// Parametro: nodo - Puntero al nodo que se va a reordenar.
// Complejidad: O(log n) - En el peor caso, el nodo se mueve desde una hoja hasta la raíz,
// lo que implica recorrer la altura del árbol, que es logarítmica en el número de nodos.
void priority_queue::ordenarArriba(Nodo* nodo) {
    while (nodo->padre != nullptr && nodo->dato > nodo->padre->dato) {
        int temp = nodo->dato;
        nodo->dato = nodo->padre->dato;
        nodo->padre->dato = temp;
        nodo = nodo->padre;
    }
}

// Función para reordenar el heap hacia abajo.
// Parametro: nodo - Puntero al nodo que se va a reordenar.
// Complejidad: O(log n) - En el peor caso, el nodo se mueve desde la raíz hasta una hoja,
// lo que implica recorrer la altura del árbol, que es logarítmica en el número de nodos.
void priority_queue::ordenarAbajo(Nodo* nodo) {
    while (true) {
        Nodo* mayor = nodo;
        if (nodo->izquierdo != nullptr && nodo->izquierdo->dato > mayor->dato) {
            mayor = nodo->izquierdo;
        }
        if (nodo->derecho != nullptr && nodo->derecho->dato > mayor->dato) {
            mayor = nodo->derecho;
        }
        if (mayor == nodo) {
            break;
        }

        int temp = nodo->dato;
        nodo->dato = mayor->dato;
        mayor->dato = temp;
        nodo = mayor;
    }
}

// Función que elimina un nodo.
// Parametro: nodo - Puntero al nodo que se va a eliminar.
// Complejidad: O(1) - Elimina el nodo y ajusta los punteros, lo cual es una operación constante.
void priority_queue::eliminarNodo(Nodo* nodo) {
    if (nodo->padre == nullptr) {
        raiz = nullptr;
    } else if (nodo->padre->izquierdo == nodo) {
        nodo->padre->izquierdo = nullptr;
    } else {
        nodo->padre->derecho = nullptr;
    }
    delete nodo;
    cantidad--;
}

// Función para encontrar el último nodo en el heap.
// Retorno: Puntero al último nodo.
// Complejidad: O(log n) - En el peor caso, recorre la altura del árbol, que es logarítmica en el número de nodos.
Nodo* priority_queue::ultimoNodo() {
    Nodo* nodo = raiz;
    while (nodo && nodo->izquierdo) {
        nodo = nodo->izquierdo;
    }
    return nodo;
}

// Agrega un dato a la fila priorizada.
// Parametro: valor - El valor entero que se va a agregar a la fila priorizada.
// Complejidad: O(log n) - Inserta el nodo y lo reordena hacia arriba, lo que implica recorrer la altura del árbol.
void priority_queue::push(int valor) {
    Nodo* nodo = new Nodo(valor);
    if (raiz == nullptr) {
        raiz = nodo;
    } else {
        Nodo* padre = ultimoNodo();
        if (padre->izquierdo == nullptr) {
            padre->izquierdo = nodo;
        } else {
            padre->derecho = nodo;
        }
        nodo->padre = padre;
        ordenarArriba(nodo);
    }
    cantidad++;
}

// Saca de la fila priorizada el dato que tiene mayor prioridad (el máximo).
// Complejidad: O(log n) - Intercambia la raíz con el último nodo, elimina el último nodo y reordena hacia abajo,
// lo que implica recorrer la altura del árbol.
void priority_queue::pop() {
    if (empty()) {
        throw runtime_error("La fila priorizada está vacía.");
    }

    Nodo* ultimo = ultimoNodo();
    int temp = raiz->dato;
    raiz->dato = ultimo->dato;
    ultimo->dato = temp;

    eliminarNodo(ultimo);

    if (raiz != nullptr) {
        ordenarAbajo(raiz);
    }
}

// Regresa el valor del dato que tiene mayor prioridad (el máximo).
// Retorno: El entero con mayor prioridad.
// Complejidad: O(1) - Accede al valor de la raíz, lo cual es una operación constante.
int priority_queue::top() const {
    if (empty()) {
        throw runtime_error("La fila priorizada está vacía.");
    }
    return raiz->dato;
}

// Regresa si la fila priorizada está vacía.
// Retorno: true si la fila está vacía, false en caso contrario.
// Complejidad: O(1) - Verifica si la cantidad es cero, lo cual es una operación constante.
bool priority_queue::empty() const {
    return cantidad == 0;
}

// Regresa la cantidad de datos que tiene la fila priorizada.
// Retorno: El número de elementos en la fila priorizada.
// Complejidad: O(1) - Devuelve el valor de la cantidad, lo cual es una operación constante.
int priority_queue::size() const {
    return cantidad;
}

// Función para imprimir la fila priorizada.
// Complejidad: O(n) - Recorre todos los nodos del árbol, lo que implica visitar cada nodo una vez.
void priority_queue::print() const {
    if (empty()) {
        cout << "La fila priorizada está vacía." << endl;
        return;
    }

    cout << "Fila priorizada: ";
    Nodo* nodo = raiz;
    while (nodo != nullptr) {
        cout << nodo->dato << " ";
        nodo = nodo->izquierdo;
    }
    cout << endl;
}