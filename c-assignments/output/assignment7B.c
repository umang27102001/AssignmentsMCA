// Program to Dynamically allocate and free memory.
#include <stdio.h>
#include <stdlib.h>
int main() {

    int n;
    printf("Enter the number of elements\n");
    scanf("%d",&n);

    //Allocate Memory in Heap using malloc function.

    int *ptr=(int*)malloc(n*sizeof(int));
    printf("Enter The Elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&ptr[i]);
    }

    //Print Elements.
    
    for (int i = 0; i < n; i++)
    {
        printf("%d ",ptr[i]);
    }

    // Free the memory usinf free().

    free(ptr);
    ptr=NULL;
    return 0;
}