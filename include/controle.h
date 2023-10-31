#ifndef controle_h
#define controle_h
#define MAX 100000
#define NUM_REGISTRADORES 32
#define MAX_MEMORIA 1000

typedef struct {
    char operacao[6];
    char destino[6];
    char operando1[20];
    char operando2[20];
    int index;
} Instrucao;

typedef struct {
    int registradores[NUM_REGISTRADORES];
    int memoria[MAX_MEMORIA];
} Memoria;

void inicializador(Memoria *mem);
void interpretador(Instrucao input[], int n);

#endif