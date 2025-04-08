#ifndef STACK_H
#define STACK_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    // -------------------- ENUM --------------------
    typedef enum { INT, STR } Type;

    typedef enum { FUNCTION, VARIABLE, PARAMETER } LexemeType;

    // -------------------- STRUCTS & UNIONS --------------------
    typedef union {
        int value_int;
        char* value_str;
    } Value;

    typedef struct {
        Type type;
        int index;
        char* name;
    } Variable;

    typedef struct {
        Type type;
        int n_params;
        char* name;
    } Function;

    typedef struct {
        Type type;
        Function* owner;
        int index;
        char* name;
    } Parameter;

    typedef union {
        Variable var;
        Function func;
        Parameter param;
    } LexemeUnion;

    typedef struct {
        LexemeType type;
        LexemeUnion lexeme;
    } Lexeme;

    typedef struct Stack {
        int n_lexemes;

        Lexeme** lexemes;

        struct Stack* child;
        struct Stack* parent;
    } Stack;

    // -------------------- FUNCTIONS --------------------
    Stack* init();

    Stack* up(Stack* current);
    Stack* down(Stack* current);

    Lexeme* add_var(Stack* current, char* name, Type type, int index);
    Lexeme* add_func(Stack* current, char* name, int n_params, Type r_type);
    Lexeme* add_param(Stack* current, char* name, Type type, int index, Lexeme* owner);

    Lexeme* find(Stack* current, char* lexeme);

    void delete(Stack* stack);

#endif