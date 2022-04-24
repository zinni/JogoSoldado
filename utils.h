#define MSG_SIZE 256
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

//Muda a cor por parametro.
void mudar_cor(int cor);

//Volta para cor padr�o do console
void cor_padrao();

//Formata��o padr�o das mensagens de erro
void imprime_erro(char erro[MSG_SIZE]);

//Formata��o padr�o das mensagens de sucesso
void imprime_sucesso(char sucesso[MSG_SIZE]);

//Mensagem padr�o para congelamento de tela
void aperte_enter();
