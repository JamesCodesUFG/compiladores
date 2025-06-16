#ifndef TYPES_H
#define TYPES_H

typedef enum {retorne, leia, excreva, novalinha} BuiltIn;
typedef enum {_int, _str} Type;

typedef struct Exec {
    BuiltIn comandoTipo;
    Expr expr;
    struct Exec* next;

} Exec;

typedef struct Params {
    char* nome;
    Type* tipo;
    struct Params* next;
} Params;

typedef struct FuncCorpo {
    Params* params;
} FuncCorpo;

typedef struct DeclFuncVar {
    char* name;
    Type* type;
    struct DeclFuncVar* corpo;
    struct DeclFuncVar* next;
} DeclFuncVar;

//Definicao de um no da arvore abstrata.
typedef struct Raiz {
    DeclFuncVar* declVar;
} Toperador;

#endif