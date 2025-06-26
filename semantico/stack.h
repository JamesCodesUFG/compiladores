#ifndef STACK_H
#define STACK_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    // -------------------- ENUM --------------------
    typedef enum { S_TIPO_INT, S_TIPO_STR } STipo;

    typedef enum { L_FUNCTION, L_VARIABLE, L_PARAMETER } LexemaTipo;

    // -------------------- STRUCTS & UNIONS --------------------

    typedef struct {
        StackVarTipo tipo;
        int index;
        char* id;
    } Variable;

    typedef struct {
        StackVarTipo tipo;
        int n_params;
        char* id;
    } Function;

    typedef struct {
        StackVarTipo tipo;
        Function* owner;
        int index;
        char* id;
    } Parameter;

    typedef struct {
        LexemaTipo tipo;
        typedef union {
            Variable var;
            Function func;
            Parameter param;
        }
    } Lexema;

    typedef struct Stack {
        int n_lexema;

        Lexeme** lexemas;

        struct Stack* child;
        struct Stack* parent;
    } Stack;

    // -------------------- FUNCTIONS -------------------- //
    Stack* init();

    Stack* up(Stack* current);
    Stack* down(Stack* current);

    Lexema* add_var(Stack* current, char* id, STipo tipo, int index);
    Lexema* add_func(Stack* current, char* id, int n_params, STipo tipo);
    Lexema* add_param(Stack* current, char* id, STipo tipo, int index, Lexema* owner);

    Lexema* find(Stack* current, char* lexema);

    void delete_stack(Stack* stack);

    void debug(Stack* stack);

#endif