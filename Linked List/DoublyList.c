#include<stdio.h>
#include<stdlib.h>

typedef struct DoubleList
{
    int data;
    struct DoubleList *next;
    struct DoubleList *prev;
}DList;

void Insert(DList **head,int val,int position)
{
    DList *temp=*head;
    DList *newNode=(DList *)malloc(sizeof(DList));
    if(!newNode)
    {
        printf("Memory error!!");
        return;
    }
    newNode->data=val;
    if(position==1||temp==NULL)
    {
        newNode->prev=NULL;
        newNode->next=*head;
        if(*head)
            (*head)->prev=newNode;
        *head=newNode;
        return;
    }
    int k=1;
    while(k<position-1&&temp->next!=NULL)
    {
        temp=temp->next;
        k++;
    }
    if(k!=position-1)
        printf("\nPosition does not exist , Inserting in the end.");

    newNode->next=temp->next;
    newNode->prev=temp;
    if(temp->next)
        (temp->next)->prev=newNode;
    temp->next=newNode;
}

void Delete(DList **head,int position)
{
    DList *temp;
    if(!*head)
    {
        printf("\n Empty List!!");
        return;
    }
    temp=*head;
    if(position==1)
    {
        *head=(*head)->next;
        if(*head!=NULL)
            (*head)->prev=NULL;
        free(temp);
        return;
    }
    int k=1;
    while(k<position&&temp->next!=NULL)
    {
        temp=temp->next;
        k++;
    }
    if(k!=position)
    {
        printf("\n Entered position does not exist!!");
        return;
    }
    temp->prev->next=temp->next;
    if(temp->next!=NULL)
        temp->next->prev=temp->prev;
    free(temp);
    return;
}

void Disp(DList *head)
{
    if(head==NULL)
        printf("\nEmpty List");
    else
    {
        DList *p=head;
        printf("\n%d",p->data);
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
    DList *head=NULL;
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
            case 3: Disp(head);
                    break;
            case 4: exit(1);
                    break;
            default : printf("\nChoice not detected, Enter again !!");
        }
    }
    return 0;
}
