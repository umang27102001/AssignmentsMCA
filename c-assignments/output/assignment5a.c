
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    printf("Enter a number\n");
    scanf("%d", &n);
    for (int i = 1; i < 11; i++)
    {
        printf("%d X %d = %d\n", n, i, n * i);
    }
    printf("Enter a number\n");
    scanf("%d", &n);
    int i = 0;
    while (i < n)
    {
        int j = 0;
        while (j <= i)
        {
            printf("%d ", j + 1);
            j++;
        }
        i++;
        printf("\n");
    }
    printf("Enter a number\n");
    scanf("%d", &n);
    i = 0;
    do
    {
        int j = 0;
        do
        {
            printf("*");
            j++;
        } while (j <= i);
        printf("\n");
        i++;
    } while (i < n);
    return 0;
}