#include <stdio.h>
#include <stdlib.h>

typedef struct node *Link;
typedef struct node {
    int item;
    Link next;
    Link prev;
} Node;

// Cria node para lista
Link cria_node(int item);

// Remove node
Link remove_node(Link node);

// Imprime a lista
void imprime_roda(Link node);

// Deleta soldado pelo sua posição na fila
Link remove_soldado(Link node, int valor);
