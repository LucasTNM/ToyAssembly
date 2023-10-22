#include <stdio.h>
#include <string.h>
#include "leitura.h"
#include "controle.h"

#define MAX 100000

//função de leitura das operações 
void leitura(Instrucao input[MAX], int *n) {
    //le a quantidade de instruções
    scanf("%d",n);
    //laço de repetição para armazenar as instruções separadamente
    for(int i = 0; i < *n && i < MAX; i++) {
        scanf("%s %s %s %s", input[i].operacao, input[i].destino, input[i].operando1, input[i].operando2);
        
        //aqui é armazenado o índice de cada operação
        input[i].index = i;
    }   
}
    