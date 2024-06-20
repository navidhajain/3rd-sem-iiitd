#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void SelectionSort(int arr[],int n){
    for(int i=0;i<n;i++){
        int min = arr[i];
        int minind = i;
        for(int j=i+1;j<n;j++){
            if(min>arr[j]){
                min = arr[j];
                minind = j;
            }
        }

        if(min<arr[i]){
            int temp = arr[minind];
            arr[minind] = arr[i];
            arr[i] = temp;
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

}

void BubbleSort(int arr[],int n){    
    for(int i=0;i<n;i++){
        bool flag = false;
        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=  arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = true;
            }
        }

        if(!flag){
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
}

void bubsort(){
    int n;
    scanf("%d",&n);
    int arr[n];

    for(int i=0;i<n;i++){
        int temp;
        scanf("%d",&temp);
        arr[i] = temp;   
    }

    BubbleSort(arr, n);

}

void selsort(){
    int n;
    scanf("%d",&n);
    int arr[n];

    for(int i=0;i<n;i++){
        int temp;
        scanf("%d",&temp);
        arr[i] = temp;   
    }

    SelectionSort(arr,n);
}

int main(){
   printf("press 1 for selections sort and 2 for bubble sort");
   int choice;
   scanf("%d", &choice); 
   if (choice==2)
   {
      bubsort();
   }
   else if(choice==1){
       selsort();
   }
   else{
       printf("wrong input");
       exit(0);
   }
           
}