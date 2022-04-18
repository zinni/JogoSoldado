#include "utils.h"

void mudar_cor(int cor){

    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, cor);
}

void cor_padrao(){

    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7);

}

void imprime_erro(char erro[MSG_SIZE]) {

    mudar_cor(4);
    printf("\n%s\n", erro);
}

void imprime_sucesso(char sucesso[MSG_SIZE]) {

    mudar_cor(10);
    printf("\n%s\n", sucesso);
    cor_padrao();
}

void aperte_enter(){

    mudar_cor(8);
    printf("\nPressione ENTER para continuar.");
    getchar();
    cor_padrao();
}
