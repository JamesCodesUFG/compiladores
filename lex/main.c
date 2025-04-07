#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern int yylex();
extern char* yytext;

extern FILE* yyin;

typedef struct Bloco {
    char** lex;

    struct Bloco* parent;
    struct Bloco* children;
} Bloco;

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Uso correto: programaPrincipal arquivo_de_teste\n");
        
        exit(1);
    }

    

    yyin = fopen(argv[1], "r");

    int token = yylex();

    while (token) {
        printf("Token: %d, Lexema: %s\n", token, yytext);
        
        token = yylex();
    }

    return 1;
}