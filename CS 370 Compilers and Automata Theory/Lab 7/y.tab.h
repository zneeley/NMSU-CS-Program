/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
#line 45 "lab7YACC.y" /* yacc.c:1921  */

    int value;
    char * string;
    struct ASTnodetype *ASTnode;
    enum OPERATORS tempOperator;
    enum SYSTYPE isType;


#line 127 "y.tab.h" /* yacc.c:1921  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
