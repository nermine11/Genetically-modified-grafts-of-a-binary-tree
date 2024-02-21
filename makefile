CC = gcc
CFLAGS= -std=c17 -pedantic -Wall



arbres_binaires.o: arbres_binaires.c arbres_binaires.h


greffe.o : greffe.c greffe.h arbres_binaires.h




%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<