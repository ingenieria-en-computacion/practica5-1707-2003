#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Crea una nueva pila vacía y la devuelve.
 * 
 * @param len valor que indica cuantos elementos se pueden guardar en la pila
 * @return Una nueva pila vacía. Si la creación falla, el estado de la cola es inválido.  
 * @details Esta función inicializa una pila vacía. 
 *          Asigna memoria dinámica a data mediante malloc con un número de elementos igual a len
 */
Stack stack_create(int len){
    Stack s;
    
    // Asignar memoria dinámica para 'data' utilizando malloc
    s.data = (Data*) malloc(len * sizeof(Data));  // Asignamos la memoria para el arreglo 'data'

    if (s.data == NULL) {
        printf("Error: No se pudo asignar memoria para la pila.\n");
        s.top = -1;  // Si falla la asignación, la pila no puede contener elementos
    } else {
        s.top = -1;  // Inicializamos el top a -1 para indicar que está vacía
    }
    
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
void stack_push(Stack* s, Data d){
    if (s == NULL || s->data == NULL) {
        return;  // Si la pila o los datos son NULL, no hacemos nada
    }
    
    // Verificamos si la pila está llena
    if (s->top == MAX_SIZE - 1) {  // Si ya hemos alcanzado el tamaño máximo de la pila
        printf("La pila está llena, no se puede insertar más elementos.\n");
        return;
    }
    
    // Añadimos el dato en la parte superior de la pila
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
Data stack_pop(Stack* s){
    Data error_value = -1;  // Valor de error en caso de que la pila esté vacía
    if (s == NULL || s->data == NULL || s->top == -1) {
        return error_value;  // Si la pila es NULL o está vacía, devolvemos el valor de error
    }
    
    // Extraemos el dato que está en la parte superior de la pila
    Data top = s->data[s->top];
    s->top--;  // Reducimos el top para eliminar el elemento superior
    
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
int stack_is_empty(Stack* s){
    if (s == NULL || s->data == NULL) {
        return -1;  // Si la pila o los datos son NULL, devolvemos -1
    }
    
    return s->top == -1 ? 1 : 0;  // Si el top es -1, la pila está vacía
}

/**
 * Vacía la pila, eliminando todos sus elementos.
 * 
 * @param s Referencia a la pila que se desea vaciar.
 * @details Esta función hace que top sea igual a -1
 */
void stack_empty(Stack* s){
    if (s == NULL || s->data == NULL) {
        return;  // Si la pila o los datos son NULL, no hacemos nada
    }
    
    s->top = -1;  // Vaciamos la pila
}

/**
 * Elimina data y libera la memoria asociada.
 * 
 * @param s Referencia a la pila que se desea liberar la memoria de data
 * @details Esta función libera la memoria asignada dinámicamente para data dentro de la pila
 */
void stack_delete(Stack* s){
    if (s == NULL || s->data == NULL) {
        return;  // Si la pila o los datos son NULL, no hacemos nada
    }
    
    free(s->data);  // Liberamos la memoria dinámica de 'data'
    s->data = NULL;  // Ponemos el puntero a NULL para evitar accesos futuros incorrectos
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
void stack_print(Stack* s){
    if (s == NULL || s->data == NULL || s->top == -1) {
        printf("La pila está vacía o es inválida.\n");
        return;
    }
    
    // Imprimimos los elementos de la pila desde el top hacia abajo
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}
