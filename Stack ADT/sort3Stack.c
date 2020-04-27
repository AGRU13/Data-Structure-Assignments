#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include <limits.h>
#define SIZE 100

typedef struct ArrayStack
{
    int capacity;
    int top;
    int *array;
}Stack;

Stack * CreateStack()
{
    Stack * S=malloc(sizeof(Stack));
    if(!S)
       return NULL;
    S->capacity=SIZE;
    S->top=-1;
    S->array=malloc(S->capacity*sizeof(int));
    if(!S->array)
        return NULL;
    return S;
}

int IsFullStack(Stack *S )
{
    return S->top==S->capacity-1;
}

int IsEmptyStack(Stack *S)
{
    return S->top==-1;
}

void Push(Stack *S,int data)
{
    if(IsFullStack(S))
        printf("\nStack is Full!!");
    else
        S->array[++S->top]=data;
}

void Pop(Stack *S)
{
    if(IsEmptyStack(S))
        printf("\Stack is Empty!!");
    else
        printf("\nElement Deleted = %d ",S->array[S->top--]);
}

int Top(Stack *S)
{
    if(IsEmptyStack(S))
        return INT_MIN;
    else
        return S->array[S->top];
}

void Disp(Stack *S)
{
    if(IsEmptyStack(S))
        printf("\nEmpty Stack!!");
    else
    {
        for(i=S->top;i>=0;i--)
            printf("\n\t|%d|",S->array[i]);
        printf("\n\t|---------|");
    }
}

void DeleteStack(S)
{
     if(S){
        if(S->array)
            free(S->array);
        free(S);
    }
}

void Sort(Stack *S1,Stack *S2,Stack *S3)
{
    SortSingle(S1,S,S2);
    SortSingle(S2,S,S3);
    SortSingle(S3,S,S1);
}

void SortSingle(Stack *S1,Stack *S,Stack *S2)
{
    while(!IsEmptyStack(S1))
    {
        while(Top(S1)<Top(S))
        {
            Push(S2,Pop(S1));
        }
    }
}




