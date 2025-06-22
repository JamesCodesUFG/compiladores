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

DeclFuncVar* criarVariavelSemTipo(char* nome, DeclFuncVar* next) {
    DeclFuncVar* decl = (DeclFuncVar*)malloc(sizeof(DeclFuncVar));

    if (!decl) {
        fprintf(stderr, "Erro ao alocar memória para Declaração de Variável\n");
        exit(EXIT_FAILURE);
    }

    decl->tipo = TipoDeclaracao.VAR;
    decl->declVar = (DeclVar*)malloc(sizeof(DeclVar));

    if (!decl->declVar) {
        fprintf(stderr, "Erro ao alocar memória para Declaração de Variável\n");
        exit(EXIT_FAILURE);
    }

    decl->declVar->nome = nome;
    decl->declVar->tipo = NULL;
    decl->next = next;

    return decl;
}

DeclFuncVar* criarVariavelComTipo(Tipo tipo, char* nome, DeclFuncVar* filhos, DeclFuncVar* next) {
    DeclFuncVar* decl = (DeclFuncVar*)malloc(sizeof(DeclFuncVar));

    if (!decl) {
        fprintf(stderr, "Erro ao alocar memória para Declaração de Variável\n");
        exit(EXIT_FAILURE);
    }

    decl->tipo = TipoDeclaracao.VAR;
    decl->declVar = (DeclVar*)malloc(sizeof(DeclVar));

    if (!decl->declVar) {
        fprintf(stderr, "Erro ao alocar memória para Declaração de Variável\n");
        exit(EXIT_FAILURE);
    }

    decl->declVar->nome = nome;
    decl->declVar->tipo = tipo;
    decl->next = filhos;

    DeclFuncVar* current = filhos;

    while (current->next != NULL) {
        current->declVar->tipo = tipo;
        
        current = current->next;
    }

    current->next = next;

    return decl;
}

DeclFuncVar* criarFuncaoSemTipo(Parametro* parametro, Bloco* bloco) {
    DeclFuncVar* decl = (DeclFuncVar*)malloc(sizeof(DeclFuncVar));

    if (!decl) {
        fprintf(stderr, "Erro ao alocar memória para Declaração de Função\n");
        exit(EXIT_FAILURE);
    }

    decl->tipo = TipoDeclaracao.FUNC;
    decl->declFunc = (DeclFunc*)malloc(sizeof(DeclFunc));

    if (!decl->declFunc) {
        fprintf(stderr, "Erro ao alocar memória para Declaração de Função\n");
        exit(EXIT_FAILURE);
    }

    decl->declFunc->nome = NULL; // Nome será definido posteriormente
    decl->declFunc->tipo = NULL; // Tipo será definido posteriormente
    decl->declFunc->parametros = parametro;
    decl->declFunc->bloco = bloco;
    decl->next = NULL;

    return decl;
}

DeclFuncVar* criarFuncaoComTipo(Tipo tipo, char* nome, DeclFuncVar* funcao, DeclFuncVar* next) {
    funcao->declFunc->nome = nome;
    funcao->declFunc->tipo = tipo;
    funcao->next = next;

    return funcao;
}

Parametro* criarParametro(Tipo tipo, char* nome, Parametro* next) {
    Parametro* parametro = (Parametro*)malloc(sizeof(Parametro));

    if (!parametro) {
        fprintf(stderr, "Erro ao alocar memória para Parâmetro\n");
        exit(EXIT_FAILURE);
    }

    parametro->nome = nome;
    parametro->tipo = tipo;
    parametro->next = next;

    return parametro;
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

    comando->tipo = EListaComando.BLOCO;
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

    comando->tipo = EListaComando.UNNITARIO;
    comando->comandoUnitario = (ComandoUnitario*)malloc(sizeof(ComandoUnitario));

    if (!comando->comandoUnitario) {
        fprintf(stderr, "Erro ao alocar memória para Comando Unitário\n");
        exit(EXIT_FAILURE);
    }

    comando->comandoUnitario->expr = tipo;
    comando->next = NULL;

    return comando;
}

ListaComando* criarComandoControleFluxo(Expr* expr, ListaComando* primeiroComando, ListaComando* segundoComando, EComandoControleFluxo tipo) {
    ListaComando* comando = (ListaComando*)malloc(sizeof(ListaComando));

    if (!comando) {
        fprintf(stderr, "Erro ao alocar memória para Comando de Controle de Fluxo\n");
        exit(EXIT_FAILURE);
    }

    comando->tipo = EListaComando.CONTROLE_FLUXO;
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

Expr* criarExprAtr(char* id, Atribuicao* expr) {
    Expr* expressao = (Expr*)malloc(sizeof(Expr));

    if (!expressao) {
        fprintf(stderr, "Erro ao alocar memória para Expressão de Atribuição\n");
        exit(EXIT_FAILURE);
    }

    expressao->tipo = EExpr.ATRIBUICAO;
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

Expr* criarExprOperador(Expr* esquerda, Expr* direita, TipoOperador operador) {
    Expr* expressao = (Expr*)malloc(sizeof(Expr));

    if (!expressao) {
        fprintf(stderr, "Erro ao alocar memória para Expressão de Operador\n");
        exit(EXIT_FAILURE);
    }

    expressao->tipo = EExpr.OPERADOR;
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

Expr* criarExprUnaria(Expr* expr, EOperador tipo) {
    Expr* expressao = (Expr*)malloc(sizeof(Expr));

    if (!expressao) {
        fprintf(stderr, "Erro ao alocar memória para Expressão Unária\n");
        exit(EXIT_FAILURE);
    }

    expressao->tipo = EExpr.UNARIA;
    expressao->unaria = (UnExpr*)malloc(sizeof(UnExpr));

    if (!expressao->unaria) {
        fprintf(stderr, "Erro ao alocar memória para Unário\n");
        exit(EXIT_FAILURE);
    }

    expressao->unaria->expr = expr;
    expressao->unaria->tipo = tipo;
    expressao->next = NULL;

    return expressao;
}

Expr* criarExprLogica(Expr* esquerda, Expr* direita, TipoOperador operador) {
    Expr* expressao = (Expr*)malloc(sizeof(Expr));

    if (!expressao) {
        fprintf(stderr, "Erro ao alocar memória para Expressão Lógica\n");
        exit(EXIT_FAILURE);
    }

    expressao->tipo = EExpr.LOGICA;
    expressao->logica = (Logica*)malloc(sizeof(Logica));

    if (!expressao->logica) {
        fprintf(stderr, "Erro ao alocar memória para Lógica\n");
        exit(EXIT_FAILURE);
    }

    expressao->logica->esquerda = esquerda;
    expressao->logica->direita = direita;
    expressao->logica->operador = operador;

    return expressao;
}

Expr* criarExprAritmetica(Expr* esquerda, Expr* direita, TipoOperador operador) {
    Expr* expressao = (Expr*)malloc(sizeof(Expr));

    if (!expressao) {
        fprintf(stderr, "Erro ao alocar memória para Expressão Aritmética\n");
        exit(EXIT_FAILURE);
    }

    expressao->tipo = EExpr.ARITMETICA;
    expressao->aritmetica = (Aritmetica*)malloc(sizeof(Aritmetica));

    if (!expressao->aritmetica) {
        fprintf(stderr, "Erro ao alocar memória para Aritmética\n");
        exit(EXIT_FAILURE);
    }

    expressao->aritmetica->esquerda = esquerda;
    expressao->aritmetica->direita = direita;
    expressao->aritmetica->operador = operador;
    expressao->next = NULL;

    return expressao;
}

Expr* criarExprRelacional(Expr* esquerda, Expr* direita, TipoOperador operador) {
    Expr* expressao = (Expr*)malloc(sizeof(Expr));

    if (!expressao) {
        fprintf(stderr, "Erro ao alocar memória para Expressão Relacional\n");
        exit(EXIT_FAILURE);
    }

    expressao->tipo = EExpr.RELACIONAL;
    expressao->relacional = (Relacional*)malloc(sizeof(Relacional));

    if (!expressao->relacional) {
        fprintf(stderr, "Erro ao alocar memória para Relacional\n");
        exit(EXIT_FAILURE);
    }

    expressao->relacional->esquerda = esquerda;
    expressao->relacional->direita = direita;
    expressao->relacional->operador = operador;
    expressao->next = NULL;

    return expressao;
}

Expr* criarExprAtribuicao(Expr* esquerda, Expr* direita) {
    Expr* expressao = (Expr*)malloc(sizeof(Expr));

    if (!expressao) {
        fprintf(stderr, "Erro ao alocar memória para Expressão de Atribuição\n");
        exit(EXIT_FAILURE);
    }

    expressao->tipo = EExpr.ATRIBUICAO;
    expressao->atribuicao = (Atribuicao*)malloc(sizeof(Atribuicao));

    if (!expressao->atribuicao) {
        fprintf(stderr, "Erro ao alocar memória para Atribuição\n");
        exit(EXIT_FAILURE);
    }

    expressao->atribuicao->esquerda = esquerda;
    expressao->atribuicao->direita = direita;
    expressao->next = NULL;

    return expressao;
}

Expr* criarExprChamada(char* id, ListaExpr* listaExpr, TipoPrimExpr tipo) {
    Expr* expressao = (Expr*)malloc(sizeof(Expr));

    if (!expressao) {
        fprintf(stderr, "Erro ao alocar memória para Expressão de Chamada\n");
        exit(EXIT_FAILURE);
    }

    expressao->tipo = EExpr.CHAMADA;
    expressao->unaria = (UnExpr*)malloc(sizeof(UnExpr));

    if (!expressao->unaria) {
        fprintf(stderr, "Erro ao alocar memória para Chamada\n");
        exit(EXIT_FAILURE);
    }

    expressao->unaria->primExpr = (PrimExpr*)malloc(sizeof(PrimExpr));

    if (!expressao->unaria->primExpr) {
        fprintf(stderr, "Erro ao alocar memória para PrimExpr\n");
        exit(EXIT_FAILURE);
    }

    expressao->unaria->primExpr->id = id;
    expressao->unaria->primExpr->listaExpr = listaExpr;
    expressao->unaria->primExpr->tipo = tipo;
    expressao->next = NULL;

    return expressao;
}

Expr* criarExprConst(str* valor, TipoPrimExpr tipo) {
    Expr* expressao = (Expr*)malloc(sizeof(Expr));

    if (!expressao) {
        fprintf(stderr, "Erro ao alocar memória para Expressão Constante\n");
        exit(EXIT_FAILURE);
    }

    expressao->tipo = EExpr.CONSTANTE;
    expressao->unaria = (UnExpr*)malloc(sizeof(UnExpr));

    if (!expressao->constante) {
        fprintf(stderr, "Erro ao alocar memória para Constante\n");
        exit(EXIT_FAILURE);
    }

    expressao->unaria->primExpr = (PrimExpr*)malloc(sizeof(PrimExpr));

    expressao->unaria->primExpr->valor = valor;
    expressao->unaria->primExpr->tipo = tipo;
    expressao->next = NULL;

    return expressao;
}

Expr* criarExprParent(Expr* expr) {
    Expr* expressao = (Expr*)malloc(sizeof(Expr));

    if (!expressao) {
        fprintf(stderr, "Erro ao alocar memória para Expressão Parêntese\n");
        exit(EXIT_FAILURE);
    }

    expressao->tipo = EExpr.PARENTESE;
    expressao->unaria = (UnExpr*)malloc(sizeof(UnExpr));

    if (!expressao->parentese) {
        fprintf(stderr, "Erro ao alocar memória para Parêntese\n");
        exit(EXIT_FAILURE);
    }

    expressao->unaria->primExpr = (PrimExpr*)malloc(sizeof(PrimExpr));

    expressao->unaria->primExpr->expr = expr;
    expressao->next = NULL;

    return expressao;
}

