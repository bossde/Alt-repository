#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Data;

struct Elem{
    Data val;
    struct Elem* next;
};

typedef struct Elem Node;

struct ElemINT{
    Data val;
    struct ElemINT* next;
};

typedef struct ElemINT NodeINT;

Data top(Node *top);
void push(Node**top, Data v);
Data pop(Node**top);
int isEmpty(Node*top);
void deleteStack(Node**top);
void ParanthesesClosed(char* sir);
int topINT(NodeINT *top);
void pushINT(NodeINT**top, Data v);
int popINT(NodeINT**top);
int isEmptyINT(NodeINT*top);
void deleteStackINT(NodeINT**top);
