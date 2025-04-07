#ifndef STACK.H
#define STACK.H

    #include <stdlib.h>
    #include <string.h>

    typedef enum { INT, STR } Type;

    typedef enum { FUNCTION, VARIABLE, PARAMETER } LexemeType;

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

        struct Stack** parent;
        struct Stack** children;
    } Stack;


    Stack* init();

    void up(Stack* current);
    void down(Stack* current);

    void add(Stack* current, char* name, Type type, int index);
    void add(Stack* current, char* name, int n_params, Type r_type);
    void add(Stack* current, char* name, Type type, int index, Lexeme* owner);

    Lexeme* find(Stack* current, char* lexeme);

#endif