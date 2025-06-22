%{

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "tipos.h"
#include "tree.h"

extern int yylex();
extern int numLinha;
extern int erroOrigem;
extern char* yytext;
extern FILE* yyin;

%}

/* rules */

%union {
    int num;
    char sym;
    char* str;
}

%token EOL

%token ID

%token ATRIBUIR

%token TIPO_INT
%token TIPO_CHAR

%token DIGITO
%token STRING

%token PROGRAMA

%token LEIA
%token ESCREVA
%token RETORNE

%token SE
%token ENTAO
%token SENAO
%token EXECUTE
%token ENQUANTO

%token ABR_PARENT
%token FCH_PARENT
%token ABR_BLOCO
%token FCH_BLOCO

%token IGUAL
%token MAIOR
%token MENOR
%token NAO_IGUAL
%token MAIOR_IGUAL
%token MENOR_IGUAL

%token MAIS       
%token MENOS      
%token MULT       
%token DIVIDE     
%token NEGATIVA   

%token E
%token OU

%token VIRGULA
%token FIM

%token NOVA_LINHA

%% /* PROGRAMA */

programa: 
    decl_func_var decl_prog { $$ = criarRaiz($1, $2) }
;

decl_func_var:
    { $$ = NULL; }
    | tipo ID decl_var FIM decl_func_var { $$ = criarVariavelComTipo($1, $2, $3, $4); }
    | tipo ID decl_func decl_func_var { $$ = criarFuncaoComTipo($1, $2, $3, $4); }
;

decl_prog: 
    PROGRAMA bloco { $$ = $2 }
;

decl_var:
    { $$ = NULL; }
    | VIRGULA ID decl_var { $$ = criarVariavelSemTipo($2, $3); }
;

decl_func:
    ABR_PARENT lista_parametros FCH_PARENT bloco { $$ = criarFuncaoSemTipo($2, $4); }
;

lista_parametros:
    { $$ = NULL; }
    | lista_parametros_cont { $$ = $1; }
;

lista_parametros_cont:
    tipo ID { $$ = criarParametro($1, $2, NULL); }
    | tipo ID VIRGULA lista_parametros_cont { $$ = criarParametro($1, $2, $3); }
;

bloco:
    ABR_BLOCO lista_decl_var lista_comando FCH_BLOCO { $$ = criarBloco($2, $3); }
;

lista_decl_var:
    { $$ = NULL; }
    | tipo ID decl_var FIM lista_decl_var { $$ = criarVariavelComTipo($1, $2, $3, $4); }
;

tipo:
    TIPO_INT { $$ = Tipo.INT; }
    | TIPO_CHAR { $$ = Tipo.STR; }
;

lista_comando:
    comando { $$ = $1; }
    | comando lista_comando { $$ = linkListaComando($1, $2) }
;

comando:
    FIM { $$ = NULL; }
    | expr FIM { $$ = criarComandoUnitario($1, EComandoUnitario.EXPR); }
    | RETORNE expr FIM { $$ = criarComandoUnitario($2, EComandoUnitario.RETORNE); }
    | LEIA ID FIM { Expr* expr = criarExprChamada($2, NULL, EPrimExpr.CHAMADA_VAR); $$ = criarComandoUnitario(expr, EComandoUnitario.LEIA); }
    | ESCREVA expr FIM { $$ = criarComandoUnitario($2, EComandoUnitario.ESCREVA); }
    | ESCREVA STRING FIM { Expr* expr = criarExprChamada($2, NULL, EPrimExpr.CHAMADA_VAR); $$ = criarComandoUnitario(expr, EComandoUnitario.ESCREVA); }
    | NOVA_LINHA FIM { $$ = NULL; }
    | SE ABR_PARENT expr FCH_PARENT ENTAO comando { $$ = criarComandoControleFluxo($3, $6, NULL); }
    | SE ABR_PARENT expr FCH_PARENT ENTAO comando SENAO comando { $$ = criarComandoControleFluxo($3, $6, $8); }
    | ENQUANTO ABR_PARENT expr FCH_PARENT EXECUTE comando { $$ = criarComandoControleFluxo($3, $6, NULL); }
    | bloco { $$ = criarComandoBloco($1); }
;

expr:
    or_expr { $$ = $1; }
    | ID ATRIBUIR expr { $$ = criarExprAtr($1, $3); }
;

or_expr:
    and_expr { $$ = $1; }
    | or_expr OU and_expr { $$ = criarExprOperador($1, $3, EOperador.OU); }
;

and_expr:
    eq_expr { $$ = $1; }
    | and_expr E eq_expr { $$ = criarExprOperador($1, $3, EOperador.E); }
;

eq_expr:
    desig_expr { $$ = $1; }
    | eq_expr IGUAL desig_expr { $$ = criarExprOperador($1, $3, EOperador.IGUALDADE); }
    | eq_expr NAO_IGUAL desig_expr { $$ = criarExprOperador($1, $3, EOperador.DIFERENCA); }
;

desig_expr:
    add_expr { $$ = $1; }
    | desig_expr MENOR add_expr { $$ = criarExprOperador($1, $3, EOperador.MENOR); }
    | desig_expr MAIOR add_expr { $$ = criarExprOperador($1, $3, EOperador.MAIOR); }
    | desig_expr MAIOR_IGUAL add_expr { $$ = criarExprOperador($1, $3, EOperador.MAIOR_IGUAL); }
    | desig_expr MENOR_IGUAL add_expr { $$ = criarExprOperador($1, $3, EOperador.MENOR_IGUAL); }
;

add_expr:
    mul_expr { $$ = $1; }
    | add_expr MAIS mul_expr { $$ = criarExprOperador($1, $3, EOperador.MAIS); }
    | add_expr MENOS mul_expr { $$ = criarExprOperador($1, $3, EOperador.MENOS); }
;

mul_expr:
    un_expr { $$ = $1; }
    | mul_expr MULT un_expr { $$ = criarOperador($1, $3, EOperador.MULTIPLICACAO); }
    | mul_expr DIVIDE un_expr { $$ = criarOperador($1, $3, EOperador.DIVISAO); }
;

un_expr:
    prim_expr { $$ = $1; }
    | MENOS prim_expr { $$ = criarUnExpr($2, EUnExpr.NEGATIVO); }
    | NEGATIVA prim_expr { $$ = criarUnExpr($2, EUnExpr.NEGACAO); }
;

prim_expr:
    ID ABR_PARENT list_expr FCH_PARENT { $$ = criarExprChamada($1, $3, EPrimExpr.CHAMADA_FUNC); }
    | ID ABR_PARENT FCH_PARENT { $$ = criarExprChamada($1, NULL, EPrimExpr.CHAMADA_FUNC); }
    | ID { $$ = criarExprChamada($1, NULL, EPrimExpr.CHAMADA_VAR); }
    | STRING { $$ = criarExprConst($1, EPrimExpr.STR); }
    | DIGITO { $$ = criarExprConst($1, EPrimExpr.INT); }
    | ABR_PARENT expr FCH_PARENT { $$ = criarExprParent($2); }
;

list_expr:
    expr { $$ = $1; }
    | list_expr VIRGULA expr { $$ = linkExpr($1, $3); }
;

%%

extern int yylineno;

yyerror(const char* s) {
    printf("ERROR: %s in line %d\n", s, yylineno);

    return 0;
}