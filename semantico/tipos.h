#ifndef TYPES_H
#define TYPES_H

typedef struct Raiz Raiz;
typedef struct DeclFuncVar DeclFuncVar;
typedef struct DeclVar DeclVar;
typedef struct DeclFunc DeclFunc;
typedef struct Bloco Bloco;
typedef struct ListaParametros ListaParametros;
typedef struct Chamada ChamadaFunc;
typedef struct PrimExpr PrimExpr;
typedef struct UnExpr UnExpr;
typedef struct Operador Operador;
typedef struct Atribuicao Atribuicao;
typedef struct Expr Expr;
typedef struct ComandoUnitario ComandoUnitario;
typedef struct ComandoControleFluxo ComandoControleFluxo;
typedef struct ListaComando ListaComando;

typedef enum { TIPO_NULL, TIPO_INT, TIPO_STR } ETipo;
typedef enum { ATRIBUICAO, OPERADOR, UNARIA } EExpr;
typedef enum { VAR, FUNC } EDeclFuncVar;
typedef enum { UNITARIO, CONTROLE_FLUXO, BLOCO } EListaComando;
typedef enum { SE_ENTAO, SE_SENAO, ENQUANTO} EComandoControleFluxo;
typedef enum { EXPR, RETORNE, LEIA, ESCREVA } EComandoUnitario;
typedef enum { NONE, NEGATIVO, NEGACAO} EUnExpr;
typedef enum { E, OU, NAO, IGUALDADE, DIFERENCA, MAIOR_QUE, MENOR_QUE, MAIOR_IGUAL, MENOR_IGUAL, MAIS, MENOS, MULTIPLICACAO, DIVISAO } EOperador;
typedef enum { CHAMADA_VAR, CHAMADA_FUNC, CONST_STR, CONST_INT, EXPRESSAO } EPrimExpr;

typedef struct Chamada {
    char* id;
    Expr* listaExpr;
} Chamada;

typedef struct PrimExpr {
    EPrimExpr tipo;
    union {
        char* valor;
        struct Chamada chamada;
        struct Expr* expr;
    };
} PrimExpr;

typedef struct UnExpr {
    EUnExpr tipo;
    PrimExpr* primExpr;
} UnExpr;

typedef struct Operador {
    EOperador tipo;
    Expr* esquerda;
    Expr* direita;
} Operador;

typedef struct Atribuicao {
    char* id;
    Expr* expr;
} Atribuicao;

typedef struct Expr {
    EExpr tipo;
    union {
        UnExpr* unaria;
        Operador* operador;
        Atribuicao* atribuicao;
    };
    Expr* next;
} Expr;

typedef struct ComandoUnitario {
    EComandoUnitario tipo;
    Expr* expr;
} ComandoUnitario;

typedef struct ComandoControleFluxo {
    EComandoControleFluxo tipo;
    Expr* expr; 
    struct ListaComando* primeiroComando;
    struct ListaComando* segundoComando;
} ComandoControleFluxo;

typedef struct ListaComando {
    EListaComando tipo;
    union {
        ComandoUnitario* comandoUnitario;
        ComandoControleFluxo* comandoControleFluxo;
        Bloco* bloco;
    };
    struct ListaComando* next;
} ListaComando;

typedef struct Bloco {
    DeclFuncVar* declFuncVar;
    ListaComando* listaComando; 
} Bloco;

typedef struct ListaParametros {
    char* id;
    ETipo tipo;
    struct ListaParametros* next;
} ListaParametros;

typedef struct DeclFunc {
    char* id;
    ETipo tipo;
    ListaParametros* listaParametros;
    Bloco* bloco;
} DeclFunc;

typedef struct DeclVar {
    char* id;
    ETipo tipo;
} DeclVar;

typedef struct DeclFuncVar {
    EDeclFuncVar tipo;
    union {
        DeclVar* declVar;
        DeclFunc* declFunc;
    };
    struct DeclFuncVar* next;
} DeclFuncVar;

typedef struct Raiz {
    DeclFuncVar* declFuncVar;
    Bloco* bloco;
} Raiz;

#endif