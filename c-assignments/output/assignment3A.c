#include <stdio.h>
#include <math.h>
int main()
{
    printf("Printable characters with their ASCII number\n");
    for (int i = 32; i < 128; i++)
    {
        printf("%c %d\n",i,i);
    }
    
    return 0;
}