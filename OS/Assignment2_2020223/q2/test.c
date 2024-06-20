#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
    int num_rows = 3;
    int num_col = 3;
    float **arr1 = (float **)malloc(sizeof(float *) * num_rows);
    for (int i = 0; i < num_rows; i++){
        arr1[i] = (float *)malloc(num_col * sizeof(float));
    }

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_col; j++) {
            arr1[i][j] = rand()%10+3;
        }
    }

    float **arr2 = (float **)malloc(sizeof(float *) * num_rows);
    for (int i = 0; i < num_rows; i++){
        arr2[i] = (float *)malloc(num_col * sizeof(float));
    }

    long res = syscall(448, arr1, arr2, num_rows, num_col);

    for (int i = 0; i < num_rows; i++){
        for (int j = 0; j < num_col; j++){
            printf("%f ", arr1[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < num_rows; i++){
        for (int j = 0; j < num_col; j++){
            printf("%f ", arr2[i][j]);
        }
        printf("\n");
    }
}