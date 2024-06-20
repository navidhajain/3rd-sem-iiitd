#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


    struct Node*head = NULL;
    struct Node*tail = NULL;
    int *size = 0;
    
    
    struct Node{
        int rollno;
        int Yoj;
        char name[100];
        char branch[100];

        struct Node *next;
        struct Node*prev;
        
    };

    void enqueue(int rollno,int Yoj,char name[100],char branch[100]){
        struct Node*toAdd;
        toAdd = (struct Node*)malloc(sizeof(struct Node));
        toAdd->next = NULL;
        toAdd->rollno = rollno;
        toAdd->Yoj = Yoj;
        strcpy(toAdd->branch,branch);
        strcpy(toAdd->name,name);

        extern  struct Node *head;
        extern struct Node*tail;

        if(head==NULL){
            head = toAdd;
            tail = toAdd;
           
            size++;
            struct Node * arr[2];
           
            return ;
        }

        tail->next = toAdd;
        tail->next->prev = tail;
        tail = tail->next;
            
        
    } 

    bool isEmpty(){
        if(head==NULL){
            return true;
        }

        return false;
    }

    void dequeue(){
        if(head==tail){
            head = NULL;
            tail = NULL;
            return;
        }

        head = head->next;

    }


    void Print(){
        extern struct Node*head;
        extern struct Node*tail;
        struct Node*ptr = head;
        while(ptr!=NULL){
           
            printf("%d %d %s %s\n",ptr->rollno,ptr->Yoj,ptr->name,ptr->branch);
            ptr = ptr->next;
        }
    }



int main(){
    int n; //queries
    scanf("%d",&n);

    struct Node*head = NULL;
    int *size = 0;
    printf("press 1 to add, 2 to delete, 3 to print");

    for(int i=0;i<n;i++){
        int x;
        scanf("%d", &x);
        if (x==1){            
            printf("enter roll no ");
            int rollno;
            int yojoin;
            scanf("%d", &rollno);

            printf("enter year of joining");
            scanf("%d", &yojoin);            

            printf("enter branch");
            char branch[100];
            scanf("%s",branch);
            getchar();

            printf("enter name ");
            char name[100];
            fgets(name, sizeof(name), stdin);
            // scanf("%s", name);
            
            enqueue(rollno,yojoin,name,branch);
        }
        else if(x==2){
            dequeue();
            
        }
        else if(x==3){
            Print();
        }
        else{
            printf("wrong input\n");
            break;
        }   
    }
        
    return 0;
    
}

