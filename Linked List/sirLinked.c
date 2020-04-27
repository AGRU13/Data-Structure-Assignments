#include<stdio.h>
#include<stdlib.h>

typedef struct Linkedlist
{
    int data;
    struct Linkedlist *next;
}LL;

void CREATE(LL **H);
void DISPLAY(LL *H);
void INSAFT(LL *H);
void INSBEF(LL *H);

int main(void)
{
    int n;
    LL *Head=NULL;
    while(1)
    {
        printf(" CREATE Press 1:\n");
        printf(" INSERT AFTER Press 2:\n");
        printf(" INSERT BEFORE Press 3:\n");
        printf(" DISPLAY Press 4:\n");
        printf(" EXIT Press 5:\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1: CREATE(&Head);
                    break;
            case 2: INSAFT(Head);
                     break;
           case 3: INSBEF(Head);
                    break;
            case 4: DISPLAY(Head);
                     break;
            case 5: exit(0);
                     break;
        }
    }
    return 0;
}

void CREATE(LL **H)
{
    LL *current;
    if(*H==NULL)
    {
        *H=(LL*)malloc(sizeof(LL));
        printf("Enter a data: \n");
        scanf("%d",&((*H)->data));
        (*H)->next=NULL;
    }
    else
    {
        current=*H;
        while(current->next!=NULL)
            current=current->next;

        current->next=(LL*)malloc(sizeof(LL));
        printf("Enter a data: ");
        scanf("%d",&(current->next->data));
        current->next->next=NULL;
    }
}

void INSAFT(LL *H)
{
   LL *current,*temp;
   int target,value;
   if(H==NULL)
   {
       printf("No Link list\n");
   }
   else
   {
       printf("Give your target node value: ");
       scanf("%d",&target);
       printf("Give your node value: ");
       scanf("%d",&value);
       while(H!=NULL)
       {
           if(H->data==target)
           {
               printf("target found");
               break;
           }
           else
            H=H->next;
       }
       if(H==NULL)
       {
           printf("No data in link list\n");
           return;
       }
       temp=(LL*)malloc(sizeof(LL));
       temp->data=value;
       temp->next=H->next;
       H->next=temp;
   }
}

void INSBEF(LL *H)
{

    LL *temp,*ptr=H,*preptr;
    int item,target;
   if(H==NULL)
   {
       printf("No Link list\n");
   }
   else
   {
       printf("Give your target node value: ");
       scanf("%d",&target);
       printf("Give your node value: ");
       scanf("%d",&item);
       while(ptr!=NULL)
       {
           if(ptr->data==target)
           {
               printf("target found");
               break;
           }
           else
            ptr=ptr->next;
       }
     if(ptr==NULL)
       {
           printf("No data in link list\n");
           return;
       }
    temp=malloc(sizeof(LL));
    if (!temp)
    {
        printf("Error");
        return;

    }
    temp->data=item;
    ptr=H;
    preptr=H;
    while(ptr->data!=target)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=temp;
    temp->next=ptr;
}
}

void DISPLAY(LL *H)
{
    if(H==NULL)
        printf("Head[%p]---->NULL",H);
    else
    {
         printf("Head[%p]----> ",H);
         while(H!=NULL)
         {
              printf("[%d][%p]----> ",H->data,H->next);
              H=H->next;
         }
         printf("NULL\n");
    }
}

