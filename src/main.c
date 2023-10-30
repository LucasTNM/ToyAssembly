#include <stdio.h>
#include "../include/leitura.h"
#include "../include/controle.h"
#include "../include/aritimeticas.h"
#include "../include/logicas.h"
#include "../include/memoria.h"
#include "../include/saida.h"

#define MAX 100000

int main (void) {
    int n;
    Instrucao input[MAX];

    leitura(input, &n);
    interpretador(input, n);

    return 0;
}
