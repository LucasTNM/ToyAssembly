#include <stdio.h>
#include <string.h>
#include "../include/leitura.h"
#include "../include/controle.h"

void LOAD(Memoria *registrador, Instrucao instrucao[], int *i) {
    int endereco, mem;
    //verifica se a string começa com "R" e algum número
    if (sscanf(instrucao[*i].destino, "R%d", &endereco) == 1) {
        //obtem o  a posição da memoria que deve ser carregada
        if(sscanf(instrucao[*i].operando1, "R%d", &mem) == 1) {
            //carrega o conteudo de memória para um registrador
            registrador->registradores[endereco] = registrador->memoria[mem];
        }
    }
}

void STORE(Memoria *registrador, Instrucao instrucao[], int *i) {
    int endereco, mem;
    //verifica se a string começa com "R" e algum número
    if (sscanf(instrucao[*i].destino, "R%d", &endereco) == 1) {
        //obtem o  a posição da memoria que deve ser carregada
        if(sscanf(instrucao[*i].operando1, "R%d", &mem) == 1) {
            //carrega o conteudo de um registrador para uma posição de memória
            registrador->memoria[mem] = registrador->registradores[endereco];
        }
    }
}
