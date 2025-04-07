#include <stdlib.h>
#include <string.h>

#include "stack.h"

/**
 * Cria uma nova stack.
 * 
 * @param lexeme
 * @param value
 * 
 * @return 
 */
Stack* init() {
    Stack* stack = malloc(sizeof(Stack));

    stack->n_lexemes = 0;

    stack->lexemes = malloc(0);

    stack->parent = NULL;
    stack->children = NULL;

    return stack;
}

/**
 * Sobe uma camada após adicionar uma nova camada à pilha.
 * 
 * @param current Endereço da stack atual.
 * 
 * @return Novo endereço de Stack.
 */
void up(Stack* current) {
    Stack* new = init();

    new->parent = current;
    
    current->children;

    return new;
}

/**
 * Desce uma camada da pilha sem altera-la.
 * 
 * @param current Endereço da Stack atual.
 * 
 * @return Novo endereço de Stack.
 */
void down(Stack* current) {
    return current->parent;
}

/**
 * Adiciona um novo lexema à lista de lexemas da stack.
 * 
 * @param current Ponteiro da Stack a ser manipulada.
 * @param lexema Ponteiro para lexema a ser adicionado.
 */
void add(Stack* current, char* name, Type type, int index) {
    current->n_lexemes++;
    
    current->lexemes = realloc(current->lexemes, sizeof(Lexeme) * current->n_lexemes);

    current->lexemes[current->n_lexemes - 1] = malloc(sizeof(Lexeme));

    current->lexemes[current->n_lexemes - 1]->type = VARIABLE;

    current->lexemes[current->n_lexemes - 1]->lexeme.var.name = name;
    current->lexemes[current->n_lexemes - 1]->lexeme.var.type = type;
    current->lexemes[current->n_lexemes - 1]->lexeme.var.index = index;

    if (current->lexemes == NULL) {
        printf("Erro ao adicionar nova camada à stack.\n");

        exit(1);
    }
}

/**
 * Adiciona um novo lexema à lista de lexemas da stack.
 * 
 * @param current Ponteiro da Stack a ser manipulada.
 * @param lexema Ponteiro para lexema a ser adicionado.
 */
void add(Stack* current, char* name, int n_params, Type r_type) {
    current->n_lexemes++;
    
    current->lexemes = realloc(current->lexemes, sizeof(Lexeme) * current->n_lexemes);

    current->lexemes[current->n_lexemes - 1] = malloc(sizeof(Lexeme));

    current->lexemes[current->n_lexemes - 1]->type = FUNCTION;

    current->lexemes[current->n_lexemes - 1]->lexeme.func.name = name;
    current->lexemes[current->n_lexemes - 1]->lexeme.func.n_params = n_params;
    current->lexemes[current->n_lexemes - 1]->lexeme.func.type = r_type;

    if (current->lexemes == NULL) {
        printf("Erro ao adicionar nova camada à stack.\n");

        exit(1);
    }
}

/**
 * Adiciona um novo lexema à lista de lexemas da stack.
 * 
 * @param current Ponteiro da Stack a ser manipulada.
 * @param lexema Ponteiro para lexema a ser adicionado.
 */
void add(Stack* current, char* name, Type type, int index, Lexeme* owner) {
    current->n_lexemes++;
    
    current->lexemes = realloc(current->lexemes, sizeof(Lexeme) * current->n_lexemes);

    current->lexemes[current->n_lexemes - 1] = malloc(sizeof(Lexeme));

    current->lexemes[current->n_lexemes - 1]->type = PARAMETER;

    current->lexemes[current->n_lexemes - 1]->lexeme.param.name = name;
    current->lexemes[current->n_lexemes - 1]->lexeme.param.type = type;
    current->lexemes[current->n_lexemes - 1]->lexeme.param.index = index;
    current->lexemes[current->n_lexemes - 1]->lexeme.param.owner = owner;

    if (current->lexemes == NULL) {
        printf("Erro ao adicionar nova camada à stack.\n");

        exit(1);
    }
}

/**
 * Encontra um lexema na pilha.
 * 
 * @param current
 * @param lexeme
 * 
 * @return 
 */
Lexeme* find(Stack* current, char* lexeme) {    
    while (current->parent != NULL) {
        for (int i = 0; i < current->n_lexemes; i++) {
            if (!strcmp(current->lexemes[i]->value.value_str, lexeme)) {
                return current->lexemes[i];
            }
        }
    }

    return NULL;
}