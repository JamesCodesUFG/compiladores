%{
    /* DEFINIÇÕES */
%}

WHITESPACE [ \t\n]*

AUX aux" "

%%

{AUX} { printf("'%s' -> Válido.\n", yytext); }
exit { return 0; }
.* { printf("'%s' -> Inválida.\n", yytext); }

%%

int yywrap() { return 0; }

int main() {
    printf("Entrada: ");
    yylex();

    return 0;
}