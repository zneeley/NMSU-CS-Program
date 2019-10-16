%{

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



%}
/*  defines the start symbol, what values come back from LEX and how the operators are associated  */

%start program

%union {
    int value;
    char * string;
    struct ASTnodetype *ASTnode;
    enum OPERATORS tempOperator;
    enum SYSTYPE isType;

}

%token <value> NUM
%token <string> ID INT VOID WHILE DO IF THEN ELSE READ WRITE FOR RETURN LE GE EQ NE LT GT 
%token AND OR NOT 
%token MYBEGIN MYEND OF BOOLEAN TRUE FALSE 
%type <ASTnode> varDecl declList varList decl funDecl param params paramList compStmt localDecl program variable stmt stmtList readStmt expression simExpr term addExpr  
%type <ASTnode> factor call writeStmt args argList exprStmt ';' assignStmt returnStmt iterStmt selcStmt
%type <tempOperator> relop multop addop
%type <isType> typeSpec
%left '+' '-' '/' '*' '%'

%%	/* end specs, begin rules */

program     : declList {$$ = $1; /* Pass the generated tree to program */} 
            ;

declList    : decl {$$ = $1; /* Pass the generated tree to declList */} 
            | decl declList { $$ = $1;  /* Pass the generated tree to declList */
                              $1->next=$2; /* Connect next of decl to declList */
                            }
            ;

decl        : varDecl {$$ = $1; /* Pass the generated tree to decl */} 
            | funDecl {$$ = $1; /* Pass the generated tree to decl */} 
            ;

varDecl     : typeSpec varList ';' {$$ = $2; /* Pass the generated tree to varDecl */
                                    ASTnode *p;
                                    p=$$;
                                    while (p != NULL) {
                                        p->isType = $1;
                                        p-> symbol -> Type = $1;
                                        p = p -> s1;
                                        }
                                    }
            ;

varList     : ID { struct SymbTab *p; 
                    // Check to see if the var is already in the table if so error, or add the information to the tree.
                    if (Search($1, level, 0) != NULL) {
                    yyerror($1);
                    yyerror("Error: Variable is already defined.");
                    exit(1);
                    }else {
                        $$ = ASTCreateNode(varDecl);
                        $$ -> name = $1;
                        $$ -> symbol = Insert($1, 0, 0, level, 1, offset, 0);
                        offset++;
                   }
                   /* Create a node with the type of varDecl, setting it's name to ID and the operator in ID */
                 }
            | ID '[' NUM ']' { struct SymbTab *p; 
                                // Check to see if the var is already in the table if so error, or add the information to the tree.
                                if (Search($1, level, 0) != NULL) {
                                yyerror($1);
                                yyerror("Error: Variable[] is already defined.");
                                exit(1);
                                } else {
                                    $$ = ASTCreateNode(varDecl);
                                    $$ -> name = $1;
                                    $$ -> value = $3;
                                    $$ -> symbol = Insert($1, 0, 2, level, $3, offset, 0);
                                    offset +=$3;
                                    }
                              }
                              
            | ID ',' varList { struct SymbTab *p; 
                                // Check to see if the var is already in the table if so error, or add the information to the tree.
                                if (Search($1, level, 0) != NULL) {
                                yyerror($1);
                                yyerror("Error: Variable is already defined.");
                                exit(1);
                                } else {
                                    $$ = ASTCreateNode(varDecl);
                                    $$ -> name = $1;
                                    $$ -> s1 = $3;
                                    $$ -> symbol = Insert($1, 0, 0, level, 1, offset, 0);
                                    offset++;
                                    }
							   /* Create a node with the type of varDecl, setting it's name to ID, the operator in ID and setting s1 in varDecl to varList*/
                             }
            | ID '[' NUM ']' ',' varList { struct SymbTab *p; 
                                            // Check to see if the var is already in the table if so error, or add the information to the tree.
                                            if (Search($1, level, 0) != NULL) {
                                            yyerror($1);
                                            yyerror("Error: Variable [] is already defined.");
                                            exit(1);
                                           } else {
                                           $$ = ASTCreateNode(varDecl);
                                           $$ -> name = $1;
                                           $$ -> value = $3;
                                           $$ -> s1 = $6;
                                           $$ -> symbol = Insert($1, 0, 2, level, $3, offset, 0);
                                           offset += $3;
                                           }
										   /* Create a node with the type of varDecl, setting it's name to ID, the operator in ID, the value of NUM and setting s1 in varDecl to varList*/
                                         }
            ;

typeSpec    : INT {$$ = INTTYPE;}
            | VOID {$$ = VOIDTYPE;}
            | BOOLEAN {$$ = BOOLTYPE;}
            ;

funDecl     : typeSpec ID { struct SymbTab *p; Display();
                                                    // Search the table to see if the function is in the table, if the function is new insert the table.
                                                    if (Search($2, level, 0) != NULL) {
                                                        yyerror($2);
                                                        yyerror("Error: Function has already been defined");
                                                        exit(1);
                                                    } else {
                                                    Insert($2,$1, 1, level, 0, 0, 0);
                                                    // Set the offset into temp to story the value and make the maxOffset to 0
                                                    Tempoffset = offset;
                                                    offset = 0;
                                                    maxOffset = offset;
                                                    }
													/* Create a node with the type of funDecl, setting its name to ID, the operator in ID,setting the s1 pointer of funDecl to params and s2 to compStmt */
                                                    }
                                    '(' params ')' { (Search($2, 0, 0)) -> fparms = $5; // find the function linking fparms to the table entry
                                    }
                                    
                                    compStmt { $$ = ASTCreateNode(funDecl);
                                                    $$ -> name = $2;
                                                    $$ -> isType = $1;
                                                    $$ -> s1 = $5;
                                                    $$ -> s2 = $8;
                                                    // Set the size of the function to maxOffset and set the symbol size to maxOffset
                                                    $$ -> size = maxOffset;
                                                    $$ -> symbol = Search($2, level,0);
                                                    $$ ->symbol-> mysize = maxOffset;
                                                    
                                                    // Restore offset
                                                    offset= Tempoffset;
                                    }
            ;

params      : VOID {$$ = NULL; /*If params is void set it to NULL*/}
            | paramList {$$ = $1; /* Pass the generated tree to params */}
            ;

paramList   : param {$$ = $1; /* Pass the generated tree to paramList */}
            | param ',' paramList {$1 -> next = $3; /*Connect the next pointer or param to paramList*/}
            ;

param       : typeSpec ID '['']' {// Check to see if param is in the table if so error or just insert the param into the table
                                    if (Search($2,level + 1,0) != NULL) {
                                    yyerror($2);
                                    yyerror("Error: Parameter[] has already been defined.");
                                    exit(1);
                                 }else {
                                  $$ = ASTCreateNode(param);
                                  $$ -> name = $2;
                                  $$ -> value = -1;
                                  $$ -> isType = $1;
                                  $$ -> symbol = Insert($2, $1, 2, level + 1, 1, offset, 0);
                                  offset++;
                                 }
								  /* Create a node with the type of param, setting its name to ID, the operator to ID and set the value to -1 to get the [] when needed */
                                 }
                                 
            | typeSpec ID {// Check to see if param is in the table if so error or just insert the param into the table
                                if (Search($2,level + 1,0) != NULL) {
                                    yyerror($2);
                                    yyerror("Error: Parameter has already been defined.");
                                    exit(1);
                                 }else {
                                    $$ = ASTCreateNode(param);
                                    $$ -> name = $2;
                                    $$ -> isType = $1;
                                    $$ -> symbol = Insert($2, $1, 0, level + 1, 1, offset, 0);
                                    offset++;

                                    
                                    }
						   /* Create a node with the type of param, setting its name to ID, and the operator to ID */
                           }
            ;

compStmt    : MYBEGIN {level++;}
                localDecl stmtList MYEND {$$ = ASTCreateNode(compStmt);
                                                $$ -> s1 = $3;
                                                $$ -> s2 = $4;
                                                Display();
                                                
                                                // See if maxOffset is less than offset if so set maxOffset to offset
                                                if (maxOffset < offset) maxOffset = offset;
                                                
                                                // Delete and remove it from offset then subtract 1 from level
                                                offset-=Delete(level);
                                                level--;
												/*Create a node with the type of compStmt setting s1 to localDecl and s2 to stmtList */
                                               }
            ;

localDecl   : /*empty */ {$$ = NULL;}
            | varDecl localDecl { $$ = $1; /* Pass the generated tree to localDecl */
                                  $1 -> next = $2; /* Point the pointer next to localDecl */
                                }
            ;

stmtList    : /* empty */ {$$ = NULL;}
            | stmt stmtList { $$ = $1; /* Pass the generated tree to stmtList */
                              $1 -> next = $2; /* Point the pointer next to stmtList*/
                            }
            ;

stmt        : exprStmt {$$ = $1; /* Pass the generated tree to stmt */}
            | compStmt {$$ = $1; /* Pass the generated tree to stmt */}
            | selcStmt {$$ = $1; /* Pass the generated tree to stmt */}
            | iterStmt {$$ = $1; /* Pass the generated tree to stmt */}
            | assignStmt {$$ = $1; /* Pass the generated tree to stmt */}
            | returnStmt {$$ = $1; /* Pass the generated tree to stmt */}
            | readStmt {$$ = $1; /* Pass the generated tree to stmt */}
            | writeStmt {$$ = $1; /* Pass the generated tree to stmt */}
            ;

exprStmt    : expression ';' {$$ = ASTCreateNode(expression); 
                              $$ -> s1 = $1; /* Pass the generated tree to exprStmt */}
            | ';' {$$ = ASTCreateNode(expression); /* Create a node with the type of expression */}
            ;

selcStmt    : IF expression THEN stmt {$$ = ASTCreateNode(ifStmt);
                                       $$ -> s1 = $2;
                                       $$ -> s2 = $4;
									   /* Create a node with the type of selcStmt, setting value of s1 as a new node with the type of ifStmt, setting the new nodes s1 to expression and setting s2 to stmt */
                                      }
            | IF expression THEN stmt ELSE stmt { $$ = ASTCreateNode(ifStmt);
                                                  $$ -> s1 = $2;
                                                  $$ -> s2 = ASTCreateNode(ifElse);
                                                  $$ -> s2 -> s1 = $4;
                                                  $$ -> s2 -> s2 = $6;
												  /* Create a node with the type of selcStmt, setting value of s1 as a new node with the type of ifStmt, setting the new nodes s1 to expression */
												  /* Create another new node with a type of ifElse setting the value of s1 to stmt and s2 to another stmt */
                                                }
            ;

iterStmt    : WHILE expression DO stmt {$$ = ASTCreateNode(iterStmt);
                                        $$ -> s1 = $2;
                                        $$ -> s2 = $4;
										/* Create a with the type of iterStmt using the pointer s1 to expression and s2 to stmt */
                                       }
            ;

returnStmt  : RETURN ';' {$$ = ASTCreateNode(returnStmt); /* Create a returnStmt node */}
            | RETURN expression ';' {$$ = ASTCreateNode(returnStmt);
                                     $$ ->s1 = $2;
									 /* Create a returnStmt node with s1 pointing to expression*/
                                    }
            ;

readStmt    : READ variable ';' {$$ = ASTCreateNode(readStmt);
                                 $$ -> s1 = $2;
								 /* Create a readStmt node using the s1 pointer set to variable */
                                }
            ;

writeStmt   : WRITE expression ';' {$$ = ASTCreateNode(writeStmt);
                                    $$ -> s1 = $2;
									/* Create a writeStmt node using the s1 pointer set to expression */
                                   }
            ;

assignStmt  : variable '=' simExpr ';' { $$ = ASTCreateNode(assignStmt);
                                         $$ -> s1 = $1;
                                         $$ -> s2 = $3;  
										 /* Create a assignStmt node using the s1 pointer set to variable and s2 to simExpr */
                                       }
            ;

expression  : simExpr {$$ = $1; /* Pass the generated tree to expression */}
            ;

variable    : ID '[' expression ']' { struct SymbTab *p; 
                                    // Search the table for the variable if found error, if not found add into the table 
                                        if ((p=Search($1,level,1)) == NULL) {
                                        yyerror($1);
                                        yyerror("Error:  Variable [] has already been defined.");
                                        exit(1);
                                    }else {
                                      $$ = ASTCreateNode(variable);
                                      $$ -> name = $1;
                                      $$ -> s1 = $3;
                                      // Set the type
                                      $$ -> isType = p->Type;
                                      // Check to see if this is a function if so error
                                      if (p->IsAFunc == 2){
                                        $$ -> symbol = p;
                                        } else {
                                            yyerror($1);
                                            yyerror("Error: Variable[] is not a function.");
                                            exit(1);
                                        }
                                      }
									  /* Create a variable node with the name in ID and s1 pointing to expression */
                                    }
            | ID { struct SymbTab *p; 
                    // Search the table for the variable if found error, if not found add into the table 
                     if ((p=Search($1,level,1)) == NULL) {
                           yyerror($1);
                           yyerror("Error:  Variable has already been defined.");
                          exit(1);
                     }else {
                     $$ = ASTCreateNode(variable);
                     $$ -> name = $1;
                     $$ -> symbol = p;
                     // set the type 
                     $$ -> isType =  p-> Type;
                     
                        // Check to see if this is a function if so error
                        if (p -> IsAFunc == 2) {
                            yyerror($1);
                           yyerror("Error: Variable is not a function.");
                          exit(1);
                        }
                        }
				   /* Create a variable node with the name in ID */
                 }
            ;

simExpr     : addExpr {$$ = $1; /* Pass the generated tree to simExpr */}
            | addExpr relop addExpr {
                                    // Check the table to see if the simExpr is in the table is so error, or add this into the table 
                                     if ( $1-> isType != $3-> isType) {
                                     yyerror("Error: Additiave type mismatch with: >, <, >=, <=, ==, !=");
                                     exit(1);
                                     }
                                      $$ = ASTCreateNode(expression);
                                      $$->s1 = $1;
                                      $$->s2 = $3;
                                      $$-> isType = $3->isType;
                                      $$->operator=$2;
                                      $$->name=CreateTemp();
                                      $$->symbol=Insert($$->name, INTTYPE, 0, level, 1, offset, 0);
                                      offset++;//Insert(char *name, enum OPERATORS Type, int isafunc, int  level, int mysize, int offset , ASTnode * fparms)
									  /* Create a expression node with the name in ID and s1 pointing to addExpr and s2 to addExpr and setting the operator of relop */
                                    }
            ;

relop       : LE  {$$= LESSTHANEQ;}
            | '<' {$$= LESSTHAN;}
            | '>' {$$= GREATERTHAN;}
            | GE  {$$= GREATERTHANEQ;}
            | EQ  {$$= EQUALTO;}
            | NE  {$$= NOTEQUAL;}
            ;

addExpr     : term {$$ = $1; /* Pass the generated tree to addExpr */}
            | addExpr addop term {
                                     if ( $1-> isType != $3-> isType) {
                                     // Check the table to see if the addExpr is in the table is so error, or add this into the table 
                                     yyerror("Error: Additiave type mismatch with: +, -");
                                     exit(1);
                                     }
                                      $$ = ASTCreateNode(expression);
                                      $$->s1 = $1;
                                      $$->s2 = $3;
                                      $$-> isType = $3->isType;
                                      $$->operator=$2;
                                      $$->name=CreateTemp();
                                      $$->symbol=Insert($$->name, INTTYPE, 0, level, 1, offset, 0);
                                      offset++;//Insert(char *name, enum OPERATORS Type, int isafunc, int  level, int mysize, int offset , ASTnode * fparms)
									  /* Create a expression node with the name in ID and s1 pointing to addExpr and s2 to addExpr and setting the operator of relop */
                                    }
            ;

addop       : '+' {$$ = PLUS;}
            | '-' {$$ = MINUS;}
            ;
            
term        : factor {$$ = $1; /* Pass the generated tree to term */}
            | term multop factor {
                                     if ( $1-> isType != $3-> isType) {
                                     // Check the table to see if the term is in the table is so error, or add this into the table 
                                     yyerror("Error: Additiave type mismatch with: *, /, &&, ||");
                                     exit(1);
                                     }
                                      $$ = ASTCreateNode(expression);
                                      $$->s1 = $1;
                                      $$->s2 = $3;
                                      $$-> isType = $3->isType;
                                      $$->operator=$2;
                                      $$->name=CreateTemp();
                                      $$->symbol=Insert($$->name, INTTYPE, 0, level, 1, offset, 0);
                                      offset++;//Insert(char *name, enum OPERATORS Type, int isafunc, int  level, int mysize, int offset , ASTnode * fparms)
									  /* Create a expression node with the name in ID and s1 pointing to addExpr and s2 to addExpr and setting the operator of relop */
                                    }
            ;

multop      : '*' {$$= TIMES;}
            | '/' {$$= DIVIDE;}
            | AND {$$= MYAND;}
            | OR  {$$= MYOR;}
            ;
            
factor      : '(' expression ')' {$$ = $2; /* Pass the generated tree to factor */}
            | NUM { $$ = ASTCreateNode(NUMBER);
                    $$->value = $1;
                    // Set the type
                    $$->isType = INTTYPE;
					/* Create a node of NUMBER setting its value to NUM */
                  }
            | variable {$$ = $1; /* Pass the generated tree to factor */}
            | call {$$ = $1; /* Pass the generated tree to factor */}
            | TRUE { $$ = ASTCreateNode(NUMBER);
                     $$->value = 1;
                     $$->isType = BOOLTYPE;
					 /* Create a node of NUMBER setting its value to 1 */
                   } 
            | FALSE { $$ = ASTCreateNode(NUMBER);
                      $$->value = 0;
                      // Set the type
                      $$->isType = BOOLTYPE;
					  /* Create a node of NUMBER setting its value to 0 */
                    }
            | NOT factor { $$ = ASTCreateNode(expression);
                           $$->operator = MYNOT;
                           $$->s1=$2;
                           // Set the type
                           $$->isType = $2 ->isType;
						   /* Create a node of expression setting its operator to MYNOT and set s1 to factor */
                         }
            ;

call        : ID '(' args ')' {struct SymbTab *p;
                                // Search the table to see if the call is in the table if so error
                               if ((p=Search($1,0,0)) != NULL) {
                                    if (p-> IsAFunc != 1) {
                                        yyerror($1);
                                        yyerror("Error: Call is not a function.");
                                        exit(1);
                                    }
                                    // Check to see if the params are the same as args if not error.
                                    if ( compareFormula(p-> fparms, $3) != 1) {
                                        yyerror($1);
                                        yyerror("Error: Parameter type or length mismatch between formals and actuals. ");
                                        exit(1);
                                    }
                                    // Create the node
                                    $$ = ASTCreateNode(call);
                                    $$ -> name = $1;
                                    $$ -> s1 = $3;
                                    // Set the symbol to p
                                    $$ -> symbol = p;
                                    // Set the type
                                    $$ -> isType = p -> Type; 
                                } else {
                                    yyerror($1);
                                    yyerror("Error: Undefined reference.");
                                    exit(1);
                                }

							   /* Create a node of call setting its name to ID and using the pointer of s1 to args */
                              }
            ;

args        : argList {$$ = $1; /* Pass the generated tree to args */}
            | /* EMPTY */ {$$ = NULL;}
            ;

argList     : expression {$$ = ASTCreateNode(expression);
                          $$ = $1; /* Pass the generated tree to argList */
                          $$-> isType = $1 -> isType; // Set the type
                          }
            | expression ','  argList {$$ = ASTCreateNode(expression);  /* Set s1 next to argList */
                                       $$ -> s1 = $1;
                                       $$ -> next = $3;
                                       $$-> isType = $1 -> isType; // set the type
                                       }
            ;



%%	/* end of rules, start of program */

int main()
{ yyparse();
    Display();
  //ASTprint(0, program);
}
