#include <stdio.h>
#include <math.h>
int main()
{
    int age;
    printf("Enter age\n");
    scanf("%d", &age);
    if (age < 18)
    {
        if (age < 0)
        {
            printf("Enter a valid age\n");
        }
        else
        {
            printf("You are not eligible for Driving License\n");
        }
    }

    else if (age >= 18)
    {
        if (age < 60)
        {
            printf("Congratulations!! You are eligible for Driving License\n");
        }
        else
        {
            printf("You are not eligible for Driving License\n");
        }
    }
    else
    {
        printf("Enter valid Age\n");
    }
    switch (age)
    {
    case 10:
        printf("Age is 10 so not eligible for Driving license\n");
        break;
    case 15:
        printf("Age is 15 so not eligible for Driving license\n");
        break;

    case 20:
        printf("Age is 20 so eligible for Driving license\n");
        break;

    default:
        printf("Enter a valid age\n");
        break;
    }

    return 0;
}