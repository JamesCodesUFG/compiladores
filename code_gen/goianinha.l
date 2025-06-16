%{

#include "goianinha.tab.h"

%}

%option yylineno

WHITESPACE  [\t\n\r' ']

ID          [a-z_][a-zA-Z0-9_]*

ATRIBUIR    =

CHAR        [^\n\"]
STRING         \"{CHAR}*\"
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

programa        { return PROGRAMA; }

{ABR_BLOCO}     { return ABR_BLOCO; }
{FCH_BLOCO}     { return FCH_BLOCO; }

{ABR_PARENT}    { return ABR_PARENT; }
{FCH_PARENT}    { return FCH_PARENT; }

int             { return TIPO_INT; }
char            { return TIPO_CHAR; }

{DIGITO}+       { return DIGITO; }
{STRING}        { return STRING; }

leia            { return LEIA; }
escreva         { return ESCREVA; }

se              { return SE; }
entao           { return ENTAO; }
senao           { return SENAO; }

enquanto        { return ENQUANTO; }
execute         { return EXECUTE; }

ou              { return OU; }
e               { return E; }

{IGUAL}         { return IGUAL; }
{NAO_IGUAL}     { return NAO_IGUAL; }
{MAIOR}         { return MAIOR; }
{MENOR}         { return MENOR; }
{MAIOR_IGUAL}   { return MAIOR_IGUAL; }
{MENOR_IGUAL}   { return MENOR_IGUAL; }
{MAIS}          { return MAIS; }
{MENOS}         { return MENOS; }
{MULT}          { return MULT; }
{DIVIDE}        { return DIVIDE; }
{NEGATIVA}      { return NEGATIVA; }

retorne         { return RETORNE; }

{VIR}           { return VIRGULA; }
{FIM}           { return FIM; }

{ATRIBUIR}      { return ATRIBUIR; }

{ID}            { return ID ; }

"/*".*"*/"      {}

"/*"[^("/*")]   { printf("ERRO: lexicon error in line %d. Comment doesn't end.\n", yylineno); return YYerror; }
\"[^\"]*        { printf("ERRO: lexicon error in line %d: String of characters occupies more than one line or doesn't end.\n", yylineno); return YYerror; }
.               { printf("ERRO: lexicon error in line %d: Invalid character.\n", yylineno, yytext); return YYerror; }

%%

int yywrap();

int yywrap() {
    return 1;
}
