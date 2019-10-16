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
#line 1 "lab9YACC.y" /* yacc.c:337  */


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
#include <string.h>
#include "ast.h"
#include "symtable.h"
#include "EMITast.h"

//init
extern int lineNum;
extern int mydebug;
int level= 0;
int offset=2, Tempoffset = 0, maxOffset = 0;
int yylex();

struct ASTnodetype *myprogram = NULL;

void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  fprintf (stderr,"%s Line Number: %d\n", s, lineNum);
}




#line 113 "y.tab.c" /* yacc.c:337  */
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
    STRING = 277,
    AND = 278,
    OR = 279,
    NOT = 280,
    MYBEGIN = 281,
    MYEND = 282,
    OF = 283,
    BOOLEAN = 284,
    MYTRUE = 285,
    MYFALSE = 286
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
#define STRING 277
#define AND 278
#define OR 279
#define NOT 280
#define MYBEGIN 281
#define MYEND 282
#define OF 283
#define BOOLEAN 284
#define MYTRUE 285
#define MYFALSE 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 47 "lab9YACC.y" /* yacc.c:352  */

    int value;
    char * string;
    struct ASTnodetype *ASTnode;
    enum OPERATORS tempOperator;
    enum SYSTYPE isType;


#line 227 "y.tab.c" /* yacc.c:352  */
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
#define YYLAST   130

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  129

#define YYUNDEFTOK  2
#define YYMAXUTOK   286

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
       2,     2,     2,     2,     2,     2,     2,    37,     2,     2,
      41,    42,    36,    33,    40,    34,     2,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    32,
      44,    43,    45,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    68,    68,    71,    72,    77,    78,    81,    92,   106,
     121,   136,   154,   155,   156,   159,   174,   159,   192,   193,
     196,   197,   200,   216,   234,   234,   250,   251,   256,   257,
     262,   263,   264,   265,   266,   267,   268,   269,   272,   274,
     277,   283,   293,   300,   301,   307,   313,   318,   325,   332,
     335,   358,   382,   383,   401,   402,   403,   404,   405,   406,
     409,   410,   428,   429,   432,   433,   451,   452,   453,   454,
     457,   458,   464,   465,   466,   471,   477,   489,   521,   522,
     525,   529
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "ID", "INT", "VOID", "WHILE",
  "DO", "IF", "THEN", "ELSE", "READ", "WRITE", "FOR", "RETURN", "LE", "GE",
  "EQ", "NE", "LT", "GT", "STRING", "AND", "OR", "NOT", "MYBEGIN", "MYEND",
  "OF", "BOOLEAN", "MYTRUE", "MYFALSE", "';'", "'+'", "'-'", "'/'", "'*'",
  "'%'", "'['", "']'", "','", "'('", "')'", "'='", "'<'", "'>'", "$accept",
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
     285,   286,    59,    43,    45,    47,    42,    37,    91,    93,
      44,    40,    41,    61,    60,    62
};
# endif

#define YYPACT_NINF -84

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-84)))

#define YYTABLE_NINF -19

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      28,   -84,   -84,   -84,     7,   -84,    28,   -84,    11,   -84,
     -84,   -84,    55,    -7,    44,    60,    17,   -84,    27,   -27,
     -84,    33,    39,    42,    84,    52,   -84,    59,    60,    62,
     -84,    28,   -84,    63,    66,   -84,   -84,   -84,   -84,    28,
      28,    60,     5,   -84,   -84,    22,    50,    50,    97,    18,
      20,    50,   -84,   -84,   -84,    50,   -84,    76,     5,   -84,
     -84,   -84,   -84,   -84,   -84,   -84,    72,    64,   -84,    53,
      54,   -84,   -84,    50,    50,    98,   -84,    95,    70,    77,
      78,    79,   -84,    80,   -84,    71,   -84,   -84,   -84,    50,
     -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,    50,    50,
     -84,   -84,   -84,   -84,    50,    75,    81,    73,   -84,     5,
       5,   -84,   -84,   -84,   -84,   -84,    85,     8,    54,   -84,
     -84,    50,   -84,   -84,   105,   -84,   -84,     5,   -84
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
      26,     0,    28,    27,    71,    51,     0,     0,     0,     0,
       0,     0,    74,    75,    39,     0,    31,     0,    28,    30,
      32,    33,    35,    36,    37,    34,     0,    72,    49,    52,
      60,    64,    73,     0,    79,     0,    72,     0,    51,     0,
       0,     0,    43,     0,    76,     0,    25,    29,    38,     0,
      54,    57,    58,    59,    62,    63,    55,    56,     0,     0,
      68,    69,    67,    66,     0,     0,    80,     0,    78,     0,
       0,    45,    47,    46,    44,    70,     0,    53,    61,    65,
      50,     0,    77,    42,    40,    48,    81,     0,    41
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -84,   -84,   112,   -84,    43,     4,    34,   -84,   -84,   -84,
     -84,    88,   -84,    86,   -84,    82,    65,   -83,   -84,   -84,
     -84,   -84,   -84,   -84,   -84,   -45,   -42,    35,   -84,    29,
     -84,    26,   -84,   -48,   -84,   -84,     9
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    13,     8,     9,    16,    34,
      25,    26,    27,    56,    39,    42,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    76,    68,    98,    69,
      99,    70,   104,    71,    72,   107,   108
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      67,    75,    77,    84,    81,    83,    79,    10,    44,    45,
      85,    14,    46,    15,    47,    12,    67,    48,    49,    20,
      50,    44,    45,    44,    45,    17,   123,   124,   105,   106,
      51,    37,    32,     1,     2,    52,    53,    54,     1,    23,
      80,    94,    95,    51,   128,    51,    55,    18,    52,    53,
      52,    53,    82,    44,    45,    24,   119,     3,    21,    55,
      73,    55,     3,    74,    19,    24,    22,    67,    67,    90,
      91,    92,    93,    41,    41,    51,   106,   100,   101,    28,
      52,    53,    40,    40,   -18,    67,    94,    95,    29,   102,
     103,    55,    37,    14,    30,    15,   -15,    96,    97,    31,
      33,    78,    36,    86,    88,   110,   109,    89,    73,   111,
     112,   113,   114,   115,   120,   122,   127,   125,    11,    35,
      38,   121,    43,    87,   116,   118,     0,   117,     0,     0,
     126
};

static const yytype_int8 yycheck[] =
{
      42,    46,    47,    51,    49,    50,    48,     0,     3,     4,
      55,    38,     7,    40,     9,     4,    58,    12,    13,    15,
      15,     3,     4,     3,     4,    32,   109,   110,    73,    74,
      25,    26,    28,     5,     6,    30,    31,    32,     5,     6,
      22,    33,    34,    25,   127,    25,    41,     3,    30,    31,
      30,    31,    32,     3,     4,    21,   104,    29,    41,    41,
      38,    41,    29,    41,     4,    31,    39,   109,   110,    16,
      17,    18,    19,    39,    40,    25,   121,    23,    24,    40,
      30,    31,    39,    40,    42,   127,    33,    34,     4,    35,
      36,    41,    26,    38,    42,    40,    41,    44,    45,    40,
      38,     4,    39,    27,    32,    10,     8,    43,    38,    32,
      32,    32,    32,    42,    39,    42,    11,    32,     6,    31,
      34,    40,    40,    58,    89,    99,    -1,    98,    -1,    -1,
     121
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,    29,    47,    48,    49,    50,    52,    53,
       0,    48,     4,    51,    38,    40,    54,    32,     3,     4,
      51,    41,    39,     6,    52,    56,    57,    58,    40,     4,
      42,    40,    51,    38,    55,    57,    39,    26,    59,    60,
      50,    52,    61,    61,     3,     4,     7,     9,    12,    13,
      15,    25,    30,    31,    32,    41,    59,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    75,
      77,    79,    80,    38,    41,    71,    72,    71,     4,    72,
      22,    71,    32,    71,    79,    71,    27,    62,    32,    43,
      16,    17,    18,    19,    33,    34,    44,    45,    74,    76,
      23,    24,    35,    36,    78,    71,    71,    81,    82,     8,
      10,    32,    32,    32,    32,    42,    73,    75,    77,    79,
      39,    40,    42,    63,    63,    32,    82,    11,    63
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    50,    51,    51,
      51,    51,    52,    52,    52,    54,    55,    53,    56,    56,
      57,    57,    58,    58,    60,    59,    61,    61,    62,    62,
      63,    63,    63,    63,    63,    63,    63,    63,    64,    64,
      65,    65,    66,    67,    67,    68,    69,    69,    70,    71,
      72,    72,    73,    73,    74,    74,    74,    74,    74,    74,
      75,    75,    76,    76,    77,    77,    78,    78,    78,    78,
      79,    79,    79,    79,    79,    79,    79,    80,    81,    81,
      82,    82
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     1,     4,
       3,     6,     1,     1,     1,     0,     0,     8,     1,     1,
       1,     3,     4,     2,     0,     5,     0,     2,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       4,     6,     4,     2,     3,     3,     3,     3,     4,     1,
       4,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     2,     4,     1,     0,
       1,     3
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
#line 68 "lab9YACC.y" /* yacc.c:1652  */
    {myprogram = (yyvsp[0].ASTnode); /* ASToutput(0, $$);  Pass the generated tree to program */}
#line 1415 "y.tab.c" /* yacc.c:1652  */
    break;

  case 3:
#line 71 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode); /* Pass the generated tree to declList */}
#line 1421 "y.tab.c" /* yacc.c:1652  */
    break;

  case 4:
#line 72 "lab9YACC.y" /* yacc.c:1652  */
    { (yyval.ASTnode) = (yyvsp[-1].ASTnode);  /* Pass the generated tree to declList */
                              (yyvsp[-1].ASTnode)->next=(yyvsp[0].ASTnode); /* Connect next of decl to declList */
                            }
#line 1429 "y.tab.c" /* yacc.c:1652  */
    break;

  case 5:
#line 77 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode); /* Pass the generated tree to decl */}
#line 1435 "y.tab.c" /* yacc.c:1652  */
    break;

  case 6:
#line 78 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode); /* Pass the generated tree to decl */}
#line 1441 "y.tab.c" /* yacc.c:1652  */
    break;

  case 7:
#line 81 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = (yyvsp[-1].ASTnode); /* Pass the generated tree to varDecl */
                                    ASTnode *p;
                                    p=(yyval.ASTnode);
                                    while (p != NULL) {
                                        p->isType = (yyvsp[-2].isType);
                                        p-> symbol -> Type = (yyvsp[-2].isType);
                                        p = p -> s1;
                                        }
                                    }
#line 1455 "y.tab.c" /* yacc.c:1652  */
    break;

  case 8:
#line 92 "lab9YACC.y" /* yacc.c:1652  */
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
#line 1474 "y.tab.c" /* yacc.c:1652  */
    break;

  case 9:
#line 106 "lab9YACC.y" /* yacc.c:1652  */
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
#line 1493 "y.tab.c" /* yacc.c:1652  */
    break;

  case 10:
#line 121 "lab9YACC.y" /* yacc.c:1652  */
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
#line 1513 "y.tab.c" /* yacc.c:1652  */
    break;

  case 11:
#line 136 "lab9YACC.y" /* yacc.c:1652  */
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
#line 1534 "y.tab.c" /* yacc.c:1652  */
    break;

  case 12:
#line 154 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.isType) = INTTYPE;}
#line 1540 "y.tab.c" /* yacc.c:1652  */
    break;

  case 13:
#line 155 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.isType) = VOIDTYPE;}
#line 1546 "y.tab.c" /* yacc.c:1652  */
    break;

  case 14:
#line 156 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.isType) = BOOLTYPE;}
#line 1552 "y.tab.c" /* yacc.c:1652  */
    break;

  case 15:
#line 159 "lab9YACC.y" /* yacc.c:1652  */
    { struct SymbTab *p; if (mydebug) Display();
                                                    // Search the table to see if the function is in the table, if the function is new insert the table.
                                                    if (Search((yyvsp[0].string), level, 0) != NULL) {
                                                        yyerror((yyvsp[0].string));
                                                        yyerror("Error: Function has already been defined");
                                                        exit(1);
                                                    } else {
                                                    // Set the offset into temp to story the value and make the maxOffset to 0
                                                    Tempoffset = offset;
                                                    offset = 2;
                                                    maxOffset = offset;
                                                    Insert((yyvsp[0].string),(yyvsp[-1].isType), 1, level, 0, offset, 0);
                                                    }
													/* Create a node with the type of funDecl, setting its name to ID, the operator in ID,setting the s1 pointer of funDecl to params and s2 to compStmt */
                                                    }
#line 1572 "y.tab.c" /* yacc.c:1652  */
    break;

  case 16:
#line 174 "lab9YACC.y" /* yacc.c:1652  */
    { (Search((yyvsp[-4].string), 0, 0)) -> fparms = (yyvsp[-1].ASTnode); // find the function linking fparms to the table entry
                                    }
#line 1579 "y.tab.c" /* yacc.c:1652  */
    break;

  case 17:
#line 177 "lab9YACC.y" /* yacc.c:1652  */
    { (yyval.ASTnode) = ASTCreateNode(funDecl);
                                                    (yyval.ASTnode) -> name = (yyvsp[-6].string);
                                                    (yyval.ASTnode) -> isType = (yyvsp[-7].isType);
                                                    (yyval.ASTnode) -> s1 = (yyvsp[-3].ASTnode);
                                                    (yyval.ASTnode) -> s2 = (yyvsp[0].ASTnode);
                                                    // Set the size of the function to maxOffset and set the symbol size to maxOffset
                                                    (yyval.ASTnode) -> size = maxOffset;
                                                    (yyval.ASTnode) -> symbol = Search((yyvsp[-6].string), level,0);
                                                    (yyval.ASTnode) ->symbol-> offset = maxOffset;
                                                    
                                                    // Restore offset
                                                    offset= Tempoffset;
                                    }
#line 1597 "y.tab.c" /* yacc.c:1652  */
    break;

  case 18:
#line 192 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = NULL; /*If params is void set it to NULL*/}
#line 1603 "y.tab.c" /* yacc.c:1652  */
    break;

  case 19:
#line 193 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode); /* Pass the generated tree to params */}
#line 1609 "y.tab.c" /* yacc.c:1652  */
    break;

  case 20:
#line 196 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode); /* Pass the generated tree to paramList */}
#line 1615 "y.tab.c" /* yacc.c:1652  */
    break;

  case 21:
#line 197 "lab9YACC.y" /* yacc.c:1652  */
    {(yyvsp[-2].ASTnode) -> next = (yyvsp[0].ASTnode); /*Connect the next pointer or param to paramList*/}
#line 1621 "y.tab.c" /* yacc.c:1652  */
    break;

  case 22:
#line 200 "lab9YACC.y" /* yacc.c:1652  */
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
#line 1641 "y.tab.c" /* yacc.c:1652  */
    break;

  case 23:
#line 216 "lab9YACC.y" /* yacc.c:1652  */
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
#line 1662 "y.tab.c" /* yacc.c:1652  */
    break;

  case 24:
#line 234 "lab9YACC.y" /* yacc.c:1652  */
    {level++;}
#line 1668 "y.tab.c" /* yacc.c:1652  */
    break;

  case 25:
#line 235 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = ASTCreateNode(compStmt);
                                                (yyval.ASTnode) -> s1 = (yyvsp[-2].ASTnode);
                                                (yyval.ASTnode) -> s2 = (yyvsp[-1].ASTnode);
                                                if (mydebug) Display();
                                                
                                                // See if maxOffset is less than offset if so set maxOffset to offset
                                                if (maxOffset < offset) maxOffset = offset;
                                                
                                                // Delete and remove it from offset then subtract 1 from level
                                                offset-=Delete(level);
                                                level--;
												/*Create a node with the type of compStmt setting s1 to localDecl and s2 to stmtList */
                                               }
#line 1686 "y.tab.c" /* yacc.c:1652  */
    break;

  case 26:
#line 250 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = NULL;}
#line 1692 "y.tab.c" /* yacc.c:1652  */
    break;

  case 27:
#line 251 "lab9YACC.y" /* yacc.c:1652  */
    { (yyval.ASTnode) = (yyvsp[-1].ASTnode); /* Pass the generated tree to localDecl */
                                  (yyvsp[-1].ASTnode) -> next = (yyvsp[0].ASTnode); /* Point the pointer next to localDecl */
                                }
#line 1700 "y.tab.c" /* yacc.c:1652  */
    break;

  case 28:
#line 256 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = NULL;}
#line 1706 "y.tab.c" /* yacc.c:1652  */
    break;

  case 29:
#line 257 "lab9YACC.y" /* yacc.c:1652  */
    { (yyval.ASTnode) = (yyvsp[-1].ASTnode); /* Pass the generated tree to stmtList */
                              (yyvsp[-1].ASTnode) -> next = (yyvsp[0].ASTnode); /* Point the pointer next to stmtList*/
                            }
#line 1714 "y.tab.c" /* yacc.c:1652  */
    break;

  case 30:
#line 262 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode); /* Pass the generated tree to stmt */}
#line 1720 "y.tab.c" /* yacc.c:1652  */
    break;

  case 31:
#line 263 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode); /* Pass the generated tree to stmt */}
#line 1726 "y.tab.c" /* yacc.c:1652  */
    break;

  case 32:
#line 264 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode); /* Pass the generated tree to stmt */}
#line 1732 "y.tab.c" /* yacc.c:1652  */
    break;

  case 33:
#line 265 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode); /* Pass the generated tree to stmt */}
#line 1738 "y.tab.c" /* yacc.c:1652  */
    break;

  case 34:
#line 266 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode); /* Pass the generated tree to stmt */}
#line 1744 "y.tab.c" /* yacc.c:1652  */
    break;

  case 35:
#line 267 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode); /* Pass the generated tree to stmt */}
#line 1750 "y.tab.c" /* yacc.c:1652  */
    break;

  case 36:
#line 268 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode); /* Pass the generated tree to stmt */}
#line 1756 "y.tab.c" /* yacc.c:1652  */
    break;

  case 37:
#line 269 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode); /* Pass the generated tree to stmt */}
#line 1762 "y.tab.c" /* yacc.c:1652  */
    break;

  case 38:
#line 272 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = ASTCreateNode(expression); 
                              (yyval.ASTnode) -> s1 = (yyvsp[-1].ASTnode); /* Pass the generated tree to exprStmt */}
#line 1769 "y.tab.c" /* yacc.c:1652  */
    break;

  case 39:
#line 274 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = ASTCreateNode(expression); /* Create a node with the type of expression */}
#line 1775 "y.tab.c" /* yacc.c:1652  */
    break;

  case 40:
#line 277 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = ASTCreateNode(ifStmt);
                                       (yyval.ASTnode) -> s1 = (yyvsp[-2].ASTnode);
                                       (yyval.ASTnode) -> s2 = ASTCreateNode(ifElse);
                                       (yyval.ASTnode) -> s2 -> s1 = (yyvsp[0].ASTnode);
									   /* Create a node with the type of selcStmt, setting value of s1 as a new node with the type of ifStmt, setting the new nodes s1 to expression and setting s2 to stmt */
                                      }
#line 1786 "y.tab.c" /* yacc.c:1652  */
    break;

  case 41:
#line 283 "lab9YACC.y" /* yacc.c:1652  */
    { (yyval.ASTnode) = ASTCreateNode(ifStmt);
                                                  (yyval.ASTnode) -> s1 = (yyvsp[-4].ASTnode);
                                                  (yyval.ASTnode) -> s2 = ASTCreateNode(ifElse);
                                                  (yyval.ASTnode) -> s2 -> s1 = (yyvsp[-2].ASTnode);
                                                  (yyval.ASTnode) -> s2 -> s2 = (yyvsp[0].ASTnode);
												  /* Create a node with the type of selcStmt, setting value of s1 as a new node with the type of ifStmt, setting the new nodes s1 to expression */
												  /* Create another new node with a type of ifElse setting the value of s1 to stmt and s2 to another stmt */
                                                }
#line 1799 "y.tab.c" /* yacc.c:1652  */
    break;

  case 42:
#line 293 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = ASTCreateNode(iterStmt);
                                        (yyval.ASTnode) -> s1 = (yyvsp[-2].ASTnode);
                                        (yyval.ASTnode) -> s2 = (yyvsp[0].ASTnode);
										/* Create a with the type of iterStmt using the pointer s1 to expression and s2 to stmt */
                                       }
#line 1809 "y.tab.c" /* yacc.c:1652  */
    break;

  case 43:
#line 300 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = ASTCreateNode(returnStmt); /* Create a returnStmt node */}
#line 1815 "y.tab.c" /* yacc.c:1652  */
    break;

  case 44:
#line 301 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = ASTCreateNode(returnStmt);
                                     (yyval.ASTnode) ->s1 = (yyvsp[-1].ASTnode);
									 /* Create a returnStmt node with s1 pointing to expression*/
                                    }
#line 1824 "y.tab.c" /* yacc.c:1652  */
    break;

  case 45:
#line 307 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = ASTCreateNode(readStmt);
                                 (yyval.ASTnode) -> s1 = (yyvsp[-1].ASTnode);
								 /* Create a readStmt node using the s1 pointer set to variable */
                                }
#line 1833 "y.tab.c" /* yacc.c:1652  */
    break;

  case 46:
#line 313 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = ASTCreateNode(writeStmt);
                                    (yyval.ASTnode) -> s1 = (yyvsp[-1].ASTnode);
									/* Create a writeStmt node using the s1 pointer set to expression */
                                   }
#line 1842 "y.tab.c" /* yacc.c:1652  */
    break;

  case 47:
#line 318 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = ASTCreateNode(writeStmt);
                                (yyval.ASTnode) -> name = (yyvsp[-1].string);
                                (yyval.ASTnode) -> isType = STRINGTYPE;
                                (yyval.ASTnode) -> label = CreateLabel();
                                }
#line 1852 "y.tab.c" /* yacc.c:1652  */
    break;

  case 48:
#line 325 "lab9YACC.y" /* yacc.c:1652  */
    { (yyval.ASTnode) = ASTCreateNode(assignStmt);
                                         (yyval.ASTnode) -> s1 = (yyvsp[-3].ASTnode);
                                         (yyval.ASTnode) -> s2 = (yyvsp[-1].ASTnode);  
										 /* Create a assignStmt node using the s1 pointer set to variable and s2 to simExpr */
                                       }
#line 1862 "y.tab.c" /* yacc.c:1652  */
    break;

  case 49:
#line 332 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode); /* Pass the generated tree to expression */}
#line 1868 "y.tab.c" /* yacc.c:1652  */
    break;

  case 50:
#line 335 "lab9YACC.y" /* yacc.c:1652  */
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
#line 1896 "y.tab.c" /* yacc.c:1652  */
    break;

  case 51:
#line 358 "lab9YACC.y" /* yacc.c:1652  */
    { struct SymbTab *p; 
                    // Search the table for the variable if found error, if not found add into the table 
                     if ((p=Search((yyvsp[0].string),level,1)) == NULL) {
                           yyerror((yyvsp[0].string));
                           yyerror("Error:  Variable has not been defined.");
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
#line 1923 "y.tab.c" /* yacc.c:1652  */
    break;

  case 52:
#line 382 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode); /* Pass the generated tree to simExpr */}
#line 1929 "y.tab.c" /* yacc.c:1652  */
    break;

  case 53:
#line 383 "lab9YACC.y" /* yacc.c:1652  */
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
#line 1950 "y.tab.c" /* yacc.c:1652  */
    break;

  case 54:
#line 401 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.tempOperator)= LESSTHANEQ;}
#line 1956 "y.tab.c" /* yacc.c:1652  */
    break;

  case 55:
#line 402 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.tempOperator)= LESSTHAN;}
#line 1962 "y.tab.c" /* yacc.c:1652  */
    break;

  case 56:
#line 403 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.tempOperator)= GREATERTHAN;}
#line 1968 "y.tab.c" /* yacc.c:1652  */
    break;

  case 57:
#line 404 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.tempOperator)= GREATERTHANEQ;}
#line 1974 "y.tab.c" /* yacc.c:1652  */
    break;

  case 58:
#line 405 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.tempOperator)= EQUALTO;}
#line 1980 "y.tab.c" /* yacc.c:1652  */
    break;

  case 59:
#line 406 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.tempOperator)= NOTEQUAL;}
#line 1986 "y.tab.c" /* yacc.c:1652  */
    break;

  case 60:
#line 409 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode); /* Pass the generated tree to addExpr */}
#line 1992 "y.tab.c" /* yacc.c:1652  */
    break;

  case 61:
#line 410 "lab9YACC.y" /* yacc.c:1652  */
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
#line 2013 "y.tab.c" /* yacc.c:1652  */
    break;

  case 62:
#line 428 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.tempOperator) = PLUS;}
#line 2019 "y.tab.c" /* yacc.c:1652  */
    break;

  case 63:
#line 429 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.tempOperator) = MINUS;}
#line 2025 "y.tab.c" /* yacc.c:1652  */
    break;

  case 64:
#line 432 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode); /* Pass the generated tree to term */}
#line 2031 "y.tab.c" /* yacc.c:1652  */
    break;

  case 65:
#line 433 "lab9YACC.y" /* yacc.c:1652  */
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
#line 2052 "y.tab.c" /* yacc.c:1652  */
    break;

  case 66:
#line 451 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.tempOperator)= TIMES;}
#line 2058 "y.tab.c" /* yacc.c:1652  */
    break;

  case 67:
#line 452 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.tempOperator)= DIVIDE;}
#line 2064 "y.tab.c" /* yacc.c:1652  */
    break;

  case 68:
#line 453 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.tempOperator)= MYAND;}
#line 2070 "y.tab.c" /* yacc.c:1652  */
    break;

  case 69:
#line 454 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.tempOperator)= MYOR;}
#line 2076 "y.tab.c" /* yacc.c:1652  */
    break;

  case 70:
#line 457 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = (yyvsp[-1].ASTnode); /* Pass the generated tree to factor */}
#line 2082 "y.tab.c" /* yacc.c:1652  */
    break;

  case 71:
#line 458 "lab9YACC.y" /* yacc.c:1652  */
    { (yyval.ASTnode) = ASTCreateNode(NUMBER);
                    (yyval.ASTnode)->value = (yyvsp[0].value);
                    // Set the type
                    (yyval.ASTnode)->isType = INTTYPE;
					/* Create a node of NUMBER setting its value to NUM */
                  }
#line 2093 "y.tab.c" /* yacc.c:1652  */
    break;

  case 72:
#line 464 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode); /* Pass the generated tree to factor */}
#line 2099 "y.tab.c" /* yacc.c:1652  */
    break;

  case 73:
#line 465 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode); /* Pass the generated tree to factor */}
#line 2105 "y.tab.c" /* yacc.c:1652  */
    break;

  case 74:
#line 466 "lab9YACC.y" /* yacc.c:1652  */
    { (yyval.ASTnode) = ASTCreateNode(NUMBER);
                     (yyval.ASTnode)->value = 1;
                     (yyval.ASTnode)->isType = BOOLTYPE;
					 /* Create a node of NUMBER setting its value to 1 */
                   }
#line 2115 "y.tab.c" /* yacc.c:1652  */
    break;

  case 75:
#line 471 "lab9YACC.y" /* yacc.c:1652  */
    { (yyval.ASTnode) = ASTCreateNode(NUMBER);
                      (yyval.ASTnode)->value = 0;
                      // Set the type
                      (yyval.ASTnode)->isType = BOOLTYPE;
					  /* Create a node of NUMBER setting its value to 0 */
                    }
#line 2126 "y.tab.c" /* yacc.c:1652  */
    break;

  case 76:
#line 477 "lab9YACC.y" /* yacc.c:1652  */
    { (yyval.ASTnode) = ASTCreateNode(expression);
                           (yyval.ASTnode)->operator = MYNOT;
                           (yyval.ASTnode)->s1=(yyvsp[0].ASTnode);
                           // Set the type
                           (yyval.ASTnode)->isType = (yyvsp[0].ASTnode) ->isType;
                           (yyval.ASTnode)->name=CreateTemp();
                           (yyval.ASTnode)->symbol=Insert((yyval.ASTnode)->name, BOOLTYPE, 0, level, 1, offset, 0);
                           offset++;
						   /* Create a node of expression setting its operator to MYNOT and set s1 to factor */
                         }
#line 2141 "y.tab.c" /* yacc.c:1652  */
    break;

  case 77:
#line 489 "lab9YACC.y" /* yacc.c:1652  */
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
#line 2176 "y.tab.c" /* yacc.c:1652  */
    break;

  case 78:
#line 521 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = (yyvsp[0].ASTnode); /* Pass the generated tree to args */}
#line 2182 "y.tab.c" /* yacc.c:1652  */
    break;

  case 79:
#line 522 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = NULL;}
#line 2188 "y.tab.c" /* yacc.c:1652  */
    break;

  case 80:
#line 525 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = ASTCreateNode(expression);
                          (yyval.ASTnode) = (yyvsp[0].ASTnode); /* Pass the generated tree to argList */
                          (yyval.ASTnode)-> isType = (yyvsp[0].ASTnode) -> isType; // Set the type
                          }
#line 2197 "y.tab.c" /* yacc.c:1652  */
    break;

  case 81:
#line 529 "lab9YACC.y" /* yacc.c:1652  */
    {(yyval.ASTnode) = ASTCreateNode(expression);  /* Set s1 next to argList */
                                       (yyval.ASTnode) -> s1 = (yyvsp[-2].ASTnode);
                                       (yyval.ASTnode) -> next = (yyvsp[0].ASTnode);
                                       (yyval.ASTnode)-> isType = (yyvsp[-2].ASTnode) -> isType; // set the type
                                       }
#line 2207 "y.tab.c" /* yacc.c:1652  */
    break;


#line 2211 "y.tab.c" /* yacc.c:1652  */
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
#line 538 "lab9YACC.y" /* yacc.c:1918  */
	/* end of rules, start of program */

int main(int argc, char*argv[])
{ 
    yyparse(); 
    char myfile[100];
    fp = NULL;
    
    printf("There is %d params.\n", argc);
    
    for (int i = 0; i < argc; i++){
        if (strcmp(argv[i], "-d") == 0){
        mydebug = 1;
        printf("-d Debug Enabled!\n");
        }
        if (strcmp(argv[i], "-o") == 0){
            printf("-o Program Name: %s\n", argv[i+1]);
            
            strcpy(myfile, argv[i+1]);
            strcat(myfile, ".asm");
            fp= fopen(myfile, "w");
            if(fp == NULL) {
                printf("Error: Could not open file named %s.asm\n", argv[i+1]);
            } else {
                fprintf(fp,"%%include \"io64.inc\" \n");
                emitGlobals(myprogram);
                fprintf(fp,"\nsection .data\n");
                emitStrings(myprogram);
                fprintf(fp,"\nsection .text\n");
                fprintf(fp,"\tglobal main\n\n\n");
                emitAst(myprogram);
                }
            
            }
        } // end for
        
    

  if (mydebug) ASTprint(0, program);
}
