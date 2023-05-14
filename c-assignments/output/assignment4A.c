#include <stdio.h>
int main()
{
    int a;
    int b;
    printf("Enter a and b\n");
    scanf("%d%d", &a, &b);
    if (a & 1 && b & 1)
    {
        printf("a is odd and b is odd\n");
    }
   else if (!(a & 1) && !(b & 1))
    {
        printf("a is even and and b is even\n");
    }
    else if ((a & 1) || (a % 2 )&& !(b & 1)|| !(b % 2))
    {
        printf("a is odd and b is even");
    }
    else if (!(a & 1) || !(a % 2) && (b & 1) || (b % 2))
    {
        printf("b is odd and a is even");
    }
    else
    {
        printf("Enter again\n");
    }
    return 0;
}