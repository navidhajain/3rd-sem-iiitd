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

    void add(int rollno,int Yoj,char name[100],char branch[100]){
        struct Node*newstudent;
        newstudent = (struct Node*)malloc(sizeof(struct Node));
        newstudent->next = NULL;
        newstudent->rollno = rollno;
        newstudent->Yoj = Yoj;
        strcpy(newstudent->branch,branch);
        strcpy(newstudent->name,name);

        extern struct Node *head;
        extern struct Node*tail;

        if(head==NULL){
            head = newstudent;
            tail = newstudent;
           
            size++;
            struct Node * arr[2];
           
            return ;
        }

        tail->next = newstudent;
        tail->next->prev = tail;
        tail = tail->next;        
    } 

    void Print(){
        extern struct Node*head;
        extern struct Node*tail;
        struct Node*ptr = head;
        while(ptr!=NULL){
           
            printf("Roll number and branch of joining: %d,  %d\n",ptr->rollno,ptr->Yoj);
            printf("Name: %s", ptr->name);
            printf("Branch: %s\n", ptr->branch);            
            ptr = ptr->next;
        }
    }

    bool Search(int rno){
        extern struct Node*head;
        struct Node* current= head;  
        while (current != NULL)
        {
            if (current->rollno == rno)
                return true;

            current = current->next;
        }
        return false;
    }

int main(){
    int n; //queries
    scanf("%d",&n);

    printf("press 1 to add, 2 to search, 3 to print");

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
            
            add(rollno, yojoin, name, branch);
        }
        else if(x==2){
            printf("enter roll number");
            int rno;
            scanf("%d", &rno);
            if (Search(rno))
            {
                printf("exists");
            }else{
                printf("does not exist");
            }
            
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

