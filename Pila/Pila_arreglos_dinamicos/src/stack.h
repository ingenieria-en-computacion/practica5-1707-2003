#ifndef __STACK_H__
#define __STACK_H__
#include <stdbool.h>

// Definimos el tamaño máximo de la pila
#define MAX_SIZE 100  // Puedes cambiar este valor si necesitas un tamaño diferente

typedef int Data;

typedef struct {
    Data *data;
    int top;
} Stack;

Stack stack_create(int);
void stack_push(Stack*, Data);
Data stack_pop(Stack*);
bool stack_is_empty(Stack*);
void stack_delete(Stack *);
void stack_empty(Stack*);
void stack_print(Stack *);

#endif // __STACK_H__
