#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
void PUSH(int *s,int *t,int val);
int POP(int *s,int *t);
void DISP(int *s,int *t);

int main()
{
    int stack[SIZE],top=-1,n,val;
    while(1)
    {
        printf("\n\nPress 1 to PUSH: ");
        printf("\nPress 2 to POP: ");
        printf("\nPress 3 to DISPLAY: ");
        printf("\nPress 4 to exit: ");
        scanf("%d",&n);
        switch(n)
        {
            case 1: printf("\nEnter the value to push into the stack: ");
                    scanf("%d",&val);
                    PUSH(stack,&top,val);
                    break;
            case 2: val = POP(stack,&top);
                    printf("\n%d Deleted!!",val);
                    break;
            case 3: DISP(stack,&top);
                    break;
            case 4: exit(1);
                    break;
            default : printf("\nChoice not detected, Enter again !!");
        }
    }
    return 0;
}

void PUSH(int *s,int *t,int val)
{
    if(*t==SIZE-1)
        printf("\nSTACK IS FULL !!");
    else
      {
          s[++(*t)]=val;
          printf("\nValue successfully PUSHED into the stack");
      }
}

int POP(int *s,int *t)
{
    int val;
    if(*t==-1)
        printf("\nSTACK IS EMPTY !!");
    else
    {
        val=s[(*t)--];
        return val;
    }
}

void DISP(int *s,int *t)
{
    int i;
    if(*t==-1)
        printf("\nEMPTY STACK.");
    else
    {
        for(i=*t;i>=0;i--)
            printf("\n\t|%d|",s[i]);
        printf("\n\t|---------|");
    }

}

















