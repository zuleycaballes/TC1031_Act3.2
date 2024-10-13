#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

// Estructura que representa un nodo en la cola priorizada.
struct Nodo {
    int dato;        
    Nodo* izquierdo; 
    Nodo* derecho;   
    Nodo* padre;     

    // Constructor del nodo.
    // Parametro: valor - Valor entero que se asignará al nodo.
    Nodo(int valor) : dato(valor), izquierdo(nullptr), derecho(nullptr), padre(nullptr) {}
};

// Clase que implementa una cola priorizada utilizando un árbol binario de nodos.
class priority_queue {
private:
    Nodo* raiz;  
    int cantidad; 

    // Función para reordenar el heap hacia arriba.
    // Parametro: nodo - Puntero al nodo que se va a reordenar.
    void ordenarArriba(Nodo* nodo);

    // Función para reordenar el heap hacia abajo.
    // Parametro: nodo - Puntero al nodo que se va a reordenar.
    void ordenarAbajo(Nodo* nodo);

    // Función que elimina un nodo.
    // Parametro: nodo - Puntero al nodo que se va a eliminar.
    void eliminarNodo(Nodo* nodo);

    // Función para encontrar el último nodo en el heap.
    // Retorno: Puntero al último nodo.
    Nodo* ultimoNodo();

public:
    priority_queue();

    ~priority_queue();

    // Agrega un dato a la fila priorizada.
    // Parametro: valor - El valor entero que se va a agregar a la fila priorizada.
    void push(int valor);

    // Saca de la fila priorizada el dato que tiene mayor prioridad (el máximo).
    void pop();

    // Regresa el valor del dato que tiene mayor prioridad (el máximo).
    // Retorno: El entero con mayor prioridad.
    int top() const;

    // Regresa si la fila priorizada está vacía.
    // Retorno: true si la fila está vacía, false en caso contrario.
    bool empty() const;

    // Regresa la cantidad de datos que tiene la fila priorizada.
    // Retorno: El número de elementos en la fila priorizada.
    int size() const;

    // Función para imprimir la fila priorizada.
    void print() const;
};

#endif // PRIORITY_QUEUE_H