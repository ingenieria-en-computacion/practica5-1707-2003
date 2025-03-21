#include "stack.h"
#include <stdlib.h>

/**
 * Crea una nueva pila vacía y la devuelve.
 * 
 * @return Una nueva pila vacía. Si la creación falla, el estado de la cola es inválido.
 * @details Esta función inicializa una pila vacía.
 */
Stack stack_create() {
    Stack s;
    s.top = -1;  // Inicializa el top de la pila a -1 para indicar que está vacía
    return s;
}

/**
 * Inserta un elemento en la parte superior de la pila.
 * 
 * @param s Referencia a la pila donde se insertará el elemento.
 * @param d Dato que se insertará en la pila.
 * @details Esta función añade el dato `d` en la parte superior de la pila. Si la pila está llena, 
 *          la función no realiza ninguna operación.
 */
void stack_push(Stack* s, Data d) {
    if (s == NULL) {
        return;  // Si el puntero a la pila es NULL, no hacemos nada
    }
    
    // Verificamos si la pila está llena, si lo está no podemos insertar más elementos
    if (s->top == MAX_SIZE - 1) {
        return;
    }

    // Incrementamos el top y añadimos el dato en la nueva posición
    s->top++;
    s->data[s->top] = d;
}

/**
 * Elimina y devuelve el elemento en la parte superior de la pila.
 * 
 * @param s Referencia a la pila de la cual se eliminará el elemento.
 * @return El dato que estaba en la parte superior de la pila. Si la pila está vacía 
 *         devuelve un valor que indica error (por ejemplo, -1 o un valor predeterminado).
 * @details Esta función elimina el elemento en la parte superior de la pila y lo devuelve.
 *          Si la pila está vacía, no se realiza ninguna operación y se devuelve un valor de error.
 */
Data stack_pop(Stack* s) {
    Data error_value;  // Valor de error, puede ser un valor predeterminado
    if (s == NULL || stack_is_empty(s)) {
        return error_value;  // Si la pila es NULL o está vacía, devolvemos un valor de error
    }

    // Extraemos el dato en la parte superior de la pila
    Data top = s->data[s->top];
    s->top--;  // Reducimos el top de la pila

    return top;
}

/**
 * Verifica si la pila está vacía.
 * 
 * @param s Referencia a la pila que se desea verificar.
 * @return 1 si la pila está vacía, 0 si no lo está. Si el puntero `s` es NULL, devuelve -1.
 * @details Esta función comprueba si la pila no contiene elementos. Es útil para evitar operaciones
 *          como `stack_pop` en una pila vacía.
 */
int stack_is_empty(Stack* s) {
    if (s == NULL) {
        return -1;  // Si la pila es NULL, devolvemos -1
    }

    return s->top == -1 ? 1 : 0;  // Si top es -1, la pila está vacía
}

/**
 * Vacía la pila, eliminando todos sus elementos.
 * 
 * @param s Referencia a la pila que se desea vaciar.
 * @details Esta función hace que top sea igual a -1
 */
void stack_empty(Stack* s) {
    if (s == NULL) {
        return;
    }

    s->top = -1;  // Restablecemos el top a -1 para vaciar la pila
}

/**
 * Imprime los elementos de la pila.
 * 
 * @param s Referencia a la pila que se desea imprimir.
 * @details Esta función imprime los elementos de la pila en orden, desde la parte superior
 *          hasta la base. Si la pila está vacía la función imprime
 *          un mensaje indicando que la pila está vacía o es inválida. La salida se dirige a
 *          la salida estándar (stdout).
 */
void stack_print(Stack *s) {
    if (s == NULL || stack_is_empty(s)) {
        printf("La pila está vacía o es inválida.\n");
        return;
    }

    // Imprime los elementos desde el top hasta la base de la pila
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}
