CC = gcc
CFLAGS= -std=c17 -pedantic -Wall


arbres_binaires.o: arbres_binaires.c arbres_binaires.h
	$(CC) $(CFLAGS) $@ $<