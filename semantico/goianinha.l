%{

#include "tipos.h"

#include "goianinha.tab.h"

%}

%option yylineno

WHITESPACE  [\t\n\r' ']

ID          [a-z_][a-zA-Z0-9_]*

ATRIBUIR    =

CHAR        [^\n\"]
STRING      \"{CHAR}*\"
DIGITO      [0-9]

IGUAL       ==
NAO_IGUAL   !=
MAIOR       >
MENOR       <
MAIOR_IGUAL >=
MENOR_IGUAL <=
MAIS        \+
MENOS       \-
MULT        \*
DIVIDE      \/
NEGATIVA    !

ABR_BLOCO   \{
FCH_BLOCO   \}
ABR_PARENT    \(
FCH_PARENT    \)

VIR         ,
FIM         \;

%%

{WHITESPACE}+   {}

programa        { return TOKEN_PROGRAMA; }

{ABR_BLOCO}     { return TOKEN_ABR_BLOCO; }
{FCH_BLOCO}     { return TOKEN_FCH_BLOCO; }

{ABR_PARENT}    { return TOKEN_ABR_PARENT; }
{FCH_PARENT}    { return TOKEN_FCH_PARENT; }

int             { return TOKEN_INT; }
char            { return TOKEN_CHAR; }

{DIGITO}+       {
                    char *str = (char*)malloc(sizeof(char) * yyleng);
                    strcpy(str, yytext);
                    yylval.str = str;
                    return VALUE_DIGITO;
                }
{STRING}        { 
                    char *str = (char*)malloc(sizeof(char) * yyleng);
                    strcpy(str, yytext);
                    yylval.str = str;
                    return VALUE_STRING; 
                }

leia            { return TOKEN_LEIA; }
escreva         { return TOKEN_ESCREVA; }
retorne         { return TOKEN_RETORNE; }
novalinha       { return TOKEN_NOVALINHA; }

se              { return TOKEN_SE; }
entao           { return TOKEN_ENTAO; }
senao           { return TOKEN_SENAO; }

enquanto        { return TOKEN_ENQUANTO; }
execute         { return TOKEN_EXECUTE; }

ou              { return TOKEN_OU; }
e               { return TOKEN_E; }

{IGUAL}         { return TOKEN_IGUAL; }
{NAO_IGUAL}     { return TOKEN_NAO_IGUAL; }
{MAIOR}         { return TOKEN_MAIOR; }
{MENOR}         { return TOKEN_MENOR; }
{MAIOR_IGUAL}   { return TOKEN_MAIOR_IGUAL; }
{MENOR_IGUAL}   { return TOKEN_MENOR_IGUAL; }
{MAIS}          { return TOKEN_MAIS; }
{MENOS}         { return TOKEN_MENOS; }
{MULT}          { return TOKEN_MULT; }
{DIVIDE}        { return TOKEN_DIVIDE; }
{NEGATIVA}      { return TOKEN_NEGATIVA; }

{VIR}           { return TOKEN_VIRGULA; }
{FIM}           { return TOKEN_FIM; }

{ATRIBUIR}      { return TOKEN_ATTR; }

{ID}            {
                    char *str = (char*)malloc(sizeof(char) * yyleng);
                    strcpy(str, yytext);
                    yylval.str = str;
                    return VALUE_ID;
                }

"/*".*"*/"      {}

"/*"[^("/*")]   { printf("ERRO: lexicon error in line %d. Comment doesn't end.\n", yylineno); return YYerror; }
\"[^\"]*        { printf("ERRO: lexicon error in line %d: String of characters occupies more than one line or doesn't end.\n", yylineno); return YYerror; }
.               { printf("ERRO: lexicon error in line %d: Invalid character '%s'.\n", yylineno, yytext); return YYerror; }

%%

int yywrap();

int yywrap() {
    return 1;
}
