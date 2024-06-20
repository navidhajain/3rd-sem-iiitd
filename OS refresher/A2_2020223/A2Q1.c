#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main(){
    //PART A

    int n;
    scanf("%d",&n);
    int* arr[n];
    
    for(int i=0;i<n;i++){
        int temp1;
        scanf("%d", &temp1);
        arr[i] = malloc(sizeof(int)*temp1);
        for(int j=0;j<temp1;j++){            
            (arr[i][j]) = rand()%10;
            printf("%d ", (arr[i][j]));
        }
        printf("\n");
    }

    //B PART
    //changing the number of columns in each row with initial values restored
    
    for(int i=0;i<n;i++){
        int temp2;
        scanf("%d",&temp2);
        arr[i] = realloc(arr[i],sizeof(int)*temp2);
        for(int j=0;j<temp2;j++){            
            (arr[i][j]) = rand()%10;
            printf("%d ", (arr[i][j]));
        }
        printf("\n");
    }
}