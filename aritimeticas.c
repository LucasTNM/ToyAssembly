#include <stdio.h>
#include <string.h>
#include "leitura.h"
#include "controle.h"

//A função MOV1 atribuirá um número a um registrador
void MOV1(Memoria *registrador, Instrucao instrucao) {
    int valor;
    //checagem para saber se é um registrador, se sim, efetuo a atribuição do numero no registrador
    if (sscanf(instrucao.destino, "R%d", &valor) == 1) {
        registrador->registradores[valor] = atoi(instrucao.operando2); 
    }
}

//A função MOV2 atribuirá um registrador a outro registrador 
void MOV2(Memoria *registrador, Instrucao instrucao) {
    int valor_destino, valor_op1;
    //aqui ocorre a checagem para saber se estou lidando com 2 registradores, se sim, realizo a operação de atribuição
    if (sscanf(instrucao.destino, "R%d", &valor_destino) == 1 && sscanf(instrucao.operando1, "R%d", &valor_op1) == 1) {
        registrador->registradores[valor_destino] = registrador->registradores[valor_op1];
    }
}

void ADD(Memoria *registrador, Instrucao instrucao){
    int valor,valor_op1,valor_op2;
    //verifica se o destino, operando1 e operando2 começam com "R" seguido de numero
    if (sscanf(instrucao.destino, "R%d", &valor) == 1 && sscanf(instrucao.operando1, "R%d", &valor_op1) == 1 && sscanf(instrucao.operando2, "R%d", &valor_op1) == 1) {
        //transforma as strings em inteiro
        int op1 = atoi(instrucao.operando1);
        int op2 = atoi(instrucao.operando2);
        //realiza a soma 
        registrador->registradores[valor] = op1 + op2;
    }
}

void SUB(Memoria *registrador, Instrucao instrucao) {
    int valor,valor_op1,valor_op2;
    //verifica se o destino, operando1 e operando2 começam com "R" seguido de numero
    if (sscanf(instrucao.destino, "R%d", &valor) == 1 && sscanf(instrucao.operando1, "R%d", &valor_op1) == 1 && sscanf(instrucao.operando2, "R%d", &valor_op1) == 1) {
        //transforma as strings em inteiro
        int op1 = atoi(instrucao.operando1);
        int op2 = atoi(instrucao.operando2);
        //realiza a subitração
        registrador->registradores[valor] = op2 - op1;
    }
}

void MUL(Memoria *registrador, Instrucao instrucao) {
    int valor,valor_op1,valor_op2;
    //verifica se o destino, operando1 e operando2 começam com "R" seguido de numero
    if (sscanf(instrucao.destino, "R%d", &valor) == 1 && sscanf(instrucao.operando1, "R%d", &valor_op1) == 1 && sscanf(instrucao.operando2, "R%d", &valor_op1) == 1) {
        //transforma as strings em inteiro
        int op1 = atoi(instrucao.operando1);
        int op2 = atoi(instrucao.operando2);
        //realiza a multiplicação
        registrador->registradores[valor] = op1 * op2;
    }
}

void DIV(Memoria *registrador, Instrucao instrucao) {
    int valor,valor_op1,valor_op2;
    //verifica se o destino, operando1 e operando2 começam com "R" seguido de numero
    if (sscanf(instrucao.destino, "R%d", &valor) == 1 && sscanf(instrucao.operando1, "R%d", &valor_op1) == 1 && sscanf(instrucao.operando2, "R%d", &valor_op1) == 1) {
        //transforma as strings em inteiro
        int op1 = atoi(instrucao.operando1);
        int op2 = atoi(instrucao.operando2);
        //se op2 diferente de zero, realiza a divisão
        if (op2 != 0) {
            registrador->registradores[valor] = op1 / op2;
        }
    }
}

void MOD(Memoria *registrador, Instrucao instrucao) {
    int valor,valor_op1,valor_op2;
    //verifica se o destino, operando1 e operando2 começam com "R" seguido de numero
    if (sscanf(instrucao.destino, "R%d", &valor) == 1 && sscanf(instrucao.operando1, "R%d", &valor_op1) == 1 && sscanf(instrucao.operando2, "R%d", &valor_op1) == 1) {
        //transforma as strings em inteiro
        int op1 = atoi(instrucao.operando1);
        int op2 = atoi(instrucao.operando2);
        //se op2 é diferente de zero, realiza a verificação do resto da divisão
        if (op2 != 0) {
            registrador->registradores[valor] = op1 % op2;
        }
    }
}