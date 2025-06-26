/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "goianinha.y"


#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "tipos.h"
#include "tree.h"

extern int yylex();
extern int numLinha;
extern int erroOrigem;
extern char* yytext;
extern FILE* yyin;

Raiz* arvore_final = NULL;


#line 90 "goianinha.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "goianinha.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_VALUE_ID = 3,                   /* VALUE_ID  */
  YYSYMBOL_VALUE_DIGITO = 4,               /* VALUE_DIGITO  */
  YYSYMBOL_VALUE_STRING = 5,               /* VALUE_STRING  */
  YYSYMBOL_TOKEN_INT = 6,                  /* TOKEN_INT  */
  YYSYMBOL_TOKEN_CHAR = 7,                 /* TOKEN_CHAR  */
  YYSYMBOL_TOKEN_ATTR = 8,                 /* TOKEN_ATTR  */
  YYSYMBOL_TOKEN_E = 9,                    /* TOKEN_E  */
  YYSYMBOL_TOKEN_OU = 10,                  /* TOKEN_OU  */
  YYSYMBOL_TOKEN_IGUAL = 11,               /* TOKEN_IGUAL  */
  YYSYMBOL_TOKEN_MAIOR = 12,               /* TOKEN_MAIOR  */
  YYSYMBOL_TOKEN_MENOR = 13,               /* TOKEN_MENOR  */
  YYSYMBOL_TOKEN_NAO_IGUAL = 14,           /* TOKEN_NAO_IGUAL  */
  YYSYMBOL_TOKEN_MAIOR_IGUAL = 15,         /* TOKEN_MAIOR_IGUAL  */
  YYSYMBOL_TOKEN_MENOR_IGUAL = 16,         /* TOKEN_MENOR_IGUAL  */
  YYSYMBOL_TOKEN_MAIS = 17,                /* TOKEN_MAIS  */
  YYSYMBOL_TOKEN_MENOS = 18,               /* TOKEN_MENOS  */
  YYSYMBOL_TOKEN_MULT = 19,                /* TOKEN_MULT  */
  YYSYMBOL_TOKEN_DIVIDE = 20,              /* TOKEN_DIVIDE  */
  YYSYMBOL_TOKEN_NEGATIVA = 21,            /* TOKEN_NEGATIVA  */
  YYSYMBOL_TOKEN_SE = 22,                  /* TOKEN_SE  */
  YYSYMBOL_TOKEN_ENTAO = 23,               /* TOKEN_ENTAO  */
  YYSYMBOL_TOKEN_SENAO = 24,               /* TOKEN_SENAO  */
  YYSYMBOL_TOKEN_EXECUTE = 25,             /* TOKEN_EXECUTE  */
  YYSYMBOL_TOKEN_ENQUANTO = 26,            /* TOKEN_ENQUANTO  */
  YYSYMBOL_TOKEN_PROGRAMA = 27,            /* TOKEN_PROGRAMA  */
  YYSYMBOL_TOKEN_LEIA = 28,                /* TOKEN_LEIA  */
  YYSYMBOL_TOKEN_ESCREVA = 29,             /* TOKEN_ESCREVA  */
  YYSYMBOL_TOKEN_RETORNE = 30,             /* TOKEN_RETORNE  */
  YYSYMBOL_TOKEN_NOVALINHA = 31,           /* TOKEN_NOVALINHA  */
  YYSYMBOL_TOKEN_ABR_PARENT = 32,          /* TOKEN_ABR_PARENT  */
  YYSYMBOL_TOKEN_FCH_PARENT = 33,          /* TOKEN_FCH_PARENT  */
  YYSYMBOL_TOKEN_ABR_BLOCO = 34,           /* TOKEN_ABR_BLOCO  */
  YYSYMBOL_TOKEN_FCH_BLOCO = 35,           /* TOKEN_FCH_BLOCO  */
  YYSYMBOL_TOKEN_VIRGULA = 36,             /* TOKEN_VIRGULA  */
  YYSYMBOL_TOKEN_FIM = 37,                 /* TOKEN_FIM  */
  YYSYMBOL_TOKEN_NOVA_LINHA = 38,          /* TOKEN_NOVA_LINHA  */
  YYSYMBOL_YYACCEPT = 39,                  /* $accept  */
  YYSYMBOL_programa = 40,                  /* programa  */
  YYSYMBOL_decl_func_var = 41,             /* decl_func_var  */
  YYSYMBOL_decl_prog = 42,                 /* decl_prog  */
  YYSYMBOL_decl_var = 43,                  /* decl_var  */
  YYSYMBOL_decl_func = 44,                 /* decl_func  */
  YYSYMBOL_lista_parametros = 45,          /* lista_parametros  */
  YYSYMBOL_lista_parametros_cont = 46,     /* lista_parametros_cont  */
  YYSYMBOL_bloco = 47,                     /* bloco  */
  YYSYMBOL_lista_decl_var = 48,            /* lista_decl_var  */
  YYSYMBOL_tipo = 49,                      /* tipo  */
  YYSYMBOL_lista_comando = 50,             /* lista_comando  */
  YYSYMBOL_comando = 51,                   /* comando  */
  YYSYMBOL_expr = 52,                      /* expr  */
  YYSYMBOL_or_expr = 53,                   /* or_expr  */
  YYSYMBOL_and_expr = 54,                  /* and_expr  */
  YYSYMBOL_eq_expr = 55,                   /* eq_expr  */
  YYSYMBOL_desig_expr = 56,                /* desig_expr  */
  YYSYMBOL_add_expr = 57,                  /* add_expr  */
  YYSYMBOL_mul_expr = 58,                  /* mul_expr  */
  YYSYMBOL_un_expr = 59,                   /* un_expr  */
  YYSYMBOL_prim_expr = 60,                 /* prim_expr  */
  YYSYMBOL_list_expr = 61                  /* list_expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   130

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  122

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   293


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   114,   114,   122,   123,   124,   128,   132,   133,   137,
     141,   142,   146,   147,   151,   155,   156,   160,   161,   165,
     166,   170,   171,   172,   173,   179,   180,   186,   187,   188,
     189,   190,   194,   195,   199,   200,   204,   205,   209,   210,
     211,   215,   216,   217,   218,   219,   223,   224,   225,   229,
     230,   231,   235,   236,   237,   241,   242,   243,   244,   245,
     246,   250,   251
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "VALUE_ID",
  "VALUE_DIGITO", "VALUE_STRING", "TOKEN_INT", "TOKEN_CHAR", "TOKEN_ATTR",
  "TOKEN_E", "TOKEN_OU", "TOKEN_IGUAL", "TOKEN_MAIOR", "TOKEN_MENOR",
  "TOKEN_NAO_IGUAL", "TOKEN_MAIOR_IGUAL", "TOKEN_MENOR_IGUAL",
  "TOKEN_MAIS", "TOKEN_MENOS", "TOKEN_MULT", "TOKEN_DIVIDE",
  "TOKEN_NEGATIVA", "TOKEN_SE", "TOKEN_ENTAO", "TOKEN_SENAO",
  "TOKEN_EXECUTE", "TOKEN_ENQUANTO", "TOKEN_PROGRAMA", "TOKEN_LEIA",
  "TOKEN_ESCREVA", "TOKEN_RETORNE", "TOKEN_NOVALINHA", "TOKEN_ABR_PARENT",
  "TOKEN_FCH_PARENT", "TOKEN_ABR_BLOCO", "TOKEN_FCH_BLOCO",
  "TOKEN_VIRGULA", "TOKEN_FIM", "TOKEN_NOVA_LINHA", "$accept", "programa",
  "decl_func_var", "decl_prog", "decl_var", "decl_func",
  "lista_parametros", "lista_parametros_cont", "bloco", "lista_decl_var",
  "tipo", "lista_comando", "comando", "expr", "or_expr", "and_expr",
  "eq_expr", "desig_expr", "add_expr", "mul_expr", "un_expr", "prim_expr",
  "list_expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-59)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      60,   -59,   -59,    29,    15,    50,   -59,    39,   -59,    13,
      60,   -59,    60,    84,    26,    60,     6,    93,    64,   -59,
      97,    65,    60,   -59,     7,   -59,   -59,     9,     9,    71,
      72,   102,    47,    51,    69,    51,   -59,   -59,    73,     6,
      70,    99,   101,     8,     5,    53,   -12,   -59,   -59,    65,
      39,    75,   -59,   -59,    51,    43,    80,   -59,   -59,    51,
      51,    77,    78,    79,    82,   -59,    85,   -59,   -59,   -59,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    83,   -59,    60,   -59,   -59,   -59,    24,    88,
      89,   -59,   -59,   -59,   -59,   -59,   101,     8,     5,     5,
      53,    53,    53,    53,   -12,   -12,   -59,   -59,    60,   -59,
     -59,    51,    94,    98,   -59,   -59,     6,     6,   100,   -59,
       6,   -59
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,    17,    18,     0,     0,     0,     1,     0,     2,     7,
      15,     6,    10,     0,     0,     3,     0,     0,     0,    11,
       0,     7,     3,     5,    57,    59,    58,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,    31,     0,    19,
       0,    32,    34,    36,    38,    41,    46,    49,    52,     7,
       0,    12,     8,     4,     0,     0,    57,    53,    54,     0,
       0,     0,    58,     0,     0,    27,     0,    14,    20,    22,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     9,     0,    33,    56,    61,     0,     0,
       0,    24,    26,    25,    23,    60,    35,    37,    39,    40,
      43,    42,    44,    45,    47,    48,    50,    51,    15,    13,
      55,     0,     0,     0,    16,    62,     0,     0,    28,    30,
       0,    29
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -59,   -59,     1,   -59,   -16,   -59,   -59,    41,    -6,    18,
     -10,    90,   -58,   -29,   -59,    57,    59,    20,    14,    -1,
       0,    67,   -59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     8,    14,    15,    18,    19,    37,    16,
       5,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    88
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      17,    11,    20,    63,    64,    52,    66,    80,    81,    24,
      25,    26,    56,    25,    26,    54,    23,    74,    75,    72,
      76,    77,    73,    53,    27,    85,    87,    28,    29,     6,
      89,    90,    30,    82,    31,    32,    33,    34,    35,    55,
      10,    35,     7,    36,    83,    12,    24,    25,    26,    13,
      24,    25,    62,     9,    24,    25,    26,   110,   118,   119,
     111,    27,   121,    22,    28,    27,     1,     2,    28,    27,
      78,    79,    28,    10,    20,    35,    86,   104,   105,    35,
     106,   107,   115,    35,    56,    25,    26,    21,   100,   101,
     102,   103,    98,    99,    57,    58,    49,    50,    17,    27,
      51,    13,    28,    59,    60,    61,    65,    69,    67,    70,
      71,    84,    55,    35,    91,    92,    93,   116,    95,    94,
     108,   112,   113,   117,   120,   109,   114,    96,     0,    68,
      97
};

static const yytype_int8 yycheck[] =
{
      10,     7,    12,    32,    33,    21,    35,    19,    20,     3,
       4,     5,     3,     4,     5,     8,    15,    12,    13,    11,
      15,    16,    14,    22,    18,    54,    55,    21,    22,     0,
      59,    60,    26,    49,    28,    29,    30,    31,    32,    32,
      34,    32,    27,    37,    50,    32,     3,     4,     5,    36,
       3,     4,     5,     3,     3,     4,     5,    33,   116,   117,
      36,    18,   120,    37,    21,    18,     6,     7,    21,    18,
      17,    18,    21,    34,    84,    32,    33,    78,    79,    32,
      80,    81,   111,    32,     3,     4,     5,     3,    74,    75,
      76,    77,    72,    73,    27,    28,     3,    33,   108,    18,
       3,    36,    21,    32,    32,     3,    37,    37,    35,    10,
       9,    36,    32,    32,    37,    37,    37,    23,    33,    37,
      37,    33,    33,    25,    24,    84,   108,    70,    -1,    39,
      71
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,     7,    40,    41,    49,     0,    27,    42,     3,
      34,    47,    32,    36,    43,    44,    48,    49,    45,    46,
      49,     3,    37,    41,     3,     4,     5,    18,    21,    22,
      26,    28,    29,    30,    31,    32,    37,    47,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,     3,
      33,     3,    43,    41,     8,    32,     3,    60,    60,    32,
      32,     3,     5,    52,    52,    37,    52,    35,    50,    37,
      10,     9,    11,    14,    12,    13,    15,    16,    17,    18,
      19,    20,    43,    47,    36,    52,    33,    52,    61,    52,
      52,    37,    37,    37,    37,    33,    54,    55,    56,    56,
      57,    57,    57,    57,    58,    58,    59,    59,    37,    46,
      33,    36,    33,    33,    48,    52,    23,    25,    51,    51,
      24,    51
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    41,    41,    41,    42,    43,    43,    44,
      45,    45,    46,    46,    47,    48,    48,    49,    49,    50,
      50,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    52,    52,    53,    53,    54,    54,    55,    55,
      55,    56,    56,    56,    56,    56,    57,    57,    57,    58,
      58,    58,    59,    59,    59,    60,    60,    60,    60,    60,
      60,    61,    61
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     5,     4,     2,     0,     3,     4,
       0,     1,     2,     4,     4,     0,     5,     1,     1,     1,
       2,     1,     2,     3,     3,     3,     3,     2,     6,     8,
       6,     1,     1,     3,     1,     3,     1,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     2,     2,     4,     3,     1,     1,     1,
       3,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* programa: decl_func_var decl_prog  */
#line 115 "goianinha.y"
        {
            (yyval.raiz) = criarRaiz((yyvsp[-1].declFuncVar), (yyvsp[0].bloco));
            arvore_final = (yyval.raiz);
        }
#line 1228 "goianinha.tab.c"
    break;

  case 3: /* decl_func_var: %empty  */
#line 122 "goianinha.y"
    { (yyval.declFuncVar) = NULL; }
#line 1234 "goianinha.tab.c"
    break;

  case 4: /* decl_func_var: tipo VALUE_ID decl_var TOKEN_FIM decl_func_var  */
#line 123 "goianinha.y"
                                                     { (yyval.declFuncVar) = criarVariavelComTipo((yyvsp[-4].tipo), (yyvsp[-3].str), (yyvsp[-2].declFuncVar), (yyvsp[0].declFuncVar)); }
#line 1240 "goianinha.tab.c"
    break;

  case 5: /* decl_func_var: tipo VALUE_ID decl_func decl_func_var  */
#line 124 "goianinha.y"
                                            { (yyval.declFuncVar) = criarFuncaoComTipo((yyvsp[-3].tipo), (yyvsp[-2].str), (yyvsp[-1].declFuncVar), (yyvsp[0].declFuncVar)); }
#line 1246 "goianinha.tab.c"
    break;

  case 6: /* decl_prog: TOKEN_PROGRAMA bloco  */
#line 128 "goianinha.y"
                         { (yyval.bloco) = (yyvsp[0].bloco); }
#line 1252 "goianinha.tab.c"
    break;

  case 7: /* decl_var: %empty  */
#line 132 "goianinha.y"
    { (yyval.declFuncVar) = NULL; }
#line 1258 "goianinha.tab.c"
    break;

  case 8: /* decl_var: TOKEN_VIRGULA VALUE_ID decl_var  */
#line 133 "goianinha.y"
                                      { (yyval.declFuncVar) = criarVariavelSemTipo((yyvsp[-1].str), (yyvsp[0].declFuncVar)); }
#line 1264 "goianinha.tab.c"
    break;

  case 9: /* decl_func: TOKEN_ABR_PARENT lista_parametros TOKEN_FCH_PARENT bloco  */
#line 137 "goianinha.y"
                                                             { (yyval.declFuncVar) = criarFuncaoSemTipo((yyvsp[-2].listaParametros), (yyvsp[0].bloco)); }
#line 1270 "goianinha.tab.c"
    break;

  case 10: /* lista_parametros: %empty  */
#line 141 "goianinha.y"
    { (yyval.listaParametros) = NULL; }
#line 1276 "goianinha.tab.c"
    break;

  case 11: /* lista_parametros: lista_parametros_cont  */
#line 142 "goianinha.y"
                            { (yyval.listaParametros) = (yyvsp[0].listaParametros); }
#line 1282 "goianinha.tab.c"
    break;

  case 12: /* lista_parametros_cont: tipo VALUE_ID  */
#line 146 "goianinha.y"
                  { (yyval.listaParametros) = criarParametro((yyvsp[-1].tipo), (yyvsp[0].str), NULL); }
#line 1288 "goianinha.tab.c"
    break;

  case 13: /* lista_parametros_cont: tipo VALUE_ID TOKEN_VIRGULA lista_parametros_cont  */
#line 147 "goianinha.y"
                                                        { (yyval.listaParametros) = criarParametro((yyvsp[-3].tipo), (yyvsp[-2].str), (yyvsp[0].listaParametros)); }
#line 1294 "goianinha.tab.c"
    break;

  case 14: /* bloco: TOKEN_ABR_BLOCO lista_decl_var lista_comando TOKEN_FCH_BLOCO  */
#line 151 "goianinha.y"
                                                                 { (yyval.bloco) = criarBloco((yyvsp[-2].declFuncVar), (yyvsp[-1].listaComando)); }
#line 1300 "goianinha.tab.c"
    break;

  case 15: /* lista_decl_var: %empty  */
#line 155 "goianinha.y"
    { (yyval.declFuncVar) = NULL; }
#line 1306 "goianinha.tab.c"
    break;

  case 16: /* lista_decl_var: tipo VALUE_ID decl_var TOKEN_FIM lista_decl_var  */
#line 156 "goianinha.y"
                                                      { (yyval.declFuncVar) = criarVariavelComTipo((yyvsp[-4].tipo), (yyvsp[-3].str), (yyvsp[-2].declFuncVar), (yyvsp[0].declFuncVar)); }
#line 1312 "goianinha.tab.c"
    break;

  case 17: /* tipo: TOKEN_INT  */
#line 160 "goianinha.y"
              { printf("Certo"); (yyval.tipo) = TIPO_INT; }
#line 1318 "goianinha.tab.c"
    break;

  case 18: /* tipo: TOKEN_CHAR  */
#line 161 "goianinha.y"
                 { (yyval.tipo) = TIPO_STR; }
#line 1324 "goianinha.tab.c"
    break;

  case 19: /* lista_comando: comando  */
#line 165 "goianinha.y"
            { (yyval.listaComando) = (yyvsp[0].listaComando); }
#line 1330 "goianinha.tab.c"
    break;

  case 20: /* lista_comando: comando lista_comando  */
#line 166 "goianinha.y"
                            { (yyval.listaComando) = linkListaComando((yyvsp[-1].listaComando), (yyvsp[0].listaComando)); }
#line 1336 "goianinha.tab.c"
    break;

  case 21: /* comando: TOKEN_FIM  */
#line 170 "goianinha.y"
              { (yyval.listaComando) = NULL; }
#line 1342 "goianinha.tab.c"
    break;

  case 22: /* comando: expr TOKEN_FIM  */
#line 171 "goianinha.y"
                     { (yyval.listaComando) = criarComandoUnitario((yyvsp[-1].expr), EXPR); }
#line 1348 "goianinha.tab.c"
    break;

  case 23: /* comando: TOKEN_RETORNE expr TOKEN_FIM  */
#line 172 "goianinha.y"
                                   { (yyval.listaComando) = criarComandoUnitario((yyvsp[-1].expr), RETORNE); }
#line 1354 "goianinha.tab.c"
    break;

  case 24: /* comando: TOKEN_LEIA VALUE_ID TOKEN_FIM  */
#line 174 "goianinha.y"
        { 
            PrimExpr* primExpr = criarPrimExprChamada((yyvsp[-1].str), NULL, CHAMADA_VAR);
            Expr* expr = criarExprUnaria(primExpr, NONE);
            (yyval.listaComando) = criarComandoUnitario(expr, LEIA);
        }
#line 1364 "goianinha.tab.c"
    break;

  case 25: /* comando: TOKEN_ESCREVA expr TOKEN_FIM  */
#line 179 "goianinha.y"
                                   { (yyval.listaComando) = criarComandoUnitario((yyvsp[-1].expr), ESCREVA); }
#line 1370 "goianinha.tab.c"
    break;

  case 26: /* comando: TOKEN_ESCREVA VALUE_STRING TOKEN_FIM  */
#line 181 "goianinha.y"
        {
            PrimExpr* primExpr = criarPrimExprConst((yyvsp[-1].str), TIPO_STR);
            Expr* expr = criarExprUnaria(primExpr, NONE);
            (yyval.listaComando) = criarComandoUnitario(expr, ESCREVA);
        }
#line 1380 "goianinha.tab.c"
    break;

  case 27: /* comando: TOKEN_NOVALINHA TOKEN_FIM  */
#line 186 "goianinha.y"
                                { (yyval.listaComando) = criarComandoUnitario(NULL, NOVALINHA); }
#line 1386 "goianinha.tab.c"
    break;

  case 28: /* comando: TOKEN_SE TOKEN_ABR_PARENT expr TOKEN_FCH_PARENT TOKEN_ENTAO comando  */
#line 187 "goianinha.y"
                                                                          { (yyval.listaComando) = criarComandoControleFluxo((yyvsp[-3].expr), (yyvsp[0].listaComando), NULL, SE_ENTAO); }
#line 1392 "goianinha.tab.c"
    break;

  case 29: /* comando: TOKEN_SE TOKEN_ABR_PARENT expr TOKEN_FCH_PARENT TOKEN_ENTAO comando TOKEN_SENAO comando  */
#line 188 "goianinha.y"
                                                                                              { (yyval.listaComando) = criarComandoControleFluxo((yyvsp[-5].expr), (yyvsp[-2].listaComando), (yyvsp[0].listaComando), SE_SENAO); }
#line 1398 "goianinha.tab.c"
    break;

  case 30: /* comando: TOKEN_ENQUANTO TOKEN_ABR_PARENT expr TOKEN_FCH_PARENT TOKEN_EXECUTE comando  */
#line 189 "goianinha.y"
                                                                                  { (yyval.listaComando) = criarComandoControleFluxo((yyvsp[-3].expr), (yyvsp[0].listaComando), NULL, ENQUANTO); }
#line 1404 "goianinha.tab.c"
    break;

  case 31: /* comando: bloco  */
#line 190 "goianinha.y"
            { (yyval.listaComando) = criarComandoBloco((yyvsp[0].bloco)); }
#line 1410 "goianinha.tab.c"
    break;

  case 32: /* expr: or_expr  */
#line 194 "goianinha.y"
            { (yyval.expr) = (yyvsp[0].expr); }
#line 1416 "goianinha.tab.c"
    break;

  case 33: /* expr: VALUE_ID TOKEN_ATTR expr  */
#line 195 "goianinha.y"
                               { (yyval.expr) = criarExprAtribuicao((yyvsp[-2].str), (yyvsp[0].expr)); }
#line 1422 "goianinha.tab.c"
    break;

  case 34: /* or_expr: and_expr  */
#line 199 "goianinha.y"
             { (yyval.expr) = (yyvsp[0].expr); }
#line 1428 "goianinha.tab.c"
    break;

  case 35: /* or_expr: or_expr TOKEN_OU and_expr  */
#line 200 "goianinha.y"
                                { (yyval.expr) = criarExprOperador((yyvsp[-2].expr), (yyvsp[0].expr), OU); }
#line 1434 "goianinha.tab.c"
    break;

  case 36: /* and_expr: eq_expr  */
#line 204 "goianinha.y"
            { (yyval.expr) = (yyvsp[0].expr); }
#line 1440 "goianinha.tab.c"
    break;

  case 37: /* and_expr: and_expr TOKEN_E eq_expr  */
#line 205 "goianinha.y"
                               { (yyval.expr) = criarExprOperador((yyvsp[-2].expr), (yyvsp[0].expr), E); }
#line 1446 "goianinha.tab.c"
    break;

  case 38: /* eq_expr: desig_expr  */
#line 209 "goianinha.y"
               { (yyval.expr) = (yyvsp[0].expr); }
#line 1452 "goianinha.tab.c"
    break;

  case 39: /* eq_expr: eq_expr TOKEN_IGUAL desig_expr  */
#line 210 "goianinha.y"
                                     { (yyval.expr) = criarExprOperador((yyvsp[-2].expr), (yyvsp[0].expr), IGUALDADE); }
#line 1458 "goianinha.tab.c"
    break;

  case 40: /* eq_expr: eq_expr TOKEN_NAO_IGUAL desig_expr  */
#line 211 "goianinha.y"
                                         { (yyval.expr) = criarExprOperador((yyvsp[-2].expr), (yyvsp[0].expr), DIFERENCA); }
#line 1464 "goianinha.tab.c"
    break;

  case 41: /* desig_expr: add_expr  */
#line 215 "goianinha.y"
             { (yyval.expr) = (yyvsp[0].expr); }
#line 1470 "goianinha.tab.c"
    break;

  case 42: /* desig_expr: desig_expr TOKEN_MENOR add_expr  */
#line 216 "goianinha.y"
                                      { (yyval.expr) = criarExprOperador((yyvsp[-2].expr), (yyvsp[0].expr), MENOR_QUE); }
#line 1476 "goianinha.tab.c"
    break;

  case 43: /* desig_expr: desig_expr TOKEN_MAIOR add_expr  */
#line 217 "goianinha.y"
                                      { (yyval.expr) = criarExprOperador((yyvsp[-2].expr), (yyvsp[0].expr), MAIOR_QUE); }
#line 1482 "goianinha.tab.c"
    break;

  case 44: /* desig_expr: desig_expr TOKEN_MAIOR_IGUAL add_expr  */
#line 218 "goianinha.y"
                                            { (yyval.expr) = criarExprOperador((yyvsp[-2].expr), (yyvsp[0].expr), MAIOR_IGUAL); }
#line 1488 "goianinha.tab.c"
    break;

  case 45: /* desig_expr: desig_expr TOKEN_MENOR_IGUAL add_expr  */
#line 219 "goianinha.y"
                                            { (yyval.expr) = criarExprOperador((yyvsp[-2].expr), (yyvsp[0].expr), MENOR_IGUAL); }
#line 1494 "goianinha.tab.c"
    break;

  case 46: /* add_expr: mul_expr  */
#line 223 "goianinha.y"
             { (yyval.expr) = (yyvsp[0].expr); }
#line 1500 "goianinha.tab.c"
    break;

  case 47: /* add_expr: add_expr TOKEN_MAIS mul_expr  */
#line 224 "goianinha.y"
                                   { (yyval.expr) = criarExprOperador((yyvsp[-2].expr), (yyvsp[0].expr), MAIS); }
#line 1506 "goianinha.tab.c"
    break;

  case 48: /* add_expr: add_expr TOKEN_MENOS mul_expr  */
#line 225 "goianinha.y"
                                    { (yyval.expr) = criarExprOperador((yyvsp[-2].expr), (yyvsp[0].expr), MENOS); }
#line 1512 "goianinha.tab.c"
    break;

  case 49: /* mul_expr: un_expr  */
#line 229 "goianinha.y"
            { (yyval.expr) = (yyvsp[0].expr); }
#line 1518 "goianinha.tab.c"
    break;

  case 50: /* mul_expr: mul_expr TOKEN_MULT un_expr  */
#line 230 "goianinha.y"
                                  { (yyval.expr) = criarExprOperador((yyvsp[-2].expr), (yyvsp[0].expr), MULTIPLICACAO); }
#line 1524 "goianinha.tab.c"
    break;

  case 51: /* mul_expr: mul_expr TOKEN_DIVIDE un_expr  */
#line 231 "goianinha.y"
                                    { (yyval.expr) = criarExprOperador((yyvsp[-2].expr), (yyvsp[0].expr), DIVISAO); }
#line 1530 "goianinha.tab.c"
    break;

  case 52: /* un_expr: prim_expr  */
#line 235 "goianinha.y"
              { (yyval.expr) = criarExprUnaria((yyvsp[0].primExpr), NONE); }
#line 1536 "goianinha.tab.c"
    break;

  case 53: /* un_expr: TOKEN_MENOS prim_expr  */
#line 236 "goianinha.y"
                            { (yyval.expr) = criarExprUnaria((yyvsp[0].primExpr), NEGATIVO); }
#line 1542 "goianinha.tab.c"
    break;

  case 54: /* un_expr: TOKEN_NEGATIVA prim_expr  */
#line 237 "goianinha.y"
                               { (yyval.expr) = criarExprUnaria((yyvsp[0].primExpr), NEGACAO); }
#line 1548 "goianinha.tab.c"
    break;

  case 55: /* prim_expr: VALUE_ID TOKEN_ABR_PARENT list_expr TOKEN_FCH_PARENT  */
#line 241 "goianinha.y"
                                                         { (yyval.primExpr) = criarPrimExprChamada((yyvsp[-3].str), (yyvsp[-1].expr), CHAMADA_FUNC); }
#line 1554 "goianinha.tab.c"
    break;

  case 56: /* prim_expr: VALUE_ID TOKEN_ABR_PARENT TOKEN_FCH_PARENT  */
#line 242 "goianinha.y"
                                                 { (yyval.primExpr) = criarPrimExprChamada((yyvsp[-2].str), NULL, CHAMADA_FUNC); }
#line 1560 "goianinha.tab.c"
    break;

  case 57: /* prim_expr: VALUE_ID  */
#line 243 "goianinha.y"
               { (yyval.primExpr) = criarPrimExprChamada((yyvsp[0].str), NULL, CHAMADA_VAR); }
#line 1566 "goianinha.tab.c"
    break;

  case 58: /* prim_expr: VALUE_STRING  */
#line 244 "goianinha.y"
                   { (yyval.primExpr) = criarPrimExprConst((yyvsp[0].str), CONST_STR); }
#line 1572 "goianinha.tab.c"
    break;

  case 59: /* prim_expr: VALUE_DIGITO  */
#line 245 "goianinha.y"
                   { (yyval.primExpr) = criarPrimExprConst((yyvsp[0].str), CONST_INT); }
#line 1578 "goianinha.tab.c"
    break;

  case 60: /* prim_expr: TOKEN_ABR_PARENT expr TOKEN_FCH_PARENT  */
#line 246 "goianinha.y"
                                             { (yyval.primExpr) = criarPrimExprParent((yyvsp[-1].expr)); }
#line 1584 "goianinha.tab.c"
    break;

  case 61: /* list_expr: expr  */
#line 250 "goianinha.y"
         { (yyval.expr) = (yyvsp[0].expr); }
#line 1590 "goianinha.tab.c"
    break;

  case 62: /* list_expr: list_expr TOKEN_VIRGULA expr  */
#line 251 "goianinha.y"
                                   { (yyval.expr) = linkExpr((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1596 "goianinha.tab.c"
    break;


#line 1600 "goianinha.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 254 "goianinha.y"


extern int yylineno;

yyerror(const char* s) {
    printf("ERROR: %s in line %d. ", s, yylineno);
    printf("Token atual: '%s'\n", yytext);

    return 0;
}
