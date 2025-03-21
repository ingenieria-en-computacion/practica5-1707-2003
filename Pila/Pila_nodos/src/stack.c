#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Crea un nuevo nodo con los datos proporcionados y lo devuelve.
 * 
 * @param d Dato que se almacenará en el nuevo nodo.
 * @return Un apuntador al nuevo nodo creado. Si la creación falla, devuelve NULL.
 * @details Esta función asigna memoria dinámicamente para un nuevo nodo utilizando `malloc`.
 *          Si la asignación de memoria falla, la función devuelve NULL. El nodo creado
 *          tiene sus campos inicializados, y el campo de datos se establece con el valor
 *          proporcionado en el parámetro `d`, el siguiente nodo se inicializa a NULL.
 */
Node* new_node(Data d) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        return NULL;  // Si no se puede asignar memoria, devolver NULL
    }

    newNode->data = d;  // Asignar el dato al nodo
    newNode->next = NULL;  // Inicializar el siguiente puntero a NULL

    return newNode;  // Devolver el nodo recién creado
}

/**
 * Crea una nueva pila vacía y la devuelve.
 * 
 * @return Un apuntador a la nueva pila creada. Si la creación falla, devuelve NULL.
 * @details Esta función asigna memoria dinámicamente para una nueva pila utilizando `malloc`.
 *          Si la asignación de memoria falla, la función devuelve NULL. La pila creada
 *          está vacía y top apunta a NULL.
 */
Stack* stack_create(){
    // Asignar memoria dinámica para la pila
    Stack* s = (Stack*) malloc(sizeof(Stack));

    if (s == NULL) {
        return NULL;  // Si no se pudo asignar memoria, devolver NULL
    }

    s->top = NULL;  // Inicializar la pila vacía (top es NULL)

    return s;
}

/**
 * Inserta un elemento en la parte superior de la pila.
 * 
 * @param s Apuntador a la pila donde se insertará el elemento.
 * @param d Dato que se insertará en la pila.
 * @details Esta función añade el dato `d` en la parte superior de la pila. Si la pila está llena
 *          o el puntero `s` es NULL, la función no realiza ninguna operación.
 */
void stack_push(Stack* s, Data d){
    if (s == NULL) {
        return;  // Si la pila es NULL, no hacer nada
    }

    // Crear un nuevo nodo para el elemento a insertar
    Node* newNode = new_node(d);  // Usamos la función new_node para crear un nuevo nodo

    if (newNode == NULL) {
        return;  // Si no se pudo crear el nodo, no hacer nada
    }

    // Insertar el nuevo nodo en la parte superior de la pila
    newNode->next = s->top;  // El siguiente de nuevo nodo será el antiguo top
    s->top = newNode;  // El nuevo nodo se convierte en el top de la pila
}

/**
 * Elimina y devuelve el elemento en la parte superior de la pila.
 * 
 * @param s Apuntador a la pila de la cual se eliminará el elemento.
 * @return El dato que estaba en la parte superior de la pila. Si la pila está vacía o el puntero
 *         `s` es NULL, devuelve un valor que indica error (por ejemplo, -1 o un valor predeterminado).
 * @details Esta función elimina el elemento en la parte superior de la pila y lo devuelve.
 *          Si la pila está vacía, no se realiza ninguna operación y se devuelve un valor de error.
 */
Data stack_pop(Stack* s){
    if (s == NULL || s->top == NULL) {
        return -1;  // Si la pila es NULL o está vacía, devolver error (-1)
    }

    // Extraer el dato que está en la parte superior de la pila
    Node* temp = s->top;  // Apuntador al nodo superior
    Data top_data = temp->data;  // Obtener el dato del nodo superior

    s->top = s->top->next;  // Mover el top al siguiente nodo
    delete_node(temp);  // Eliminar el nodo superior y liberar la memoria

    return top_data;  // Devolver el dato extraído
}

/**
 * Verifica si la pila está vacía.
 * 
 * @param s Apuntador a la pila que se desea verificar.
 * @return 1 si la pila está vacía, 0 si no lo está. Si el puntero `s` es NULL, devuelve -1.
 * @details Esta función comprueba si la pila no contiene elementos. Es útil para evitar operaciones
 *          como `stack_pop` en una pila vacía.
 */
int stack_is_empty(Stack* s){
    if (s == NULL) {
        return -1;  // Si la pila es NULL, devolver -1
    }

    return s->top == NULL ? 1 : 0;  // Si top es NULL, la pila está vacía
}

/**
 * Vacía la pila, eliminando todos sus elementos.
 * 
 * @param s Apuntador a la pila que se desea vaciar.
 * @details Esta función elimina todos los elementos de la pila, dejándola vacía.
 *          Si el puntero `s` es NULL, la función no realiza ninguna operación.
 *          La memoria de los elementos eliminados se libera adecuadamente.
 */
void stack_empty(Stack* s){
    if (s == NULL) {
        return;  // Si la pila es NULL, no hacer nada
    }

    // Vaciar la pila eliminando todos los nodos
    while (s->top != NULL) {
        stack_pop(s);  // Eliminar y liberar el nodo superior hasta que la pila esté vacía
    }
}

/**
 * Elimina la pila y libera la memoria asociada a ella.
 * 
 * @param s Apuntador a la pila que se desea eliminar.
 * @details Esta función libera la memoria asignada dinámicamente para la pila y todos sus elementos
 *          utilizando `free`. Si el puntero pasado es NULL, la función no realiza ninguna operación.
 *          Es responsabilidad del llamante asegurarse de que la pila ya no se utiliza después
 *          de ser eliminada.
 */
void stack_delete(Stack *s){
    if (s == NULL) {
        return;  // Si la pila es NULL, no hacer nada
    }

    stack_empty(s);  // Vaciar la pila eliminando todos los elementos

    free(s);  // Liberar la memoria de la pila
}

/**
 * Imprime los elementos de la pila.
 * 
 * @param s Apuntador a la pila que se desea imprimir.
 * @details Esta función imprime los elementos de la pila en orden, desde la parte superior
 *          hasta la base. Si la pila está vacía o el puntero `s` es NULL, la función imprime
 *          un mensaje indicando que la pila está vacía o es inválida. La salida se dirige a
 *          la salida estándar (stdout).
 */
void stack_print(Stack *s){
    if (s == NULL || s->top == NULL) {
        printf("La pila está vacía o es inválida.\n");
        return;  // Si la pila es NULL o vacía, no imprimir nada
    }

    Node* current = s->top;  // Apuntador al nodo superior
    while (current != NULL) {
        printf("%d ", current->data);  // Imprimir el dato del nodo
        current = current->next;  // Mover al siguiente nodo
    }
    printf("\n");
}
