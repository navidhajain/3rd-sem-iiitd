#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* insert(struct Node *root,int d){
    if(root==NULL){
        
        struct Node *newnode = malloc(sizeof(struct Node));
        newnode->data = d;
        
        newnode->left= NULL;
        
        newnode->right= NULL;
        return newnode;
    }
    
    if(root->data > d){
        
        root->left = insert(root->left,d);
    }else {
        
        root->right = insert(root->right, d);
    }

    return root;
}

int findMin(struct Node* root){
    if(root->left==NULL){
        return root->data;
    }
    return findMin(root->left);
}

void search(struct Node* root, int data){
    if (root==NULL){
        printf("does not exist");
    }
    else if(root->data==data){
        printf("does exist");
    }
    else{
        if (root->data > data){
            search(root->left, data);
        }else{
            search(root->right, data);
        }
    }    
}

struct Node* delete(struct Node*root, int data){
    if(root==NULL){
        return NULL;
    }

    if(data > root->data){
        root->right = delete(root->right,data); 
    }else if(data < root->data){
        root->left = delete(root->left, data);
    }else{
        if(root->left==NULL){
            return root->right;
        }        
        else if(root->right==NULL){
            return root->left;
        }
        else {
            int min;
            min = findMin(root->right);
            root->data = min;
            root->right = delete(root->right, min);
            data = min;
        }
    } 
    return root;
}

void inorder(struct Node* root){
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main(){
    int n; //queries
    scanf("%d",&n);
    struct Node* root = NULL;

    printf("press 1 to add, 2 to delete, 3 to search, 4 to find minimum element, 5 to print inorderly:      ");
    for (int i = 0; i < n; i++)
    {
        int choice;
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("enter element to be added:      ");
                    int ele1;
                    scanf("%d", &ele1);
                    root= insert(root, ele1);
                    break;
            case 2: printf("enter element to be deleted:      ");
                    int ele2;
                    scanf("%d", &ele2);
                    root = delete(root, ele2);
                    break;
            case 3: printf("enter element to search:      ");
                    int ele3;
                    scanf("%d", &ele3);
                    search(root, ele3);
                    break;
            case 4: printf("%d", findMin(root)); 
                    break;
            case 5: inorder(root);
                    break;  
            default: printf("wrong choice\n"); 
                    exit(0); 
        }
        continue;
    }
    return 0;
    
}