%{

const int FLAG_WHITESPACE = 0;
const int FLAG_ID = 1;   
const int FLAG_STR = 3;      
const int FLAG_DIGITO = 4;   
const int FLAG_IGUAL = 5;    
const int FLAG_NAO_IGUAL = 6; 
const int FLAG_MAIOR_IGUA = 7;
const int FLAG_MENOR_IGUA = 8;
const int FLAG_MAIS = 9;      
const int FLAG_MENOS = 10;     
const int FLAG_MULT = 11;      
const int FLAG_DIVIDE = 12;    
const int FLAG_NEGATIVA = 13; 
const int FLAG_I_BLOCO = 14;   
const int FLAG_F_BLOCO = 15;   
const int FLAG_I_PARENT = 16;  
const int FLAG_F_PARENT = 17;
const int FLAG_VIR = 18;  
const int FLAG_FIM = 19;

const int FLAG_PROGRAMA = 20;
const int FLAG_INT = 21;
const int FLAG_CHAR = 22;
const int FLAG_LEIA = 23;            
const int FLAG_ESCREVA = 24;         
const int FLAG_SE = 25;              
const int FLAG_ENTAO = 26;           
const int FLAG_SENAO = 27;           
const int FLAG_ENQUANTO = 28;        
const int FLAG_EXECUTE = 29;         
const int FLAG_OU = 30;              
const int FLAG_E = 31;               
const int FLAG_RETORNE = 32;

const int FLAG_ERROR_COMENTARIO = 33;
const int FLAG_ERROR_CADEIA = 34;
const int FLAG_ERROR_CARACTERE = 35;

%}
%option yylineno

WHITESPACE  [\t\n\r' ']

ID          [a-z_][a-zA-Z0-9_]*

CHAR        [^\n\"]
STR         \"{CHAR}*\"
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

I_BLOCO     \{
F_BLOCO     \}

I_PARENT    \(
F_PARENT    \)

VIR         ,
FIM         \;

%%

{WHITESPACE}+   {}

programa        { return FLAG_PROGRAMA; }

{I_BLOCO}       { return FLAG_I_BLOCO; }
{F_BLOCO}       { return FLAG_F_BLOCO; }

{I_PARENT}       { return FLAG_I_PARENT; }
{F_PARENT}       { return FLAG_F_PARENT; }

int             { return FLAG_INT; }
char            { return FLAG_CHAR; }

{DIGITO}+       { return FLAG_DIGITO; }
{STR}           { return FLAG_STR; }

leia            { return FLAG_LEIA; }
escreva         { return FLAG_ESCREVA; }

se              { return FLAG_SE; }
entao           { return FLAG_ENTAO ; }
senao           { return FLAG_SENAO ; }

enquanto        { return FLAG_ENQUANTO ; }
execute         { return FLAG_EXECUTE ; }

ou              { return FLAG_OU ; }
e               { return FLAG_E ; }

{IGUAL}         { return FLAG_IGUAL ; }
{NAO_IGUAL}     { return FLAG_NAO_IGUAL ; }
{MAIOR_IGUAL}   { return FLAG_MAIOR_IGUA ; }
{MENOR_IGUAL}   { return FLAG_MENOR_IGUA ; }
{MAIS}          { return FLAG_MAIS ; }
{MENOS}         { return FLAG_MENOS ; }
{MULT}          { return FLAG_MULT ; }
{DIVIDE}        { return FLAG_DIVIDE ; }
{NEGATIVA}      { return FLAG_NEGATIVA ; }

retorne         { return FLAG_RETORNE ; }

{VIR}           { return FLAG_VIR ; }
{FIM}           { return FLAG_FIM ; }

{ID}            { return FLAG_ID ; }

"/*".*"*/"      {}

"/*"[^("/*")]   { printf("ERRO NA LINHA %d: COMENTARIO NAO TERMINA.\n", yylineno); return FLAG_ERROR_COMENTARIO ; }
\"[^\"]*        { printf("ERRO NA LINHA %d: CADEIA DE CARACTERES OCUPA MAIS DE UMA LINHA OU NAO TERMINA.\n", yylineno); return FLAG_ERROR_CADEIA ; }
.               { printf("ERRO NA LINHA %d: CARACTERE INVALIDO.\n", yylineno); return FLAG_ERROR_CARACTERE ; }

%%

int yywrap();

int yywrap() {
    return 1;
}