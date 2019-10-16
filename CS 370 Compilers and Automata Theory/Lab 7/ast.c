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
    p->symbol = NULL;
    return(p);
}

// A funtion used to add tabbing to the output of the program
void PT(int howmany)
{
	// Loop till i == howmany adding tabs when needed.
	 for (int i = 0; i <= howmany; i++) {
         printf("  ");
     } // end for
} // end PT



/*  Print out the abstract syntax tree */
void ASTprint(int level,ASTnode *p)
{
   int i;
   // If p is NULL just return without printing. If P is not NULL print as needed.
   if (p == NULL ) return;
   else
     { 
       PT(level); /*indent */
	   
	   // A switch statment looking at the types of nodes passed to the ASTprint funtion.
       switch (p->type) {
        case varDecl :  printf("Variable ");
					// Check the operator and print either int, boolean or void
                     if (p->operator == INTTYPE) {
                       printf("INT ");
                     } else if (p->operator == BOOLTYPE) {
                         printf("BOOLEAN ");
                     } else {
                         printf("VOID ");
                     } // end if else
                     
					// Print the name of the node
                     printf("%s",p->name);
                     
					// Check the value if the value is greater than 0 print the value.
                     if (p->value > 0)
                        printf("[%d]",p->value);
                     printf("\n");
                     
					 // Recursively print s1
                     ASTprint(level,p->s1);
                     
                     break;
        case funDecl :  
					// Check the operator and print either int, boolean or void
                     if (p->operator == INTTYPE)
                       printf("INT ");
                     if (p->operator == VOIDTYPE)
                       printf("VOID ");
                     if (p->operator == BOOLTYPE)
                       printf("BOOLEAN ");
				   
				   // Print the name of the funcation
                     printf("FUNCTION %s \n",p->name);
                     // print out the parameter list using recursion to print s1
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
                       } // end if else
						   
                     printf("\n");
                     ASTprint(level+2, p->s2); // print out the block
                     break;
        case param :  printf("PARAMETER ");
		
					  // Check the operator and print either int, boolean or void
                      if (p->operator == INTTYPE)
                         printf (" INT ");
                      if (p->operator == VOIDTYPE)
                         printf (" VOID ");
                      if (p->operator == BOOLTYPE)
                         printf (" BOOLEAN ");
					 
					 // Print the name of the parameter
                      printf (" %s",p->name);
					  
					  // If the value of the node is -1 print []
                      if (p->value == -1 ) 
                         printf("[]");
                      printf("\n");                  
                     break;
    
       case expression :  printf("EXPR ");
					// Switch statment used to print the correct symbol in the node.
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
                       } // end switch
                     printf("\n");
					 
					 // Recursively print s1
                     ASTprint(level+1, p->s1);
					 
			 // Recursively print s2 if the operator is not MYNOT
		     if (p->operator != MYNOT) {
                         ASTprint(level+1, p->s2);
             }
                     break;
        case compStmt :  printf("BLOCK STATEMENT  \n",p->name);
					// Recursively print s1 and s2
                     ASTprint(level+1, p->s1);
                     ASTprint(level+1, p->s2);
                     break;
        case iterStmt :  printf("WHILE STATEMENT \n");
					// Recursively print s1 and s2
                     ASTprint(level+1, p->s1);
                     ASTprint(level+2, p->s2);
                     break; 
        case NUMBER :  
					// Check the value of the node if is is equal to 1 that print true or is the value is 0 print false. 
					// If it is not any of these values just print the value in the node.
					   if(p->value == 1) {
                            printf("TRUE value\n");
                       } else if(p->value == 0) {
                            printf("FALSE value\n"); 
                       } else {
                           printf("NUMBER with value %d\n",p->value);
                       } // end if else
						   
					   // Recursively print s1
                       ASTprint(level+1, p->s1);
                       break;
        case variable : printf("IDENTIFIER %s\n",p->name);
						// Recursively print s1
                        ASTprint(level+1, p->s1);
                        break;                    
        case writeStmt :  printf("WRITE STATEMENT\n");
					// Recursively print s1
                     ASTprint(level+1, p->s1);
                     break;
        case readStmt :  printf("READ STATEMENT\n");
					// Recursively print s1
                     ASTprint(level+1, p->s1);
                     break;
        case assignStmt :  printf("Assignment STATEMENT\n");
					// Recursively print s1 and s2
                     ASTprint(level+1, p->s1);
                     ASTprint(level+1, p->s2);
                     break;
        case selcStmt :  printf("Selc STATEMENT\n");
					// Recursively print s1 and s2
                     ASTprint(level+1, p->s1);
                     ASTprint(level+1, p->s2);
                     break;
        case returnStmt :  printf("RETURN STATEMENT\n");
					// Recursively print s1
                     ASTprint(level+1, p->s1);
                     break;
        case ifStmt : printf("IF STATEMENT\n");
					// Recursively print s1 and s2
                     ASTprint(level+1, p->s1);
                     ASTprint(level+1, p->s2);
                     break;
        case ifElse : printf("IF ELSE STATEMENT\n");
					// Recursively print s1 and s2
                     ASTprint(level+1, p->s1);
                     ASTprint(level+1, p->s2);
                     break;
        case call : printf("CAll STATEMENT %s\n",p->name);
					// Recursively print s1
                    ASTprint(level+1, p->s1);
                    break;
        default: printf("unknown type in ASTprint\n");


       } // end switch
	   // Print the next pointer of the node
       ASTprint(level, p->next); 
	   
     } // end if else

} // end ASTprint



/* dummy main program so I can compile for syntax error independently   
main()
{
}
/* */
