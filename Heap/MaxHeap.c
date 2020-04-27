#include<stdio.h>
#include<stdlib.h>

typedef struct Heap{
    int *arr;
    int count;
    int capacity;
}Heap;

Heap *CreateHeap(int capacity){
    Heap *h=malloc(sizeof(Heap));
    if(!h){
        printf("\nMemory Error!!");
        return NULL;
    }
    h->capacity=capacity;
    h->cout=0;
    h->arr=malloc(sizeof(capacity*int));
    if(!arr){
        printf("\nMemory Error!!");
        return NULL:
    }
    return h;
}

int Parent(Heap *h,int i){
    if(i<=0||i>=h->count)
        return -1;
    return (i-1)/2;
}

int LeftChild(Heap *h,int i){
    int pos=2*i+1;
    if(i<0||pos>=h->count) return -1;
    return pos;
}

int RightChild(Heap *h,int i){
    int pos=2*i+2;
    if(i<0||pos>=h->count) return -1;
    return pos;
}

void PercolateDown(Heap *h,int i){
    if(h==NULL)
        return;
    int left,right,max;
    left=LeftChild(h,i);
    right=RightChild(h,i);
    max=i;
    if(left!=-1&&h->arr[left]>h->arr[i])
        max=left;
    if(right!=-1&&h->arr[right]>max)
        max=right;
    if(max!=i){
        int temp=h->arr[i];
        h->arr[i]=h->arr[max];
        h->arr[max]=temp;
        PercolateDown(h,max);
    }
}

int Delete(Heap *h){
    if(h==NULL)
        return -2;
    if(h->count==0){
        printf("\nEmpty Heap!!");
        return -1;
    }
    int data;
    data=h->arr[0];
    h->arr[0]=h->arr[h->count-1];
    h->count--;
    PercolateDown(h,0);
    return 0;
}

void Insert(Heap *h,int data){
    if(h==NULL)
        return;
    if(h->count==h->capacity)
        ResizeHeap(h);
    h->count++;
    i=h->count-1;
    while(i>0&&data>h->arr[(i-1)/2]){
        h->arr[i]=h->arr[(i-1)/2];
        i=(i-1)/2;
    }
    h->arr[i]=data;
}

void ResizeHeap(Heap *h){
    int *arrray_old=h,i;
    h->capacity*=2;
    h->array=malloc(sizeof(h->capacity*int));
    if(!h){
        printf("\nMemory Error!!");
        return;
    }
    for(i=0;i<h->count;i++)
        h->arr[i]=arrray_old[i];
    free(arrray_old);
}

void BuildHeap(Heap *h,int a[],int n){
    if(h==NULL)
        return;
    while(n>h->capacity)
        ResizeHeap(h);
    h->count=n;
    int i;
    for(i=0;i<n;i++)
        h->arr[i]=a[i];
    for(i=(n-2)/2;i>=0;i--)
        PercolateDown(h,i);
}

void HeapSort(Heap *h){
    if(h==NULL)
        return;
    if(h->count==0){
        printf("\nEmpty Heap!!");
        return;
    }
    int i,temp,old_size=h->count;
    for(i=0;i<h->count-1;i++){
        temp=h->arr[0];
        h->arr[0]=h->arr[h->count-1];
        h->arr[h->count-1]=temp;
        h->count--;
        PercolateDown(h,0);
    }
   printf("\nDeletion of all the elements from the heap gives =\n");
   for(i=0,i<old_size;i++)
        printf("%d",h->arr[i]);
    h->count=0;
}

int main(){
    int n,data;
    Heap *h=CreateHeap(100);
    while(1){
        printf("\nEnter 1 to Enter an element into the Maxheap: ");
        printf("\nEnter 2 to Delete the maximum element: ");
        printf("\nEnter 3 to get the maximum element: ");
        printf("\nEnter 4 to buil heap from an array: ");
        printf("\nEnter 5 to delete all elements from the heap(HeapSort): ");
        printf("\nEnter 6 to exit: ");
    }
}
