%{

/*
 * Name: Zachary Neeley
 * Date: 2/27/19
 * Purpose: The purpose of this program is to create a code interperator using LEX and YACC
 *          to learn the general process of tokens, expressions and basic trees.
 *     
 *      Input: Numbers and characters ex: int x[100],y, z;
 *      Output: Any syntax errors in the code and their line number
 * 
 */



/* begin specs */
#include <stdio.h>
#include <ctype.h>
#include "ast.c"

extern int lineNum;

int yylex();

struct ASTnodetype *myprogram = NULL;
enum OPERATORS tempOperator;

void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  fprintf (stderr,"%s on line %d\n", s, lineNum);
}



%}
/*  defines the start symbol, what values come back from LEX and how the operators are associated  */

%start program

%union {
    int value;
    char * string;
    struct ASTnodetype *ASTnode;

}

%token <value> NUM
%token <string> ID INT VOID WHILE DO IF THEN ELSE READ WRITE FOR RETURN LE GE EQ NE LT GT 
%token AND OR NOT 
%token MYBEGIN MYEND OF BOOLEAN TRUE FALSE 
%type <ASTnode> varDecl declList varList decl funDecl typeSpec param params paramList compStmt localDecl program variable stmt stmtList readStmt expression simExpr term addop multop addExpr relop 
%type <ASTnode> factor call writeStmt args argList exprStmt ';' assignStmt returnStmt iterStmt selcStmt

%%	/* end specs, begin rules */

program     : declList {ASTprint(0, $$); $$ = $1;} 
            ;

declList    : decl {$$ = $1;} 
            | decl declList { $$ = $1; 
                              $1->next=$2;
                            }
            ;

decl        : varDecl {$$ = $1;} 
            | funDecl {$$ = $1;} 
            ;

varDecl     : typeSpec varList ';' {$$ = $2;}
            ;

varList     : ID { $$ = ASTCreateNode(varDecl);
                   $$ -> name = $1;
                   $$ -> operator = tempOperator;
                   
                 }
            | ID '[' NUM ']' { $$ = ASTCreateNode(varDecl);
                               $$ -> name = $1;
                               $$ -> operator = tempOperator;
                               $$ -> value = $3;
                   
                             }
            | ID ',' varList { $$ = ASTCreateNode(varDecl);
                               $$ -> name = $1;
                               $$ -> operator = tempOperator;
                               $$ -> s1 = $3;
                             }
            | ID '[' NUM ']' ',' varList { $$ = ASTCreateNode(varDecl);
                                           $$ -> name = $1;
                                           $$ -> operator = tempOperator;
                                           $$ -> value = $3;
                                           $$ -> s1 = $6;
                                         }
            ;

typeSpec    : INT {tempOperator = INTTYPE;}
            | VOID {tempOperator = VOIDTYPE;}
            | BOOLEAN {tempOperator = BOOLTYPE;}
            ;

funDecl     : typeSpec ID '(' params ')' compStmt { $$ = ASTCreateNode(funDecl);
                                                    $$ -> name = $2;
                                                    $$ -> operator = tempOperator;
                                                    $$ -> s1 = $4;
                                                    $$ -> s2 = $6;
                                                    }
            ;

params      : VOID {$$ = NULL;}
            | paramList {$$ = $1;}
            ;

paramList   : param {$$ = $1;}
            | param ',' paramList {$1 -> next = $3;}
            ;

param       : typeSpec ID '['']' {$$ = ASTCreateNode(param);
                                  $$ -> name = $2;
                                  $$ -> operator = tempOperator;
                                  $$ -> value = -1;
                                 }
                                 
            | typeSpec ID {$$ = ASTCreateNode(param);
                           $$ -> name = $2;
                           $$ -> operator = tempOperator;
                           }
            ;

compStmt    : MYBEGIN localDecl stmtList MYEND {$$ = ASTCreateNode(compStmt);
                                                $$ -> s1 = $2;
                                                $$ -> s2 = $3;
                                                
                                               }
            ;

localDecl   : /*empty */ {$$ = NULL;}
            | varDecl localDecl { $$ = $1;
                                  $1 -> next = $2;
                                }
            ;

stmtList    : /* empty */ {$$ = NULL;}
            | stmt stmtList { $$ = $1;
                              $1 -> next = $2;
                            }
            ;

stmt        : exprStmt {$$ = $1;}
            | compStmt {$$ = $1;}
            | selcStmt {$$ = $1;}
            | iterStmt {$$ = $1;}
            | assignStmt {$$ = $1;}
            | returnStmt {$$ = $1;}
            | readStmt {$$ = $1;}
            | writeStmt {$$ = $1;}
            ;

exprStmt    : expression ';' {$$ = $1;}
            | ';' {$$ = ASTCreateNode(expression);}
            ;

selcStmt    : IF expression THEN stmt {$$ = ASTCreateNode(selcStmt);
                                       $$ -> s1 = ASTCreateNode(ifStmt);
                                       $$ -> s1 -> s1 = $2;
                                       $$ -> s1 -> s2 = $4;
                                      }
            | IF expression THEN stmt ELSE stmt { $$ = ASTCreateNode(selcStmt);
            printf("selcStmt create\n");
                                                  $$ -> s1 = ASTCreateNode(ifStmt);
                                                  $$ -> s1 -> s1 = $2;
                                                  $$ -> s1 -> s2 = ASTCreateNode(ifElse);
                                                  $$ -> s1 -> s2 -> s1 = $4;
                                                  $$ -> s1 -> s2 -> s2 = $6;
                                                }
            ;

iterStmt    : WHILE expression DO stmt {$$ = ASTCreateNode(iterStmt);
                                        $$ -> s1 = $2;
                                        $$ -> s2 = $4;
                                       }
            ;

returnStmt  : RETURN ';' {$$ = ASTCreateNode(returnStmt);}
            | RETURN expression ';' {$$ = ASTCreateNode(returnStmt);
                                     $$ ->s1 = $2;
                                    }
            ;

readStmt    : READ variable ';' {$$ = ASTCreateNode(readStmt);
                                 $$ -> s1 = $2;
                                }
            ;

writeStmt   : WRITE expression ';' {$$ = ASTCreateNode(writeStmt);
                                    $$ -> s1 = $2;
                                   }
            ;

assignStmt  : variable '=' simExpr ';' { $$ = ASTCreateNode(assignStmt);
                                         $$ -> s1 = $1;
                                         $$ -> s2 = $3;   
                                       }
            ;

expression  : simExpr {$$ = $1;}
            ;

variable    : ID '[' expression ']' { $$ = ASTCreateNode(variable);
                                      $$ -> name = $1;
                                      $$ -> s1 = $3;
                
                                    }
            | ID { $$ = ASTCreateNode(variable);
                   $$ -> name = $1;
                 }
            ;

simExpr     : addExpr {$$ = $1;}
            | addExpr relop addExpr { $$ = ASTCreateNode(expression);
                                      $$->s1 = $1;
                                      $$->s2 = $3;
                                      $$->operator = tempOperator;
                                    }
            ;

relop       : LE  {tempOperator = LESSTHANEQ;}
            | '<' {tempOperator = LESSTHAN;}
            | '>' {tempOperator = GREATERTHAN;}
            | GE  {tempOperator = GREATERTHANEQ;}
            | EQ  {tempOperator = EQUALTO;}
            | NE  {tempOperator = NOTEQUAL;}
            ;

addExpr     : term {$$ = $1;}
            | addExpr addop term { $$ = ASTCreateNode(expression);
                                   $$->s1 = $1;
                                   $$->s2 = $3;
                                   $$->operator = tempOperator;
                                 }
            ;

addop       : '+' {tempOperator = PLUS;}
            | '-' {tempOperator = MINUS;}
            ;

term        : factor {$$ = $1;}
            | term multop factor { $$ = ASTCreateNode(expression);
                                   $$->s1 = $1;
                                   $$->s2 = $3;
                                   $$->operator = tempOperator;
                                 }
            ;

multop      : '*' {tempOperator = TIMES;}
            | '/' {tempOperator = DIVIDE;}
            | AND {tempOperator = MYAND;}
            | OR  {tempOperator = MYOR;}
            ;

factor      : '(' expression ')' {$$ = $2;}
            | NUM { $$ = ASTCreateNode(NUMBER);
                    $$->value = $1;
                  }
            | variable {$$ = $1;}
            | call {$$ = $1;}
            | TRUE { $$ = ASTCreateNode(NUMBER);
                     $$->value = 1;
                   } 
            | FALSE { $$ = ASTCreateNode(NUMBER);
                      $$->value = 0;
                    }
            | NOT factor { $$ = ASTCreateNode(expression);
                           $$->operator = MYNOT;
                           $$->s1=$2;
                         }
            ;

call        : ID '(' args ')' {$$ = ASTCreateNode(call);
                               $$ -> name = $1;
                               $$ -> s1 = $3;
                              }
            ;

args        : argList {$$ = $1;}
            | /* EMPTY */ {$$ = NULL;}
            ;

argList     : expression {$$ = $1;}
            | expression ','  argList {$1 -> next = $3;}
            ;



%%	/* end of rules, start of program */

int main()
{ yyparse();
  ASTprint(0, program);
}
