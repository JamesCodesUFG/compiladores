#include <stdio.h>
#include <stdlib.h>

#include "tree.h"
#include "stack.h"
#include "tipos.h"

Stack* stack;

void semantico_raiz(Raiz* raiz) {
    printf("Raiz encontrada.\n");

    // Iniciar stack;

    DeclFuncVar* c_declFuncVar = raiz->declFuncVar;

    while (c_declFuncVar != NULL) {
        semantico_decl_func_var(c_declFuncVar);

        c_declFuncVar = c_declFuncVar->next;
    }

    semantico_bloco(raiz->bloco);
}

void semantico_decl_func_var(DeclFuncVar* declFuncVar) {
    switch (declFuncVar->tipo) {
        case VAR:
            semantico_decl_var(declFuncVar->declVar);
            break;
        case FUNC:
            semantico_decl_func(declFuncVar->declFunc);
            break;
        default:
            printf("ERRO: da Tipo DeclFuncVar incorreto.\n");
            exit(1);
    }
}

void semantico_decl_var(DeclVar* declVar) {
    switch (declVar->tipo) {
        case TIPO_INT:
            printf("Variavel '%s' do tipo int encontrado.\n", declVar->id);
            // Verificar se já existe mesmo nome no escopo.
            // Adicionar variável na stack atual.
            break;
        case TIPO_STR:
            printf("Variavel '%s' do tipo int encontrado.\n", declVar->id);
            // Verificar se já existe mesmo nome no escopo.
            // Adicionar variável na stack atual.
            break;
        default:
            printf("ERRO: Tipo da DeclVar incorreto.\n");
            exit(1);
    }
}

void semantico_decl_func(DeclFunc* declFunc) {
    switch (declFunc->tipo) {
        case TIPO_INT:
            printf("Função '%s' do tipo int encontrado.\n", declFunc->id);
            // Verificar se já existe mesmo nome no escopo.
            // Adicionar função na stack atual.
            break;
        case TIPO_STR:
            printf("Função '%s' do tipo int encontrado.\n", declFunc->id);
            // Verificar se já existe mesmo nome no escopo.
            // Adicionar variável na stack atual.
            break;
        default:
            printf("ERRO: Tipo da DeclFunc incorreto.\n");
            exit(1);
    }

    ListaParametros* c_listaParametros = declFunc->listaParametros;

    while (c_listaParametros != NULL) {
        semantico_lista_parametros(c_listaParametros);

        c_listaParametros = c_listaParametros->next;
    }
}

void semantico_lista_parametros(ListaParametros* listaParametros) {
    switch (listaParametros->tipo) {
        case TIPO_INT:
            printf("Parametro '%s' do tipo int encontrado.\n", listaParametros->id);
            // Adicionar parametro na stack atual apontando para a função owner.
            break;
        case TIPO_STR:
            printf("Parametro '%s' do tipo int encontrado.\n", listaParametros->id);
            // Adicionar parametro na stack atual apontando para a função owner.
            break;
        default:
            printf("ERRO: Tipo da ListaParametro incorreto.\n");
            exit(1);
    }
}

void semantico_bloco(Bloco* bloco) {
    printf("Bloco encontrado.");

    // Adicionar novo escopo na stack;

    DeclFuncVar* c_declFuncVar = bloco->declFuncVar;

    while (c_declFuncVar != NULL) {
        semantico_decl_func_var(c_declFuncVar);

        c_declFuncVar = c_declFuncVar->next;
    }

    ListaComando* c_listaComando = bloco->listaComando;

    while (c_listaComando != NULL) {
        semantico_lista_comando(c_listaComando);

        c_listaComando = c_listaComando->next;
    }
}

void semantico_lista_comando(ListaComando* listaComando) {
    switch (listaComando->tipo) {
        case UNITARIO:
            semantico_comando_unitario(listaComando->comandoUnitario);
            break;
        case CONTROLE_FLUXO:
            semantico_comando_controle_fluxo(listaComando->comandoControleFluxo);
            break;
        case BLOCO:
            semantico_bloco(listaComando->bloco);
            break;
        default:
            printf("ERRO: Tipo da ListaComando incorreto.\n");
            exit(1);
    }

    if (listaComando->next != NULL) semantico_lista_comando(listaComando->next);
}

void semantico_comando_controle_fluxo(ComandoControleFluxo* comando) {
    switch (comando->tipo) {
        case SE_ENTAO:
            printf("Comando SE_ENTAO encontrado.\n");
            break;
        case SE_SENAO:
            printf("Comando SE_SENAO encontrado.\n");
            break;
        case ENQUANTO:
            printf("Comando ENQUANTO encontrado.\n");
            break;
        default:
            printf("ERRO: Tipo da ListaComando incorreto.\n");
            exit(1);
    }

    semantico_expr(comando->expr);
    semantico_lista_comando(comando->primeiroComando);
    semantico_lista_comando(comando->segundoComando);
}

void semantico_comando_unitario(ComandoUnitario* comando) {
    switch (comando->tipo) {
        case EXPR:
            printf("Comando EXPR encontrado.\n");
            break;
        case RETORNE:
            printf("Comando RETORNE encontrado.\n");
            break;
        case LEIA:
            printf("Comando LEIA encontrado.\n");
            break;
        case ESCREVA:
            printf("Comando ESCREVA encontrado.\n");
            break;
        default:
            printf("ERRO: Tipo da ComandoUnitario incorreto.\n");
            exit(1);
    }

    semantico_expr(comando->expr);
}

void semantico_expr(Expr* expr) {
    switch (expr->tipo) {
        case ATRIBUICAO:
            semantico_atribuicao(expr->atribuicao);
            break;
        case OPERADOR:
            semantico_operador(expr->operador);
            break;
        case UNARIA:
            semantico_un_expr(expr->unaria);
            break;
        default:
            printf("ERRO: Tipo da Expr incorreto.\n");
            exit(1);
    }
}

void semantico_atribuicao(Atribuicao* atribuicao) {
    printf("Atribuicao encontrada, id = '%s'", atribuicao->id);

    // Verificar se a variável existe.

    semantico_expr(atribuicao->expr);
}

void semantico_operador(Operador* operador) {
    switch (operador->tipo) {
        case E:
            printf("Operador E encontrado.\n");
            break;
        case OU:
            printf("Operador OU encontrado.\n");
            break;
        case NAO:
            printf("Operador NAO encontrado.\n");
            break;
        case IGUALDADE:
            printf("Operador IGUALDADE encontrado.\n");
            break;
        case DIFERENCA:
            printf("Operador DIFERENCA encontrado.\n");
            break;
        case MAIOR_QUE:
            printf("Operador MAIOR_QUE encontrado.\n");
            break;
        case MENOR_QUE:
            printf("Operador MENOR_QUE encontrado.\n");
            break;
        case MAIOR_IGUAL:
            printf("Operador MAIOR_IGUAL encontrado.\n");
            break;
        case MENOR_IGUAL:
            printf("Operador MENOR_IGUAL encontrado.\n");
            break;
        case MAIS:
            printf("Operador MAIS encontrado.\n");
            break;
        case MENOS:
            printf("Operador MENOS encontrado.\n");
            break;
        case MULTIPLICACAO:
            printf("Operador MULTIPLICACAO encontrado.\n");
            break;
        case DIVISAO:
            printf("Operador DIVISAO encontrado.\n");
            break;
        default:
            printf("ERRO: Tipo da Operador incorreto.\n");
            exit(1);
    }

    semantico_expr(operador->esquerda);
    semantico_expr(operador->direita);
}

void semantico_un_expr(UnExpr* unExpr) {
    switch (unExpr->tipo) {
        case NONE:
            printf("Expressao unaria NONE encontrado.\n");
        case NEGATIVO:
            printf("Expressao unaria NEGATIVO encontrado.\n");
        case NEGACAO:
            printf("Expressao unaria NEGACAO encontrado.\n");
        default:
            printf("ERRO: Tipo da UnExpr incorreto.\n");
            exit(1);
    }

    semantico_prim_expr(unExpr->primExpr);
}

void semantico_prim_expr(PrimExpr* primExpr) {
    switch (primExpr->tipo) {
        case CHAMADA_VAR:
            printf("Expressao primaria CHAMADA_VAR encontrado.\n");
            semantico_chamada(primExpr->chamada);
            break;
        case CHAMADA_FUNC:
            printf("Expressao primaria CHAMADA_FUNC encontrado.\n");
            semantico_chamada(primExpr->chamada);
            break;
        case CONST_INT:
            printf("Expressao primaria CONST_INT encontrado.\n");
            break;
        case CONST_STR:
            printf("Expressao primaria CONST_STR encontrado.\n");
            break;
        case EXPRESSAO:
            printf("Expressao primaria EXPRESSAO encontrado.\n");
            semantico_expr(primExpr->expr);
            break;
        default:
            printf("ERRO: Tipo da PrimExpr incorreto.\n");
            exit(1);
    }
}

void semantico_chamada(Chamada chamada) {
    printf("Chamada para id = '%s' encontrado.\n", chamada.id);

    // Verificar se variável ou função existe no escopo.
    // Caseo listaExpr não seja vazia, verificar se quantidade parametros correto.
    // Percorrer arvore para construir dicionario e então contar quantidade de parametros.

    semantico_expr(chamada.listaExpr);
}