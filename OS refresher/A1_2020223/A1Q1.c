#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv){    
    FILE *ip;
    FILE *op; 

    ip = fopen(argv[1],"r");
    op = fopen(argv[2],"w");

    char x;    
    while (1==fread(&x, 1, 1,ip)){
        fwrite(&x,1,1,op);
    }    
    return 0;
}