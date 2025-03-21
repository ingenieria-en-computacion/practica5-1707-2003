#ifndef __STACK_H__
#define __STACK_H__

#include <stdbool.h>

// Definimos el tamaño máximo de la pila
#define MAX_SIZE 100  // Cambié 'TAM' por 'MAX_SIZE' como convención

typedef int Data;  // Definimos que 'Data' es de tipo int, ajusta según necesites

// Definimos la estructura de la pila
typedef struct {
    Data data[MAX_SIZE];  // Arreglo que contiene los elementos de la pila
    int top;  // Índice que apunta al elemento superior de la pila
} Stack;

// Declaración de las funciones
Stack stack_create();
void stack_push(Stack*, Data);
Data stack_pop(Stack*);
bool stack_is_empty(Stack*);
void stack_empty(Stack*);
void stack_print(Stack *);

#endif // __STACK_H__
