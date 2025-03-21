#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdbool.h>

// Definimos el tipo de dato que usaremos para almacenar los elementos en la cola
typedef int Data;
typedef int data;
#define TAM 100  // Tamaño máximo de la cola

// Definimos la estructura de la cola
typedef struct {
    Data datos[TAM];  // Arreglo de datos para almacenar los elementos de la cola
    int head;          // Índice para el primer elemento de la cola
    int tail;          // Índice para el siguiente espacio disponible en la cola
    int len;           // Longitud actual de la cola
} Queue;

// Funciones que se implementarán para trabajar con la cola
Queue queue_create();
void queue_enqueue(Queue*, Data);
Data queue_dequeue(Queue*);
bool queue_is_empty(Queue*);
Data queue_front(Queue*);
void queue_empty(Queue*);
void queue_delete(Queue*);

#endif // __QUEUE_H__
