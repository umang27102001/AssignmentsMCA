/* Enrollment no: 22/10/JC/010
Upload your implementation using C ( .c file ) to  store a list of 10 elements taken as input from the user and display the nth element of the list (where the value of n is taken as input from the user).
*/
#include <stdio.h>
int main()
{
    int array[10];
    int select;
    int element, setIndex, exit, getIndex;
    do
    {
        printf("\nEnter 1 to Insert element\n");
        printf("Enter 2 to Display Element\n");
        printf("Enter 3 to Exit\n");
        scanf("%d", &select);
        switch (select)
        {
        case 1:
            printf("\nEnter the index and Element\n");
            scanf("%d %d",&setIndex ,&element);
            array[setIndex] = element;
            break;
        case 2:
            printf("\nEnter the index to get Element\n");
            scanf("%d",&getIndex);
            printf("%d\n", array[getIndex]);
            break;
        default:
            break;
        }
    } while (select!=3);

    return 0;
}