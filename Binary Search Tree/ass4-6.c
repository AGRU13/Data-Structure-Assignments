#include<stdio.h>
#include<stdlib.h>

#define SIZE 50
typedef struct BinaryTree{
    int data;
    struct BinaryTree* left;
    struct BinaryTree* right;
    struct BinaryTree* next;
}Tree;

typedef struct Queue{
    Tree **node;
    int capacity;
    int front,rear;
}Q;

Q* CreateQueue(){
    Q* q=malloc(sizeof(Q));
    if(!q){
        printf("\nMemory Error!!");
        return;
    }
    q->front=q->rear=-1;
    q->capacity=SIZE;
    q->node=malloc(q->capacity*sizeof(Tree));
    if(!q->node){
        printf("\nMemory Error!!");
        return;
    }
    return q;
}

IsFullQueue(Q *q){
    return (q->rear+1)%q->capacity==q->front;
}

IsEmptyQueue(Q *){
    return q->front==-1;
}

void Enqueue(Q *q,Tree node){
    if(IsFullQueue){
        printf("Queue OverFlow!!")
        return;
    }
    q->rear=(q->rear+1)%q->capacity;
    q->node[q->rear]=node;
    if(q->front==-1)
        q->front=q->rear;
}

Tree* Dequeue(q *q){
    if(IsEmptyQueue){
        printf("\nEmpty Queue!!");
        return;
    }
    Tree *node=q->node[front];
    if(q->front==q->rear)
        q->front=q->rear=-1;
    else q->front=(q->front+1)%q->capacity;
}
