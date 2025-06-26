#ifndef _TREE_H
#define _TREE_H

#include <stdio.h>
#include <stdlib.h>

#include "tipos.h"

Raiz* criarRaiz(DeclFuncVar* declaracao, Bloco* bloco);

ListaParametros* criarParametro(ETipo tipo, char* id, ListaParametros* next);
DeclFuncVar* criarFuncaoSemTipo(ListaParametros* listaParametros, Bloco* bloco);
DeclFuncVar* criarFuncaoComTipo(ETipo tipo, char* id, DeclFuncVar* funcao, DeclFuncVar* next);

DeclFuncVar* criarVariavelSemTipo(char* id, DeclFuncVar* next);
DeclFuncVar* criarVariavelComTipo(ETipo tipo, char* id, DeclFuncVar* filhos, DeclFuncVar* next);

Bloco* criarBloco(DeclFuncVar* declFuncVar, ListaComando* listaComando);

ListaComando* linkListaComando(ListaComando* primeiro, ListaComando* segundo);

ListaComando* criarComandoBloco(Bloco* bloco);
ListaComando* criarComandoUnitario(Expr* expr, EComandoUnitario tipo);
ListaComando* criarComandoControleFluxo(Expr* expr, ListaComando* primeiroComando, ListaComando* segundoComando, EComandoControleFluxo tipo);

Expr* criarExprOperador(Expr* esquerda, Expr* direita, EOperador operador);

Expr* criarExprAtribuicao(char* id, Expr* expr);
Expr* criarExprOperador(Expr* esquerda, Expr* direita, EOperador operador);
Expr* criarExprUnaria(PrimExpr* expr, EOperador tipo);

PrimExpr* criarPrimExprChamada(char* id, Expr* listaExpr, EPrimExpr tipo);
PrimExpr* criarPrimExprConst(char* valor, EPrimExpr tipo);
PrimExpr* criarPrimExprParent(Expr* expr);

Expr* linkExpr(Expr* esquerda, Expr* direita);

#endif