#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void add(int a,int b){
    printf("Sum: %d\n",a+b);
}

void subtract(int a,int b){
    printf("Difference: %d\n",a-b);

}

void multiply(int a,int b){
    printf("Product: %d\n",a*b);

}

void division(int a,int b){
    float num1 = a;
    float num2 = b ;
    float f = num1/num2;
    printf("Quotient: %f\n",f);

}

void exponent(int a,int b){
    int ans = 1;
    for(int i=0;i<b;i++){
        ans *= a;
    }

    printf("Value of a raised to the power b is  : %d\n",ans);


}

int main(){
    void (*arr[5])(int,int);

    arr[0] = add;
    arr[1] = subtract;
    arr[2] = multiply;
    arr[3] = division;
    arr[4] = exponent;
    printf("number of queries: ");
    int q,a,b;
    scanf("%d",&q);
    for (int i = 0; i < q; i++)
    {
        printf("press 1 to add, 2 to subtract, 3 to multiply, 4 to divide, 5 for exponentiation:  ");
        int n;
        scanf("%d", &n);
        printf("enter 2 values: ");
        scanf("%d %d", &a,&b);

        if(n==1){
        (arr[0])(a,b); 
        }else if(n==2){
            (arr[1](a,b));
        }else if(n==3){
            (arr[2](a,b));
        }else if(n==4){
            (arr[3](a,b));
        }else if(n==5){
            (arr[4](a,b));
        }
        else
        {printf("wrong choice\n");
        break;}
    }

    return 0;

}