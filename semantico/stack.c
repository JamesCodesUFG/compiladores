#include <stdlib.h>
#include <string.h>

#include "stack.h"

/**
 * Inicia uma nova stack.
 * 
 * @return Endereço da nova stack.
 */
Stack* init() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));

    stack->n_lexema = 0;

    stack->lexemas = malloc(0);

    stack->child = NULL;
    stack->parent = NULL;
    
    return stack;
}

/**
 * Sobe uma camada após adicionar uma nova camada à pilha.
 * 
 * @param stack Endereço da stack atual.
 * 
 * @return Novo endereço de Stack.
 */
Stack* up(Stack* stack) {
    Stack* new_stack = init();

    new_stack->parent = stack;
    
    stack->child = new_stack;

    return new_stack;
}

static Stack* delete_(Stack* stack) {
    Stack* parent = stack->parent;

    for (int i = 0; i < stack->n_lexema; i++) {
        free(stack->lexemas[i]);
    }

    free(stack->lexemas);

    free(stack->child);

    return parent;
}

void delete_stack(Stack* stack) {
    while (stack != NULL) {
        stack = delete_(stack);
    }
}

Stack* down(Stack* stack) {
    return delete_(stack);
}

static void add_lexema(Stack* stack, LexemaTipo tipo) {
    stack->lexemas = realloc(stack->lexemas, sizeof(Lexema) * ++stack->n_lexema);

    if (stack->lexemas == NULL) {
        printf("Erro ao adicionar lexema à stack.\n");
        exit(1);
    }

    stack->lexemas[stack->n_lexema - 1] = (Lexema*)malloc(sizeof(Lexema));

    stack->lexemas[stack->n_lexema - 1]->tipo = tipo;
}

Lexema* add_var(Stack* stack, char* id, STipo tipo, int index) {
    add_lexema(stack, L_VARIABLE);

    stack->lexemas[stack->n_lexema - 1]->func.id = malloc(strlen(id) * sizeof(char) + 1);;
    strcpy(stack->lexemas[stack->n_lexema - 1]->func.id, id);

    stack->lexemas[stack->n_lexema - 1]->var.tipo = tipo;
    stack->lexemas[stack->n_lexema - 1]->var.index = index;

    return stack->lexemas[stack->n_lexema - 1];
}

/**
 * Adiciona um novo lexema à lista de lexemas da stack.
 * 
 * @param stack Stack a ser manipulada.
 * @param id Nome da variável.
 * @param n_params Quantidade de parâmetros.
 * @param type Tipo do valor de retorno.
 */
Lexema* add_func(Stack* stack, char* id, int n_params, STipo tipo) {
    add_lexema(stack, L_FUNCTION);

    stack->lexemas[stack->n_lexema - 1]->func.id = malloc(strlen(id) * sizeof(char) + 1);;
    strcpy(stack->lexemas[stack->n_lexema - 1]->func.id, id);

    stack->lexemas[stack->n_lexema - 1]->func.n_params = n_params;
    stack->lexemas[stack->n_lexema - 1]->func.tipo = tipo;

    return stack->lexemas[stack->n_lexema - 1];
}

Lexema* add_param(Stack* stack, char* id, STipo tipo, int index, Lexema* owner) {
    add_lexema(stack, L_PARAMETER);

    stack->lexemas[stack->n_lexema - 1]->param.id = malloc(strlen(id) * sizeof(char) + 1);
    strcpy(stack->lexemas[stack->n_lexema - 1]->param.id, id);

    stack->lexemas[stack->n_lexema - 1]->param.tipo = tipo;
    stack->lexemas[stack->n_lexema - 1]->param.index = index;
    stack->lexemas[stack->n_lexema - 1]->param.owner = owner;

    return stack->lexemas[stack->n_lexema - 1];
}

/**
 * Encontra um lexema na pilha.
 * 
 * @param stack Stack a qual o lexema pertence.
 * @param lexema Nome do lexema.
 * 
 * @return Endereço do lexema ou NULL quando não encontrado.
 */
Lexema* find(Stack* stack, char* lexema) {    
    while (stack != NULL) {
        for (int i = 0; i < stack->n_lexema; i++) {
            switch(stack->lexemas[i]->tipo) {
                case L_VARIABLE:
                    if (!strcmp(stack->lexemas[i]->var.id, lexema)) return stack->lexemas[i];
                    break;
                case L_FUNCTION:
                    if (!strcmp(stack->lexemas[i]->func.id, lexema)) return stack->lexemas[i];
                    break;
                case L_PARAMETER:
                    if (!strcmp(stack->lexemas[i]->param.id, lexema)) return stack->lexemas[i];
                    break;
            }
        }

        stack = stack->parent;
    }

    return NULL;
}

void debug(Stack* stack) {
    while (stack != NULL) {
        printf("n_lexema: %d\n", stack->n_lexema);
        printf("lexemas: [");

        for (int i = 0; i < stack->n_lexema; i++) {
            switch (stack->lexemas[i]->tipo) {
                case L_VARIABLE:
                    printf(" '%s'", stack->lexemas[i]->var.id);
                    break;
                case L_FUNCTION:
                    printf(" '%s'", stack->lexemas[i]->func.id);
                    break;
                case L_PARAMETER:
                    printf(" '%s'", stack->lexemas[i]->param.id);
                    break;
            }
        }

        printf("\n\n");

        stack = stack->parent;
    }
}