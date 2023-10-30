#include <stdio.h>
#include <string.h>
#include "../include/leitura.h"
#include "../include/controle.h"
#include <stdlib.h>

//A função MOV1 atribuirá um número a um registrador
void MOV1(Memoria *registrador, Instrucao instrucao[], int *i) {
    int valor;
    //checagem para saber se é um registrador, se sim, efetuo a atribuição do numero no registrador
    if (sscanf(instrucao[*i].destino, "R%d", &valor) == 1) {
        registrador->registradores[valor] = atoi(instrucao[*i].operando1);
    }
}


//A função MOV2 atribuirá um registrador a outro registrador
void MOV2(Memoria *registrador, Instrucao instrucao[], int *i) {
    int valor_destino, valor_op1;
    //aqui ocorre a checagem para saber se estou lidando com 2 registradores, se sim, realizo a operação de atribuição
    if (sscanf(instrucao[*i].destino, "R%d", &valor_destino) == 1 && sscanf(instrucao[*i].operando1, "R%d", &valor_op1) == 1) {
        registrador->registradores[valor_destino] = registrador->registradores[valor_op1];
    }
}

//A função ADD soma dois registradores e guarda o resultado
void ADD(Memoria *registrador, Instrucao instrucao[], int *i) {
    int destino, operando1, operando2;

    if (sscanf(instrucao[*i].destino, "R%d", &destino) == 1 &&
        sscanf(instrucao[*i].operando1, "R%d", &operando1) == 1 &&
        sscanf(instrucao[*i].operando2, "R%d", &operando2) == 1) {
        registrador->registradores[destino] = registrador->registradores[operando1] + registrador->registradores[operando2];
    }
}

//A função SUB subtrai dois números e guarda o resultado
void SUB(Memoria *registrador, Instrucao instrucao[], int *i) {
    int destino, operando1, operando2;
    //verifica se o destino, operando1 e operando2 começam com "R" seguido de numero
    if (sscanf(instrucao[*i].destino, "R%d", &destino) == 1 &&
        sscanf(instrucao[*i].operando1, "R%d", &operando1) == 1 &&
        sscanf(instrucao[*i].operando2, "R%d", &operando2) == 1) {
        //faz a operação de subtração de dois operadores
        registrador->registradores[destino] = registrador->registradores[operando2] - registrador->registradores[operando1];
    }
}

//A função MUL multiplica dois números e guarda o resultado 
void MUL(Memoria *registrador, Instrucao instrucao[], int *i) {
    int destino, operando1, operando2;
    //verifica se o destino, operando1 e operando2 começam com "R" seguido de numero
    if (sscanf(instrucao[*i].destino, "R%d", &destino) == 1 &&
        sscanf(instrucao[*i].operando1, "R%d", &operando1) == 1 &&
        sscanf(instrucao[*i].operando2, "R%d", &operando2) == 1) {
        //faz a operação de multiplicação
        registrador->registradores[destino] = registrador->registradores[operando1] * registrador->registradores[operando2];
    }
}

//A função DIV divide dois números e guarda o resultado
void DIV(Memoria *registrador, Instrucao instrucao[], int *i) {
    int destino, operando1, operando2;
    //verifica se o destino, operando1 e operando2 começam com "R" seguido de numero
    if (sscanf(instrucao[*i].destino, "R%d", &destino) == 1 &&
        sscanf(instrucao[*i].operando1, "R%d", &operando1) == 1 &&
        sscanf(instrucao[*i].operando2, "R%d", &operando2) == 1) {
        //faz a operação de divisão entre dois operadores
        registrador->registradores[destino] = registrador->registradores[operando1] / registrador->registradores[operando2];
    }
}

//A função MOD guarda o resto da operação de divisão
void MOD(Memoria *registrador, Instrucao instrucao[], int *i) {
    int destino, operando1, operando2;
    // Verifica se o destino, operando1 e operando2 começam com "R" seguido de um número
    if (sscanf(instrucao[*i].destino, "R%d", &destino) == 1 &&
        sscanf(instrucao[*i].operando1, "R%d", &operando1) == 1 &&
        sscanf(instrucao[*i].operando2, "R%d", &operando2) == 1) {
        // Calcula o operador de módulo com valor absoluto dos operandos
        int resultado = registrador->registradores[operando1] % registrador->registradores[operando2];
        if(resultado < 0) {
        registrador->registradores[destino] = resultado + registrador->registradores[operando2];
        }
        else {
            registrador->registradores[destino] = resultado;
        }
    }
}
