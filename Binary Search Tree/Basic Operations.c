#include<stdio.h>
#include<stdlib.h>

typedef struct BinarySearchTree{
    int data;
    struct BinarySearchTree *left;
    struct BinarySearchTree *right;
}BST;

BST* findMax(BST* root){
    if(!root){
        printf("\nEmpty Tree!!");
        return NULL;
    }
    while(root->right) root=root->right;
    return root;
}

BST* recursiveInsert(BST* root,int data){
    if(!root){
        root=malloc(sizeof(BST));
        if(!root){
            printf("\nMemory Error!!");
            return NULL;
        }
        root->data=data;
        root->left=root->right=NULL;
    }else{
        if(root->data>data) root->left=recursiveInsert(root->left,data);
        else if(root->data<data)root->right=recursiveInsert(root->right,data);
        else printf("\nElement already present!!");
    }
    return root;
}

void Insert(BST* *root,int data){
    BST *newNode=malloc(sizeof(BST));
    if(!newNode){
        printf("\nMemory Error!!");
        return;
    }
    newNode->data=data;
    newNode->left=newNode->right=NULL;
    if(*root==NULL){
        *root=newNode;
        printf("\nElement Inserted");
        return;
    }
    BST *child=*root,*par=NULL;
    while(child){
        par=child;
        if(child->data==data){
            printf("\nElement already present!!");
            return;
        }
        else if(data>child->data) child=child->right;
        else child=child->left;
    }
    if(par->data<data) par->right=newNode;
    else par->left=newNode;
    printf("\nElement Inserted");
}

BST* recursiveDelete(BST* root,int data){
    if(!root)
        printf("\nElement not found!!");
    else if(data>root->data) root->right=recursiveDelete(root->right,data);
    else if(data<root->data) root->left=recursiveDelete(root->left,data);
    else{
        BST* temp=NULL;
        if(root->left&&root->right){
            temp=findMax(root->left);
            root->data=temp->data;
            root->left=recursiveDelete(root->left,temp->data);
        }else {
            temp=root;
            if(root->left) root=root->left;
            else root=root->right;
            free(temp);
        }
    }
    return root;
}

void Delete(BST **root,int data){
    if(!*root){
        printf("\nEmpty Tree!!");
        return;
    }
    int left=0;
    if((*root)->left) left=1;
    else left=0;
    BST *temp=*root,*par1=NULL,*child=NULL,*par2=NULL;
    while(temp&&temp->data!=data){
        par1=temp;
        if(temp->data>data){
            temp=temp->left;
            left=1;
        }
        else{
            temp=temp->right;
            left=0;
        }
    }
    if(!temp){
        printf("\nElement not there in the tree!!");
        return;
    }
    if(temp->left&&temp->right){
        child=temp->left;
        while(child->right){
            par2=child;
            child=child->right;
        }
        temp->data=child->data;
        if(par2)
            par2->right=child->left;
        else temp->left=NULL;
        free(child);
    }else{
        if(left){
            if(temp==*root) *root=(*root)->left;
            else{
                if(!temp->left)
                    par1->left=temp->right;
                else par1->left=temp->left;
                free(temp);
            }
        }else{
            if(temp==*root) *root=(*root)->right;
            else{
                if(!temp->left)
                    par1->right=temp->right;
                else par1->right=temp->left;
                free(temp);
            }
        }
    }
    printf("\n%d Deleted..",data);
}

void Inorder(BST *root){
    if(root){
        Inorder(root->left);
        printf("%d ",root->data);
        Inorder(root->right);
    }
}

void Preorder(BST* root){
    if(root){
        printf("%d ",root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Postorder(BST* root){
    if(root){
        Postorder(root->left);
        Postorder(root->right);
        printf("%d ",root->data);
    }
}

int main(){
    int data,ch;
    BST *root=NULL;
    while(1){
        printf("\nEnter 1 to insert an element: ");
        printf("\nEnter 2 to delete an element: ");
        printf("\nEnter 3 for preorder traversal of the tree: ");
        printf("\nEnter 4 for inorder traversal of the tree: ");
        printf("\nEnter 5 for postorder traversal of the tree: ");
        printf("\nEnter 6 to exit: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("\nEnter a number to insert: ");
                    scanf("%d",&data);
                    Insert(&root,data);
                    break;
            case 2: printf("\nEnter a number to delete: ");
                    scanf("%d",&data);
                    Delete(&root,data);
                    break;
            case 3: if(!root) printf("\nEmpty Tree!!");
                    else{
                        printf("\nPreorder traversal of the tree=\n ");
                        Preorder(root);
                    }
                    break;
            case 4: if(!root) printf("\nEmpty Tree!!");
                    else{
                        printf("\nInorder traversal of the tree=\n ");
                        Inorder(root);
                    }
                    break;
            case 5: if(!root) printf("\nEmpty Tree!!");
                    else{
                        printf("\nPostorder traversal of the tree=\n ");
                        Postorder(root);
                    }
                    break;
            case 6: exit(0);
                    break;
            default: printf("\nEnter choice not present!!");
        }
    }
    return -123;
}
