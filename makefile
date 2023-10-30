# Compilador
CC = gcc

# Opções de compilação
CFLAGS = -Wall -g

ODIR = ./src
IDIR = ./include
OBJDIR = objects
BINDIR = bin

# Lista de arquivos-fonte
SOURCES = $(wildcard $(ODIR)/*.c)

# Lista de arquivos-objetos (gerados a partir dos arquivos-fonte)
OBJECTS = $(patsubst $(ODIR)/%.c, $(OBJDIR)/%.o, $(SOURCES))

all: binfolder objfolder bin/main

# Regra padrão para compilar o executável
bin/main: $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

binfolder:
	mkdir -p $(BINDIR)

objfolder:
	mkdir -p $(OBJDIR)

# Regras para compilar cada arquivo-fonte em um arquivo-objeto
$(OBJDIR)/%.o: $(ODIR)/%.c $(IDIR)/%.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/main.o: $(ODIR)/main.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean run

clean:
	rm -f $(OBJDIR)/* $(BINDIR)/*
	rmdir $(OBJDIR) $(BINDIR)

run:
	$(BINDIR)/main


