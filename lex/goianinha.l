%{ /* definições */ %}

%option yylineno

WHITESPACE  [\t\n\r' ']

ID          [a-z_][a-zA-Z0-9_]*

ATRIBUIR    =

CHAR        [^\n\"]
STR         \"{CHAR}*\"
DIGITO      [0-9]

IGUAL       ==
NAO_IGUAL   !=
MAIOR       >
MAIOR_IGUAL >=
MENOR       <
MENOR_IGUAL <=
MAIS        \+
MENOS       \-
MULT        \*
DIVIDE      \/
NEGATIVA    !

I_BLOCO     \{
F_BLOCO     \}

I_PARENT    \(
F_PARENT    \)

VIR         ,
FIM         \;

%%

{WHITESPACE}+   {}

programa        { return PROGRAMA; }

{I_BLOCO}       { return ABR_BLOCO; }
{F_BLOCO}       { return FCH_BLOCO; }

{I_PARENT}       { return ABR_PARENT; }
{F_PARENT}       { return FCH_PARENT; }

int             { return INT; }
char            { return CHAR; }

{DIGITO}+       { return NUMERO; }
{STR}           { return TEXTO; }

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
{MAIOR_IGUAL}   { return MAIOR_IGUA; }
{MENOR_IGUAL}   { return MENOR_IGUA; }
{MAIS}          { return MAIS; }
{MENOS}         { return MENOS; }
{MULT}          { return MULT; }
{DIVIDE}        { return DIVIDE; }
{NEGATIVA}      { return NEGATIVA; }

retorne         { return RETORNE; }

{VIR}           { return VIR; }
{FIM}           { return FIM; }

{ATRIBUIR}      { return ATRIBUIR; }

{ID}            { return ID ; }

"/*".*"*/"      {}

"/*"[^("/*")]   { printf("ERRO NA LINHA %d: COMENTARIO NAO TERMINA.\n", yylineno); return FLAG_ERROR_COMENTARIO ; }
\"[^\"]*        { printf("ERRO NA LINHA %d: CADEIA DE CARACTERES OCUPA MAIS DE UMA LINHA OU NAO TERMINA.\n", yylineno); return FLAG_ERROR_CADEIA ; }
.               { printf("ERRO NA LINHA %d: CARACTERE INVALIDO.\n", yylineno); return FLAG_ERROR_CARACTERE ; }

%%

int yywrap();

int yywrap() {
    return 1;
}