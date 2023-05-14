
#include <stdio.h>
#include <stdlib.h>
int main() {
    int array[3][3];
    int i=0;
    while(i<9){
        printf("Enter the element at (%d,%d)",i/3,i%3);
        scanf("%d",&array[i/3][i%3]);
        i++;
    }
    i=0;
    while(i<9){
        printf("%d ",array[i/3][i%3]);
        if(i>0 && (i+1)%3==0){
            printf("\n");
        }
        i++;
    }
    
    return 0;
}