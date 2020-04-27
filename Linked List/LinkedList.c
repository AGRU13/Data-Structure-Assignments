#include<stdio.h>
#include<stdlib.h>

typedef struct LinkedList
{
    int data;
    struct LinkedList *next;
}List;

int Length(List *head)
{
    List *current=head;
    int count=0;
    while(current!=NULL)
    {
        current=current->next;
        count++;
    }
    return count;
}

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

void Delete(List **head,int position)
{
    List *p,*q;
    int k=1;
    if(*head==NULL)
    {
        printf("\nList Is Empty!!");
        return;
    }
    p=*head;
    if(position==1)
    {
        *head=(*head)->next;
        free(p);
        return;
    }else{
        while(p!=NULL&&k<position)
        {
            k++;
            q=p;
            p=p->next;
        }
        if(p==NULL)
        {
            printf("\nPosition Doesn't exist !!");
            return;
        }else{
            q->next=p->next;
            free(p);
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

int main()
{
    int n,val,position;
    List *head=NULL;
    while(1)
    {
        printf("\n\nPress 1 to Insert: ");
        printf("\nPress 2 to Delete: ");
        printf("\nPress 3 to DISPLAY: ");
        printf("\nPress 4 to exit: ");
        scanf("%d",&n);
        switch(n)
        {
            case 1: printf("\nEnter the value to Insert into the List: ");
                    scanf("%d",&val);
                    printf("\nEnter the position to insert the new element: ");
                    scanf("%d",&position);
                    Insert(&head,val,position);
                    break;
            case 2: printf("\nEnter the position of the element you want to delete: ");
                        scanf("%d",&position);
                        Delete(&head,position);
                    break;
            case 3: DISP(head);
                    break;
            case 4: exit(1);
                    break;
            default : printf("\nChoice not detected, Enter again !!");
        }
    }
    return 0;
}












