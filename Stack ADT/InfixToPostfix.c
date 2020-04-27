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
    char *array;
};

struct ArrayStack *CreateStack()
{
    struct ArrayStack *S = malloc(sizeof(struct ArrayStack));
    if(!S)
        return NULL;
    S->capacity=SIZE;
    S->top=-1;
    S->array=malloc(S->capacity*sizeof(char));
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

void Push(struct ArrayStack *S, char data)
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

int Precedence(int ch)
{
    if(ch=='-'||ch=='+')
        return 1;
    if(ch=='*'||ch=='/')
        return 2;
    return -124;
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

int main()
{
    struct ArrayStack *S = CreateStack();
    char string[100],output[100];
    int i=0,j=0;
    printf("Enter an infix expression to convert it to postfix: ");
    gets(string);
    for(i=0;i<strlen(string);i++)
    {
        if(isalnum(string[i])){
            output[j++]=string[i];
        }
        else if(string[i]=='(')
            Push(S,string[i]);
        else if(string[i]==')'){
             while (!IsEmptyStack(S) && Top(S) != '(')
                output[j++] = Pop(S);
            Pop(S);
        }
        else{
            while(!IsEmptyStack(S)&&Precedence(string[i])<=Precedence(Top(S))){
                output[j++]=Pop(S);
            }
            Push(S,string[i]);
        }
    }

    while(!IsEmptyStack(S)){
        output[j++]=Pop(S);
    }
    output[j]='\0';
    printf("\n Postfix expression is = ");
    puts(output);
    return 0;
}
