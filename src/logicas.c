#include <stdio.h>
#include <string.h>
#include "../include/leitura.h"
#include "../include/controle.h"

void BEQ(Memoria *registrador, Instrucao instrucao[], int *i) {
    int valor_destino, valor_operando1, valor_operando2;

    // Verifica se o destino e o operando1 começam com "R" seguido de número
    if (sscanf(instrucao[*i].destino, "R%d", &valor_destino) == 1 &&
        sscanf(instrucao[*i].operando1, "R%d", &valor_operando1) == 1) {

        // Verifica se os valores em R[valor_destino] e R[valor_operando1] são iguais
        if (registrador->registradores[valor_destino] == registrador->registradores[valor_operando1]) {

            // Verifica se é possível obter um valor de endereço válido a partir de operando2
            if (sscanf(instrucao[*i].operando2, "%d", &valor_operando2) == 1) {
                *i = valor_operando2 - 1;
            }
        }
    }
}

void BLT(Memoria *registrador, Instrucao instrucao[], int *i) {
    int valor,valor_op1,valor_op2;
    //verifica se o destino e o operando1 começam com "R" seguido de numero
    if (sscanf(instrucao[*i].destino, "R%d", &valor) == 1 && sscanf(instrucao[*i].operando1, "R%d", &valor_op1) == 1) {
        //verifica se são iguais
        if (registrador->registradores[valor] < registrador->registradores[valor_op1]) {
            //se as condições foram atendidas, ele recebe o valor de endereço e salta a linha
            if(sscanf(instrucao[*i].operando2, "%d", &valor_op2) == 1) {
                *i = valor_op2 - 1;
            }
        }
    }
}

void JMP(Memoria *registrador, Instrucao instrucao[], int *i) {
    int endereco;
    if(sscanf(instrucao[*i].destino, "%d", &endereco) == 1) {
        registrador->registradores[31] = endereco;
        *i = endereco - 1;
    }
}
