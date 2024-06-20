#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
struct Node {
    int data;
    int height;
    struct Node *left, *right;
};

int max(int x,int y);
int height(struct Node*root);
struct Node* rightRotate(struct Node*root);
struct Node* leftRotate(struct Node* root);
struct Node* balanceit(struct Node*root,int data);
struct Node* insert(struct Node *root, int d);
struct Node* findMin(struct Node* root);
struct Node* delete(struct Node*root,int data);
void inorder(struct Node* root);
void search(struct Node* root, int data);




int max(int x,int y){
    return x>y? x:y;
}

int height(struct Node*root){
    if(root==NULL){
        return 0;
    }
    return root->height;
}

struct Node* rightRotate(struct Node*root){
    struct Node *x = root->left;
    struct Node *temp = x->right;

    x->right = root;
    root->left = temp;

    root->height = max(height(root->left),height(root->right))+1;
    x->height = max(height(x->left),height(x->right))+1;

    return x;
}

struct Node* leftRotate(struct Node* root){
    struct Node *y = root->right;
    struct Node *temp = y->left;

    y->left = root;
    root->right = temp;

    root->height = max(height(root->left),height(root->right))+1;
    y->height = max(height(y->left),height(y->right))+1;

    return y;
}

struct Node* balanceit(struct Node*root,int data){
    int balance = height(root->left)-height(root->right);

    if(abs(balance)<=1){
        return root;
    }

    if(balance>1 && root->left->data<data){
        return rightRotate(root);
    }
    if(balance<-1&&root->right->data<data){
        return leftRotate(root);
    }
    if(balance>1&&data<root->left->data){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance<-1&&data<root->right->data){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;

}

struct Node* insert(struct Node *root, int d){
    
    if(root==NULL){
        struct Node *newnode;
        newnode = malloc(sizeof(struct Node));
        newnode->data = d;
        newnode->left= NULL;
        newnode->right= NULL;
        newnode->height = 1;
        return newnode;
    }

    if(root->data>d){
        root->left = insert(root->left,d);
    }   
    else {
        root->right = insert(root->right,d);
    }

    root->height = 1 + max(height(root->left),height(root->right));
    
    root = balanceit(root,d);

    return root;
}

struct Node* findMin(struct Node* root){
    if(root->left==NULL || root->right ==NULL){
        return root;
    }

    return findMin(root->left);
}

struct Node* delete(struct Node*root,int data){
    if(root==NULL){
        return NULL;
    }
    if(data>root->data){
        root->right = delete(root->right,data);
    }else if(data<root->data){
        root->left = delete(root->left,data);
    } else{
        if(root->left == NULL && root->right==NULL){
            root=NULL;
            return root;
        }else if(root->left==NULL){
            root= root->right;
        }else if(root->right==NULL){
            root= root->left;
        }else {
            struct Node* temp= findMin(root->right);
            root->data=temp->data;
            root->right=delete(root->right, temp->data);
        }
    }
    root->height = max(height(root->left),height(root->right))+1;
    root = balanceit(root,data);

    return root;
}

void inorder(struct Node* root){
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
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
    printf("\n");   
}

int main(){
    int n; //queries
    scanf("%d",&n);
    struct Node *root = NULL;

    
    for (int i = 0; i < n; i++)  {
        printf("press 1 to add, 2 to delete, 3 to search, 4 to find minimum element, 5 to print inorderly:      ");
        int choice;
        scanf("%d", &choice);
        
        if (choice==1)            {
            printf("enter element to be added:      ");
            int ele1;
            scanf("%d", &ele1);
            
            root= insert(root, ele1);
            
        }
        else if (choice==2){
            printf("enter element to be deleted:      ");
                int ele2;
                scanf("%d", &ele2);
                root = delete(root, ele2);
                
        }
        else if(choice==3){
            printf("enter element to search:      ");
                int ele3;
                scanf("%d", &ele3);
                search(root, ele3);
                
        }          
        else if(choice==4){
            printf("%d", findMin(root)->data);
            printf("\n");
        }   
        else if(choice==5){
            inorder(root);
            printf("\n");
        }
        else{
            printf("wrong choice"); 
            exit(0);
        }        
    }
    return 0;
}