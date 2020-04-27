#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct list{
    int data;
    struct list *next;
}List;

void Push(List **top,int data)
{
    List *newNode=malloc(sizeof(List));
    if(!newNode)
        printf("\nMemory Error!!");
    else
    {
        newNode->data=data;
        newNode->next=*top;
        *top=newNode;
    }
}

int IsEmptyStack(List *top)
{
    return top==NULL;
}

int Pop(List **top)
{
    if(IsEmptyStack(*top))
        return -1;
    List *temp=*top;
    *top=(*top)->next;
    int val=temp->data;
    free(temp);
    return val;
}

int Top(List *top)
{
    if(IsEmptyStack(top))
        return -1;
    return top->data;
}

void Display(List *top)
{
    if(top==NULL)
        printf("\nEmpty Stack!!");
    else
    {
        List *current=top;
        while(current!=NULL)
        {
            printf("\n\t|%d|",current->data);
            current=current->next;
        }
    }
}

void Postfix(char *ch)
{
    List *top=NULL;
    int i,op1,op2,num=0;
    char op;
    for(i=0;i<strlen(ch);i++)
    {
            if(isdigit(ch[i]))
            {
                while()
                num=num*10+ch[i];
                Push(&top,num);
            }

            else
            {
                op=ch[i];
                op1=Pop(&top);
                op2=Pop(&top);
                switch(op)
                {
                    case '+': num=op1+op2;
                              break;
                    case '-': num=op2-op1;
                              break;
                    case '/': num=op2/op1;
                              break;
                    case '*': num=op2*op1;
                              break;
                }
                Push(&top,num);
            }
        }
    }
    printf("\nEvaluation of the given postfix expression gives= %d",Pop(&top));
    DeleteStack(&top);
}

void DeleteStack(List **top)
{
    List *p,*temp;
    p=*top;
    while(p->next)
    {
        temp=p->next;
        p->next=temp->next;
        free(temp);
    }
    free(p);
    *top=NULL;
}

int main()
{
    int data,n;
    char string[100];
    while(1)
    {
        printf("\nEnter 1 for postfix evaluation: ");
        printf("\nEnter 2 for prefix evaluation: ");
        printf("\nEnter 3 to exit: ");
        scanf("%d",&n);
        getchar();
        switch(n)
        {
            case 1: printf("\nEnter a postfix expression: ");
                    gets(string);
                    Postfix(string);
                    break;
            case 3: exit(0);
            default: printf("\nEnter choice not detected , enter again!!");
        }
    }
    return -123;
}









