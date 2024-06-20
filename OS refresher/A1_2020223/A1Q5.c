#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


bool BinarySearch(unsigned int arr[], unsigned int start, unsigned int end, unsigned int target){
    if(start>end){
        return false;
    }

    unsigned int mid = start + (end-start)/2;
    if(arr[mid]==target){
        return true;
    }
    if(arr[mid]>target){
        return BinarySearch(arr,start,mid-1,target);
    }else {
        return BinarySearch(arr,mid+1,end,target);
    }
}

void BubbleSort(unsigned int arr[],int n){
    
    for(int i=0;i<n;i++){
        bool flag = false;
        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                unsigned int temp=  arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = true;
            }
        }

        if(!flag){
            break;
        }
    }
}

int main(){  

    int n;
    scanf("%d", &n);
    unsigned int arr[1000];

    for(int i=0;i<n;i++){
        unsigned int temp;
        scanf("%u", &temp);
        arr[i] = temp;
    }
    unsigned int target;
    scanf("%u", &target);
    
    BubbleSort(arr,n);

    bool isthere = BinarySearch(arr,0,n-1,target);
    printf(isthere ? "true" : "false");
    printf("\n");

    return 0;

}