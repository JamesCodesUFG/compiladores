#ifndef TYPES_H
#define TYPES_H

typedef enum { INT, STR } Tipo;
typedef enum { ATRIBUICAO, OPERADOR, PRIMARIO } EExpr;
typedef enum { VAR, FUNC } EDeclaracao;
typedef enum { UNITARIA, CONTROLE_FLUXO, BLOCO } EListaComando;
typedef enum { SE_ENTAO, SE_SENAO, ENQUANTO} EComandoControleFluxo;
typedef enum { EXPR, RETORNE, LEIA, EXCREVA } EComandoUnitario;
typedef enum { NONE, NEGATIVO, NEGACAO} EUnExpr;
typedef enum { E, OU, NAO, IGUALDADE, DIFERENCA, MAIOR_QUE, MENOR_QUE, MAIOR_IGUAL, MENOR_IGUAL, MAIS, MENOS, MULTIPLICACAO, DIVISAO } EOperador;
typedef enum { CHAMADA_VAR, CHAMADA_FUNC, CONST_STR, CONST_INT, EXPRESSAO } EPrimExpr;

typedef struct Chamada {
    char* nome;
    Expr* expr;
} ChamadaFunc;

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
} _Expr;

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
    struct Comando* primeiroComando;
    struct Comando* segundoComando;
} ComandoControleFluxo;

typedef struct ListaComando {
    EListaComando tipo;
    union {
        ComandoUnitario* comandoUnitario;
        ComandoControleFluxo* comandoControleFluxo;
        Bloco* bloco;
    }
    struct Comando* next;
} ListaComando;

typedef struct Bloco {
    DeclFuncVar* declFuncVar;
    ListaComando* listaComando; 
} Bloco;

typedef struct ListaParametros {
    char* nome;
    Tipo* tipo;
    struct Parametro* next;
} ListaParametros;

typedef struct _DeclFunc {
    char* id;
    Tipo tipo;
    ListaParametros* listaParametros;
    Bloco* bloco;
} _DeclFunc;

typedef struct DeclVar {
    char* id;
    Tipo tipo;
} _DeclVar;

typedef struct DeclFuncVar {
    EDeclaracao tipo;
    union {
        _DeclVar* declVar;
        _DeclFunc* declFunc;
    }
    struct DeclFuncVar* next;
} DeclFuncVar;

typedef struct Raiz {
    DeclFuncVar* declFuncVar;
    Bloco* bloco;
} Toperador;

#endif