#ifndef _SEMANTICO_H
#define _SEMANTICO_H

#include <stdio.h>
#include <stdlib.h>

#include "tree.h"
#include "stack.h"
#include "tipos.h"

Stack* stack;

void semantico_raiz(Raiz* raiz);

void semantico_decl_func_var(DeclFuncVar* declFuncVar);

void semantico_decl_var(DeclVar* declVar);

void semantico_decl_func(DeclFunc* declFunc);

void semantico_lista_parametros(ListaParametros* listaParametros);

void semantico_bloco(Bloco* bloco);

void semantico_lista_comando(ListaComando* listaComando);

void semantico_comando_controle_fluxo(ComandoControleFluxo* comando);

void semantico_comando_unitario(ComandoUnitario* comando);

void semantico_expr(Expr* expr);

void semantico_atribuicao(Atribuicao* atribuicao);

void semantico_operador(Operador* operador);

void semantico_un_expr(UnExpr* unExpr);

void semantico_prim_expr(PrimExpr* primExpr);

void semantico_chamada(Chamada chamada);

#endif