CC = gcc
CFLAGS =   -g  -Wall -ansi
LFLAGS = -lm

goianinha: sintatico.o lexico.o main.o
	$(CC) $(CFLAGS) $(LFLAGS) lexico.o sintatico.o main.o -o goianinha

main.o: main.c
	$(CC) $(CFLAGS) $(FLAGS) -c main.c -o main.o
                
sintatico.o: goianinha.tab.c
	$(CC) $(CFLAGS) -c goianinha.tab.c -o sintatico.o

goianinha.tab.c: goianinha.y
	bison -d -t -v goianinha.y 

lexico.o: lex.yy.c
	$(CC) $(CFLAGS) -c lex.yy.c -o lexico.o

lex.yy.c: goianinha.l
	flex  --yylineno goianinha.l 

clean:
	rm -f goianinha*.c lex.yy.c *.o goianinha goianinha*.h *.output *.tgz

cleanObj:
	rm -f *.o  

tgz: clean
	tar -zcvf goianinha.tgz *
	echo "O arquivo goianinha.tgz com os fontes e Makefile foi gerado. Pode ser enviado."	
