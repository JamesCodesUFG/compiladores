#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "tree.h"
#include "tipos.h"

#include "goianinha.tab.h"

extern int yylex();
extern char* yytext;

extern FILE* yyin;

extern Raiz* arvore_final;

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Uso correto: programaPrincipal arquivo_de_teste\n");
        
        exit(1);
    }

    yyin = fopen(argv[1], "r");

    yyparse();

    return 0;
}