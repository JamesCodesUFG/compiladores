/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_GOIANINHA_TAB_H_INCLUDED
# define YY_YY_GOIANINHA_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    VALUE_ID = 258,                /* VALUE_ID  */
    VALUE_DIGITO = 259,            /* VALUE_DIGITO  */
    VALUE_STRING = 260,            /* VALUE_STRING  */
    TOKEN_INT = 261,               /* TOKEN_INT  */
    TOKEN_CHAR = 262,              /* TOKEN_CHAR  */
    TOKEN_ATTR = 263,              /* TOKEN_ATTR  */
    TOKEN_E = 264,                 /* TOKEN_E  */
    TOKEN_OU = 265,                /* TOKEN_OU  */
    TOKEN_IGUAL = 266,             /* TOKEN_IGUAL  */
    TOKEN_MAIOR = 267,             /* TOKEN_MAIOR  */
    TOKEN_MENOR = 268,             /* TOKEN_MENOR  */
    TOKEN_NAO_IGUAL = 269,         /* TOKEN_NAO_IGUAL  */
    TOKEN_MAIOR_IGUAL = 270,       /* TOKEN_MAIOR_IGUAL  */
    TOKEN_MENOR_IGUAL = 271,       /* TOKEN_MENOR_IGUAL  */
    TOKEN_MAIS = 272,              /* TOKEN_MAIS  */
    TOKEN_MENOS = 273,             /* TOKEN_MENOS  */
    TOKEN_MULT = 274,              /* TOKEN_MULT  */
    TOKEN_DIVIDE = 275,            /* TOKEN_DIVIDE  */
    TOKEN_NEGATIVA = 276,          /* TOKEN_NEGATIVA  */
    TOKEN_SE = 277,                /* TOKEN_SE  */
    TOKEN_ENTAO = 278,             /* TOKEN_ENTAO  */
    TOKEN_SENAO = 279,             /* TOKEN_SENAO  */
    TOKEN_EXECUTE = 280,           /* TOKEN_EXECUTE  */
    TOKEN_ENQUANTO = 281,          /* TOKEN_ENQUANTO  */
    TOKEN_PROGRAMA = 282,          /* TOKEN_PROGRAMA  */
    TOKEN_LEIA = 283,              /* TOKEN_LEIA  */
    TOKEN_ESCREVA = 284,           /* TOKEN_ESCREVA  */
    TOKEN_RETORNE = 285,           /* TOKEN_RETORNE  */
    TOKEN_ABR_PARENT = 286,        /* TOKEN_ABR_PARENT  */
    TOKEN_FCH_PARENT = 287,        /* TOKEN_FCH_PARENT  */
    TOKEN_ABR_BLOCO = 288,         /* TOKEN_ABR_BLOCO  */
    TOKEN_FCH_BLOCO = 289,         /* TOKEN_FCH_BLOCO  */
    TOKEN_VIRGULA = 290,           /* TOKEN_VIRGULA  */
    TOKEN_FIM = 291,               /* TOKEN_FIM  */
    TOKEN_NOVA_LINHA = 292         /* TOKEN_NOVA_LINHA  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 22 "goianinha.y"

    int num;
    char sym;
    char* str;
    Raiz* raiz;
    DeclFuncVar* declFuncVar;
    DeclVar* declVar;
    DeclFunc* declFunc;
    Bloco* bloco;
    ListaParametros* listaParametros;
    ChamadaFunc* chamadaFunc;
    PrimExpr* primExpr;
    UnExpr* unExpr;
    Operador* operador;
    Atribuicao* atribuicao;
    Expr* expr;
    ComandoUnitario* comandoUnitario;
    ComandoControleFluxo* comandoControleFluxo;
    ListaComando* listaComando;
    ETipo tipo;

#line 123 "goianinha.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_GOIANINHA_TAB_H_INCLUDED  */
