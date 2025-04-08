#include <stdio.h>

#include "stack.h"

/**
 * A fim de testar a pilha será:
 * 
 * 1 - Criar uma Stack.
 * 2 - Adicionar 2 variável, 1 função e 3 parâmetros.
 * 3 - Adicionar novo escopo.
 * 4 - Adicionar 2 variável, 1 função e 3 parâmetros.
 * 5 - Encontrar lexemas.
 * 6 - Excluir escopo atual.
 * 7 - Encontrar lexemas.
 * 8 - Excluir Stack.
 */

int main() {
    Stack* stack = init();

    Lexeme* var_1 = add_var(stack, "var_1", INT, 0);
    Lexeme* var_2 = add_var(stack, "var_2", STR, 1);
    Lexeme* func_1 = add_func(stack, "func_1", 2, INT);
    Lexeme* param_1 = add_param(stack, "param_1", INT, 3, func_1);
    Lexeme* param_2 = add_param(stack, "param_2", INT, 4, func_1);
    Lexeme* param_3 = add_param(stack, "param_3", INT, 5, func_1);

    stack = up(stack);

    Lexeme* var_3 = add_var(stack, "var_1", INT, 6);
    Lexeme* var_4 = add_var(stack, "var_4", STR, 7);
    Lexeme* func_2 = add_func(stack, "func_2", 8, INT);
    Lexeme* param_4 = add_param(stack, "param_1", INT, 9, func_2);
    Lexeme* param_5 = add_param(stack, "param_2", INT, 10, func_2);
    Lexeme* param_6 = add_param(stack, "param_3", INT, 11, func_2);

    debug(stack);

    Lexeme* find_1 = find(stack, "var_1");
    Lexeme* find_2 = find(stack, "var_2");
    Lexeme* find_3 = find(stack, "func_1");
    Lexeme* find_4 = find(stack, "func_2");
    Lexeme* find_5 = find(stack, "param_1");

    printf("Lexema 'var_1': %s\n", var_3 == find_1 ? "True" : "False");
    printf("Lexema 'var_2': %s\n", var_2 == find_2 ? "True" : "False");
    printf("Lexema 'func_1': %s\n", func_1 == find_3 ? "True" : "False");
    printf("Lexema 'func_2': %s\n", func_2 == find_4 ? "True" : "False");
    printf("Lexema 'param_1': %s\n", param_4 == find_5 ? "True" : "False");

    //stack = down(stack);

    Lexeme* find_7 = find(stack, "var_1");
    Lexeme* find_8 = find(stack, "func_1");
    Lexeme* find_9 = find(stack, "param_1");

    printf("Lexema 'var_1': %s\n", var_1 == find_7 ? "True" : "False");
    printf("Lexema 'func_1': %s\n", func_1 == find_8 ? "True" : "False");
    printf("Lexema 'param_1': %s\n", param_1 == find_9 ? "True" : "False");

    delete(stack);

    return 0;
}