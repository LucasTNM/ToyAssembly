#include <stdio.h>
#include <string.h>
#include "leitura.h"
#include "controle.h"
#include "aritimeticas.h"
#include "logicas.h"
#include "memoria.h"
#include "saida.h"

//aqui inicializamos os registradores a as memórias com 0 
void inicializador(Memoria *mem) {
    //inicializando os registradores com 0
    for (int i = 0; i < 32; i++) {
        mem->registradores[i] = 0; 
    }

    //inicializando a memoria com 0
    for (int i = 0; i < 1000; i++)
    {
        mem->memoria[i] = 0;
    }
    
}

void interpretador(Instrucao input[], int n) {

    //Criamos o ponteiro mem a fim de utilizar em nossas operações
    Memoria mem;
    //inicializamos o ponteiro
    inicializador(&mem);
    
    //loop para verificar todas as instruções
    for(int i = 0; i < n && i < MAX; i++) {
        //armazenando o índice de cada linha 
        input[31].index = i;
        
        //OPERAÇÃO MOV registrador recebe registrador 
        if (strcmp(input[i].operacao, "MOV") == 0) {
            //verifica se a relação é registrador para registrador
            int valor_operando1;
            if (sscanf(input[i].operando1, "R%d", &valor_operando1) == 1) { 
            //MOV2 É A OPERAÇÃO DE REGISTRADOR ATRIBUI REGISTRADOR
            MOV2(&mem, input[i]);
            }
            //se não for, significa que é registrador recebe um inteiro
            else {
                //MOV1 É A OPERAÇÃO REGISTRADOR RECEBE INTEIRO
                MOV1(&mem, input[i]);
            }
        } 
        
        //OPERAÇÃO ADD soma dois numeros de dois registradores e guarda no registrador destino
        else if (strcmp(input[i].operacao, "ADD") == 0) {
            ADD(&mem, input[i]);
        }

        //OPERAÇÃO SUB subtrai o numero do segundo registrador com o do primeiro registrador e guarda no registrador destino
        else if (strcmp(input[i].operacao, "SUB") == 0) {
            SUB(&mem, input[i]);
        }

        //OPERAÇÃO MUL multiplica dois numeros e guarda no registrador destino
        else if (strcmp(input[i].operacao, "MUL") == 0) {
            MUL(&mem, input[i]);
        }
        
        //OPERAÇÃO DIV faz a divisão inteira dos numeros
        else if (strcmp(input[i].operacao, "DIV") == 0) {
            DIV(&mem, input[i]);
        }

        //OPERAÇÃO MOD verifica o resto dos numeros apos a divisão
        else if (strcmp(input[i].operacao, "MOD") == 0) {
            MOD(&mem, input[i]);
        }

        //OPERAÇÃO BEQ verifica se dois registradores são iguais
        else if (strcmp(input[i].operacao, "BEQ") == 0) {
            BEQ(&mem, input, &i);
        }

        //OPERAÇÃO BLT verifica se um registrador é menor que o outro
        else if (strcmp(input[i].operacao, "BLT") == 0) {
            BLT(&mem, input, &i);
        }

        //OPERAÇÃO JUMP pula para um linha definida
        else if (strcmp(input[i].operacao, "JUMP") == 0) {
            JUMP(&mem, input, &i);
        }

        //OPERAÇÃO LOAD carrega um valores de memória para um registrador
        else if (strcmp(input[i].operacao, "LOAD") == 0) {
            LOAD(&mem, input, &i);
        }
        
        //OPERAÇÃO STORE guarda o valor de um registrador em uma posição de memória
        else if (strcmp(input[i].operacao, "STORE") == 0) {
            STORE(&mem, input, &i);
        }

        //OPERAÇÃO PRINT imprime o que estiver em um registrador
        else if (strcmp(input[i].operacao, "PRINT") == 0) {
            PRINT(&mem, input);
        }

        //OPERAÇÃO EXIT termina as operações
        else if (strcmp(input[i].operacao, "EXIT") == 0) {
            exit(0);
        }
    }
    exit(0);
}




