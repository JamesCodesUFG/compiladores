COMPILADOR = gcc
CFLAGS = -g -Wall -ansi
LFLAGS = -lm

ifeq ($(OS), Windows_NT)
	CLEAN = del *.o; del lex.yy.c;
	CLEAN_OBJ = del *.o;
	CLEAN_ALL = del *.o; del lex.yy.c; del goianinha.exe;
else
	CLEAN = rm -f *.o lex.yy.c
	CLEAN_OBJ = rm -f *.o
	CLEAN_ALL = rm -f *.o lex.yy.c goianinha
endif

goianinha: lexico.o main.o
	$(COMPILADOR) $(CFLAGS) $(LFLAGS) lexico.o main.o -o goianinha
	${CLEAN}

main.o: main.c
	$(COMPILADOR) $(CFLAGS) -c main.c -o main.o

lex.yy.c: goianinha.l
	flex goianinha.l

lexico.o: lex.yy.c
	$(COMPILADOR) $(CFLAGS) -c lex.yy.c -o lexico.o

clean:
	${CLEAN}

cleanObj:
	${CLEAN_OBJ}

tgz:
	${CLEAN_ALL}
	tar -zcvf Lexico.tgz *
	echo "O arquivo Lexico.tgz com os fontes e Makefile foi gerado. Pode ser enviado."