#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<limits.h>
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

void Postfix(char *ch)
{
    struct ArrayStack *S = CreateStack();
    if(!S)
        exit(-1);
    int i,op1,op2,res;
    for(i=0;i<strlen(ch);i++)
    {
        if(isdigit(ch[i]))
            Push(S,ch[i]-'0');
        else
        {
            op1=Pop(S);
            op2=Pop(S);
            switch(ch[i])
            {
                case '+': res=op1+op2;
                break;
                case '-': res=op2-op1;
                break;
                case '*': res=op1*op2;
                break;
                case '/': res=op2/op1;
            }
            Push(S,res);
        }
    }
    printf("\n OUPUT IS = %d",Pop(S));
    DeleteStack(S);
}

void Prefix(char *ch)
{
    struct ArrayStack *S = CreateStack();
    if(!S)
        exit(-1);
    int i,op1,op2,res;
    for(i=strlen(ch)-1;i>=0;i--)
    {
        if(isdigit(ch[i]))
            Push(S,ch[i]-'0');
        else
        {
            op1=Pop(S);
            op2=Pop(S);
            switch(ch[i])
            {
                case '+': res=op1+op2;
                break;
                case '-': res=op1-op2;
                break;
                case '*': res=op1*op2;
                break;
                case '/': res=op1/op2;
            }
            Push(S,res);
        }
    }
    printf("\n OUPUT IS = %d",Pop(S));
    DeleteStack(S);
}
int main()
{
    char string[100];
    int n;
    while(1)
    {
        printf("\n\nEnter 1 for POSTFIX evaluation: ");
        printf("\nEnter 2 for PREFIX evaluation: ");
        printf("\nEnter 3 to exit: ");
        scanf("%d",&n);
        getchar();
        switch(n)
        {
            case 1: printf("\nEnter an expression: ");
                    gets(string);
                    Postfix(string);
                    break;
            case 2: printf("\nEnter an expression: ");
                    gets(string);
                    Prefix(string);
                    break;
            case 3: exit(0);
            default: printf("\nChoice does not exist!! Input again!!");
        }
    }
    return 0;
}
