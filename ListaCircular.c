#include "listaCircular.h"

Link cria_node(int item) {
    Link node = (Link)malloc(sizeof(Node));
    node->item = item;
    return node;
}

Link remove_node(Link node) {
    Link proximo = node->next;
    Link anterior = node->prev;

    anterior->next = proximo;
    proximo->prev = anterior;
    return proximo;
}

void imprime_roda(Link node) {
    printf("\n%d ", node->item);
    Link atual = node->next;
    while (node != atual){
        if(atual->next != node){
            printf(", %d ", atual->item);
        } else {
            printf(", %d ", atual->item);
        }
        atual = atual->next;
    }
    printf("\n");
}

Link remove_soldado(Link node, int valor){
    if (valor > 0){
        for (int i = 0; i < valor - 1;i++){
            node = node->next;
        }
    }
    else{
        for (int i = 0; i > valor;i--){
            node = node->prev;
        }
    }
    printf("\nSoldado removido: %d\n", node->item);
    node = remove_node(node);
    return node;
}
