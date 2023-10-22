#ifndef logicas_h
#define logicas_h

#include "controle.h"

void BEQ(Memoria *registrador, Instrucao instrucao[], int *i);
void BLT(Memoria *registrador, Instrucao instrucao[], int *i);
void JMP(Memoria *registrador, Instrucao instrucao[], int *i);

#endif