#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <limits.h>
#define SIZE 10

struct ThreeStack
{
    int top1;
    int top2;
    int base3;
    int top3;
    int capacity;
    int *array;
};

int IsFullStack1(struct ThreeStack *S)
{
    return S->top1==S->base3-1;
}

int IsFullStack2(struct ThreeStack *S)
{
    return S->top2==S->top3+1;
}

int IsFullStack3(struct ThreeStack *S)
{
    return S->top3==S->top2-1;
}

void Push1(struct ThreeStack *S,int data)
{
    if(IsFullStack1(S))
    {
        if(S->top3+1==S->top2)
            printf("\nStack Overflow!!");
        else
        {
            int i;
            for(i=S->top3+1;i>S->base3;i--)
                S->array[i]=S->array[i-1];
            S->base3+=1;
            S->top3+=1;
            S->array[++S->top1]=data;
        }
    }
    else
        S->array[++S->top1]=data;
}

void Push2(struct ThreeStack *S,int data)
{
    if(IsFullStack2(S))
    {
        if(S->base3-1==S->top1)
            printf("\nStack Overflow!!");
        else
        {
            int i;
            for(i=S->base3-1;i<S->top3;i++)
                S->array[i]=S->array[i+1];
            S->base3-=1;
            S->top3-=1;
            S->array[--S->top2]=data;
        }
    }
    else
        S->array[--S->top2]=data;
}

void Push3(struct ThreeStack *S,int data)
{
    if(IsFullStack3(S))
    {
        if(S->base3-1==S->top1)
            printf("\nStack Overflow");
        else
        {
            int i;
            for(i=S->base3-1;i<S->top3;i++)
                S->array[i]=S->array[i+1];
            S->base3-=1;
            S->array[S->top3]=data;
        }
    }
    else
        S->array[++S->top3]=data;
}

void Push(struct ThreeStack *S)
{
    int n,val;
    printf("\nEnter value to Push: ");
    scanf("%d",&val);
    while(1){
    printf("\nEnter 1 to Push in stack 1: ");
    printf("\nEnter 2 to Push in stack 2: ");
    printf("\nEnter 3 to Push in stack 3: ");
    scanf("%d",&n);
    switch(n)
    {
        case 1: Push1(S,val);
                    return;
        case 2: Push2(S,val);
                    return;
        case 3: Push3(S,val);
                    return;
        default: printf("\nChoice not detected!! Enter again");
    }
    }
}

int Pop(struct ThreeStack *S)
{
    int n;
    while(1){
    printf("\nEnter 1 to Pop from stack 1: ");
    printf("\nEnter 2 to Pop from stack 2: ");
    printf("\nEnter 3 to Pop from stack 3: ");
    scanf("%d",&n);
    switch(n)
    {
        case 1: if(S->top1==-1){
                        printf("\nStack Underflow");
                        return INT_MIN;}
                    else
                        return S->array[S->top1--];
        case 2: if(S->top2==S->capacity){
                        printf("\nStack Underflow");
                        return INT_MIN;}
                    else
                        return S->array[S->top2++];
        case 3: if(S->top3==S->base3-1){
                        printf("\nStack Underflow");
                        return INT_MIN;}
                    else
                        return S->array[S->top3--];
        default: printf("\nChoice not detected!! Enter again");
    }
    }
}

struct ThreeStack *CreateStack()
{
    struct ThreeStack *S=malloc(sizeof(struct ThreeStack));
    if(!S)
        return NULL;
    S->capacity=SIZE;
    S->top1=-1;
    S->top2=S->capacity;
    S->top3=(S->capacity-1)/3;
    S->base3=S->top3+1;
    S->array=malloc(S->capacity*sizeof(int));
    if(!S->array)
        return NULL;
    return S;
}

void Disp(struct ThreeStack *S)
{
    int n,i;
    while(1){
    printf("\nEnter 1 to Display stack 1: ");
    printf("\nEnter 2 to Display stack 2: ");
    printf("\nEnter 3 to Display stack 3: ");
    scanf("%d",&n);
    printf("\nStack is = ");
    switch(n)
    {
        case 1: if(S->top1==-1){
                        printf("\nEmpty Stack");
                        return ;}
                    else
                        for(i=S->top1;i>=0;i--)
                            printf("\n\t|%d|",S->array[i]);
                        printf("\n\t|---------|");
                    return;
        case 2: if(S->top2==S->capacity){
                        printf("\nEmpty Stack");
                        return ;}
                    else
                        for(i=S->top2;i<S->capacity;i++)
                            printf("\n\t|%d|",S->array[i]);
                        printf("\n\t|---------|");
                    return;
        case 3: if(S->top3==S->base3-1){
                        printf("\nEmpty Stack");
                        return ;}
                    else
                        for(i=S->top3;i>=S->base3;i--)
                            printf("\n\t|%d|",S->array[i]);
                        printf("\n\t|---------|");
                    return;
        default: printf("\nChoice not detected!! Enter again");
    }
    }
}

int main()
{
    struct ThreeStack *S=CreateStack();
    int n;
    while(1)
    {
        printf("\nEnter 1 to Push: ");
        printf("\nEnter 2 to Pop: ");
        printf("\nEnter 3 to Display: ");
        printf("\nEnter 4 to exit: ");
        scanf("%d",&n);
        switch(n)
        {
            case 1: Push(S);
                        break;
            case 2: printf("\nElement deleted: %d",Pop(S));
                        break;
            case 3: Disp(S);
                        break;
            case 4: exit(0);
            default: printf("\nChoice not detected!!Enter again!!");
        }
    }
    return -12312;
}






