COMPILADOR = gcc
CFLAGS = -g -Wall

main: main.c stack.o stack.h
	${COMPILADOR} ${CFLAGS} main.c stack.o -o main
	rm -f stack.o

stack.o: stack.c stack.h
	$(COMPILADOR) $(CFLAGS) -c stack.c -o stack.o

clean:
	rm -f *.o meu_programa