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

static Lexema* add(Stack* stack, LexemaTipo tipo) {
    stack->lexemas = realloc(stack->lexemas, sizeof(Lexema) * ++stack->n_lexema);

    stack->lexemas[stack->n_lexema - 1] = malloc(sizeof(Lexema));

    stack->lexemas[stack->n_lexema - 1]->tipo = tipo;
}

/**
 * Adiciona um novo lexema do tipo variável à lista de lexemas da stack.
 * 
 * @param stack Stack a ser manipulada.
 * @param id Nome da variável.
 * @param type Tipo da variável.
 * @param index Posição em que a variável aparece.
 */
Lexema* add_var(Stack* stack, char* id, STipo type, int index) {
    add(stack, L_VARIABLE);

    stack->lexemas[stack->n_lexema - 1]->lexema.func.id = malloc(strlen(id) * sizeof(char) + 1);;
    strcpy(stack->lexemas[stack->n_lexema - 1]->lexema.func.id, id);

    stack->lexemas[stack->n_lexema - 1]->lexema.var.type = type;
    stack->lexemas[stack->n_lexema - 1]->lexema.var.index = index;

    if (stack->lexemas == NULL) {
        printf("Erro ao adicionar nova camada à stack.\n");

        exit(1);
    }

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
Lexema* add_func(Stack* stack, char* id, int n_params, Type r_type) {
    add(stack, L_FUNCTION);

    stack->lexemas[stack->n_lexema - 1]->lexema.func.id = malloc(strlen(id) * sizeof(char) + 1);;
    strcpy(stack->lexemas[stack->n_lexema - 1]->lexema.func.id, id);

    stack->lexemas[stack->n_lexema - 1]->lexema.func.n_params = n_params;
    stack->lexemas[stack->n_lexema - 1]->lexema.func.type = r_type;

    if (stack->lexemas == NULL) {
        printf("Erro ao adicionar nova camada à stack.\n");

        exit(1);
    }

    return stack->lexemas[stack->n_lexema - 1];
}

/**
 * Adiciona um novo lexema à lista de lexemas da stack.
 * 
 * @param stack Stack a ser manipulada.
 * @param id Nome da variável.
 * @param type Tipo da variável.
 * @param index Posição em que a variável aparece.
 * @param owner Lexema do tipo função a qual o parâmetro pertence.
 */
Lexema* add_param(Stack* stack, char* id, Type type, int index, Lexema* owner) {
    add(stack, L_PARAMETER);

    stack->lexemas[stack->n_lexema - 1]->lexema.param.id = malloc(strlen(id) * sizeof(char) + 1);
    strcpy(stack->lexemas[stack->n_lexema - 1]->lexema.param.id, id);

    stack->lexemas[stack->n_lexema - 1]->lexema.param.type = type;
    stack->lexemas[stack->n_lexema - 1]->lexema.param.index = index;
    stack->lexemas[stack->n_lexema - 1]->lexema.param.owner = owner;

    if (stack->lexemas == NULL) {
        printf("Erro ao adicionar nova camada à stack.\n");

        exit(1);
    }

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
            switch(stack->lexemas[i]->type) {
                case VARIABLE:
                    if (!strcmp(stack->lexemas[i]->lexema.var.id, lexema)) return stack->lexemas[i];
                    break;
                case FUNCTION:
                    if (!strcmp(stack->lexemas[i]->lexema.func.id, lexema)) return stack->lexemas[i];
                    break;
                case PARAMETER:
                    if (!strcmp(stack->lexemas[i]->lexema.param.id, lexema)) return stack->lexemas[i];
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
            switch (stack->lexemas[i]->type) {
                case VARIABLE:
                    printf(" '%s'", stack->lexemas[i]->lexema.var.id);
                    break;
                case FUNCTION:
                    printf(" '%s'", stack->lexemas[i]->lexema.func.id);
                    break;
                case PARAMETER:
                    printf(" '%s'", stack->lexemas[i]->lexema.param.id);
                    break;
            }
        }

        printf("\n\n");

        stack = stack->parent;
    }
}