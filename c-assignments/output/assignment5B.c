#include <stdio.h>
#include <math.h>
int main()
{
for (int i = 0; i < 6; i++)
{
    for (int j = 1; j < 6-i; j++)
    {
        printf(" ");
    }
    
    for (int j = 0; j <=i ; j++)
    {
        printf("%d ",j+1);
    }
    
    printf("\n");
}
for (int i = 0; i < 5; i++)
{
    for (int j = 0; j <= i; j++)
    {
        printf(" ");
    }
    
    for (int j = 0; j < 5-i; j++)
    {
       printf("%d ",j+1);
    }
    
    printf("\n");
}

    return 0;
}