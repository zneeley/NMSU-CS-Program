#ifndef symtable
#define symtable
typedef struct SymbTable {
   // info for needed values
	char *variable;
	int offset;

	// Used for the next node in the list
	struct SymbTable *next; 
} Node;

   struct SymbTable *first, *last;

//Prototypes
void Insert(char *a, int x);
void Display();
void Delete(char *a);
int Search(char *a);
int fetchAddress(char *a);

#endif
