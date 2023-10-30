#ifndef aritimeticas_h
#define aritimeticas_h
#include "../include/aritimeticas.h"

void MOV1 (Memoria *registrador, Instrucao instrucao[], int *i);
void MOV2 (Memoria *registrador, Instrucao instrucao[], int *i);
void ADD (Memoria *registrador, Instrucao instrucao[], int *i);
void SUB (Memoria *registrador, Instrucao instrucao[], int *i);
void MUL (Memoria *registrador, Instrucao instrucao[], int *i);
void DIV (Memoria *registrador, Instrucao instrucao[], int *i);
void MOD (Memoria *registrador, Instrucao instrucao[], int *i);

#endif