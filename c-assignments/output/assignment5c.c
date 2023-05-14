
#include <stdio.h>
#include <stdlib.h>
int main()
{

    int n;
    printf("Enter the month index starting from 1\n");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        printf("January, 31 days\n");
        break;

    case 2:
        printf("Feburary, 28 days\n");
        break;

    case 3:
        printf("March, 31 days\n");
        break;

    case 4:
        printf("April, 30 days\n");
        break;

    case 5:
        printf("May, 31 days\n");
        break;

    case 6:
        printf("June, 30 days\n");
        break;

    case 7:
        printf("July, 31 days\n");
        break;

    case 8:
        printf("August, 31 days\n");
        break;

    case 9:
        printf("September, 30 days\n");
        break;

    case 10:
        printf("October, 31 days\n");
        break;
    case 11:
        printf("November, 30 days\n");
        break;
    case 12:
        printf("December, 31 days\n");
        break;

    default:
    printf("Enter a valid Month index\n");
        break;
    }
    return 0;
}