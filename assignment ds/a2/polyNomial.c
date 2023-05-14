/* Enrollment no: 22/10/JC/010
   polynomial addition
*/
#include<stdio.h>
#include<conio.h>
int main()
{
 int i,sum[20],m,n,A[20],B[20],size;
 printf("Enter polynomial as ordered list\n");
 printf("\nEnter number of element of first list: ");
 scanf("%d",&m);
 printf("\nEnter first polynomial: ");
 for(i=0;i<m;i++)
  scanf("%d",&A[i]);
 printf("\nEnter number of element of second list: ");
 scanf("%d",&n);
 printf("\nEnter first polynomial: ");
 for(i=0;i<n;i++)
  scanf("%d",&B[i]);
 printf("\nFirst polynomial is\n");
 for(i=0;i<n;i++)
 {
  printf("%d",A[i]);
  if(i!=0)
   printf("x^%d",i);
  if(i!=n-1)
   printf("+");
  }
  printf("\nSecond polynomial is\n");
  for(i=0;i<m;i++)
  {
   printf("%d",B[i]);
   if(i!=0)
    printf("x^%d",i);
   if(i!=n-1)
    printf("+");
  }
  for(i=0;i<m;i++)
   sum[i]=A[i];
  for(i=0;i<n;i++)
   sum[i] += B[i];
  size= (m > n)? m:n;
  printf("\nSum of polynomial is\n");
  for(i=0;i<size;i++)
  {
   printf("%d",sum[i]);
   if(i!=0)
    printf("x^%d",i);
   if(i!=size-1)
    printf("+");
  }
  getch();
  return 0;
}