#ifndef _TREE_H
#define _TREE_H

#include <stdio.h>
#include <stdlib.h>

#include "tipos.h"

Raiz* criarRaiz(DeclFuncVar* declaracao, Bloco* bloco);

Parametro* criarParametro(Tipo tipo, char* nome, Parametro* next);
DeclFuncVar* criarFuncaoSemTipo(Parametro* parametro, Bloco* bloco);
DeclFuncVar* criarFuncaoComTipo(Tipo tipo, char* nome, DeclFuncVar* funcao, DeclFuncVar* next);

DeclFuncVar* criarVariavelSemTipo(char* nome, DeclFuncVar* next);
DeclFuncVar* criarVariavelComTipo(Tipo tipo, char* nome, DeclFuncVar* filhos, DeclFuncVar* next);

Bloco* criarBloco(DeclFuncVar* declFuncVar, ListaComando* listaComando);

ListaComando* linkListaComando(ListaComando* primeiro, ListaComando* segundo);

ListaComando* criarComandoBloco(Bloco* bloco);
ListaComando* criarComandoUnitario(Expr* expr, EComandoUnitario tipo);
ListaComando* criarComandoControleFluxo(Expr* expr, ListaComando* primeiroComando, ListaComando* segundoComando, EComandoControleFluxo tipo);

Expr* criarExprAtr(char* id, Atribuicao* expr);
Expr* criarExprOperador(Expr* esquerda, Expr* direita, TipoOperador operador);
Expr* criarExprUnaria(Expr* expr, EOperador tipo);

Expr* criarExprLogica(Expr* esquerda, Expr* direita, TipoOperador operador);
Expr* criarExprAritmetica(Expr* esquerda, Expr* direita, TipoOperador operador);
Expr* criarExprRelacional(Expr* esquerda, Expr* direita, TipoOperador operador);
Expr* criarExprAtribuicao(Expr* esquerda, Expr* direita);

Expr* criarExprChamada(char* id, ListaExpr* listaExpr, EPrimExpr tipo);
Expr* criarExprConst(str* valor, EPrimExpr tipo);
Expr* criarExprParent(Expr* expr);

#endif