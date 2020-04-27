#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include <limits.h>
#define SIZE 100

struct ArrayStack
{
    int top;
    int capacity;
    int *array;
};

struct ArrayStack *CreateStack()
{
    struct ArrayStack *S = malloc(sizeof(struct ArrayStack));
    if(!S)
        return NULL;
    S->capacity=SIZE;
    S->top=-1;
    S->array=malloc(S->capacity*sizeof(int));
    if(!S->array)
        return NULL;
    return S;
};

int IsEmptyStack(struct ArrayStack *S)
{
    return S->top==-1;
}

int IsFullStack(struct ArrayStack *S)
{
    return S->top==S->capacity-1;
}

void Push(struct ArrayStack *S, int data)
{
    if(IsFullStack(S))
        printf("STACK OVERFLOW");
    else
        S->array[++S->top]=data;
}

int Pop(struct ArrayStack *S)
{
    if(IsEmptyStack(S)){
        return INT_MIN;
    }
    else
        return S->array[S->top--];
}

int Top(struct ArrayStack *S)
{
    if(IsEmptyStack(S))
        return INT_MIN;
    return S->array[S->top];
}

void DISP(struct ArrayStack *S)
{
    int i;
    if(IsEmptyStack(S))
        printf("\nEMPTY STACK.");
    else
    {
        for(i=S->top;i>=0;i--)
            printf("\n\t|%d|",S->array[i]);
        printf("\n\t|---------|");
    }

}

void DeleteStack(struct ArrayStack *S)
{
    if(S){
        if(S->array)
            free(S->array);
        free(S);
    }
}

void InsertAtBottom(struct ArrayStack *S,int data)
{
    if(IsEmptyStack(S))
     {
         Push(S,data);
         return;
     }
    int temp=Pop(S);
    InsertAtBottom(S,data);
    Push(S,temp);
}

void ReverseStack(struct ArrayStack *S)
{
    int data;
    if(IsEmptyStack(S))
        return;
    data=Pop(S);
    ReverseStack(S);
    InsertAtBottom(S,data);
}

int main()
{
    struct ArrayStack *S= CreateStack();
    int n,val;
    while(1)
    {
    printf("\n\nEnter 1 to PUSH: ");
    printf("\nEnter 2 to POP: ");
    printf("\nEnter 3 to ReverseStack: ");
    printf("\nEnter 4 to Display: ");
    printf("\nEnter 5 to exit: ");
    scanf("%d",&n);
    switch(n)
    {
        case 1: printf("\nEnter value to push: ");
                scanf("%d",&val);
                Push(S,val);
                break;
        case 2: printf("\nElement deleted: %d",Pop(S));
                break;
        case 3: printf("\nStack is reversed!! ");
                ReverseStack(S);
                break;
        case 4: printf("\nStack is = ");
                DISP(S);
                break;
        case 5:  DeleteStack(S);
                 exit(0);
        default: printf("\nEntered choice not detected!! Enter again!!");
    }
    }
    return -234;
}
