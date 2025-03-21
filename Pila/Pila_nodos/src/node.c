#include "node.h"
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
 *          proporcionado en el parámetro `d`, el siguiente .
 */
Node *new_node(Data d){
    // Asignar memoria dinámicamente para un nuevo nodo
    Node* new_n = (Node*) malloc(sizeof(Node));

    if (new_n == NULL) {
        return NULL;  // Si no se pudo asignar memoria, devolver NULL
    }

    new_n->data = d;  // Establecer el dato proporcionado en el nodo
    new_n->next = NULL;  // El siguiente nodo es NULL, ya que es el último nodo

    return new_n;
}

/**
 * Elimina un nodo y libera la memoria asociada a él.
 * 
 * @param n Apuntador al nodo que se desea eliminar.
 * @details Esta función libera la memoria asignada dinámicamente para el nodo utilizando `free`.
 *          Si el apuntador pasado es NULL, la función no realiza ninguna operación.
 *          Es responsabilidad del llamante asegurarse de que el nodo ya no se utiliza después
 *          de ser eliminado. Está función solo libera nodos cuyo enlace al siguiente es nulo
 */
void delete_node(Node* n){
    if (n != NULL) {
        free(n);  // Liberar la memoria del nodo
    }
}

/**
 * Imprime la información contenida en un nodo.
 * 
 * @param n Apuntador al nodo que se desea imprimir.
 * @details Esta función imprime los campos del nodo, como su valor y punteros a otros nodos,
 *          en un formato legible. Si el puntero pasado es NULL, la función imprime un mensaje
 *          indicando que el nodo es inválido. La salida se dirige a la salida estándar (stdout).
 */
void print_node(Node* n){
    if (n == NULL) {
        printf("Nodo inválido.\n");
    } else {
        printf("Dato: %d\n", n->data);  // Imprimir el dato almacenado en el nodo
        printf("Siguiente: %p\n", (void*)n->next);  // Imprimir la dirección del siguiente nodo (NULL si es el último)
    }
}
