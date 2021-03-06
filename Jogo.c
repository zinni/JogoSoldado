#include "jogo.h"

int qtd_soldados;
int passos_remover;
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

    mudar_cor(1);
    printf("\n\n               JOGO DOS SOLDADOS");
    printf("\n-------------------------------------------------");
    mudar_cor(11);
    printf("\n\n\t1. Defina a quantidade de soldados.");
    printf("\n\t2. Defina o intervalo de contagem.");
    printf("\n\t3. Defina sua posi??o na fila.");
    printf("\n\t4. Roda o jogo passo a passo.");
    printf("\n\t5. Mostra resultado final.");
    printf("\n\t0. Sair do programa.");
    mudar_cor(3);
    printf("\n\n\tEntre com a op??o desejada: ");
    scanf("%d", &opcao);
    return opcao;
}

void menu_principal(void) {

    int opcao_menu = -1;
    while (opcao_menu != 0) {
        opcao_menu = menuPrincipal();
        switch(opcao_menu) {
            case 1:
                printf("\n\tQuantos soldados? ");
                scanf("%d", &qtd_soldados);
                break;
            case 2:
                printf("\n\tQual a intervalo? ");
                scanf("%d", &passos_remover);
                break;
            case 3:
                printf("\n\tQual a sua posi??o na fila? ");
                scanf("%d", &item_escolhido);
                break;
            case 4:
                roda_passos(qtd_soldados, passos_remover, item_escolhido);
                break;
            case 5:
                roda_final(qtd_soldados, passos_remover, item_escolhido);
                break;
            case 0:
                printf("\n\n\n\tSaindo...\n\n");
                exit(0);
                break;
            default:
                imprime_erro("\tESCOLHA INV?LIDA TENTE NOVAMENTE.");
                getchar();
                aperte_enter();
                break;
        }
    }
}

void roda_passos(int qtd_soldados, int passos_remover, int item_escolhido){
    Link node = cria_roda(qtd_soldados);
        system("cls");
        mudar_cor(1);
        printf("\n\n   JOGO INICIADO COM OS SEGUINTES N?MEROS");
        printf("\n-------------------------------------------------");
        mudar_cor(11);
        printf("\n\n\tTotal de soldados: %d", qtd_soldados);
        printf("\n\tQuantos passos para remover: %d", passos_remover);
        printf("\n\tSua posi??o da sorte ?: %d\n\n", item_escolhido);
        getchar();
        aperte_enter();
    while(node != node->next) {
        system("cls");
        mudar_cor(11);
        node = remove_soldado(node, passos_remover);
        imprime_roda(node);
        aperte_enter();
    }
    if(node->item == item_escolhido) {
        system("cls");
        imprime_sucesso("\n\n\tParab?ns! Voc? se salvou!\n");
        aperte_enter();
    } else {
        system("cls");
        imprime_erro("\n\n\tMelhor sorte na pr?xima vez! =(\n");
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
        imprime_sucesso("\n\n\tParab?ns! Voc? se salvou!\n");
        getchar();
        aperte_enter();
    } else {
        imprime_erro("\n\n\tMelhor sorte na pr?xima vez! =(\n");
        getchar();
        aperte_enter();
    }
}
