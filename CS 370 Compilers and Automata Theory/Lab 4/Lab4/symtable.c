/*
 * Name: Zachary Neeley
 * Date: 2/17/19
 * Purpose: The prupose of this program is to create a calculator using LEX and YACC
 *          to learn the basic process of tokens, expressions and basic trees.
 *     
 *      Input: Tokens given by the LEX file.
 *      Output: Show each token read in the input and the the digit found. Finially
 *              showing an answer.
 *
 * Changes: Changed the struct to only have the offset and variable.
 *			Add fetchAddress which will return the offset of a node.
 *			Modified the Insert method to accept a char * and a int.
 *			Modified search to return the new values for the struct.
 * 			
 */

#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include "symtable.h"

// Size for the list
int size = 0;

void Insert(char *a, int x){

   //Check to see if the node exists
   int n = Search(a);
   if(n == 1){
      printf("\n\tThe New label already exists");
   }else{
   //Allocate the needed memory for node.
   Node *p = (Node *)malloc(sizeof(Node));
   p -> variable = malloc(sizeof(a));
 
   //Pleace the new variable and offset into the end of the table.
   p -> variable = a;
   p -> offset = x;
   p -> next = NULL;

      //If the list is empty set the first and last pointer to p 
      if(size==0){
         first=p;
         last=p;
      } else {
      	last->next=p;
         last=p;
      }

      //Set the starting position.
      Node *first = p;

      size++; 
   }//end of else
   
}//End of Insert 

void Display(){
   Node *p;
   //Set p to the first node 
   p = first;

   printf("Variable\t\tOffset\n");
   while(p != NULL){
      printf("%s\t\t\t",p -> variable);
      printf("%d\t\n",p -> offset);
      p=p->next;
   } // end While
}//end of Display    

int Search(char *a){
	//Set flag to false
   int flag = 0;
   Node *p;
   
   // Set p to the first node.
   p = first;

   while(p != NULL){
   	//Look through the list and if the node is found return true.
   	if (strcmp(p -> variable, a) == 0)
   		flag = 1;
   		p=p->next;
   } // end While
   
   // If node found return false.
   return flag;
   
} // End Search

void Delete(char *a){
   Node *p, *temp;
   //Set p to the first node. 
   p = first;
   int n = Search(a);
   
   if(a == 0)
      printf("\nVarible not found\n");
      else {
		  
   	//If the variable is found point to the next node in the list.
   	if(strcmp(first -> variable, a) == 0)
		
         first = first -> next;
		 
         //If not found go to the next node in the list.
   	   else if (strcmp(last -> variable, a) == 0){
		   
            temp = p -> next;
			
			
            while (strcmp(temp -> variable, a) !=0){
            	p = p -> next;
            	temp = temp -> next;
            }//end of while
			
         p -> next = NULL;
         last = p;   
         } else {
         	temp = p -> next;
            while(strcmp(temp -> variable, a) != 0){
               p = p -> next;
               temp = temp -> next;
            }//end of while
			
            p -> next = temp -> next;
			
         }//end of if-else
         size--;
	 
   //Print that changes were made
   printf("\n\tAfter Deletion:\n");
   Display();
		}
   }//end of Delete Method
   
int fetchAddress(char *a) {
    Node *p;
	// Set p to the first node.
    p = first;
	// init address
    int address = 0;
    
	// Loop through the list till the node is found.
    while ( p != NULL) {
        
		// If the node is found get the address and return
        if (strcmp(p -> variable, a) == 0) {
            address = p -> offset;
            return address;
        }
        
		// Point to the next node
        p = p -> next;
    } // end while
    return -1;
	
} // end fetchAddress
