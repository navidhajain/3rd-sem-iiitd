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

    void push(int rollno,int Yoj,char name[100],char branch[100]){
        struct Node*newstud;
        newstud = (struct Node*)malloc(sizeof(struct Node));
        newstud->next = NULL;
        newstud->rollno = rollno;
        newstud->Yoj = Yoj;
        strcpy(newstud->branch,branch);
        strcpy(newstud->name,name);

        extern  struct Node *head;
        extern struct Node*tail;

        if(head==NULL){
            head = newstud;
            tail = newstud;
           
            size++;
            struct Node * arr[2];
           
            return ;
        }

        tail->next = newstud;
        tail->next->prev = tail;
        tail = tail->next;
            
        
    } 

    bool isEmpty(){
        if(head==NULL){
            return true;
        }

        return false;
    }

    void pop(){
        if(head==tail){
            head = NULL;
            tail = NULL;
            return;
        }

        tail = tail->prev;
        tail->next = NULL;

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
            
            push(rollno, yojoin, name, branch);
        }
        else if(x==2){
            pop();
            
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

