%{
    /* Definições */
%}

WHITESPACE [ \n\t]*

ID {WHITESPACE}[a-z]([A-Z][a-z0-9]*)*

STRING \"[a-zA-Z0-9]*\"

REPETICAO "enquanto""("{EXPR}")""execute"{COMD}
CONDICIONAL "se""("{EXPR}")""entao"{COMD}|"se""("{EXPR}")""entao"{COMD}"senao"{COMD}
ESCREVA "escreva" {EXPR}";"|"escreva" {STRING}";"
LEIA "leia" {L_VALUE_EXPR}";"
RETORNE "retorne"{EXPR}";"
COMD ";"|{EXPR}";"|{RETORNE}|{LEIA}|{ESCREVA}|"novalinha"";"|{CONDICIONAL}|{REPETICAO}|{BLOCO}
LISTA_COMD {COMD}|{COMD} {LISTA_COMD} 
TIPO "int"|"car"
LISTA_DECL_VAR {TIPO} {ID} {DECL_VAR}";" {LISTA_DECL_VAR}| 
BLOCO "{"{LISTA_DECL_VAR} {LIST_COMD}"}" | "{"{LISTA_DECL_VAR}"}"
LISTA_PARAM_CONT {TIPO} {ID} | {TIPO} {ID}"," {LISTA_PARAM_CONT}
LISTA_PARAM {LISTA_PARAM_CONT} |
DECL_FUNC "("LISTA_PARAM")" {BLOCO}
DECL_VAR ,{WHITESPACE}{ID}{DECL_VAR}|
DECL_PROG "programa" {BLOCO}
DECL_FUNC_VAR {TIPO}{ID}{DECL_VAR};{WHITESPACE}{DECL_FUNC_VAR}|{TIPO}{ID}{DECL_FUNC}{DECL_FUNC_VAR} | 
PROGRAMA {DECL_FUNC_VAR}|{DECL_PROG}


%%
    /* Regras */

{INT_TYPE} {printf("Definição de inteiro\n"); }
{INT_TYPE_A} {printf("Definição de inteiro a\n"); }
[0-9]* { printf("Interger\n"); }
[0-9]*.[0-9]* { printf("Floating\n"); }
"[a-zA-Z0-9_ ]*" { printf("String\n"); }
.* { printf("Invalid\n"); }
\n { return 0; }

%%

int yywrap() {
    return 0;
}

int main() {
    printf("Enter string: ");
    yylex();

    return 0;
}