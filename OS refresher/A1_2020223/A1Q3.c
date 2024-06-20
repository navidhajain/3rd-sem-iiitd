#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(){   
    int a1;
    scanf("%d",&a1);

    int a2;
    scanf("%d",&a2);

    int temp = a1;
    a1 = a2;
    a2 = temp;   

    printf("after swap first variable has: %d\n", a1);
    printf("after swap second variable has: %d\n", a2);

    int n;
    scanf("%d",&n);

    int arr1[n];
    int arr2[n];

    for(int j = 0; j < n; j++)    {
        int input;
        scanf("%d", &arr1[j]);
    }

    for(int j = 0; j < n; j++)    {
        int input;
        scanf("%d", &arr2[j]);
    }


    for(int i=0;i<n;i++){
        int temp = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = temp;
    }

    printf("array 1: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    printf("array 2: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\n");
}