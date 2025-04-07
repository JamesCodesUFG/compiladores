COMPILADOR = gcc
CFLAGS = -g -Wall -ansi
LFLAGS = -lm

lex: lexico.o main.o
	$(COMPILADOR) $(CFLAGS) $(LFLAGS) lexico.o main.o -o lex
	rm -f *.o lex.yy.c

main.o: main.c
	$(COMPILADOR) $(CFLAGS) -c main.c -o main.o

lex.yy.c: lex.l
	flex lex.l

lexico.o: lex.yy.c
	$(COMPILADOR) $(CFLAGS) -c lex.yy.c -o lexico.o

clean:
	rm -f *.o lex

cleanObj:
	rm -f *.o

tgz:
	rm -f *.o rm lex *.tgz
	tar -zcvf Lexico.tgz *
	echo "O arquivo Lexico.tgz com os fontes e Makefile foi gerado. Pode ser enviado."