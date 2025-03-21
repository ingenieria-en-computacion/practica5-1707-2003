#include "queue.h"
#include <stdlib.h>
#include <stdbool.h>

#define QUEUE_SIZE 100 // Asumimos un tamaño máximo para la cola

// Estructura para la cola
struct Queue {
    Data datos[QUEUE_SIZE];  // Arreglo de datos para la cola
    int head;  // Índice del frente de la cola
    int tail;  // Índice del final de la cola
};

// Crea una nueva cola vacía y la devuelve
Queue queue_create() {
    Queue q;
    q.head = -1;  // Inicializamos el índice del frente
    q.tail = -1;  // Inicializamos el índice del final
    return q;
}

// Inserta un elemento al final de la cola
void queue_enqueue(Queue* q, Data d) {
    if (q->tail == QUEUE_SIZE - 1) {
        // La cola está llena, no podemos insertar más elementos
        return;
    }
    if (q->head == -1) {
        q->head = 0;  // Si la cola está vacía, ponemos el primer elemento
    }
    q->tail++;  // Avanzamos el índice del final
    q->datos[q->tail] = d;  // Insertamos el dato en la cola
}

// Elimina y devuelve el elemento al frente de la cola
Data queue_dequeue(Queue* q) {
    if (queue_is_empty(q)) {
        // Cola vacía, devolvemos un valor de error
        Data error; 
        return error;  // Asegúrate de definir un valor de error si es necesario
    }
    Data front = q->datos[q->head];  // Obtenemos el dato al frente
    q->head++;  // Avanzamos el índice del frente
    if (q->head > q->tail) {
        // Si la cola queda vacía, restablecemos los índices
        q->head = -1;
        q->tail = -1;
    }
    return front;  // Devolvemos el dato del frente
}

// Verifica si la cola está vacía
bool queue_is_empty(Queue* q) {
    return q->head == -1;  // Si head es -1, la cola está vacía
}

// Obtiene el elemento al frente de la cola sin eliminarlo
Data queue_front(Queue* q) {
    if (queue_is_empty(q)) {
        // Cola vacía, devolvemos un valor de error
        Data error; 
        return error;  // Asegúrate de definir un valor de error si es necesario
    }
    return q->datos[q->head];  // Devolvemos el dato al frente
}

// Vacía la cola, eliminando todos sus elementos
void queue_empty(Queue* q) {
    q->head = -1;  // Restablecemos el índice del frente
    q->tail = -1;  // Restablecemos el índice del final
}
