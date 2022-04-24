#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "listaCircular.h"
#include "utils.h"

//Inicializa a roda com o numero de soldados escolhido
Link cria_roda(int qtd_soldados);

//Estrutura de texto do menu
int menuPrincipal();

//Estrutura lógica do menu
void menu_principal(void);

//Roda o jogo passo a passo com confirmação do usuário
void roda_passos(int qtd_soldados, int passos_remover, int item_escolhido);

//Roda o jogo automaticamente e mostra apenas o resultado final
void roda_final(int qtd_soldados, int passos_remover, int item_escolhido);
