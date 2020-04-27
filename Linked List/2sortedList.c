#include<stdio.h>
#include<stdlib.h>

typedef struct LinkedList
{
    int data;
    struct LinkedList *next;
}List;

void Insert(List **head,int data,int position)
{
    List *p,*q,*newNode;
    int k=1;
    newNode=(List *)malloc(sizeof(List));
    if(!newNode)
    {
        printf("\nMemory Error!!");
        return;
    }
    p=*head;
    newNode->data=data;
    if(position==1||p==NULL)
    {
        if(position!=1)
            printf("\nDesired position does not exist inserting at last!!");
        newNode->next=p;
        *head=newNode;
    }else{
        while(p->next!=NULL&&k<position-1)
        {
            k++;
            p=p->next;
        }
        if(k!=position-1)
            printf("\nDesired position does not exist inserting at last!!");
        newNode->next=p->next;
        p->next=newNode;
    }
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

List* MergeIterative(List *head1,List *head2)
{
    List *newNode=malloc(sizeof(List)),*temp;
    temp=newNode;
    newNode->next=NULL;
    while(head1!=NULL&&head2!=NULL)
    {
        if(head1->data<=head2->data)
        {
            temp->next=head1;
            temp=temp->next;
            head1=head1->next;
        }else{
            temp->next=head2;
            temp=temp->next;
            head2=head2->next;
        }
    }
    if(head1==NULL) temp->next=head2;
    else temp->next=head1;

    temp=newNode->next;
    free(newNode);
    return temp;
}

List* MergeRecursive(List *head1,List *head2)
{
    List *temp=NULL;
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;
    if(head1->data<=head2->data)
    {
        temp=head1;
        temp->next=MergeRecursive(head1->next,head2);
    }else{
        temp=head2;
        temp->next=MergeRecursive(head2->next,head1);
    }
    return temp;
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

int main()
{
    List *head1=NULL,*head2=NULL;
    int i;
    for(i=1;i<=5;i++)
        Insert(&head1,i+3,i);
    for(i=1;i<=10;i++)
        Insert(&head2,2*i,i);
    DISP(head1);
    DISP(head2);
    printf("\nIterative merging\n");
    DISP(MergeIterative(head1,head2));
   //printf("\nRecursive merging\n");
    //DISP(MergeRecursive(head1,head2));
    return 0;
}
