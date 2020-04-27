#include<stdio.h>
#include<stdlib.h>

typedef struct LinkedList
{
    int data;
    struct LinkedList *next;
}List;

typedef struct LinkedLinkList
{
    int data;
    struct LinkedLinkList *right;
    struct LinkedList *down;
}List2D;

void Insert(List2D **head,int n,int val)
{
    List2D *p,*q;
    p=*head;
    int i;
    if(n==1&&p==NULL)
    {
        List2D *newNode = malloc(sizeof(List2D));
        if(!newNode)
        {
            printf("\nMemory Error!!");
            return;
        }
        newNode->data=val;
        newNode->right=NULL;
        newNode->down=NULL;
        *head=newNode;
        return;
    }
    for(i=1;i<n;i++)
    {
        q=p;
        p=p->right;
    }
    if(p==NULL)
    {
        List2D *newNode = malloc(sizeof(List2D));
        if(!newNode)
        {
            printf("\nMemory Error!!");
            return;
        }
        newNode->data=val;
        newNode->right=NULL;
        newNode->down=NULL;
        q->right=newNode;
        return;
    }
    else
    {
        if(p->down==NULL)
        {
            List *newNode = malloc(sizeof(List));
            if(!newNode)
            {
                printf("\nMemory Error!!");
                return;
            }
            newNode->data=val;
            p->down=newNode;
            newNode->next=NULL;
            return;
        }
        List *a=p->down,*b=a;
        while(a!=NULL)
        {
            b=a;
            a=a->next;
        }

        List *newNode = malloc(sizeof(List));
        if(!newNode)
        {
            printf("\nMemory Error!!");
            return;
        }
        newNode->data=val;
        b->next=newNode;
        newNode->next=NULL;
        return;
    }
}

void DISP(List2D *head)
{
    if(head==NULL)
        printf("\nEMPTY LIST.");
    else
    {
        printf("\n");
        List2D *p=head;
        while(p!=NULL)
        {
            printf("->%d",p->data);
            List *q=p->down;
            while(q!=NULL)
            {
                printf("->%d",q->data);
                q=q->next;
            }
            p=p->right;
        }
    }
}

int main()
{
    List2D *head=NULL;
    int i=1,n,data=0;
    FILE *fp;
    char ch;
    fp=fopen("2DLIST.TXT","r");
    if(fp==NULL)
    {
        puts("Cannot open file!!");
        exit(1);
    }
    ch=fgetc(fp);
    n=ch-'0';
    ch=fgetc(fp);
    while(i<=n)
    {
        ch=fgetc(fp);
        while(ch!='\n'&&ch!=' ')
        {
            data=data*10+ch-'0';
            ch=fgetc(fp);
        }
        if(ch=='\n')
            i++;
        Insert(&head,i,data);
        data=0;
    }
    DISP(head);
    return 0;
}
