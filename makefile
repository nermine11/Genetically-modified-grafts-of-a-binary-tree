CC = gcc
CFLAGS= -std=c17 -pedantic -Wall

OBJ = arbres_binaires.o greffe.o saage.o main.o

main : $(OBJ)
	$(CC) -o $@ $^



arbres_binaires.o: arbres_binaires.c arbres_binaires.h
greffe.o : greffe.c greffe.h arbres_binaires.h
saage.o : saage.c saage.h arbres_binaires.h
main.o : main.c arbres_binaires.h greffe.h saage.h




%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o
