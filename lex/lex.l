%{
    /* Definições */
%}

WHITESPACE  [\t\n\r' ']

ID          [a-z][a-zA-Z0-9_]*

CHAR        [a-zA-Z0-9]
DIGITO      [0-9]

IGUAL       =
NAO_IGUAL   !=
MAIOR_IGUAL >=
MENOR_IGUAL <=
MAIS        \+
MENOS       \-
MULT        \*
DIVIDE      \/
NEGATIVA    !

FIM         ;


%%

{WHITESPACE}+   { printf("Espaço em branco.\n"); }

programa        { printf("Terminal PROGRAMA encontrado.\n"); }

int             { printf("Terminal INT encontrado.\n"); }
char            { printf("Terminal CHAR encontrado.\n"); }

{DIGITO}+       { printf("Valor INT encontrado: %s\n", yytext); }
\"{CHAR}*\"     { printf("Valor CHAR encontrado: %s\n", yytext); }

leia            { printf("Terminal LEIA encontrado.\n"); }
escreva         { printf("Terminal ESCREVA encontrado.\n"); }

se              { printf("Condicional SE encontrado.\n"); }
entao           { printf("Condicional ENTÃO encontrado.\n"); }
senao           { printf("Condicional SENÃO encontrado.\n"); }

enquanto        { printf("Repetição ENQUANTO encontrado.\n"); }
execute         { printf("Repetição EXECUTE encontrado.\n"); }

ou              { printf("Terminal PROGRAMA encontrado.\n"); }
e               { printf("Terminal PROGRAMA encontrado.\n"); }

{IGUAL}         { printf("Terminal IGUAL encontrado.\n"); }
{NAO_IGUAL}     { printf("Terminal NÂO IGUAL encontrado.\n"); }
{MAIOR_IGUAL}   { printf("Terminal MAIOR QUE encontrado.\n"); }
{MENOR_IGUAL}   { printf("Terminal MENOR QUE encontrado.\n"); }
{MAIS}          { printf("Terminal ADIÇÃO encontrado.\n"); }
{MENOS}         { printf("Terminal SUBTRAÇÃO encontrado.\n"); }
{MULT}          { printf("Terminal MULTIPLICAÇÃO encontrado.\n"); }
{DIVIDE}           { printf("Terminal DIVISÃO encontrado.\n"); }
{NEGATIVA}      { printf("Terminal NEGAÇÃO encontrado.\n"); }

retorne         { printf("Terminal RETORNE encontrado.\n"); }

{FIM}           { printf("Fim de linha.\n"); }

{ID}            { printf("Identificador encontrado: %s\n", yytext); }

.               { printf("Caractere não reconhecido"); }

%%

int yywrap();

int yywrap() {
    return 1;
    
}