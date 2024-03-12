CC = clang
CFLAGS= -std=c17 -pedantic -Wall

saage : src/arbres_binaires.o src/greffe.o src/saage.o src/main.o
	$(CC) -o $@ $^


src/arbres_binaires.o: src/arbres_binaires.c include/arbres_binaires.h
src/greffe.o : src/greffe.c include/greffe.h include/arbres_binaires.h
src/saage.o : src/saage.c include/saage.h include/arbres_binaires.h
src/main.o : src/main.c include/arbres_binaires.h include/greffe.h include/saage.h




%.o: %.c
	$(CC) $(CFLAGS) -I include -c -o $@ $<

clean:
	rm -f src/*.o


ARCHIVE = Elkilani_Desravines_v20240309
dist: clean
	mkdir -p $(ARCHIVE)
	cp -Rt $(ARCHIVE) src include makefile rapport.pdf
	zip -r $(ARCHIVE).zip $(ARCHIVE)
	rm -fr $(ARCHIVE)