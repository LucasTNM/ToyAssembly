#ifndef aritimeticas_h
#define aritimeticas_h
#include "controle.h"

void MOV1 (Memoria *registrador, Instrucao instrucao);
void MOV2 (Memoria *registrador, Instrucao instrucao);
void ADD (Memoria *registrador, Instrucao instrucao);
void SUB (Memoria *registrador, Instrucao instrucao);
void MUL (Memoria *registrador, Instrucao instrucao);
void DIV (Memoria *registrador, Instrucao instrucao);
void MOD (Memoria *registrador, Instrucao instrucao);

#endif