#include <stdio.h>
#include <string.h>
#include "../include/leitura.h"
#include "../include/controle.h"

void PRINT(Memoria *registrador, Instrucao instrucao[], int *i) {
    int valor;
    if(sscanf(instrucao[*i].destino, "R%d", &valor) == 1) {
        valor = registrador->registradores[valor];
        printf("%i\n", valor);
    }
}
