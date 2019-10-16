#ifndef SYMTAB_H
#define SYMTAB_H

struct SymbTab {
    int offset;
    char *name;
    
    struct SymbTab *next;
};

#endif
