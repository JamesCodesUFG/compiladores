#ifndef _STACK_H
#define _STACK_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    typedef enum { S_TIPO_INT, S_TIPO_STR } STipo;

    typedef enum { L_FUNCTION, L_VARIABLE, L_PARAMETER } LexemaTipo;

    typedef struct {
        STipo tipo;
        int index;
        char* id;
    } Variable;

    typedef struct {
        STipo tipo;
        int n_params;
        char* id;
    } Function;

    typedef struct {
        STipo tipo;
        Function* owner;
        int index;
        char* id;
    } Parameter;

    typedef struct {
        LexemaTipo tipo;
        union {
            Variable var;
            Function func;
            Parameter param;
        };
    } Lexema;

    typedef struct Stack {
        int n_lexema;

        Lexema** lexemas;

        struct Stack* child;
        struct Stack* parent;
    } Stack;

    Stack* init();

    Stack* up(Stack* current);
    Stack* down(Stack* current);

    Lexema* add_var(Stack* current, char* id, STipo tipo, int index);
    Lexema* add_func(Stack* current, char* id, int n_params, STipo tipo);
    Lexema* add_param(Stack* current, char* id, STipo tipo, int index, Lexema* owner);

    Lexema* gfind(Stack* current, char* lexema);
    Lexema* efind(Stack* current, char* lexema);

    void delete_stack(Stack* stack);

    void debug(Stack* stack);

#endif