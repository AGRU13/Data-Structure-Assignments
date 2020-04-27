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

struct AdvanceStack
{
    struct ArrayStack *elementStack;
    struct ArrayStack *minStack;
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

void PushAdvance(struct AdvanceStack *S,int data)
{
    Push(S->elementStack,data);
    if(IsEmptyStack(S->minStack)||Top(S->minStack)>=data)
        Push(S->minStack,data);
}

int PopAdvance(struct AdvanceStack *S)
{
    int temp;
    if(IsEmptyStack(S->elementStack))
        return -1;
    temp = Top(S->elementStack);
    if(Top(S->minStack)==temp)
        temp=Pop(S->minStack);
    return Pop(S->elementStack);
}

int GetMinimum(struct AdvanceStack *S)
{
    return Top(S->minStack);
}

struct AdvanceStack *CreateAdvStack()
{
    struct AdvanceStack *S = (struct AdvanceStack*)malloc(sizeof(struct AdvanceStack));
    if(!S)
        return NULL;
    S->elementStack=CreateStack();
    S->minStack=CreateStack();
    return S;
};

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

int main()
{
    struct AdvanceStack *S= CreateAdvStack();
    int n,val;
    while(1)
    {
    printf("\n\nEnter 1 to PUSH: ");
    printf("\nEnter 2 to POP: ");
    printf("\nEnter 3 to GetMinimum: ");
    printf("\nEnter 4 to Display: ");
    printf("\nEnter 5 to exit: ");
    scanf("%d",&n);
    switch(n)
    {
        case 1: printf("\nEnter value to push: ");
                scanf("%d",&val);
                PushAdvance(S,val);
                break;
        case 2: printf("\nElement deleted: %d",PopAdvance(S));
                break;
        case 3: printf("\nMinimum is = %d ",GetMinimum(S));
                break;
        case 4: printf("\nElement Stack is = ");
                DISP(S->elementStack);
                printf("\nMinimum Stack is = ");
                DISP(S->minStack);
                break;
        case 5:  DeleteStack(S->elementStack);
                 DeleteStack(S->minStack);
                 free(S);
                 return 0;
                 exit(0);
        default: printf("\nEntered choice not detected!! Enter again!!");
    }
    }
    return -234;
}
