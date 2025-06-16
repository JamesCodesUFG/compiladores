%{

#include <stdio.h>

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
    decl_func_var decl_prog { printf("Programa lido com sucesso.\n"); }
;

decl_func_var:
    { printf("decl_func_var: vazio.\n"); }
    | tipo ID decl_var FIM decl_func_var { printf("decl_func_var: unico\n"); }
    | tipo ID decl_func decl_func_var { printf("decl_func_var: multiplos\n"); }
;

decl_prog: 
    PROGRAMA bloco { printf("decl_prog: %s\n"); }
;

decl_var:
    { printf("decl_var: vazio.\n"); }
    | VIRGULA ID decl_var { printf("decl_var\n"); }
;

decl_func:
    ABR_PARENT lista_parametros FCH_PARENT bloco { printf("decl_func\n"); }
;

lista_parametros:
    { printf("lista_parametros: vazio.\n"); }
    | lista_parametros_cont { printf("lista_parametros\n"); }
;

lista_parametros_cont:
    tipo ID { printf("lista_parametros_cont: unico\n"); }
    | tipo ID VIRGULA lista_parametros_cont { printf("lista_parametros_cont: multiplos\n"); }
;

bloco:
    ABR_BLOCO lista_decl_var lista_comando FCH_BLOCO { printf("bloco\n"); }
;

lista_decl_var:
    { printf("lista_decl_var: vazio.\n"); }
    | tipo ID decl_var FIM lista_decl_var { printf("lista_decl_var\n"); }
;

tipo:
    TIPO_INT { printf("tipo: int\n"); }
    | TIPO_CHAR { printf("tipo: char\n"); }
;

lista_comando:
    comando { printf("lista_comando: unico\n"); }
    | comando lista_comando { printf("lista_comando: multiplos\n"); }
;

comando:
    FIM { printf("comando: fim\n"); }
    | expr FIM { printf("comando: expr\n"); }
    | RETORNE expr FIM { printf("comando: retorne\n"); }
    | LEIA ID FIM { printf("comando: leia\n"); }
    | ESCREVA expr FIM { printf("comando: escreva expr\n"); }
    | ESCREVA STRING FIM { printf("comando: escreva string\n"); }
    | NOVA_LINHA FIM { printf("comando: nova linha\n"); }
    | SE ABR_PARENT expr FCH_PARENT ENTAO comando { printf("comando: se\n"); }
    | SE ABR_PARENT expr FCH_PARENT ENTAO comando SENAO comando { printf("comando: se-senao\n"); }
    | ENQUANTO ABR_PARENT expr FCH_PARENT EXECUTE comando { printf("comando: enquanto\n"); }
    | bloco { printf("comando: bloco\n"); }
;

expr:
    or_expr { printf("expr: or_expr\n"); }
    | ID ATRIBUIR expr { printf("expr: atribuicao\n"); }
;

or_expr:
    and_expr { printf("or_expr: and_expr\n"); }
    | or_expr OU and_expr { printf("or_expr: ou\n"); }
;

and_expr:
    eq_expr { printf("and_expr: eq_expr\n"); }
    | and_expr E eq_expr { printf("and_expr: e\n"); }
;

eq_expr:
    desig_expr { printf("eq_expr: desig_expr\n"); }
    | eq_expr IGUAL desig_expr { printf("eq_expr: igual\n"); }
    | eq_expr NAO_IGUAL desig_expr { printf("eq_expr: nao igual\n"); }
;

desig_expr:
    add_expr { printf("desig_expr: add_expr\n"); }
    | desig_expr MENOR add_expr { printf("desig_expr: menor\n"); }
    | desig_expr MAIOR add_expr { printf("desig_expr: maior\n"); }
    | desig_expr MAIOR_IGUAL add_expr { printf("desig_expr: maior igual\n"); }
    | desig_expr MENOR_IGUAL add_expr { printf("desig_expr: menor igual\n"); }
;

add_expr:
    mul_expr { printf("add_expr: mul_expr\n"); }
    | add_expr MAIS mul_expr { printf("add_expr: mais\n"); }
    | add_expr MENOS mul_expr { printf("add_expr: menos\n"); }
;

mul_expr:
    un_expr { printf("mul_expr: un_expr\n"); }
    | mul_expr MULT un_expr { printf("mul_expr: mult\n"); }
    | mul_expr DIVIDE un_expr { printf("mul_expr: divide\n"); }
;

un_expr:
    prim_expr { printf("un_expr: prim_expr\n"); }
    | MENOS prim_expr { printf("un_expr: menos\n"); }
    | NEGATIVA prim_expr { printf("un_expr: negativa\n"); }
;

prim_expr:
    ID ABR_PARENT list_expr FCH_PARENT { printf("prim_expr: lista\n"); }
    | ID ABR_PARENT FCH_PARENT { printf("prim_expr: vazio\n"); }
    | ID { printf("prim_expr: id\n"); }
    | STRING { printf("prim_expr: string\n"); }
    | DIGITO { printf("prim_expr: digito\n"); }
    | ABR_PARENT expr FCH_PARENT { printf("prim_expr: expr\n"); }
;

list_expr:
    expr { printf("list_expr: unico\n"); }
    | list_expr VIRGULA expr { printf("list_expr: multiplo\n"); }
;

%%

extern int yylineno;

yyerror(const char *s) {
    printf("ERROR: %s in line %d\n", s, yylineno);

    return 0;
}