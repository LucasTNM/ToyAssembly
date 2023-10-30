#include <stdio.h>
#include <string.h>
#include "../include/leitura.h"
#include "../include/controle.h"

#define MAX 100000

//função de leitura das operações 
void leitura(Instrucao input[MAX], int *n) {
    //le a quantidade de instruções
    scanf("%d", n);
    //laço de repetição para armazenar as instruções separadamente
    for(int i = 0; i < *n; i++) {
        scanf("%s", input[i].operacao);
        if(strcmp(input[i].operacao, "EXIT") == 0) {
            continue;
        }
        else if(strcmp(input[i].operacao, "PRINT") == 0 || strcmp(input[i].operacao, "JMP" ) == 0) {
            scanf("%s", input[i].destino);
        }
        else if(strcmp(input[i].operacao, "MOV") == 0 || strcmp(input[i].operacao, "LOAD") == 0 || strcmp(input[i].operacao, "STORE")== 0) {
            scanf("%s %s", input[i].destino, input[i].operando1);
        }
        else {
            scanf("%s %s %s",input[i].destino, input[i].operando1, input[i].operando2);
        }    
    }   
}

    