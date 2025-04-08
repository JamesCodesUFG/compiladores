#include <stdlib.h>
#include <string.h>

#include "stack.h" 

/**
 * Inicia uma nova stack.
 * 
 * @return Endereço da nova stack.
 */
Stack* init() {
    Stack* stack = malloc(sizeof(Stack));

    stack->n_lexemes = 0;

    stack->lexemes = malloc(0);

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

static void delete_(Stack* stack) {
    for (int i = 0; i < stack->n_lexemes; i++) {
        free(stack->lexemes[i]);
    }

    free(stack->lexemes);

    stack = stack->parent;

    free(stack->child);
}

void delete(Stack* stack) {
    while (stack != NULL) {
        delete_(stack);
    }
}

/**
 * Desce uma camada da pilha sem altera-la.
 * 
 * @param stack Endereço da Stack atual.
 * 
 * @return Novo endereço de Stack.
 */
Stack* down(Stack* stack) {
    return stack->parent;
}

static Lexeme* add(Stack* stack, LexemeType type) {
    stack->lexemes = realloc(stack->lexemes, sizeof(Lexeme) * ++stack->n_lexemes);

    stack->lexemes[stack->n_lexemes - 1] = malloc(sizeof(Lexeme));

    stack->lexemes[stack->n_lexemes - 1]->type = type;
}

/**
 * Adiciona um novo lexema do tipo variável à lista de lexemas da stack.
 * 
 * @param stack Stack a ser manipulada.
 * @param name Nome da variável.
 * @param type Tipo da variável.
 * @param index Posição em que a variável aparece.
 */
Lexeme* add_var(Stack* stack, char* name, Type type, int index) {
    add(stack, VARIABLE);

    stack->lexemes[stack->n_lexemes - 1]->lexeme.func.name = malloc(strlen(name) * sizeof(char) + 1);;
    strcpy(stack->lexemes[stack->n_lexemes - 1]->lexeme.func.name, name);

    stack->lexemes[stack->n_lexemes - 1]->lexeme.var.type = type;
    stack->lexemes[stack->n_lexemes - 1]->lexeme.var.index = index;

    if (stack->lexemes == NULL) {
        printf("Erro ao adicionar nova camada à stack.\n");

        exit(1);
    }

    return stack->lexemes[stack->n_lexemes - 1];
}

/**
 * Adiciona um novo lexema à lista de lexemas da stack.
 * 
 * @param stack Stack a ser manipulada.
 * @param name Nome da variável.
 * @param n_params Quantidade de parâmetros.
 * @param type Tipo do valor de retorno.
 */
Lexeme* add_func(Stack* stack, char* name, int n_params, Type r_type) {
    add(stack, FUNCTION);

    stack->lexemes[stack->n_lexemes - 1]->lexeme.func.name = malloc(strlen(name) * sizeof(char) + 1);;
    strcpy(stack->lexemes[stack->n_lexemes - 1]->lexeme.func.name, name);

    stack->lexemes[stack->n_lexemes - 1]->lexeme.func.n_params = n_params;
    stack->lexemes[stack->n_lexemes - 1]->lexeme.func.type = r_type;

    if (stack->lexemes == NULL) {
        printf("Erro ao adicionar nova camada à stack.\n");

        exit(1);
    }

    return stack->lexemes[stack->n_lexemes - 1];
}

/**
 * Adiciona um novo lexema à lista de lexemas da stack.
 * 
 * @param stack Stack a ser manipulada.
 * @param name Nome da variável.
 * @param type Tipo da variável.
 * @param index Posição em que a variável aparece.
 * @param owner Lexeme do tipo função a qual o parâmetro pertence.
 */
Lexeme* add_param(Stack* stack, char* name, Type type, int index, Lexeme* owner) {
    add(stack, PARAMETER);

    stack->lexemes[stack->n_lexemes - 1]->lexeme.param.name = malloc(strlen(name) * sizeof(char) + 1);
    strcpy(stack->lexemes[stack->n_lexemes - 1]->lexeme.param.name, name);

    stack->lexemes[stack->n_lexemes - 1]->lexeme.param.type = type;
    stack->lexemes[stack->n_lexemes - 1]->lexeme.param.index = index;
    stack->lexemes[stack->n_lexemes - 1]->lexeme.param.owner = owner;

    if (stack->lexemes == NULL) {
        printf("Erro ao adicionar nova camada à stack.\n");

        exit(1);
    }

    return stack->lexemes[stack->n_lexemes - 1];
}

/**
 * Encontra um lexema na pilha.
 * 
 * @param stack Stack a qual o lexema pertence.
 * @param lexeme Nome do lexema.
 * 
 * @return Endereço do lexema ou NULL quando não encontrado.
 */
Lexeme* find(Stack* stack, char* lexeme) {    
    while (stack != NULL) {
        for (int i = 0; i < stack->n_lexemes; i++) {
            switch(stack->lexemes[i]->type) {
                case VARIABLE:
                    if (!strcmp(stack->lexemes[i]->lexeme.var.name, lexeme)) return stack->lexemes[i];
                    break;
                case FUNCTION:
                    if (!strcmp(stack->lexemes[i]->lexeme.func.name, lexeme)) return stack->lexemes[i];
                    break;
                case PARAMETER:
                    if (!strcmp(stack->lexemes[i]->lexeme.param.name, lexeme)) return stack->lexemes[i];
                    break;
            }
        }

        stack = stack->parent;
    }

    return NULL;
}