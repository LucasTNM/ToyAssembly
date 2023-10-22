#include <stdio.h>
#include <string.h>
#include "leitura.h"
#include "controle.h"

void PRINT(Memoria *registrador, Instrucao instrucao[]) {
    int valor;
    if(sscanf(instrucao->destino, "R%d", &valor) == 1) {
        valor = registrador->registradores[valor];
        printf("%d\n", valor);
    }
}