#include <stdio.h>
#include "jogo.h"

int qtd_soldados;
int passos_remover ;
int item_escolhido;

Link cria_roda(int qtd_soldados) {
    Link primeiro = cria_node(1);
    Link anterior = primeiro;
    for (int i = 2; i <= qtd_soldados; i++) {
        Link atual = cria_node(i);
        anterior->next = atual;
        atual->prev = anterior;
        anterior = atual;
    }
    anterior->next = primeiro;
    primeiro->prev = anterior;
    return primeiro;
}

int menuPrincipal(){

    int opcao;
    system("cls");

    printf("\n\n               JOGO DOS SOLDADOS");
    printf("\n-------------------------------------------------");
    printf("\n\n\t1. Defina a quantidade de soldados.");
    printf("\n\t2. Defina o intervalo de contagem.");
    printf("\n\t3. Defina sua posi��o na fila.");
    printf("\n\t4. Roda o jogo passo a passo.");
    printf("\n\t5. Mostra resultado final.");
    printf("\n\t0. Sair do programa.");
    printf("\n\nEntre com a op��o desejada: ");
    scanf("%d", &opcao);
    return opcao;
}

void menu_principal(void) {

    int opcao_menu = -1;
    while (opcao_menu != 0) {
        opcao_menu = menuPrincipal();
        switch(opcao_menu) {
            case 1:
                printf("\nQuantos soldados? ");
                scanf("%d", &qtd_soldados);
                break;
            case 2:
                printf("\nQual a intervalo? ");
                scanf("%d", &passos_remover);
                break;
            case 3:
                printf("\nQual a sua posi��o na fila? ");
                scanf("%d", &item_escolhido);
                break;
            case 4:
                roda_passos(qtd_soldados, passos_remover, item_escolhido);
                break;
            case 5:
                roda_final(qtd_soldados, passos_remover, item_escolhido);
                break;
            case 0:
                printf("\n\n\nSaindo...\n\n");
                exit(0);
                break;
            default:
                printf("ESCOLHA INV�LIDA TENTE NOVAMENTE.");
                aperte_enter();
                break;
        }
    }
}

void roda_passos(int qtd_soldados, int passos_remover, int item_escolhido){
    Link node = cria_roda(qtd_soldados);
        system("cls");
        printf("\n\n   JOGO INICIADO COM OS SEGUINTES N�MEROS");
        printf("\n-------------------------------------------------");
        printf("\nTotal de soldados: %d", qtd_soldados);
        printf("\nQuantos passos para remover: %d", passos_remover);
        printf("\nSua posi��o da sorter �: %d\n", item_escolhido);
        getchar();
        aperte_enter();
    while(node != node->next) {
        system("cls");
        node = remove_soldado(node, passos_remover);
        imprime_roda(node);
        aperte_enter();
    }
    if(node->item == item_escolhido) {
        system("cls");
        imprime_sucesso("\n\nParab�ns! Voc� se salvou!\n");
        aperte_enter();
    } else {
        system("cls");
        imprime_erro("\n\nMelhor sorte na pr�xima vez! =(\n");
        aperte_enter();
    }
}

void roda_final(int qtd_soldados, int passos_remover, int item_escolhido){
    Link node = cria_roda(qtd_soldados);
    while(node != node->next) {
        node = remove_soldado(node, passos_remover);
        system("cls");
    }
    if(node->item == item_escolhido) {
        system("cls");
        imprime_sucesso("\n\nParab�ns! Voc� se salvou!\n");
        aperte_enter();
    } else {
        imprime_erro("\n\nMelhor sorte na pr�xima vez! =(\n");
        aperte_enter();
    }
}