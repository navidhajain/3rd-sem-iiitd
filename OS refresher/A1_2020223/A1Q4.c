#include <stdio.h>
#include <stdlib.h>

int length(char arr[]){
    int count = 0;
    while(arr[count]!='\0'){
        count++;
    }
    return count;
}

int main(){
    char arr1[100];
    scanf("%[^\n]s", arr1);
    
    int n = length(arr1)-1;
    
    for(int i=0;i<=n/2;i++){
        char temp = arr1[i];
        arr1[i] = arr1[n-i];
        arr1[n-i] = temp;
    }
    printf("%s\n", arr1);
}