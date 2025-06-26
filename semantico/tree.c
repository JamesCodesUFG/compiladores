#include "tipos.h"
#include "tree.h"

Raiz* criarRaiz(DeclFuncVar* declFuncVar, Bloco* bloco) {
    Raiz* raiz = (Raiz*)malloc(sizeof(Raiz));

    if (!raiz) {
        fprintf(stderr, "Erro ao alocar memória para Raiz\n");
        exit(EXIT_FAILURE);
    }

    raiz->declFuncVar = declFuncVar;
    raiz->bloco = bloco;

    return raiz;
}

DeclFuncVar* criarVariavelSemTipo(char* id, DeclFuncVar* next) {
    DeclFuncVar* decl = (DeclFuncVar*)malloc(sizeof(DeclFuncVar));

    if (!decl) {
        fprintf(stderr, "Erro ao alocar memória para Declaração de Variável\n");
        exit(EXIT_FAILURE);
    }

    decl->tipo = VAR;
    decl->declVar = (DeclVar*)malloc(sizeof(DeclVar));

    if (!decl->declVar) {
        fprintf(stderr, "Erro ao alocar memória para Declaração de Variável\n");
        exit(EXIT_FAILURE);
    }

    decl->declVar->id = id;
    decl->declVar->tipo = TIPO_NULL;
    decl->next = next;

    return decl;
}

DeclFuncVar* criarVariavelComTipo(ETipo tipo, char* id, DeclFuncVar* filhos, DeclFuncVar* next) {
    DeclFuncVar* decl = (DeclFuncVar*)malloc(sizeof(DeclFuncVar));

    if (!decl) {
        fprintf(stderr, "Erro ao alocar memória para Declaração de Variável\n");
        exit(EXIT_FAILURE);
    }

    decl->tipo = VAR;
    decl->declVar = (DeclVar*)malloc(sizeof(DeclVar));

    if (!decl->declVar) {
        fprintf(stderr, "Erro ao alocar memória para Declaração de Variável\n");
        exit(EXIT_FAILURE);
    }

    decl->declVar->id = id;
    decl->declVar->tipo = tipo;
    decl->next = filhos;

    DeclFuncVar* current = filhos;

    while (1) {
        current->declVar->tipo = tipo;
        
        if (current->next == NULL) {
            current->next = next;
            break;
        }

        current = current->next;
    }

    

    return decl;
}

DeclFuncVar* criarFuncaoSemTipo(ListaParametros* listaParametros, Bloco* bloco) {
    DeclFuncVar* decl = (DeclFuncVar*)malloc(sizeof(DeclFuncVar));

    if (!decl) {
        fprintf(stderr, "Erro ao alocar memória para Declaração de Função\n");
        exit(EXIT_FAILURE);
    }

    decl->tipo = FUNC;
    decl->declFunc = (DeclFunc*)malloc(sizeof(DeclFunc));

    if (!decl->declFunc) {
        fprintf(stderr, "Erro ao alocar memória para Declaração de Função\n");
        exit(EXIT_FAILURE);
    }

    decl->declFunc->id = NULL;
    decl->declFunc->tipo = TIPO_NULL;
    decl->declFunc->listaParametros = listaParametros;
    decl->declFunc->bloco = bloco;
    decl->next = NULL;

    return decl;
}

DeclFuncVar* criarFuncaoComTipo(ETipo tipo, char* id, DeclFuncVar* funcao, DeclFuncVar* next) {
    funcao->declFunc->id = id;
    funcao->declFunc->tipo = tipo;
    funcao->next = next;

    return funcao;
}

ListaParametros* criarParametro(ETipo tipo, char* id, ListaParametros* next) {
    ListaParametros* listaParametros = (ListaParametros*)malloc(sizeof(ListaParametros));

    if (!listaParametros) {
        fprintf(stderr, "Erro ao alocar memória para Parâmetro\n");
        exit(EXIT_FAILURE);
    }

    listaParametros->id = id;
    listaParametros->tipo = tipo;
    listaParametros->next = next;

    return listaParametros;
}

Bloco* criarBloco(DeclFuncVar* declFuncVar, ListaComando* listaComando) {
    Bloco* bloco = (Bloco*)malloc(sizeof(Bloco));

    if (!bloco) {
        fprintf(stderr, "Erro ao alocar memória para Bloco\n");
        exit(EXIT_FAILURE);
    }

    bloco->declFuncVar = declFuncVar;
    bloco->listaComando = listaComando;

    return bloco;
}

ListaComando* linkListaComando(ListaComando* primeiro, ListaComando* segundo) {
    if (primeiro == NULL) return segundo;

    primeiro->next = segundo;

    return primeiro;
}

ListaComando* criarComandoBloco(Bloco* bloco) {
    ListaComando* comando = (ListaComando*)malloc(sizeof(ListaComando));

    if (!comando) {
        fprintf(stderr, "Erro ao alocar memória para Comando de Bloco\n");
        exit(EXIT_FAILURE);
    }

    comando->tipo = BLOCO;
    comando->bloco = bloco;
    comando->next = NULL;

    return comando;
}

ListaComando* criarComandoUnitario(Expr* expr, EComandoUnitario tipo) {
    ListaComando* comando = (ListaComando*)malloc(sizeof(ListaComando));

    if (!comando) {
        fprintf(stderr, "Erro ao alocar memória para Comando Unitário\n");
        exit(EXIT_FAILURE);
    }

    comando->tipo = UNITARIO;
    comando->comandoUnitario = (ComandoUnitario*)malloc(sizeof(ComandoUnitario));

    if (!comando->comandoUnitario) {
        fprintf(stderr, "Erro ao alocar memória para Comando Unitário\n");
        exit(EXIT_FAILURE);
    }

    comando->comandoUnitario->tipo = tipo;
    comando->comandoUnitario->expr = expr;
    comando->next = NULL;

    return comando;
}

ListaComando* criarComandoControleFluxo(Expr* expr, ListaComando* primeiroComando, ListaComando* segundoComando, EComandoControleFluxo tipo) {
    ListaComando* comando = (ListaComando*)malloc(sizeof(ListaComando));

    if (!comando) {
        fprintf(stderr, "Erro ao alocar memória para Comando de Controle de Fluxo\n");
        exit(EXIT_FAILURE);
    }

    comando->tipo = CONTROLE_FLUXO;
    comando->comandoControleFluxo = (ComandoControleFluxo*)malloc(sizeof(ComandoControleFluxo));

    if (!comando->comandoControleFluxo) {
        fprintf(stderr, "Erro ao alocar memória para Comando de Controle de Fluxo\n");
        exit(EXIT_FAILURE);
    }

    comando->comandoControleFluxo->expr = expr;
    comando->comandoControleFluxo->primeiroComando = primeiroComando;
    comando->comandoControleFluxo->segundoComando = segundoComando;
    comando->comandoControleFluxo->tipo = tipo;
    comando->next = NULL;

    return comando;
}

Expr* criarExprAtribuicao(char* id, Expr* expr) {
    Expr* expressao = (Expr*)malloc(sizeof(Expr));

    if (!expressao) {
        fprintf(stderr, "Erro ao alocar memória para Expressão de Atribuição\n");
        exit(EXIT_FAILURE);
    }

    expressao->tipo = ATRIBUICAO;
    expressao->atribuicao = (Atribuicao*)malloc(sizeof(Atribuicao));

    if (!expressao->atribuicao) {
        fprintf(stderr, "Erro ao alocar memória para Atribuição\n");
        exit(EXIT_FAILURE);
    }

    expressao->atribuicao->id = id;
    expressao->atribuicao->expr = expr;
    expressao->next = NULL;

    return expressao;
}

Expr* criarExprOperador(Expr* esquerda, Expr* direita, EOperador operador) {
    Expr* expressao = (Expr*)malloc(sizeof(Expr));

    if (!expressao) {
        fprintf(stderr, "Erro ao alocar memória para Expressão de Operador\n");
        exit(EXIT_FAILURE);
    }

    expressao->tipo = OPERADOR;
    expressao->operador = (Operador*)malloc(sizeof(Operador));

    if (!expressao->operador) {
        fprintf(stderr, "Erro ao alocar memória para Operador\n");
        exit(EXIT_FAILURE);
    }

    expressao->operador->esquerda = esquerda;
    expressao->operador->direita = direita;
    expressao->operador->tipo = operador;
    expressao->next = NULL;

    return expressao;
}

Expr* criarExprUnaria(PrimExpr* primExpr, EOperador tipo) {
    Expr* expressao = (Expr*)malloc(sizeof(Expr));

    if (!expressao) {
        fprintf(stderr, "Erro ao alocar memória para Expressão Unária\n");
        exit(EXIT_FAILURE);
    }

    expressao->tipo = UNARIA;
    expressao->unaria = (UnExpr*)malloc(sizeof(UnExpr));

    if (!expressao->unaria) {
        fprintf(stderr, "Erro ao alocar memória para Unário\n");
        exit(EXIT_FAILURE);
    }

    expressao->unaria->primExpr = primExpr;
    expressao->unaria->tipo = tipo;
    expressao->next = NULL;

    return expressao;
}

PrimExpr* criarPrimExprChamada(char* id, Expr* listaExpr, EPrimExpr tipo) {
    PrimExpr* primExpr = (PrimExpr*)malloc(sizeof(PrimExpr));

    if (!primExpr) {
        fprintf(stderr, "Erro ao alocar memória para Expressão de Chamada\n");
        exit(EXIT_FAILURE);
    }

    primExpr->tipo = tipo;
    primExpr->chamada.id = id;
    primExpr->chamada.listaExpr = listaExpr;

    return primExpr;
}

PrimExpr* criarPrimExprConst(char* valor, EPrimExpr tipo) {
    PrimExpr* primExpr = (PrimExpr*)malloc(sizeof(PrimExpr));

    if (!primExpr) {
        fprintf(stderr, "Erro ao alocar memória para Expressão Constante\n");
        exit(EXIT_FAILURE);
    }

    primExpr->tipo = tipo;
    primExpr->valor = valor;

    return primExpr;
}

PrimExpr* criarPrimExprParent(Expr* expr) {
    PrimExpr* primExpr = (PrimExpr*)malloc(sizeof(PrimExpr));

    if (!primExpr) {
        fprintf(stderr, "Erro ao alocar memória para Expressão Parêntese\n");
        exit(EXIT_FAILURE);
    }

    primExpr->tipo = EXPRESSAO;
    primExpr->expr = expr;

    return primExpr;
}

Expr* linkExpr(Expr* primeiro, Expr* segundo) {
    if (primeiro == NULL) return segundo;

    primeiro->next = segundo;

    return primeiro;
}
