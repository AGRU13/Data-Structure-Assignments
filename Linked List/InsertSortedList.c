#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct LinkedList
{
    int data;
    struct LinkedList *next;
}List;

void Insert(List **head,int val)
{
    List *newNode = malloc(sizeof(List));
    List *current=*head,*temp;
    if(!newNode)
    {
        printf("\nMemory Error!!");
        return;
    }
    newNode->data=val;
    if(current==NULL||current->data>=newNode->data)
    {
        newNode->next=current;
        *head=newNode;
        return;
    }
    while(current!=NULL&&current->data<newNode->data)
    {
        temp=current;
        current=current->next;
    }
    newNode->next=current;
    temp->next=newNode;
}

void DISP(List *head)
{
    if(head==NULL)
        printf("\nEMPTY LIST.");
    else
    {
        printf("\n");
        List *p=head;
        printf("%d",p->data);
        p=p->next;
        while(p!=NULL)
        {
            printf("->%d",p->data);
            p=p->next;
        }
    }
}

void DeleteList(List **head)
{
    List *auxNode,*iterator;
    iterator=*head;
    while(iterator!=NULL)
    {
        auxNode=iterator;
        iterator=iterator->next;
        free(auxNode);
    }
    *head=NULL;
}

int main(int argc,char *argv[])
{
    if(argc!=2)
    {
        printf("Enter only one argument!!");
        return -1223;
    }
    int n = atoi(argv[1]);
    if(n<0)
    {
        printf("Enter positive integer only!!");
        return -1111;
    }
    List *head=NULL;
    int i,num,j,pos,k;
    int arr[n];
    clock_t t;
    t=clock();
    double ttime=0;
    for(i=0;i<6;i++)
    {
        t=clock()-t;
        srand(i);
        for(j=0;j<n;j++)
        {
            pos=0;
            num=rand()%10001;
            while(pos<j&&arr[pos]<num)
                pos++;
            for(k=j;k>pos;k--)
            {
                arr[k]=arr[k-1];
            }
            arr[pos]=num;
        }
        t=clock()-t;
        printf("\n");
        for(j=0;j<n;j++)
            printf("%d ",arr[j]);
        fprintf(stderr,"\t%f",(float)t/CLOCKS_PER_SEC);
        ttime+=(double)t/CLOCKS_PER_SEC;
    }
    printf("\nAverage time for array insertion is = %lf",ttime/6);
    t=clock();
    ttime=0;
    for(i=0;i<6;i++)
    {
        t=clock()-t;
        srand(i);
        for(j=0;j<n;j++)
        {
            pos=0;
            num=rand()%10001;
            Insert(&head,num);
        }
        t=clock()-t;
        DISP(head);
        fprintf(stderr,"\t%f",(float)t/CLOCKS_PER_SEC);
        ttime+=(double)t/CLOCKS_PER_SEC;
        head=NULL;
    }
    printf("\nAverage time for Linked List insertion is = %lf",ttime/6);
    return 0;
}
