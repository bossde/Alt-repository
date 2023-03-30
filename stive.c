#include "stive.h"

Data top(Node *top){
    if (isEmpty(top)) return SCHAR_MIN;
    return top->val;
}

void push(Node**top, Data v) {
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->val=v;
    newNode->next=*top;
    *top=newNode;
}

Data pop(Node**top) {
    if (isEmpty(*top)) return SCHAR_MIN;
    Node *temp=(*top);
    Data aux=temp->val;
    *top=(*top)->next;
    free(temp);
    return aux;
}

int isEmpty(Node*top){
    return top==NULL;
}

void deleteStack(Node**top){
    Node  *temp;
    while (!isEmpty(*top))
        temp=*top;
    *top=(*top)->next;
    free(temp);
}

int topINT(NodeINT *top){
    if (isEmptyINT(top)) return INT_MIN;
    return top->val;
}

void pushINT(NodeINT**top, Data v) {
    NodeINT* newNode=(NodeINT*)malloc(sizeof(NodeINT));
    newNode->val=v;
    newNode->next=*top;
    *top=newNode;
}

int popINT(NodeINT**top) {
    if (isEmptyINT(*top)) return INT_MIN;
    NodeINT *temp=(*top);
    Data aux=temp->val;
    *top=(*top)->next;
    free(temp);
    return aux;
}

int isEmptyINT(NodeINT*top){
    return top==NULL;
}

void deleteStackINT(NodeINT**top){
    NodeINT  *temp;
    while (!isEmptyINT(*top))
        temp=*top;
    *top=(*top)->next;
    free(temp);
}


/*void ParanthesesClosed(char*sir){
    int aux = 1;
    int variable;
    int k1;
    int k2;
    int ok = 0;
    Node* StackOpen = NULL;
    Node* StackClosed = NULL;
    variable = strlen(sir);
    for(int i = 0; i < strlen(sir); i++){
        if(sir[i] == ')') printf("%d ", aux);
        if(sir[i] == '('){
            aux = i + 1;
            break;
        }
        aux++;
    }
    for(int i = aux; i < strlen(sir); i++){
        if(sir[i] == '(') {
            ok = 0;
            k1 = i + 1;
            for (int j = variable - 1; j >= i; j--) {
                if (sir[j] == ')') {
                    variable = i;
                    ok = 1;
                    break;
                }
            }
            if (ok == 0) {
                printf("%d ", k1);
            }
        }
    }
    int contor1 = 0, contor2 = 0;
    for(int i = 0; i < strlen(sir) - 1; i++)
    {
        if(sir[i] == '(') contor1++;
        if(sir[i] ==')') contor2++;
    }
    int contor = contor2 - contor1;
    while(contor > 0){
        for(int j = strlen(sir) - 1; j >= 0; j++){
            if(sir[j] == ')'){
                printf("%d ", j + 1);
                contor--;
            }
        }
    }
}*/
void ParanthesesClosed(char*sir){
    NodeINT* StackPOS = NULL;
    Node* Stack = NULL;
    int val;
    int aux = 1;
    /*for(int i = 0; i < strlen(sir); i++){
        if(sir[i] == ')') printf("%d ", aux);
        if(sir[i] == '('){
            aux = i + 1;
            break;
        }
        aux++;
    }*/
    for(int i = 0; i < strlen(sir); i++){
        if(sir[i] == '('){
            push(&Stack,sir[i]);
            pushINT(&StackPOS, i + 1);
        }
    }
    for(int i = 0; i < strlen(sir) - 1; i++){
        if(sir[i] == ')' && isEmpty(Stack) == 0){
            pop(&Stack);
            popINT(&StackPOS);
        }
        if(sir[i] == ')' && isEmpty(Stack) != 0){
            printf("%d ", i + 1);
        }
    }
    while(isEmpty(Stack) == 0){
        pop(&Stack);
        val = popINT(&StackPOS);
        printf("%d ", val);
    }
}

