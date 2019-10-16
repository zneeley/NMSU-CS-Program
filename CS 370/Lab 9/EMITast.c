/*
 * Name: Zachary Neeley
 * Date: 5/3/19
 * Purpose: The purpose of this program is to create a code interperator using LEX and YACC
 *          to generate a abstract syntax tree.
 *     
 *      Input: Any valid line of a algol C language. Ex int x[100], y;
 *      Output: A generated abstract syntax tree of the given input and a symbol table from the tree with a NASM generated files.
 * 
 */

#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include "ast.h"
#include "EMITast.h"

#define WSIZE 8
int LTEMP = 0;
extern int mydebug;

// Postcondition: A generate label following _L(NUM) for any needed information.
char * CreateLabel() {
     // init
     char hold[100];
     char *s;
     
     // Create the needed label and return it back to the calling function. 
     sprintf(hold,"_L%d",LTEMP++);
     s=strdup(hold);
     return (s);

} // end CreateLabel

// Precondition: A ASTnode with a type of funDecl.
// Postcondition: Will print out the needed information to a file with the needed stack pointer and offset for the activation record.
void emitLabelStart(ASTnode *p){
    //Print the label name.
    fprintf(fp, "%s:\n", p->name);
    
    // Check to see if the label is main if so we need to set rbp and rsp to be equal
    if (strcmp(p->name, "main") == 0) {
        fprintf(fp,"\tmov rbp, rsp\t\t;SPECIAL RSP to RSB for MAIN only\n");
    }
    
    // Create the activation record needed for the function
    fprintf(fp,"\tmov r8, rsp\t\t;FUNC header RSP has to be at most RBP\n");
    fprintf(fp,"\tadd r8, -%d,\t\t;adjust Stack Pointer for Activation record\n", p->symbol->offset * WSIZE);
    fprintf(fp,"\tmov [r8], rbp\t\t;FUNC header store old BP\n");
    fprintf(fp,"\tmov [r8+8],rsp\t\t;FUNC header store old SP\n");
    fprintf(fp,"\tmov rsp, r8\t\t;FUNC header new SP\n\n");
    
} // end emitLabelStart

// Precondition: The funtion has been printed to the file.
// Postcondition: Finish the activation record adding a return when needed.
void emitLabelEnd(){
    fprintf(fp, "\tmov rbp, [rsp]\t\t;FUNC restore the offset\n");
    fprintf(fp, "\tmov rsp, [rsp+8]\t\t;FUNC restore the stack pointer\n");
    fprintf(fp, "\tmov rsp, rbp\t\t;Make stack pointer and offset equal\n");
    fprintf(fp, "\txor rax, rax\n");
    fprintf(fp, "\tret\n");
    
} // end emitLabelEnd

// Precondition: ASTnode of varDecl.
// Postcondition: The printed information for globals.
void emitGlobals(ASTnode *p){
    // To to see if null then just return.
    if(p == NULL) 
        return;
    
    // Check to see if the type is a varDecl and its at level 0 to make sure that it is a global
    if (p->type == varDecl && p->symbol->level == 0) {
        
        if(p->value != 0) {
        fprintf(fp,"common %s %d \t\t;Define a global variable\n", p->name, (p->value * WSIZE));
        } else {
            fprintf(fp,"common %s %d \t\t;Define a global variable\n", p->name, WSIZE);
        } // end if else
    } // end if
    
    // Recursively call to get any lists of varDecl
    emitGlobals(p->s1);
    emitGlobals(p->s2);
    emitGlobals(p->next);
    
} // end emitGlobals

// Precondition: ASTnode of writeStmt
// Postcondition: Added strings to the output file under the .data section
void emitStrings(ASTnode *p){
    // Check to see if its null if so than return.
    if(p == NULL) 
        return;
    
    // Check to see if the type is writeStmt 
    if (p->type == writeStmt) {
        // Check to see if the type is a string
        if (p->isType == STRINGTYPE)
            // Add the string to the .data section of the output file.
            fprintf(fp, "%s:\tdb %s, 0\t\t;Global string\n", p->label, p->name);
    } // end if
    
    // Recursively go through the strings
    emitStrings(p->s1);
    emitStrings(p->s2);
    emitStrings(p->next);
    
} // end emitStrings

// Precondition: ASTnode with a type of variable.
// Postcondition: RAX will contain the value of the identifier.
void emitIdent(ASTnode *p){
    // Array S1 will check to see if it is null if so than the incoming identifier is not a array.
    if (p->s1 != NULL) { 
        
        // If the incoming identifier is an array than check to see if a number, variable or a expression.
        switch (p->s1->type) {
        case NUMBER:
            fprintf(fp, "\tmov rcx, %d\t\t;Array number\n", p->s1->value);
            break;
                
        case variable:
            emitIdent(p->s1); 
            fprintf(fp, "\tmov rcx, [rax]\t\t;Array identifier\n");
            break;
                
        case expression: 
            emitExpr(p->s1);
            fprintf(fp, "\tmov rcx, [rsp + %d]\t\t;Array expr\n", p->s1->symbol->offset * WSIZE);
            break;
                
        case call:
            break;
                
        default:
            printf("Error with Array s1\n");
            exit(1);
        } // end switch
        
        // Create a int called logW which will allow me to shift rcx to any size word length. Ex 8 or 64. 
        int logW = (int) (log10(WSIZE)/log10(2));
        fprintf(fp, "\tshl rcx, %d\t\t;Shift internal offset by 3\n", logW); 
        
    } // end if 
  
    // Check to see if the identifier is a global if so we can use the name of the identifier
    if (p->type == variable && p->symbol->level == 0) {
        fprintf(fp,"\tmov rax, %s\t\t;Move the variable name to rax\n", p->name);
    } else {
        // If the identifier is not a global than move the offset * WSIZE into rax
        fprintf(fp,"\tmov rax, %d\t\t;Move the variable into rax\n", (p->symbol->offset * WSIZE));
        // Add the stack pointer
        fprintf(fp,"\tadd rax, rsp\t\t;Add rsp to rax\n");
        
    } // end if else
        
    // If the identifier is an array add the internal offset
    if (p->s1 != NULL) {
        fprintf(fp, "\tadd rax, rcx\t\t;Add array internal offset\n");
        
    } // end if
    
} // end emitIdent

// Precondition: ASTnode of expression
// Postcondition: RAX will contain the final of the expression
void emitExpr(ASTnode *p){
    // Return if p is NULL
    if (p == NULL) return;
    
    // LHS of the expression looking at the type to see if it is a number, variable, or expression.
    switch (p->s1->type) {
        case NUMBER:
            fprintf(fp, "\tmov rax, %d\t\t;Expression LHS number\n", p->s1->value);
            break;
            
        case variable:
            emitIdent(p->s1); 
            fprintf(fp, "\tmov rax, [rax]\t\t;Expression LHS identifier\n");
            break;
            
        case expression: 
            emitExpr(p->s1);
            fprintf(fp, "\tmov rax, [rsp + %d]\t\t;Expression LHS expression\n", p->s1->symbol->offset * WSIZE);
            break;
            
        case call:
            break;
            
        default:
            printf("Error with LHS\n");
            exit(1);
    } // end switch
    
    // Store the value in rax to stack pointer + offset
    fprintf(fp, "\tmov [rsp + %d], rax\t\t;Store rax for later use\n", p->symbol->offset * WSIZE);
    
    // Check to see if p->s2 is null to make sure when having the NOT operator that we do not go into p->s2.
    if (p->s2 != NULL) {
        // RHS of the expression looking at the type to see if it is a number, variable, or expression.
        switch (p->s2->type) {
            case NUMBER:
                fprintf(fp, "\tmov rbx, %d\t\t;Expression RHS number\n", p->s2->value);
                break;
                
            case variable:
                emitIdent(p->s2); 
                fprintf(fp, "\tmov rbx, [rax]\t\t;Expression RHS identifier\n");
                break;
                
            case expression: 
                emitExpr(p->s2);
                fprintf(fp, "\tmov rbx, [rsp + %d]\t\t;Expression RHS expr\n", p->s2->symbol->offset * WSIZE);
                break;
                
            case call:
                break;
                
            default:
                printf("Error with RHS\n");
                exit(1);
        }// end switch
    } // end if
    
    // Get the value from stack pointer + offset and store back into rax
    fprintf(fp, "\tmov rax, [rsp + %d]\t\t;Get the stored rax value\n", p->symbol->offset * WSIZE);

    // Check the operator of the expression which and add the needed lines to the output file
    switch (p->operator) {
        case PLUS:
            fprintf(fp, "\tadd rax, rbx\t\t;add the two values\n");
            break;
            
        case MINUS:
            fprintf(fp, "\tsub rax, rbx\t\t;sub the two values\n");
            break;
            
        case TIMES:
            fprintf(fp, "\timul rbx\t\t;multi the values\n");
            break;
            
        case DIVIDE:
            fprintf(fp, "\txor rdx, rdx\t\t;clear rdx\n");
            fprintf(fp, "\tidiv rbx\t\t;divide the values\n");
            break;
        case MYAND:
            //LHS
            fprintf(fp, "\tcmp rax, 0\t\t;LHS cmp to 0\n");
            fprintf(fp, "\tsetne al\t\t;Set al if not equal\n");
            fprintf(fp, "\tmov rdx ,1\t\t;Set rdx to 1\n");
            fprintf(fp, "\tand rax, rdx\t\t;And rax with rdx\n");
            
            //RHS
            fprintf(fp, "\tcmp rbx, 0\t\t;RHS cmp to 0\n");
            fprintf(fp, "\tsetne bl\t\t;Set al if not equal\n");
            fprintf(fp, "\tmov rdx ,1\t\t;Set rdx to 1\n");
            fprintf(fp, "\tand rbx, rdx\t\t;And rax with rdx\n");
            
            // and
            fprintf(fp, "\tand rax, rbx\t\t;And rax with rbx\n");
            
            break;
        case MYOR:
            fprintf(fp, "\tor rax, rdx\t\t;or the 2 values\n");
            fprintf(fp, "\tmov rbx, 1\t\t;set rbx to 1 to filter rax\n");
            fprintf(fp, "\tand rax, rbx\t\t;and rax with rbx to get the correct answer\n");
            break;
        case LESSTHANEQ:
            fprintf(fp, "\tcmp rax, rbx\t\t;expr LESSTHANEQ\n");
            fprintf(fp, "\tsetle al\t\t;set the last byte the rax in the register\n");
            fprintf(fp, "\tmov rbx ,1\t\t;set rbx to 1\n");
            fprintf(fp, "\tand rax, rbx\t\t;filter rax\n");
            break;
        case LESSTHAN:
            fprintf(fp, "\tcmp rax, rbx\t\t;expr LESSTHAN\n");
            fprintf(fp, "\tsetl al\t\t;set the last byte the rax in the register\n");
            fprintf(fp, "\tmov rbx ,1\t\t;set rbx to 1\n");
            fprintf(fp, "\tand rax, rbx\t\t;filter rax\n");
            break;
        case GREATERTHAN:
            fprintf(fp, "\tcmp rax, rbx\t\t;expr GREATERTHAN\n");
            fprintf(fp, "\tsetg al\t\t;set the last byte the rax in the register\n");
            fprintf(fp, "\tmov rbx ,1\t\t;set rbx to 1\n");
            fprintf(fp, "\tand rax, rbx\t\t;filter rax\n");
            break;
        case GREATERTHANEQ:
            fprintf(fp, "\tcmp rax, rbx\t\t;expr GREATERTHANEQ\n");
            fprintf(fp, "\tsetge al\t\t;set the last byte the rax in the register\n");
            fprintf(fp, "\tmov rbx ,1\t\t;set rbx to 1\n");
            fprintf(fp, "\tand rax, rbx\t\t;filter rax\n");
            break;
        case EQUALTO:
            fprintf(fp, "\tcmp rax, rbx\t\t;expr equal\n");
            fprintf(fp, "\tsete al\t\t;set the last byte the rax in the register\n");
            fprintf(fp, "\tmov rbx ,1\t\t;set rbx to 1\n");
            fprintf(fp, "\tand rax, rbx\t\t;filter rax\n");
            break;
        case NOTEQUAL:
            fprintf(fp, "\tcmp rax, rbx\t\t;expr not equal\n");
            fprintf(fp, "\tsetne al\t\t;set the last byte the rax in the register\n");
            fprintf(fp, "\tmov rbx ,1\t\t;set rbx to 1\n");
            fprintf(fp, "\tand rax, rbx\t\t;filter rax\n");
            break;
        case MYNOT:
            fprintf(fp, "\tcmp rax , 0\t\t;CMP rax to 0\n");
            fprintf(fp, "\tsete al\t\t;Set al if equal to 0\n");
            fprintf(fp, "\tmov rdx, 1\t\t;Set rdx to 1\n");
            fprintf(fp, "\tand rax, rdx\t\t;And rax with rdx\n");
            break;
        default:
            printf("Unknown operator \n");
            exit(1);
            break;
    }  // end switch
    
    // Store rax back into the expr location
    fprintf(fp, "\tmov [rsp + %d], rax\t\t;store rax in rsp + offset\n", p->symbol->offset*WSIZE);
    
} // end emitExpr

// Precondition: ASTnode of assignStmt
// Postcondition: RAX will contain the final value
void emitAssign(ASTnode *p) {
    // Return if p is NULL
    if (p == NULL) return;
    
    // RHS check the type to see if it is a number, variable, or expression.
    switch (p->s2->type) {
        case NUMBER:
            fprintf(fp, "\tmov rbx, %d\t\t;Assignment nunber\n", p->s2->value);
            break;
            
        case variable:
            emitIdent(p->s2); 
            fprintf(fp, "\tmov rbx, [rax]\t\t;Assignment identifier\n");
            break;
            
        case expression:
            emitExpr(p->s2);
            fprintf(fp, "\tmov rbx, [rsp + %d]\t\t;Assignment expression\n", p->s2->symbol->offset * WSIZE);
            break;
            
        case call:
            break;
            
        default:
            printf("Error with assignment\n");
            exit(1);
            
    } // end switch
    
    //LHS will always be an identifier so call emitIdent
    emitIdent(p->s1);
    
    // Move the value from rbx into rax
    fprintf(fp, "\tmov [rax], rbx\t\t;Assign the value\n");

} // end emitAssign

// Precondition: ASTnode of ifStmt
// Postcondition: Output file will contain the needed labels and logic to handle an ifStmt.
void emitIF(ASTnode *p) {
    // Create and generate the needed labels
    char * L1 = CreateLabel();
    char * L2 = CreateLabel();
    
    // Check p->s1->type to see if it is a number, variable, or expression
    switch (p->s1->type) {
        case NUMBER:
            fprintf(fp, "\tmov rax, %d\t\t;If nunber\n", p->s1->value);
            break;
            
        case variable:
            emitIdent(p->s1); 
            fprintf(fp, "\tmov rax, [rax]\t\t;If identifier\n");
            break;
            
        case expression: 
            emitExpr(p->s1);
            fprintf(fp, "\tmov rax, [rsp + %d]\t\t;If expression\n", p->s1->symbol->offset * WSIZE);
            break;
            
        case call:
            break;
            
        default:
            printf("Error with IF\n");
            exit(1);
    } // end switch
    
    // Check to see if the expression from the if is false if so jump to L1
    fprintf(fp, "\n\tCMP rax, 0\t\t;IF compare\n");
    fprintf(fp, "\tJE %s\t\t;\n", L1);
    
     // Look through s1 for the if
     emitAst(p->s2->s1);
     
     // Check to see if we are in an if/else statement if so jump to L2
     if (p->s2->s2 != NULL) {
         fprintf(fp, "\tJMP %s\n", L2);
         
     } // end if
     
     // Print label for L1
     fprintf(fp, "%s:\t\t\t;Label target\n", L1);
     
     // If we are in a if/else statement do the else logic and print the needed label
     if (p->s2->s2 != NULL) {
         emitAst(p->s2->s2);
         
         fprintf(fp, "%s:\t\t\t;Label target\n", L2);
         
     } // end if
} // end emitIF

// Precondition: ASTnode of iterStmt
// Postcondition: Output file will contain the needed labels and information needed for a while loop
void emitWhile(ASTnode *p) {
    // Return if p is NULL
    if (p == NULL) return;
    
    // Create the needed labels 
    char *Label1 = CreateLabel();
    char *Label2 = CreateLabel();
    
    // Print out Label1 to jump back to
    fprintf(fp, "%s:\t\t\t;Label target\n", Label1);
    
    // Check to see p->s1->type to see if it is a number, variable or expression
    switch (p->s1->type) {
        case NUMBER:
            fprintf(fp, "\tmov rax, %d\t\t;While nunber\n", p->s1->value);
            break;
            
        case variable:
            emitIdent(p->s1); 
            fprintf(fp, "\tmov rax, [rax]\t\t;While identifier\n");
            break;
            
        case expression: 
            emitExpr(p->s1);
            fprintf(fp, "\tmov rax, [rsp + %d]\t\t;While expression\n", p->s1->symbol->offset * WSIZE);
            break;
            
        case call:
            break;
            
        default:
            printf("Error with loop condition\n");
            exit(1);
    } // end switch
    
     // Check to see if the expression from the while loop is false if so jump to label2
    fprintf(fp, "\n\tCMP rax, 0\t\t;Loop compare\n");
    fprintf(fp, "\tJE %s\n", Label2);
    
    // Add the information in the loop
    emitAst(p->s2);
    
    // Jump back to Label1 
    fprintf(fp, "\tJMP %s\t\t;Jmp back to loop condition\n", Label1);
    
    // Print the Label2 target
    fprintf(fp, "%s:\t\t\t;Label target\n", Label2);
    
} // end emitWhile

// Precondition: ASTnode from a completed yacc parse.
// Postcondition: A NASM file that runs the code given.
void emitAst(ASTnode *p)
{
   //init
   int i;
   // If p is NULL just return without printing. If P is not NULL print as needed.
   if (p == NULL ) return;
	   
	   // A switch statment looking at the types of nodes passed to the emitAst funtion.
       switch (p->type) {
        case varDecl :
                     break;
        case funDecl :  
                     emitLabelStart(p);
                     emitAst( p->s1);
                     emitAst( p->s2);
                     emitAst( p->next);
                     emitLabelEnd();
                     break;
        case param : if (mydebug) printf("PARAMETER ");
		
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
    
       case expression : if (mydebug) printf("EXPR ");
                        
					 // Switch statment used to print the correct symbol in the node
					 // Recursively print s1
                     emitAst( p->s1);
					 
			 // Recursively print s2 if the operator is not MYNOT
		     if (p->operator != MYNOT) {
                         emitAst( p->s2);
             }
                     break;
        case compStmt : if (mydebug) printf("BLOCK STATEMENT  \n",p->name);
					// Recursively print s1 and s2
                     emitAst( p->s1);
                     emitAst( p->s2);
                     break;
        case iterStmt : if (mydebug) printf("WHILE STATEMENT \n");
					 emitWhile(p);
                     break; 
        case NUMBER :  
					// Check the value of the node if is is equal to 1 that print true or is the value is 0 print false. 
					// If it is not any of these values just print the value in the node.
						   
					   // Recursively print s1
                       emitAst( p->s1);
                       break;
        case variable : if (mydebug) printf("IDENTIFIER %s\n",p->name);
                        emitIdent(p);
						// Recursively print s1
                        emitAst( p->s1);
                        break;                    
        case writeStmt :
           if (mydebug) printf("write stmt\n");
                        // Check to see if the write statement is a string if so do not run the expression code
                        if (p -> isType != STRINGTYPE) {
                            // Look at the write statement to see if it is a number, variable or expression
                            switch (p->s1->type) {
                                case NUMBER: if(p->s1->isType == BOOLTYPE){
                                        fprintf(fp, "\tmov rsi, %d\t\t;Write boolean value\n", p->s1->value);
                                        } else {
                                        fprintf(fp, "\tmov rsi, %d\t\t;Write number\n", p->s1->value);
                                        }
                                        break;
                                case variable: 
                                        emitIdent(p->s1);
                                        fprintf(fp, "\tmov rsi, [rax]\t\t;Write variable\n");
                                        break;
                                case expression: emitExpr(p->s1);
                                        fprintf(fp, "\tmov rsi, [rsp + %d]\t\t;Write expression\n", (p->s1->symbol->offset * WSIZE));
                                        break;
                                case call:
                                        break;
                                default: printf("Unknown type\n");
                                
                            } // end switch
                            
                            fprintf(fp, "\tPRINT_DEC 8, rsi\t\t;standard Write a value\n");
                            fprintf(fp, "\tNEWLINE\n\n");
                        } else {
                            // Print out strings
                            fprintf(fp, "\tPRINT_STRING %s\t\t;standard Write a string\n", p->label);
                            fprintf(fp, "\tNEWLINE\n\n");
                        } // end if else
                        
                     break;
        case readStmt : if (mydebug) printf("read STATEMENT\n");
                    emitIdent(p->s1);
                    fprintf(fp, "\tGET_DEC 8, [rax]\t\t;Read in a value\n\n");
					// Recursively print s1
                     emitAst( p->s1);
                     break;
        case assignStmt : if (mydebug) printf("Assignment STATEMENT\n");
                    emitAssign(p);
                     break;
        case selcStmt : if (mydebug) printf("Selc STATEMENT\n");
					// Recursively print s1 and s2
                     emitAst( p->s1);
                     emitAst( p->s2);
                     break;
        case returnStmt : if (mydebug) printf("RETURN STATEMENT\n");
					// Recursively print s1
                     emitAst( p->s1);
                     break;
        case ifStmt : if (mydebug) printf("IF STATEMENT\n");
                     emitIF(p);
                     break;
        case ifElse : if (mydebug) printf("IF ELSE STATEMENT\n");
                     break;
        case call : if (mydebug) printf("CAll STATEMENT %s\n",p->name);
					// Recursively print s1
                    emitAst( p->s1);
                    break;
        
        default: printf("unknown type in emitAst %d\n", p->type);


       } // end switch
	   // Print the next pointer of the node
       emitAst( p->next); 
	   
} // end emitAST

