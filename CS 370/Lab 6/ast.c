/*   Abstract syntax tree code

     This code is used to define an AST node, 
    routine for printing out the AST
    defining an enumerated type so we can figure out what we need to
    do with this.  The ENUM is basically going to be every non-terminal
    and terminal in our language.

    Shaun Cooper February 2015

*/

#include<stdio.h>
#include<malloc.h>
#include "ast.h" 

/* uses malloc to create an ASTnode and passes back the heap address of the newley created node */
ASTnode *ASTCreateNode(enum ASTtype mytype)
{
    ASTnode *p;
    p=(ASTnode *)malloc(sizeof(ASTnode));
    p->type=mytype;
    p->s1=NULL;
    p->s2=NULL;
    p->name=NULL;
    p->operator=VOIDTYPE;
    p->value=0;
    p->next = NULL;
    return(p);
}

/*  Helper function to print tabbing */

void PT(int howmany)
{
	 for (int i = 0; i <= howmany; i++) {
         printf("  ");
     }
}



/*  Print out the abstract syntax tree */
void ASTprint(int level,ASTnode *p)
{
   int i;
   if (p == NULL ) return;
   else
     { 
       PT(level); /*indent */
       switch (p->type) {
        case varDecl :  printf("Variable ");
                     if (p->operator == INTTYPE) {
                       printf("INT ");
                     } else if (p->operator == BOOLTYPE) {
                         printf("BOOLEAN ");
                     } else {
                         printf("VOID ");
                     }
                     
                     printf("%s",p->name);
                     
                     if (p->value > 0)
                        printf("[%d]",p->value);
                     printf("\n");
                     
                     ASTprint(level,p->s1);
                     
                     break;
        case funDecl :  
                     if (p->operator == INTTYPE)
                       printf("INT ");
                     if (p->operator == VOIDTYPE)
                       printf("VOID ");
                     if (p->operator == BOOLTYPE)
                       printf("BOOLEAN ");
                     printf("FUNCTION %s \n",p->name);
                     /* print out the parameter list */
                     if (p->s1 == NULL ) { 
                        PT(level+2); 
                        printf (" (VOID) "); }
                     else
                       { 
                         PT(level+2);
                         printf( "( \n");
                          ASTprint(level+2, p->s1);
                         PT(level+2);
                         printf( ") ");
                       }
                     printf("\n");
                     ASTprint(level+2, p->s2); // print out the block
                     break;
        case param :  printf("PARAMETER ");
                      if (p->operator == INTTYPE)
                         printf (" INT ");
                      if (p->operator == VOIDTYPE)
                         printf (" VOID ");
                      if (p->operator == BOOLTYPE)
                         printf (" BOOLEAN ");
                      printf (" %s",p->name);
                      if (p->value == -1 ) 
                         printf("[]");
                      printf("\n");                  
                     break;
    
       case expression :  printf("EXPR ");
                     switch(p->operator) {
                        case PLUS : printf(" + ");
                           break;
                        case MINUS : printf(" - ");
                           break;
                        case GREATERTHAN: printf(" > ");
                           break;
                        case LESSTHAN: printf(" < ");
                           break;
                        case DIVIDE: printf(" / ");
                           break;
                        case TIMES: printf(" * ");
                           break;
                        case GREATERTHANEQ: printf(" >= ");
                           break; 
                        case LESSTHANEQ: printf(" >= ");
                           break; 
                        case EQUALTO: printf(" == ");
                           break; 
                        case NOTEQUAL: printf(" != ");
                           break; 
                        case MYOR: printf(" OR ");
                           break;
                        case MYAND: printf(" AND ");
                           break;
                       }
                     printf("\n");
                     ASTprint(level+1, p->s1);
		     if (p->operator != MYNOT) {
                         ASTprint(level+1, p->s2);
             }
                     break;
        case compStmt :  printf("BLOCK STATEMENT  \n",p->name);
            
                     ASTprint(level+1, p->s1);
                     ASTprint(level+1, p->s2);
                     break;
        case iterStmt :  printf("WHILE STATEMENT \n");
                     ASTprint(level+1, p->s1);
                     ASTprint(level+2, p->s2);
                     break; 
        case NUMBER :  if(p->value == 1) {
                            printf("TRUE value\n");
                       } else if(p->value == 0) {
                            printf("FALSE value\n"); 
                       } else {
                           printf("NUMBER with value %d\n",p->value);
                       }
                       ASTprint(level+1, p->s1);
                       break;
        case variable : printf("IDENTIFIER %s\n",p->name);
                        ASTprint(level+1, p->s1);
                        break;                    
        case writeStmt :  printf("WRITE STATEMENT\n");
                     ASTprint(level+1, p->s1);
                     break;
        case readStmt :  printf("READ STATEMENT\n");
                     ASTprint(level+1, p->s1);
                     break;
        case assignStmt :  printf("Assignment STATEMENT\n");
                     ASTprint(level+1, p->s1);
                     ASTprint(level+1, p->s2);
                     break;
        case selcStmt :  printf("Selc STATEMENT\n");
                     ASTprint(level+1, p->s1);
                     ASTprint(level+1, p->s2);
                     break;
        case returnStmt :  printf("RETURN STATEMENT\n");
                     ASTprint(level+1, p->s1);
                     break;
        case ifStmt : printf("IF STATEMENT\n");
                     ASTprint(level+1, p->s1);
                     ASTprint(level+1, p->s2);
                     break;
        case ifElse : printf("IF ELSE STATEMENT\n");
                     ASTprint(level+1, p->s1);
                     ASTprint(level+1, p->s2);
                     break;
        case call : printf("CAll STATEMENT %s\n",p->name);
                    ASTprint(level+1, p->s1);
                    break;
        default: printf("unknown type in ASTprint\n");


       }
       ASTprint(level, p->next);
     }

}



/* dummy main program so I can compile for syntax error independently   
main()
{
}
/* */
