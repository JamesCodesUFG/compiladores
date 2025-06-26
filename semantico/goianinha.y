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

Raiz* arvore_final = NULL;

%}

/* rules */

%union {
    int num;
    char sym;
    char* str;
    Raiz* raiz;
    DeclFuncVar* declFuncVar;
    DeclVar* declVar;
    DeclFunc* declFunc;
    Bloco* bloco;
    ListaParametros* listaParametros;
    ChamadaFunc* chamadaFunc;
    PrimExpr* primExpr;
    UnExpr* unExpr;
    Operador* operador;
    Atribuicao* atribuicao;
    Expr* expr;
    ComandoUnitario* comandoUnitario;
    ComandoControleFluxo* comandoControleFluxo;
    ListaComando* listaComando;
    ETipo tipo;
}

/* DECLARAÇÃO DOS TIPO DAS REGRAS */


%type<raiz> programa
%type<declFuncVar> decl_func_var
%type<bloco> decl_prog bloco
%type<declFuncVar> decl_var decl_func lista_decl_var
%type<listaParametros> lista_parametros lista_parametros_cont
%type<tipo> tipo
%type<listaComando> lista_comando comando
%type<expr> expr list_expr or_expr and_expr eq_expr desig_expr add_expr mul_expr un_expr
%type<primExpr> prim_expr


/* DECLARAÇÃO DOS TOKENS SINTÁTICOS */


%token<str> VALUE_ID

%token<str> VALUE_DIGITO
%token<str> VALUE_STRING

%token TOKEN_INT
%token TOKEN_CHAR

%token TOKEN_ATTR

%token TOKEN_E
%token TOKEN_OU

%token TOKEN_IGUAL
%token TOKEN_MAIOR
%token TOKEN_MENOR
%token TOKEN_NAO_IGUAL
%token TOKEN_MAIOR_IGUAL
%token TOKEN_MENOR_IGUAL

%token TOKEN_MAIS       
%token TOKEN_MENOS      
%token TOKEN_MULT       
%token TOKEN_DIVIDE     
%token TOKEN_NEGATIVA  

%token TOKEN_SE
%token TOKEN_ENTAO
%token TOKEN_SENAO
%token TOKEN_EXECUTE
%token TOKEN_ENQUANTO

%token TOKEN_PROGRAMA

%token TOKEN_LEIA
%token TOKEN_ESCREVA
%token TOKEN_RETORNE
%token TOKEN_NOVALINHA

%token TOKEN_ABR_PARENT
%token TOKEN_FCH_PARENT

%token TOKEN_ABR_BLOCO
%token TOKEN_FCH_BLOCO

%token TOKEN_VIRGULA
%token TOKEN_FIM

%token TOKEN_NOVA_LINHA

%%

programa: 
    decl_func_var decl_prog
        {
            $$ = criarRaiz($1, $2);
            arvore_final = $$;
        }
;

decl_func_var:
    { $$ = NULL; }
    | tipo VALUE_ID decl_var TOKEN_FIM decl_func_var { $$ = criarVariavelComTipo($1, $2, $3, $5); }
    | tipo VALUE_ID decl_func decl_func_var { $$ = criarFuncaoComTipo($1, $2, $3, $4); }
;

decl_prog: 
    TOKEN_PROGRAMA bloco { $$ = $2; }
;

decl_var:
    { $$ = NULL; }
    | TOKEN_VIRGULA VALUE_ID decl_var { $$ = criarVariavelSemTipo($2, $3); }
;

decl_func:
    TOKEN_ABR_PARENT lista_parametros TOKEN_FCH_PARENT bloco { $$ = criarFuncaoSemTipo($2, $4); }
;

lista_parametros:
    { $$ = NULL; }
    | lista_parametros_cont { $$ = $1; }
;

lista_parametros_cont:
    tipo VALUE_ID { $$ = criarParametro($1, $2, NULL); }
    | tipo VALUE_ID TOKEN_VIRGULA lista_parametros_cont { $$ = criarParametro($1, $2, $4); }
;

bloco:
    TOKEN_ABR_BLOCO lista_decl_var lista_comando TOKEN_FCH_BLOCO { $$ = criarBloco($2, $3); }
;

lista_decl_var:
    { $$ = NULL; }
    | tipo VALUE_ID decl_var TOKEN_FIM lista_decl_var { $$ = criarVariavelComTipo($1, $2, $3, $5); }
;

tipo:
    TOKEN_INT { printf("Certo"); $$ = TIPO_INT; }
    | TOKEN_CHAR { $$ = TIPO_STR; }
;

lista_comando:
    comando { $$ = $1; }
    | comando lista_comando { $$ = linkListaComando($1, $2); }
;

comando:
    TOKEN_FIM { $$ = NULL; }
    | expr TOKEN_FIM { $$ = criarComandoUnitario($1, EXPR); }
    | TOKEN_RETORNE expr TOKEN_FIM { $$ = criarComandoUnitario($2, RETORNE); }
    | TOKEN_LEIA VALUE_ID TOKEN_FIM
        { 
            PrimExpr* primExpr = criarPrimExprChamada($2, NULL, CHAMADA_VAR);
            Expr* expr = criarExprUnaria(primExpr, NONE);
            $$ = criarComandoUnitario(expr, LEIA);
        }
    | TOKEN_ESCREVA expr TOKEN_FIM { $$ = criarComandoUnitario($2, ESCREVA); }
    | TOKEN_ESCREVA VALUE_STRING TOKEN_FIM
        {
            PrimExpr* primExpr = criarPrimExprConst($2, TIPO_STR);
            Expr* expr = criarExprUnaria(primExpr, NONE);
            $$ = criarComandoUnitario(expr, ESCREVA);
        }
    | TOKEN_NOVALINHA TOKEN_FIM { $$ = criarComandoUnitario(NULL, NOVALINHA); }
    | TOKEN_SE TOKEN_ABR_PARENT expr TOKEN_FCH_PARENT TOKEN_ENTAO comando { $$ = criarComandoControleFluxo($3, $6, NULL, SE_ENTAO); }
    | TOKEN_SE TOKEN_ABR_PARENT expr TOKEN_FCH_PARENT TOKEN_ENTAO comando TOKEN_SENAO comando { $$ = criarComandoControleFluxo($3, $6, $8, SE_SENAO); }
    | TOKEN_ENQUANTO TOKEN_ABR_PARENT expr TOKEN_FCH_PARENT TOKEN_EXECUTE comando { $$ = criarComandoControleFluxo($3, $6, NULL, ENQUANTO); }
    | bloco { $$ = criarComandoBloco($1); }
;

expr:
    or_expr { $$ = $1; }
    | VALUE_ID TOKEN_ATTR expr { $$ = criarExprAtribuicao($1, $3); }
;

or_expr:
    and_expr { $$ = $1; }
    | or_expr TOKEN_OU and_expr { $$ = criarExprOperador($1, $3, OU); }
;

and_expr:
    eq_expr { $$ = $1; }
    | and_expr TOKEN_E eq_expr { $$ = criarExprOperador($1, $3, E); }
;

eq_expr:
    desig_expr { $$ = $1; }
    | eq_expr TOKEN_IGUAL desig_expr { $$ = criarExprOperador($1, $3, IGUALDADE); }
    | eq_expr TOKEN_NAO_IGUAL desig_expr { $$ = criarExprOperador($1, $3, DIFERENCA); }
;

desig_expr:
    add_expr { $$ = $1; }
    | desig_expr TOKEN_MENOR add_expr { $$ = criarExprOperador($1, $3, MENOR_QUE); }
    | desig_expr TOKEN_MAIOR add_expr { $$ = criarExprOperador($1, $3, MAIOR_QUE); }
    | desig_expr TOKEN_MAIOR_IGUAL add_expr { $$ = criarExprOperador($1, $3, MAIOR_IGUAL); }
    | desig_expr TOKEN_MENOR_IGUAL add_expr { $$ = criarExprOperador($1, $3, MENOR_IGUAL); }
;

add_expr:
    mul_expr { $$ = $1; }
    | add_expr TOKEN_MAIS mul_expr { $$ = criarExprOperador($1, $3, MAIS); }
    | add_expr TOKEN_MENOS mul_expr { $$ = criarExprOperador($1, $3, MENOS); }
;

mul_expr:
    un_expr { $$ = $1; }
    | mul_expr TOKEN_MULT un_expr { $$ = criarExprOperador($1, $3, MULTIPLICACAO); }
    | mul_expr TOKEN_DIVIDE un_expr { $$ = criarExprOperador($1, $3, DIVISAO); }
;

un_expr:
    prim_expr { $$ = criarExprUnaria($1, NONE); }
    | TOKEN_MENOS prim_expr { $$ = criarExprUnaria($2, NEGATIVO); }
    | TOKEN_NEGATIVA prim_expr { $$ = criarExprUnaria($2, NEGACAO); }
;

prim_expr:
    VALUE_ID TOKEN_ABR_PARENT list_expr TOKEN_FCH_PARENT { $$ = criarPrimExprChamada($1, $3, CHAMADA_FUNC); }
    | VALUE_ID TOKEN_ABR_PARENT TOKEN_FCH_PARENT { $$ = criarPrimExprChamada($1, NULL, CHAMADA_FUNC); }
    | VALUE_ID { $$ = criarPrimExprChamada($1, NULL, CHAMADA_VAR); }
    | VALUE_STRING { $$ = criarPrimExprConst($1, CONST_STR); }
    | VALUE_DIGITO { $$ = criarPrimExprConst($1, CONST_INT); }
    | TOKEN_ABR_PARENT expr TOKEN_FCH_PARENT { $$ = criarPrimExprParent($2); }
;

list_expr:
    expr { $$ = $1; }
    | list_expr TOKEN_VIRGULA expr { $$ = linkExpr($1, $3); }
;

%%

extern int yylineno;

yyerror(const char* s) {
    printf("ERROR: %s in line %d. ", s, yylineno);
    printf("Token atual: '%s'\n", yytext);

    return 0;
}