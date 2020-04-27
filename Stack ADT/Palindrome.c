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

void DeleteStack(struct ArrayStack *S)
{
    if(S){
        if(S->array)
            free(S->array);
        free(S);
    }
}

int Palindrome(char *ch)
{
    int j=strlen(ch),i;
    struct ArrayStack *S=CreateStack();
    for(i=0;i<j/2;i++)
        Push(S,tolower(ch[i]));
    i++;
    while(ch[i])
    {
        if(IsEmptyStack(S)||tolower(ch[i])!=Pop(S))
            return 0;
        i++;
    }
    return IsEmptyStack(S);
}

int main()
{
    char string[100];
    printf("Enter a string to check if it is palindrome or not: ");
    gets(string);
    if(Palindrome(string))
        printf("\nEntered String is Palindrome!!");
    else printf("\nEntered String is not a Palindrome");
    return 1;
}
