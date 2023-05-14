// Program to swap values of two variables using pointers.

#include <stdio.h>
#include <math.h>
void swap(int*ptr1,int *ptr2){
    *ptr1=*ptr1+*ptr2;
    *ptr2=*ptr1-*ptr2;
    *ptr1=*ptr1-*ptr2;
}
int main()
{
    int a;
    int b;
    printf("Enter a\n");
    scanf("%d",&a);
    printf("Enter b\n");
    scanf("%d",&b);
    printf("Before: a=%d and b=%d\n",a,b);
    swap(&a,&b);
    printf("After: a=%d and b=%d\n",a,b);
    return 0;
}