#include<stdio.h>
#include<stdlib.h>

typedef struct MinHeapNode{
    char ch;
    int freq;
    struct MinHeapNode *left, *right;
}Node;

typedef struct MinHeap{
    int capacity;
    int count;
    struct MinHeapNode **arr;
}Heap;

Node *CreateNode(char ch,int f){
    Node *newNode=malloc(sizeof(Node));
    if(!newNode){
        printf("\nMemory Error!!");
        exit(0);
    }
    newNode->left=newNode->right=NULL;
    newNode->ch=ch;
    newNode->freq=f;
    return newNode;
}

Heap* CreateHeap(int capacity){
    Heap *h=malloc(sizeof(Heap));
    if(!h){
        printf("\nMemory Error!!");
        return NULL;
    }
    h->count=0;
    h->capacity=capacity;
    h->arr=malloc(h->capacity*sizeof(Node));
    if(!h->arr){
        printf("\nMemory Error!!");
        return NULL;
    }
    return h;
}

void PercolateDown(Heap *h,int i){
    int left,right,min;
    left=2*i+1;
    right=2*i+2;
    min=i;
    if(left<h->count&&h->arr[left]->freq<h->arr[i]->freq)
        min=left;
    if(right<h->count&&h->arr[right]->freq<h->arr[min]->freq)
        min=right;
    if(min!=i){
        Node *temp=h->arr[i];
        h->arr[i]=h->arr[min];
        h->arr[min]=temp;
        PercolateDown(h,min);
    }
}

Node* Delete(Heap *h){
    Node *temp=h->arr[0];
    h->arr[0]=h->arr[h->count-1];
    h->count--;
    PercolateDown(h,0);
    return temp;
}

void Insert(Heap *h,Node *node){
    h->count++;
    int i=h->count-1;
    while(i>0&&node->freq<h->arr[(i-1)/2]->freq){
        h->arr[i]=h->arr[(i-1)/2];
        i=(i-1)/2;
    }
    h->arr[i]=node;
}

Heap* BuildHeap(char ch[],int f[],int n){
    Heap *h=CreateHeap(n);
    int i;
    h->count=n;
    for(i=0;i<n;i++)
        h->arr[i]=CreateNode(ch[i],f[i]);
    for(i=(n-2)/2;i>=0;i--)
        PercolateDown(h,i);
    return h;
}

void PrintCodes(Node *node,int a[],int top){
    if(node->left){
        a[top]=0;
        PrintCodes(node->left,a,top+1);
    }
    if(node->right){
        a[top]=1;
        PrintCodes(node->right,a,top+1);
    }
    if(!node->left&&!node->right){
        int i;
        printf("\n%c = ",node->ch);
        for(i=0;i<top;i++)
            printf("%d",a[i]);
    }
}

void Inorder(Node *node){
    if(node){
        Inorder(node->left);
        printf("%d ",node->freq);
        Inorder(node->right);
    }
}

void HuffmanCodes(char ch[],int f[],int n){
    Heap *h=BuildHeap(ch,f,n);
    Node *left,*right,*top;
    while(h->count!=1){
        left=Delete(h);
        right=Delete(h);
        top=CreateNode('$',left->freq+right->freq);
        top->left=left;
        top->right=right;
        Insert(h,top);
    }
    top=Delete(h);
    Inorder(top);
    int arr[100];
    PrintCodes(top,arr,0);
}

int main(){
    int n,i;
    printf("\nEnter the number of charcters for huffman encoding: ");
    scanf("%d",&n);
    char ch[n];
    int f[n];
    printf("\nEnter the characters and their corresponding frequency: ");
    for(i=0;i<n;i++){
        getchar();
        scanf("%c",&ch[i]);
        scanf("%d",&f[i]);
    }
    printf("\nPress a Enter to get the huffman codes: ");
    getchar();
    HuffmanCodes(ch,f,n);
    return 0;
}
