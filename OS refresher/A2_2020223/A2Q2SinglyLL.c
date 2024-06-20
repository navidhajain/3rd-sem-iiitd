#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
    struct Node{
        int rollno;
        int yearofjoin;
        char name[100];
        char branch[100];
        struct Node *next;
        
    };

    struct Node*  add(struct Node *head, int*size, int rollno,int yearofjoin,char name[100],char branch[100]){
        struct Node*newstudent;
        newstudent = (struct Node*)malloc(sizeof(struct Node));
        newstudent->next = NULL;
        newstudent->rollno = rollno;
        newstudent->yearofjoin = yearofjoin;
        strcpy(newstudent->branch, branch);
        strcpy(newstudent->name, name);

        if(head==NULL){
            head = newstudent;           
            size++;
            return head;
        }

        struct Node *temp = head;

        while(temp->next!=NULL){
            temp = temp->next;
        }

        temp->next = newstudent;
        return head;
    } 

    void print(struct Node*head){
        struct Node*temp = head;
        while(temp!=NULL){
           
            printf("Roll number and branch of joining: %d,  %d\n",temp->rollno,temp->yearofjoin);
            printf("Name: %s", temp->name);
            printf("Branch: %s\n", temp->branch);

            temp = temp->next;
        }
    }

    bool Search(struct Node* head, int rno){
        struct Node* current = head;  
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

    struct Node*head = NULL;
    int *size = 0;
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
            
            head = add(head, size, rollno, yojoin, name, branch);
        }
        else if(x==2){
            printf("enter roll number");
            int rno;
            scanf("%d", &rno);
            if (Search(head, rno))
            {
                printf("exists");
            }else{
                printf("does not exist");
            }
            
        }
        else if(x==3){
            print(head);
        }
        else{
            printf("wrong input");
            break;
        }   
    }
        
    return 0;
}

