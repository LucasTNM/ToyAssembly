CFLAGS = -Wall
CC = gcc

OBJDIR = objects
BUNDIR = bin
SRC = $(wildcard *.c)
OBJ = $(patsubst %.c,$(OBJDIR)/%.o,$(SRC))

all: binfolder objfolder bin/main

bin/main: $(OBJ)
$(CC) $(CFLAGS) $(OBJ) -o $@ $(LDFLAGS)

binfolder:
mkdir -p $(BINDIR)

objfolder:
mkdir -p $(OBJDIR)

objects/main.o: main.c
$(CC) $(CFLAGS) -c $< -o $@

objects/%.o: %.c %.h
$(CC) $(CFLAGS) -c $< -o $@


.PHONY: clean

clean:
rm bin/* objects/*
rmdir bin objects