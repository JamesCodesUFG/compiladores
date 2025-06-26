#include <stdio.h>
#include <stdlib.h>

#include "tree.h"
#include "tipos.h"
#include "stack.h"
#include "semantico.h"

Stack* current_stack;

static void safe_exit() {
    delete_stack(current_stack);
    exit(1);
}

void semantico_raiz(Raiz* raiz) {
    printf("Raiz encontrada.\n");

    current_stack = init();

    DeclFuncVar* c_declFuncVar = raiz->declFuncVar;

    while (c_declFuncVar != NULL) {
        semantico_decl_func_var(c_declFuncVar);

        c_declFuncVar = c_declFuncVar->next;
    }

    semantico_bloco(raiz->bloco);

    delete_stack(current_stack);
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
            printf("ERRO: da Tipo DeclFuncVar incorreto (%d).\n", declFuncVar->tipo);
            safe_exit();
    }
}

void semantico_decl_var(DeclVar* declVar) {
    STipo tipo;

    switch (declVar->tipo) {
        case TIPO_INT:
            if (efind(declVar->id) != NULL) {
                printf("ERROR: Error semantico detectado.\n");
                safe_exit();
            } else {
                printf("Variavel '%s' do tipo int encontrado.\n", declVar->id);
                tipo = S_TIPO_INT;
            }

            break;
        case TIPO_STR:
            if (efind(declVar->id) != NULL) {
                printf("ERROR: Error semantico detectado.\n");
                safe_exit();
            } else {
                printf("Variavel '%s' do tipo str encontrado.\n", declVar->id);
                tipo = S_TIPO_STR;
            }
            break;
        default:
            printf("ERRO: Tipo da DeclVar incorreto (%s -> %d).\n", declVar->id, declVar->tipo);
            safe_exit();
    }

    add_var(current_stack, declVar->id, tipo, 0);
}

void semantico_decl_func(DeclFunc* declFunc) {
    STipo tipo;

    switch (declFunc->tipo) {
        case TIPO_INT:
            if (efind(declVar->id) != NULL) {
                printf("ERROR: Error semantico detectado.\n");
                safe_exit();
            } else {
                printf("Função '%s' do tipo int encontrado.\n", declFunc->id);
                tipo = S_TIPO_INT;
            }

            break;
        case TIPO_STR:
            if (efind(declVar->id) != NULL) {
                printf("ERROR: Error semantico detectado.\n");
                safe_exit();
            } else {
                printf("Função '%s' do tipo str encontrado.\n", declFunc->id);
                tipo = S_TIPO_INT;
            }
            
            break;
        default:
            printf("ERRO: Tipo da DeclFunc incorreto.\n");
            safe_exit();
    }

    Lexema* lexema = add_func(current_stack, declVar->id, 0, tipo);

    int param_counter = 0;

    ListaParametros* c_listaParametros = declFunc->listaParametros;

    while (c_listaParametros != NULL) {
        semantico_lista_parametros(c_listaParametros);

        c_listaParametros = c_listaParametros->next;

        param_counter++;
    }

    lexema->func
}

void semantico_lista_parametros(ListaParametros* listaParametros, Lexema* lexema) {
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
            safe_exit();
    }
}

void semantico_bloco(Bloco* bloco) {
    printf("Bloco encontrado.\n");

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
            safe_exit();
    }
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
            safe_exit();
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
        case NOVALINHA:
            printf("Comando NOVALINHA econtrado.\n");
            break;
        default:
            printf("ERRO: Tipo da ComandoUnitario incorreto.\n");
            safe_exit();
    }

    if (comando->expr != NULL) semantico_expr(comando->expr);
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
            safe_exit();
    }
}

void semantico_atribuicao(Atribuicao* atribuicao) {
    printf("Atribuicao encontrada (id = '%s').\n", atribuicao->id);

    // Verificar se a variável existe.

    semantico_expr(atribuicao->expr);
}

void semantico_operador(Operador* operador) {
    switch (operador->tipo) {
        case E:
            printf("--> Operador E encontrado.\n");
            break;
        case OU:
            printf("-> Operador OU encontrado.\n");
            break;
        case NAO:
            printf("Operador NAO encontrado.\n");
            break;
        case IGUALDADE:
            printf("---> Operador IGUALDADE encontrado.\n");
            break;
        case DIFERENCA:
            printf("---> Operador DIFERENCA encontrado.\n");
            break;
        case MAIOR_QUE:
            printf("----> Operador MAIOR_QUE encontrado.\n");
            break;
        case MENOR_QUE:
            printf("----> Operador MENOR_QUE encontrado.\n");
            break;
        case MAIOR_IGUAL:
            printf("----> Operador MAIOR_IGUAL encontrado.\n");
            break;
        case MENOR_IGUAL:
            printf("----> Operador MENOR_IGUAL encontrado.\n");
            break;
        case MAIS:
            printf("-----> Operador MAIS encontrado.\n");
            break;
        case MENOS:
            printf("-----> Operador MENOS encontrado.\n");
            break;
        case MULTIPLICACAO:
            printf("------> Operador MULTIPLICACAO encontrado.\n");
            break;
        case DIVISAO:
            printf("------> Operador DIVISAO encontrado.\n");
            break;
        default:
            printf("ERRO: Tipo da Operador incorreto.\n");
            safe_exit();
    }

    semantico_expr(operador->esquerda);
    semantico_expr(operador->direita);
}

void semantico_un_expr(UnExpr* unExpr) {
    switch (unExpr->tipo) {
        case NONE:
            printf("Expressao unaria NONE encontrado.\n");
            break;
        case NEGATIVO:
            printf("Expressao unaria NEGATIVO encontrado.\n");
            break;
        case NEGACAO:
            printf("Expressao unaria NEGACAO encontrado.\n");
            break;
        default:
            printf("ERRO: Tipo da UnExpr incorreto.\n");
            safe_exit();
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
            safe_exit();
    }
}

void semantico_chamada(Chamada chamada) {
    printf("Chamada para id = '%s' encontrado.\n", chamada.id);

    // Verificar se variável ou função existe no escopo.
    // Caseo listaExpr não seja vazia, verificar se quantidade parametros correto.
    // Percorrer arvore para construir dicionario e então contar quantidade de parametros.

    if (chamada.listaExpr != NULL) semantico_expr(chamada.listaExpr);
}
