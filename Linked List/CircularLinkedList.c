#include<stdio.h>
#include<stdlib.h>

typedef struct CircularList
{
    int data;
    struct CircularList *next;
}CList;

void Insert(CList **head, int data, int position)
{
    CList *newNode=malloc(sizeof(CList)),*current=*head;
    int k=1;
    if(!newNode)
    {
        printf("\nMemory Error!!");
        return;
    }
    newNode->data=data;
    newNode->next=newNode;
    if(*head==NULL)
        *head=newNode;
    else if(position==1)
    {
        while(current->next!=*head)
            current=current->next;
        newNode->next=*head;
        current->next=newNode;
        *head=newNode;
    }
    else
    {
        while(k<position-1&&current->next!=*head)
        {
            k++;
            current=current->next;
        }
        if(k!=position-1)
            printf("Position does not exist, Inserting in the end!!");

        newNode->next=current->next;
        current->next=newNode;

    }
}

void Delete(CList **head,int position)
{
    CList *temp,*current;
    int k=1;
    if(*head==NULL)
    {
        printf("\nEmpty List!!");
        return;
    }
    current=temp=*head;
    if(position==1)
    {
        while(current->next!=*head)
            current=current->next;
        current->next=(*head)->next;
        (*head)=(*head)->next;
        free(temp);
    }
   // else if(position>Length(*head))
     //   {
       //     printf("\nPosition does not exist!!");
         //   return;
        //}
    else
    {
        while(k<position-1&&current->next!=*head)
        {
            k++;
            current=current->next;
        }

        if(k!=position-1)
            printf("\nPosition does not exist!!");
        else{
        temp=current->next;
        current->next=temp->next;
        free(temp);}
    }
}

int Length(CList *head)
{
    if(head==NULL)
    {
        printf("\nEmpty List!!");
        return -1;
    }
    int count=0;
    CList *current=head;
    do
    {
        current=current->next;
        count++;
    }while(current!=head);
    return count;
}

void Display(CList *head)
{
    CList *current;
    if(head==NULL)
    {
        printf("\nEmpty List!!");
        return;
    }
    current=head;
    printf("\n%d",current->data);
    current=current->next;
    while(current!=head)
    {
        printf("->%d",current->data);
        current=current->next;
    }
}

int main()
{
    int n,val,position;
    CList *head=NULL;
    while(1)
    {
        printf("\n\nPress 1 to Insert: ");
        printf("\nPress 2 to Delete: ");
        printf("\nPress 3 to DISPLAY: ");
        printf("\nPress 4 to Display Size: ");
        printf("\nPress 5 to exit: ");
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
            case 3: Display(head);
                    break;
            case 4: printf("\nList size= %d",Length(head));
                    break;
            case 5: exit(1);
                    break;
            default : printf("\nChoice not detected, Enter again !!");
        }
    }
    return 0;
}
