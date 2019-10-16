/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "lab7YACC.y" /* yacc.c:337  */


/*
 * Name: Zachary Neeley
 * Date: 4/10/19
 * Purpose: The purpose of this program is to create a code interperator using LEX and YACC
 *          to generate a abstract syntax tree.
 *     
 *      Input: Any valid line of a algol C language. Ex int x[100], y;
 *      Output: A generated abstract syntax tree of the given input and a symbol table from the tree.
 * 
 */



/* begin specs */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "ast.h"
#include "symtable.h"


//init
extern int lineNum;
int level= 0;
int offset=0, Tempoffset = 0, maxOffset = 0;
int yylex();

struct ASTnodetype *myprogram = NULL;

void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  fprintf (stderr,"%s Line Number: %d\n", s, lineNum);
}




#line 111 "y.tab.c" /* yacc.c:337  */
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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUM = 258,
    ID = 259,
    INT = 260,
    VOID = 261,
    WHILE = 262,
    DO = 263,
    IF = 264,
    THEN = 265,
    ELSE = 266,
    READ = 267,
    WRITE = 268,
    FOR = 269,
    RETURN = 270,
    LE = 271,
    GE = 272,
    EQ = 273,
    NE = 274,
    LT = 275,
    GT = 276,
    AND = 277,
    OR = 278,
    NOT = 279,
    MYBEGIN = 280,
    MYEND = 281,
    OF = 282,
    BOOLEAN = 283,
    TRUE = 284,
    FALSE = 285
  };
#endif
/* Tokens.  */
#define NUM 258
#define ID 259
#define INT 260
#define VOID 261
#define WHILE 262
#define DO 263
#define IF 264
#define THEN 265
#define ELSE 266
#define READ 267
#define WRITE 268
#define FOR 269
#define RETURN 270
#define LE 271
#define GE 272
#define EQ 273
#define NE 274
#define LT 275
#define GT 276
#define AND 277
#define OR 278
#define NOT 279
#define MYBEGIN 280
#define MYEND 281
#define OF 282
#define BOOLEAN 283
#define TRUE 284
#define FALSE 285

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 45 "lab7YACC.y" /* yacc.c:352  */

    int value;
    char * string;
    struct ASTnodetype *ASTnode;
    enum OPERATORS tempOperator;
    enum SYSTYPE isType;


#line 223 "y.tab.c" /* yacc.c:352  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   119

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  127

#define YYUNDEFTOK  2
#define YYMAXUTOK   285

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    36,     2,     2,
      40,    41,    35,    32,    39,    33,     2,    34,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    31,
      43,    42,    44,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    37,     2,    38,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    66,    66,    69,    70,    75,    76,    79,    90,   104,
     119,   134,   152,   153,   154,   157,   172,   157,   190,   191,
     194,   195,   198,   214,   232,   232,   248,   249,   254,   255,
     260,   261,   262,   263,   264,   265,   266,   267,   270,   272,
     275,   280,   290,   297,   298,   304,   310,   316,   323,   326,
     349,   373,   374,   392,   393,   394,   395,   396,   397,   400,
     401,   419,   420,   423,   424,   442,   443,   444,   445,   448,
     449,   455,   456,   457,   462,   468,   477,   509,   510,   513,
     517
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "ID", "INT", "VOID", "WHILE",
  "DO", "IF", "THEN", "ELSE", "READ", "WRITE", "FOR", "RETURN", "LE", "GE",
  "EQ", "NE", "LT", "GT", "AND", "OR", "NOT", "MYBEGIN", "MYEND", "OF",
  "BOOLEAN", "TRUE", "FALSE", "';'", "'+'", "'-'", "'/'", "'*'", "'%'",
  "'['", "']'", "','", "'('", "')'", "'='", "'<'", "'>'", "$accept",
  "program", "declList", "decl", "varDecl", "varList", "typeSpec",
  "funDecl", "$@1", "$@2", "params", "paramList", "param", "compStmt",
  "$@3", "localDecl", "stmtList", "stmt", "exprStmt", "selcStmt",
  "iterStmt", "returnStmt", "readStmt", "writeStmt", "assignStmt",
  "expression", "variable", "simExpr", "relop", "addExpr", "addop", "term",
  "multop", "factor", "call", "args", "argList", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,    59,    43,    45,    47,    42,    37,    91,    93,    44,
      40,    41,    61,    60,    62
};
# endif

#define YYPACT_NINF -51

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-51)))

#define YYTABLE_NINF -19

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       2,   -51,   -51,   -51,    31,   -51,     2,   -51,    36,   -51,
     -51,   -51,    45,     4,    46,    49,    14,   -51,    19,    -3,
     -51,    13,    23,    35,    56,    40,   -51,    41,    49,    51,
     -51,     2,   -51,    53,    67,   -51,   -51,   -51,   -51,     2,
       2,    49,     8,   -51,   -51,     7,    39,    39,    89,    39,
      21,    39,   -51,   -51,   -51,    39,   -51,    68,     8,   -51,
     -51,   -51,   -51,   -51,   -51,   -51,    64,    57,   -51,    54,
      55,   -51,   -51,    39,    39,    88,   -51,    90,    65,    70,
      72,   -51,    73,   -51,    66,   -51,   -51,   -51,    39,   -51,
     -51,   -51,   -51,   -51,   -51,   -51,   -51,    39,    39,   -51,
     -51,   -51,   -51,    39,    71,    69,    74,   -51,     8,     8,
     -51,   -51,   -51,   -51,    75,   -19,    55,   -51,   -51,    39,
     -51,   -51,    94,   -51,   -51,     8,   -51
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    12,    13,    14,     0,     2,     3,     5,     0,     6,
       1,     4,     8,     0,     0,     0,     0,     7,     0,     8,
      10,     0,     9,    13,     0,     0,    19,    20,     0,    23,
      16,     0,    11,     0,     0,    21,    22,    24,    17,    26,
      26,     0,    28,    27,    70,    50,     0,     0,     0,     0,
       0,     0,    73,    74,    39,     0,    31,     0,    28,    30,
      32,    33,    35,    36,    37,    34,     0,    71,    48,    51,
      59,    63,    72,     0,    78,     0,    71,     0,    50,     0,
       0,    43,     0,    75,     0,    25,    29,    38,     0,    53,
      56,    57,    58,    61,    62,    54,    55,     0,     0,    67,
      68,    66,    65,     0,     0,    79,     0,    77,     0,     0,
      45,    46,    44,    69,     0,    52,    60,    64,    49,     0,
      76,    42,    40,    47,    80,     0,    41
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -51,   -51,   104,   -51,   -13,    -6,    25,   -51,   -51,   -51,
     -51,    80,   -51,    78,   -51,    76,    59,   -50,   -51,   -51,
     -51,   -51,   -51,   -51,   -51,   -45,   -42,    26,   -51,    16,
     -51,    20,   -51,   -48,   -51,   -51,     0
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    13,     8,     9,    16,    34,
      25,    26,    27,    56,    39,    42,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    76,    68,    97,    69,
      98,    70,   103,    71,    72,   106,   107
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      67,    75,    77,    83,    80,    82,    79,     1,     2,    20,
      84,    44,    45,    93,    94,    46,    67,    47,     1,    23,
      48,    49,    32,    50,    44,    45,    40,    40,   104,   105,
       3,    10,    51,    37,    14,    17,    15,    52,    53,    54,
      12,     3,    44,    45,    73,    51,    24,    74,    55,    18,
      52,    53,    81,    19,    21,   117,    24,    22,   121,   122,
      29,    55,    28,    51,    41,    41,    67,    67,    52,    53,
      89,    90,    91,    92,   105,   126,   -18,    99,   100,    55,
      31,    30,    14,    67,    15,   -15,    93,    94,    33,   101,
     102,    36,    37,    78,    85,    87,   108,    95,    96,    88,
     109,   110,    73,   111,   112,   125,   123,   113,   119,   118,
      11,    35,    38,   115,   114,   120,    43,    86,   116,   124
};

static const yytype_uint8 yycheck[] =
{
      42,    46,    47,    51,    49,    50,    48,     5,     6,    15,
      55,     3,     4,    32,    33,     7,    58,     9,     5,     6,
      12,    13,    28,    15,     3,     4,    39,    40,    73,    74,
      28,     0,    24,    25,    37,    31,    39,    29,    30,    31,
       4,    28,     3,     4,    37,    24,    21,    40,    40,     3,
      29,    30,    31,     4,    40,   103,    31,    38,   108,   109,
       4,    40,    39,    24,    39,    40,   108,   109,    29,    30,
      16,    17,    18,    19,   119,   125,    41,    22,    23,    40,
      39,    41,    37,   125,    39,    40,    32,    33,    37,    34,
      35,    38,    25,     4,    26,    31,     8,    43,    44,    42,
      10,    31,    37,    31,    31,    11,    31,    41,    39,    38,
       6,    31,    34,    97,    88,    41,    40,    58,    98,   119
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,    28,    46,    47,    48,    49,    51,    52,
       0,    47,     4,    50,    37,    39,    53,    31,     3,     4,
      50,    40,    38,     6,    51,    55,    56,    57,    39,     4,
      41,    39,    50,    37,    54,    56,    38,    25,    58,    59,
      49,    51,    60,    60,     3,     4,     7,     9,    12,    13,
      15,    24,    29,    30,    31,    40,    58,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    74,
      76,    78,    79,    37,    40,    70,    71,    70,     4,    71,
      70,    31,    70,    78,    70,    26,    61,    31,    42,    16,
      17,    18,    19,    32,    33,    43,    44,    73,    75,    22,
      23,    34,    35,    77,    70,    70,    80,    81,     8,    10,
      31,    31,    31,    41,    72,    74,    76,    78,    38,    39,
      41,    62,    62,    31,    81,    11,    62
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    49,    50,    50,
      50,    50,    51,    51,    51,    53,    54,    52,    55,    55,
      56,    56,    57,    57,    59,    58,    60,    60,    61,    61,
      62,    62,    62,    62,    62,    62,    62,    62,    63,    63,
      64,    64,    65,    66,    66,    67,    68,    69,    70,    71,
      71,    72,    72,    73,    73,    73,    73,    73,    73,    74,
      74,    75,    75,    76,    76,    77,    77,    77,    77,    78,
      78,    78,    78,    78,    78,    78,    79,    80,    80,    81,
      81
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     1,     4,
       3,     6,     1,     1,     1,     0,     0,     8,     1,     1,
       1,     3,     4,     2,     0,     5,     0,     2,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       4,     6,     4,     2,     3,     3,     3,     4,     1,     4,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     2,     4,     1,     0,     1,
       3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 2:
#line 66 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode); /* Pass the generated tree to program */}
#line 1407 "y.tab.c" /* yacc.c:1652  */
    break;

  case 3:
#line 69 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode); /* Pass the generated tree to declList */}
#line 1413 "y.tab.c" /* yacc.c:1652  */
    break;

  case 4:
#line 70 "lab7YACC.y" /* yacc.c:1652  */
    { (yyval.ASTnode) = (yyvsp[-1].ASTnode);  /* Pass the generated tree to declList */
                              (yyvsp[-1].ASTnode)->next=(yyvsp[0].ASTnode); /* Connect next of decl to declList */
                            }
#line 1421 "y.tab.c" /* yacc.c:1652  */
    break;

  case 5:
#line 75 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode); /* Pass the generated tree to decl */}
#line 1427 "y.tab.c" /* yacc.c:1652  */
    break;

  case 6:
#line 76 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode); /* Pass the generated tree to decl */}
#line 1433 "y.tab.c" /* yacc.c:1652  */
    break;

  case 7:
#line 79 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = (yyvsp[-1].ASTnode); /* Pass the generated tree to varDecl */
                                    ASTnode *p;
                                    p=(yyval.ASTnode);
                                    while (p != NULL) {
                                        p->isType = (yyvsp[-2].isType);
                                        p-> symbol -> Type = (yyvsp[-2].isType);
                                        p = p -> s1;
                                        }
                                    }
#line 1447 "y.tab.c" /* yacc.c:1652  */
    break;

  case 8:
#line 90 "lab7YACC.y" /* yacc.c:1652  */
    { struct SymbTab *p; 
                    // Check to see if the var is already in the table if so error, or add the information to the tree.
                    if (Search((yyvsp[0].string), level, 0) != NULL) {
                    yyerror((yyvsp[0].string));
                    yyerror("Error: Variable is already defined.");
                    exit(1);
                    }else {
                        (yyval.ASTnode) = ASTCreateNode(varDecl);
                        (yyval.ASTnode) -> name = (yyvsp[0].string);
                        (yyval.ASTnode) -> symbol = Insert((yyvsp[0].string), 0, 0, level, 1, offset, 0);
                        offset++;
                   }
                   /* Create a node with the type of varDecl, setting it's name to ID and the operator in ID */
                 }
#line 1466 "y.tab.c" /* yacc.c:1652  */
    break;

  case 9:
#line 104 "lab7YACC.y" /* yacc.c:1652  */
    { struct SymbTab *p; 
                                // Check to see if the var is already in the table if so error, or add the information to the tree.
                                if (Search((yyvsp[-3].string), level, 0) != NULL) {
                                yyerror((yyvsp[-3].string));
                                yyerror("Error: Variable[] is already defined.");
                                exit(1);
                                } else {
                                    (yyval.ASTnode) = ASTCreateNode(varDecl);
                                    (yyval.ASTnode) -> name = (yyvsp[-3].string);
                                    (yyval.ASTnode) -> value = (yyvsp[-1].value);
                                    (yyval.ASTnode) -> symbol = Insert((yyvsp[-3].string), 0, 2, level, (yyvsp[-1].value), offset, 0);
                                    offset +=(yyvsp[-1].value);
                                    }
                              }
#line 1485 "y.tab.c" /* yacc.c:1652  */
    break;

  case 10:
#line 119 "lab7YACC.y" /* yacc.c:1652  */
    { struct SymbTab *p; 
                                // Check to see if the var is already in the table if so error, or add the information to the tree.
                                if (Search((yyvsp[-2].string), level, 0) != NULL) {
                                yyerror((yyvsp[-2].string));
                                yyerror("Error: Variable is already defined.");
                                exit(1);
                                } else {
                                    (yyval.ASTnode) = ASTCreateNode(varDecl);
                                    (yyval.ASTnode) -> name = (yyvsp[-2].string);
                                    (yyval.ASTnode) -> s1 = (yyvsp[0].ASTnode);
                                    (yyval.ASTnode) -> symbol = Insert((yyvsp[-2].string), 0, 0, level, 1, offset, 0);
                                    offset++;
                                    }
							   /* Create a node with the type of varDecl, setting it's name to ID, the operator in ID and setting s1 in varDecl to varList*/
                             }
#line 1505 "y.tab.c" /* yacc.c:1652  */
    break;

  case 11:
#line 134 "lab7YACC.y" /* yacc.c:1652  */
    { struct SymbTab *p; 
                                            // Check to see if the var is already in the table if so error, or add the information to the tree.
                                            if (Search((yyvsp[-5].string), level, 0) != NULL) {
                                            yyerror((yyvsp[-5].string));
                                            yyerror("Error: Variable [] is already defined.");
                                            exit(1);
                                           } else {
                                           (yyval.ASTnode) = ASTCreateNode(varDecl);
                                           (yyval.ASTnode) -> name = (yyvsp[-5].string);
                                           (yyval.ASTnode) -> value = (yyvsp[-3].value);
                                           (yyval.ASTnode) -> s1 = (yyvsp[0].ASTnode);
                                           (yyval.ASTnode) -> symbol = Insert((yyvsp[-5].string), 0, 2, level, (yyvsp[-3].value), offset, 0);
                                           offset += (yyvsp[-3].value);
                                           }
										   /* Create a node with the type of varDecl, setting it's name to ID, the operator in ID, the value of NUM and setting s1 in varDecl to varList*/
                                         }
#line 1526 "y.tab.c" /* yacc.c:1652  */
    break;

  case 12:
#line 152 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.isType) = INTTYPE;}
#line 1532 "y.tab.c" /* yacc.c:1652  */
    break;

  case 13:
#line 153 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.isType) = VOIDTYPE;}
#line 1538 "y.tab.c" /* yacc.c:1652  */
    break;

  case 14:
#line 154 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.isType) = BOOLTYPE;}
#line 1544 "y.tab.c" /* yacc.c:1652  */
    break;

  case 15:
#line 157 "lab7YACC.y" /* yacc.c:1652  */
    { struct SymbTab *p; Display();
                                                    // Search the table to see if the function is in the table, if the function is new insert the table.
                                                    if (Search((yyvsp[0].string), level, 0) != NULL) {
                                                        yyerror((yyvsp[0].string));
                                                        yyerror("Error: Function has already been defined");
                                                        exit(1);
                                                    } else {
                                                    Insert((yyvsp[0].string),(yyvsp[-1].isType), 1, level, 0, 0, 0);
                                                    // Set the offset into temp to story the value and make the maxOffset to 0
                                                    Tempoffset = offset;
                                                    offset = 0;
                                                    maxOffset = offset;
                                                    }
													/* Create a node with the type of funDecl, setting its name to ID, the operator in ID,setting the s1 pointer of funDecl to params and s2 to compStmt */
                                                    }
#line 1564 "y.tab.c" /* yacc.c:1652  */
    break;

  case 16:
#line 172 "lab7YACC.y" /* yacc.c:1652  */
    { (Search((yyvsp[-4].string), 0, 0)) -> fparms = (yyvsp[-1].ASTnode); // find the function linking fparms to the table entry
                                    }
#line 1571 "y.tab.c" /* yacc.c:1652  */
    break;

  case 17:
#line 175 "lab7YACC.y" /* yacc.c:1652  */
    { (yyval.ASTnode) = ASTCreateNode(funDecl);
                                                    (yyval.ASTnode) -> name = (yyvsp[-6].string);
                                                    (yyval.ASTnode) -> isType = (yyvsp[-7].isType);
                                                    (yyval.ASTnode) -> s1 = (yyvsp[-3].ASTnode);
                                                    (yyval.ASTnode) -> s2 = (yyvsp[0].ASTnode);
                                                    // Set the size of the function to maxOffset and set the symbol size to maxOffset
                                                    (yyval.ASTnode) -> size = maxOffset;
                                                    (yyval.ASTnode) -> symbol = Search((yyvsp[-6].string), level,0);
                                                    (yyval.ASTnode) ->symbol-> mysize = maxOffset;
                                                    
                                                    // Restore offset
                                                    offset= Tempoffset;
                                    }
#line 1589 "y.tab.c" /* yacc.c:1652  */
    break;

  case 18:
#line 190 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = NULL; /*If params is void set it to NULL*/}
#line 1595 "y.tab.c" /* yacc.c:1652  */
    break;

  case 19:
#line 191 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode); /* Pass the generated tree to params */}
#line 1601 "y.tab.c" /* yacc.c:1652  */
    break;

  case 20:
#line 194 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode); /* Pass the generated tree to paramList */}
#line 1607 "y.tab.c" /* yacc.c:1652  */
    break;

  case 21:
#line 195 "lab7YACC.y" /* yacc.c:1652  */
    {(yyvsp[-2].ASTnode) -> next = (yyvsp[0].ASTnode); /*Connect the next pointer or param to paramList*/}
#line 1613 "y.tab.c" /* yacc.c:1652  */
    break;

  case 22:
#line 198 "lab7YACC.y" /* yacc.c:1652  */
    {// Check to see if param is in the table if so error or just insert the param into the table
                                    if (Search((yyvsp[-2].string),level + 1,0) != NULL) {
                                    yyerror((yyvsp[-2].string));
                                    yyerror("Error: Parameter[] has already been defined.");
                                    exit(1);
                                 }else {
                                  (yyval.ASTnode) = ASTCreateNode(param);
                                  (yyval.ASTnode) -> name = (yyvsp[-2].string);
                                  (yyval.ASTnode) -> value = -1;
                                  (yyval.ASTnode) -> isType = (yyvsp[-3].isType);
                                  (yyval.ASTnode) -> symbol = Insert((yyvsp[-2].string), (yyvsp[-3].isType), 2, level + 1, 1, offset, 0);
                                  offset++;
                                 }
								  /* Create a node with the type of param, setting its name to ID, the operator to ID and set the value to -1 to get the [] when needed */
                                 }
#line 1633 "y.tab.c" /* yacc.c:1652  */
    break;

  case 23:
#line 214 "lab7YACC.y" /* yacc.c:1652  */
    {// Check to see if param is in the table if so error or just insert the param into the table
                                if (Search((yyvsp[0].string),level + 1,0) != NULL) {
                                    yyerror((yyvsp[0].string));
                                    yyerror("Error: Parameter has already been defined.");
                                    exit(1);
                                 }else {
                                    (yyval.ASTnode) = ASTCreateNode(param);
                                    (yyval.ASTnode) -> name = (yyvsp[0].string);
                                    (yyval.ASTnode) -> isType = (yyvsp[-1].isType);
                                    (yyval.ASTnode) -> symbol = Insert((yyvsp[0].string), (yyvsp[-1].isType), 0, level + 1, 1, offset, 0);
                                    offset++;

                                    
                                    }
						   /* Create a node with the type of param, setting its name to ID, and the operator to ID */
                           }
#line 1654 "y.tab.c" /* yacc.c:1652  */
    break;

  case 24:
#line 232 "lab7YACC.y" /* yacc.c:1652  */
    {level++;}
#line 1660 "y.tab.c" /* yacc.c:1652  */
    break;

  case 25:
#line 233 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = ASTCreateNode(compStmt);
                                                (yyval.ASTnode) -> s1 = (yyvsp[-2].ASTnode);
                                                (yyval.ASTnode) -> s2 = (yyvsp[-1].ASTnode);
                                                Display();
                                                
                                                // See if maxOffset is less than offset if so set maxOffset to offset
                                                if (maxOffset < offset) maxOffset = offset;
                                                
                                                // Delete and remove it from offset then subtract 1 from level
                                                offset-=Delete(level);
                                                level--;
												/*Create a node with the type of compStmt setting s1 to localDecl and s2 to stmtList */
                                               }
#line 1678 "y.tab.c" /* yacc.c:1652  */
    break;

  case 26:
#line 248 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = NULL;}
#line 1684 "y.tab.c" /* yacc.c:1652  */
    break;

  case 27:
#line 249 "lab7YACC.y" /* yacc.c:1652  */
    { (yyval.ASTnode) = (yyvsp[-1].ASTnode); /* Pass the generated tree to localDecl */
                                  (yyvsp[-1].ASTnode) -> next = (yyvsp[0].ASTnode); /* Point the pointer next to localDecl */
                                }
#line 1692 "y.tab.c" /* yacc.c:1652  */
    break;

  case 28:
#line 254 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = NULL;}
#line 1698 "y.tab.c" /* yacc.c:1652  */
    break;

  case 29:
#line 255 "lab7YACC.y" /* yacc.c:1652  */
    { (yyval.ASTnode) = (yyvsp[-1].ASTnode); /* Pass the generated tree to stmtList */
                              (yyvsp[-1].ASTnode) -> next = (yyvsp[0].ASTnode); /* Point the pointer next to stmtList*/
                            }
#line 1706 "y.tab.c" /* yacc.c:1652  */
    break;

  case 30:
#line 260 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode); /* Pass the generated tree to stmt */}
#line 1712 "y.tab.c" /* yacc.c:1652  */
    break;

  case 31:
#line 261 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode); /* Pass the generated tree to stmt */}
#line 1718 "y.tab.c" /* yacc.c:1652  */
    break;

  case 32:
#line 262 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode); /* Pass the generated tree to stmt */}
#line 1724 "y.tab.c" /* yacc.c:1652  */
    break;

  case 33:
#line 263 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode); /* Pass the generated tree to stmt */}
#line 1730 "y.tab.c" /* yacc.c:1652  */
    break;

  case 34:
#line 264 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode); /* Pass the generated tree to stmt */}
#line 1736 "y.tab.c" /* yacc.c:1652  */
    break;

  case 35:
#line 265 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode); /* Pass the generated tree to stmt */}
#line 1742 "y.tab.c" /* yacc.c:1652  */
    break;

  case 36:
#line 266 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode); /* Pass the generated tree to stmt */}
#line 1748 "y.tab.c" /* yacc.c:1652  */
    break;

  case 37:
#line 267 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode); /* Pass the generated tree to stmt */}
#line 1754 "y.tab.c" /* yacc.c:1652  */
    break;

  case 38:
#line 270 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = ASTCreateNode(expression); 
                              (yyval.ASTnode) -> s1 = (yyvsp[-1].ASTnode); /* Pass the generated tree to exprStmt */}
#line 1761 "y.tab.c" /* yacc.c:1652  */
    break;

  case 39:
#line 272 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = ASTCreateNode(expression); /* Create a node with the type of expression */}
#line 1767 "y.tab.c" /* yacc.c:1652  */
    break;

  case 40:
#line 275 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = ASTCreateNode(ifStmt);
                                       (yyval.ASTnode) -> s1 = (yyvsp[-2].ASTnode);
                                       (yyval.ASTnode) -> s2 = (yyvsp[0].ASTnode);
									   /* Create a node with the type of selcStmt, setting value of s1 as a new node with the type of ifStmt, setting the new nodes s1 to expression and setting s2 to stmt */
                                      }
#line 1777 "y.tab.c" /* yacc.c:1652  */
    break;

  case 41:
#line 280 "lab7YACC.y" /* yacc.c:1652  */
    { (yyval.ASTnode) = ASTCreateNode(ifStmt);
                                                  (yyval.ASTnode) -> s1 = (yyvsp[-4].ASTnode);
                                                  (yyval.ASTnode) -> s2 = ASTCreateNode(ifElse);
                                                  (yyval.ASTnode) -> s2 -> s1 = (yyvsp[-2].ASTnode);
                                                  (yyval.ASTnode) -> s2 -> s2 = (yyvsp[0].ASTnode);
												  /* Create a node with the type of selcStmt, setting value of s1 as a new node with the type of ifStmt, setting the new nodes s1 to expression */
												  /* Create another new node with a type of ifElse setting the value of s1 to stmt and s2 to another stmt */
                                                }
#line 1790 "y.tab.c" /* yacc.c:1652  */
    break;

  case 42:
#line 290 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = ASTCreateNode(iterStmt);
                                        (yyval.ASTnode) -> s1 = (yyvsp[-2].ASTnode);
                                        (yyval.ASTnode) -> s2 = (yyvsp[0].ASTnode);
										/* Create a with the type of iterStmt using the pointer s1 to expression and s2 to stmt */
                                       }
#line 1800 "y.tab.c" /* yacc.c:1652  */
    break;

  case 43:
#line 297 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = ASTCreateNode(returnStmt); /* Create a returnStmt node */}
#line 1806 "y.tab.c" /* yacc.c:1652  */
    break;

  case 44:
#line 298 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = ASTCreateNode(returnStmt);
                                     (yyval.ASTnode) ->s1 = (yyvsp[-1].ASTnode);
									 /* Create a returnStmt node with s1 pointing to expression*/
                                    }
#line 1815 "y.tab.c" /* yacc.c:1652  */
    break;

  case 45:
#line 304 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = ASTCreateNode(readStmt);
                                 (yyval.ASTnode) -> s1 = (yyvsp[-1].ASTnode);
								 /* Create a readStmt node using the s1 pointer set to variable */
                                }
#line 1824 "y.tab.c" /* yacc.c:1652  */
    break;

  case 46:
#line 310 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = ASTCreateNode(writeStmt);
                                    (yyval.ASTnode) -> s1 = (yyvsp[-1].ASTnode);
									/* Create a writeStmt node using the s1 pointer set to expression */
                                   }
#line 1833 "y.tab.c" /* yacc.c:1652  */
    break;

  case 47:
#line 316 "lab7YACC.y" /* yacc.c:1652  */
    { (yyval.ASTnode) = ASTCreateNode(assignStmt);
                                         (yyval.ASTnode) -> s1 = (yyvsp[-3].ASTnode);
                                         (yyval.ASTnode) -> s2 = (yyvsp[-1].ASTnode);  
										 /* Create a assignStmt node using the s1 pointer set to variable and s2 to simExpr */
                                       }
#line 1843 "y.tab.c" /* yacc.c:1652  */
    break;

  case 48:
#line 323 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode); /* Pass the generated tree to expression */}
#line 1849 "y.tab.c" /* yacc.c:1652  */
    break;

  case 49:
#line 326 "lab7YACC.y" /* yacc.c:1652  */
    { struct SymbTab *p; 
                                    // Search the table for the variable if found error, if not found add into the table 
                                        if ((p=Search((yyvsp[-3].string),level,1)) == NULL) {
                                        yyerror((yyvsp[-3].string));
                                        yyerror("Error:  Variable [] has already been defined.");
                                        exit(1);
                                    }else {
                                      (yyval.ASTnode) = ASTCreateNode(variable);
                                      (yyval.ASTnode) -> name = (yyvsp[-3].string);
                                      (yyval.ASTnode) -> s1 = (yyvsp[-1].ASTnode);
                                      // Set the type
                                      (yyval.ASTnode) -> isType = p->Type;
                                      // Check to see if this is a function if so error
                                      if (p->IsAFunc == 2){
                                        (yyval.ASTnode) -> symbol = p;
                                        } else {
                                            yyerror((yyvsp[-3].string));
                                            yyerror("Error: Variable[] is not a function.");
                                            exit(1);
                                        }
                                      }
									  /* Create a variable node with the name in ID and s1 pointing to expression */
                                    }
#line 1877 "y.tab.c" /* yacc.c:1652  */
    break;

  case 50:
#line 349 "lab7YACC.y" /* yacc.c:1652  */
    { struct SymbTab *p; 
                    // Search the table for the variable if found error, if not found add into the table 
                     if ((p=Search((yyvsp[0].string),level,1)) == NULL) {
                           yyerror((yyvsp[0].string));
                           yyerror("Error:  Variable has already been defined.");
                          exit(1);
                     }else {
                     (yyval.ASTnode) = ASTCreateNode(variable);
                     (yyval.ASTnode) -> name = (yyvsp[0].string);
                     (yyval.ASTnode) -> symbol = p;
                     // set the type 
                     (yyval.ASTnode) -> isType =  p-> Type;
                     
                        // Check to see if this is a function if so error
                        if (p -> IsAFunc == 2) {
                            yyerror((yyvsp[0].string));
                           yyerror("Error: Variable is not a function.");
                          exit(1);
                        }
                        }
				   /* Create a variable node with the name in ID */
                 }
#line 1904 "y.tab.c" /* yacc.c:1652  */
    break;

  case 51:
#line 373 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode); /* Pass the generated tree to simExpr */}
#line 1910 "y.tab.c" /* yacc.c:1652  */
    break;

  case 52:
#line 374 "lab7YACC.y" /* yacc.c:1652  */
    {
                                    // Check the table to see if the simExpr is in the table is so error, or add this into the table 
                                     if ( (yyvsp[-2].ASTnode)-> isType != (yyvsp[0].ASTnode)-> isType) {
                                     yyerror("Error: Additiave type mismatch with: >, <, >=, <=, ==, !=");
                                     exit(1);
                                     }
                                      (yyval.ASTnode) = ASTCreateNode(expression);
                                      (yyval.ASTnode)->s1 = (yyvsp[-2].ASTnode);
                                      (yyval.ASTnode)->s2 = (yyvsp[0].ASTnode);
                                      (yyval.ASTnode)-> isType = (yyvsp[0].ASTnode)->isType;
                                      (yyval.ASTnode)->operator=(yyvsp[-1].tempOperator);
                                      (yyval.ASTnode)->name=CreateTemp();
                                      (yyval.ASTnode)->symbol=Insert((yyval.ASTnode)->name, INTTYPE, 0, level, 1, offset, 0);
                                      offset++;//Insert(char *name, enum OPERATORS Type, int isafunc, int  level, int mysize, int offset , ASTnode * fparms)
									  /* Create a expression node with the name in ID and s1 pointing to addExpr and s2 to addExpr and setting the operator of relop */
                                    }
#line 1931 "y.tab.c" /* yacc.c:1652  */
    break;

  case 53:
#line 392 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.tempOperator)= LESSTHANEQ;}
#line 1937 "y.tab.c" /* yacc.c:1652  */
    break;

  case 54:
#line 393 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.tempOperator)= LESSTHAN;}
#line 1943 "y.tab.c" /* yacc.c:1652  */
    break;

  case 55:
#line 394 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.tempOperator)= GREATERTHAN;}
#line 1949 "y.tab.c" /* yacc.c:1652  */
    break;

  case 56:
#line 395 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.tempOperator)= GREATERTHANEQ;}
#line 1955 "y.tab.c" /* yacc.c:1652  */
    break;

  case 57:
#line 396 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.tempOperator)= EQUALTO;}
#line 1961 "y.tab.c" /* yacc.c:1652  */
    break;

  case 58:
#line 397 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.tempOperator)= NOTEQUAL;}
#line 1967 "y.tab.c" /* yacc.c:1652  */
    break;

  case 59:
#line 400 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode); /* Pass the generated tree to addExpr */}
#line 1973 "y.tab.c" /* yacc.c:1652  */
    break;

  case 60:
#line 401 "lab7YACC.y" /* yacc.c:1652  */
    {
                                     if ( (yyvsp[-2].ASTnode)-> isType != (yyvsp[0].ASTnode)-> isType) {
                                     // Check the table to see if the addExpr is in the table is so error, or add this into the table 
                                     yyerror("Error: Additiave type mismatch with: +, -");
                                     exit(1);
                                     }
                                      (yyval.ASTnode) = ASTCreateNode(expression);
                                      (yyval.ASTnode)->s1 = (yyvsp[-2].ASTnode);
                                      (yyval.ASTnode)->s2 = (yyvsp[0].ASTnode);
                                      (yyval.ASTnode)-> isType = (yyvsp[0].ASTnode)->isType;
                                      (yyval.ASTnode)->operator=(yyvsp[-1].tempOperator);
                                      (yyval.ASTnode)->name=CreateTemp();
                                      (yyval.ASTnode)->symbol=Insert((yyval.ASTnode)->name, INTTYPE, 0, level, 1, offset, 0);
                                      offset++;//Insert(char *name, enum OPERATORS Type, int isafunc, int  level, int mysize, int offset , ASTnode * fparms)
									  /* Create a expression node with the name in ID and s1 pointing to addExpr and s2 to addExpr and setting the operator of relop */
                                    }
#line 1994 "y.tab.c" /* yacc.c:1652  */
    break;

  case 61:
#line 419 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.tempOperator) = PLUS;}
#line 2000 "y.tab.c" /* yacc.c:1652  */
    break;

  case 62:
#line 420 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.tempOperator) = MINUS;}
#line 2006 "y.tab.c" /* yacc.c:1652  */
    break;

  case 63:
#line 423 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode); /* Pass the generated tree to term */}
#line 2012 "y.tab.c" /* yacc.c:1652  */
    break;

  case 64:
#line 424 "lab7YACC.y" /* yacc.c:1652  */
    {
                                     if ( (yyvsp[-2].ASTnode)-> isType != (yyvsp[0].ASTnode)-> isType) {
                                     // Check the table to see if the term is in the table is so error, or add this into the table 
                                     yyerror("Error: Additiave type mismatch with: *, /, &&, ||");
                                     exit(1);
                                     }
                                      (yyval.ASTnode) = ASTCreateNode(expression);
                                      (yyval.ASTnode)->s1 = (yyvsp[-2].ASTnode);
                                      (yyval.ASTnode)->s2 = (yyvsp[0].ASTnode);
                                      (yyval.ASTnode)-> isType = (yyvsp[0].ASTnode)->isType;
                                      (yyval.ASTnode)->operator=(yyvsp[-1].tempOperator);
                                      (yyval.ASTnode)->name=CreateTemp();
                                      (yyval.ASTnode)->symbol=Insert((yyval.ASTnode)->name, INTTYPE, 0, level, 1, offset, 0);
                                      offset++;//Insert(char *name, enum OPERATORS Type, int isafunc, int  level, int mysize, int offset , ASTnode * fparms)
									  /* Create a expression node with the name in ID and s1 pointing to addExpr and s2 to addExpr and setting the operator of relop */
                                    }
#line 2033 "y.tab.c" /* yacc.c:1652  */
    break;

  case 65:
#line 442 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.tempOperator)= TIMES;}
#line 2039 "y.tab.c" /* yacc.c:1652  */
    break;

  case 66:
#line 443 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.tempOperator)= DIVIDE;}
#line 2045 "y.tab.c" /* yacc.c:1652  */
    break;

  case 67:
#line 444 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.tempOperator)= MYAND;}
#line 2051 "y.tab.c" /* yacc.c:1652  */
    break;

  case 68:
#line 445 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.tempOperator)= MYOR;}
#line 2057 "y.tab.c" /* yacc.c:1652  */
    break;

  case 69:
#line 448 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = (yyvsp[-1].ASTnode); /* Pass the generated tree to factor */}
#line 2063 "y.tab.c" /* yacc.c:1652  */
    break;

  case 70:
#line 449 "lab7YACC.y" /* yacc.c:1652  */
    { (yyval.ASTnode) = ASTCreateNode(NUMBER);
                    (yyval.ASTnode)->value = (yyvsp[0].value);
                    // Set the type
                    (yyval.ASTnode)->isType = INTTYPE;
					/* Create a node of NUMBER setting its value to NUM */
                  }
#line 2074 "y.tab.c" /* yacc.c:1652  */
    break;

  case 71:
#line 455 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode); /* Pass the generated tree to factor */}
#line 2080 "y.tab.c" /* yacc.c:1652  */
    break;

  case 72:
#line 456 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode); /* Pass the generated tree to factor */}
#line 2086 "y.tab.c" /* yacc.c:1652  */
    break;

  case 73:
#line 457 "lab7YACC.y" /* yacc.c:1652  */
    { (yyval.ASTnode) = ASTCreateNode(NUMBER);
                     (yyval.ASTnode)->value = 1;
                     (yyval.ASTnode)->isType = BOOLTYPE;
					 /* Create a node of NUMBER setting its value to 1 */
                   }
#line 2096 "y.tab.c" /* yacc.c:1652  */
    break;

  case 74:
#line 462 "lab7YACC.y" /* yacc.c:1652  */
    { (yyval.ASTnode) = ASTCreateNode(NUMBER);
                      (yyval.ASTnode)->value = 0;
                      // Set the type
                      (yyval.ASTnode)->isType = BOOLTYPE;
					  /* Create a node of NUMBER setting its value to 0 */
                    }
#line 2107 "y.tab.c" /* yacc.c:1652  */
    break;

  case 75:
#line 468 "lab7YACC.y" /* yacc.c:1652  */
    { (yyval.ASTnode) = ASTCreateNode(expression);
                           (yyval.ASTnode)->operator = MYNOT;
                           (yyval.ASTnode)->s1=(yyvsp[0].ASTnode);
                           // Set the type
                           (yyval.ASTnode)->isType = (yyvsp[0].ASTnode) ->isType;
						   /* Create a node of expression setting its operator to MYNOT and set s1 to factor */
                         }
#line 2119 "y.tab.c" /* yacc.c:1652  */
    break;

  case 76:
#line 477 "lab7YACC.y" /* yacc.c:1652  */
    {struct SymbTab *p;
                                // Search the table to see if the call is in the table if so error
                               if ((p=Search((yyvsp[-3].string),0,0)) != NULL) {
                                    if (p-> IsAFunc != 1) {
                                        yyerror((yyvsp[-3].string));
                                        yyerror("Error: Call is not a function.");
                                        exit(1);
                                    }
                                    // Check to see if the params are the same as args if not error.
                                    if ( compareFormula(p-> fparms, (yyvsp[-1].ASTnode)) != 1) {
                                        yyerror((yyvsp[-3].string));
                                        yyerror("Error: Parameter type or length mismatch between formals and actuals. ");
                                        exit(1);
                                    }
                                    // Create the node
                                    (yyval.ASTnode) = ASTCreateNode(call);
                                    (yyval.ASTnode) -> name = (yyvsp[-3].string);
                                    (yyval.ASTnode) -> s1 = (yyvsp[-1].ASTnode);
                                    // Set the symbol to p
                                    (yyval.ASTnode) -> symbol = p;
                                    // Set the type
                                    (yyval.ASTnode) -> isType = p -> Type; 
                                } else {
                                    yyerror((yyvsp[-3].string));
                                    yyerror("Error: Undefined reference.");
                                    exit(1);
                                }

							   /* Create a node of call setting its name to ID and using the pointer of s1 to args */
                              }
#line 2154 "y.tab.c" /* yacc.c:1652  */
    break;

  case 77:
#line 509 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode); /* Pass the generated tree to args */}
#line 2160 "y.tab.c" /* yacc.c:1652  */
    break;

  case 78:
#line 510 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = NULL;}
#line 2166 "y.tab.c" /* yacc.c:1652  */
    break;

  case 79:
#line 513 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = ASTCreateNode(expression);
                          (yyval.ASTnode) = (yyvsp[0].ASTnode); /* Pass the generated tree to argList */
                          (yyval.ASTnode)-> isType = (yyvsp[0].ASTnode) -> isType; // Set the type
                          }
#line 2175 "y.tab.c" /* yacc.c:1652  */
    break;

  case 80:
#line 517 "lab7YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = ASTCreateNode(expression);  /* Set s1 next to argList */
                                       (yyval.ASTnode) -> s1 = (yyvsp[-2].ASTnode);
                                       (yyval.ASTnode) -> next = (yyvsp[0].ASTnode);
                                       (yyval.ASTnode)-> isType = (yyvsp[-2].ASTnode) -> isType; // set the type
                                       }
#line 2185 "y.tab.c" /* yacc.c:1652  */
    break;


#line 2189 "y.tab.c" /* yacc.c:1652  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 526 "lab7YACC.y" /* yacc.c:1918  */
	/* end of rules, start of program */

int main()
{ yyparse();
    Display();
  //ASTprint(0, program);
}
