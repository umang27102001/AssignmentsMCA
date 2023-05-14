/* Enrollment no: 22/10/JC/010
Upload your menu driven implementation using C ( .c file ) to store a list of 20 elements (taken as input from the user) and perform any of the following task depending upon the user's choice:-      
i) Take an element from the user as input and insert it at the nth location of the list (where the value of n is taken as input from the user).
ii) Take the value of n from the user as input and delete the nth element of the list.
iii) Take an element from the user as input and search the list. If the element is found in the list then its location in the list is displayed else it displays "Element not found".
*/
#include <stdio.h>
#include <stdlib.h>
struct Array
{
    int *A;
    int size;
    int length;
};
void Display(struct Array arr)
{
    int i;
    printf("\nElements are\n");
    for (i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
}
void Insert(struct Array *arr, int index, int x)
{
    int i;
    if (index >= 0 && index <= arr->length)
    {
        for (i = arr->length; i > index; i--)
            arr->A[i] = arr->A[i - 1];
        arr->A[index] = x;
        arr->length++;
    }
}
int Delete(struct Array *arr, int index)
{
    int x = 0;
    int i;

    if (index >= 0 && index < arr->length)
    {
        x = arr->A[index];
        for (i = index; i < arr->length - 1; i++)
            arr->A[i] = arr->A[i + 1];
        arr->length--;
        return x;
    }

    return 0;
}
int main()
{
    struct Array arr1;
    int ch;
    int x, index;
    printf("Enter Size of Array\n");
    scanf("%d", &arr1.size);
    arr1.A = (int *)malloc(arr1.size * sizeof(int));
    arr1.length = 0;
    do
    {
        printf("\n\nMenu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4.Exit\n");
        printf("enter you choice ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter an element and index\n");
            scanf("%d%d", &x, &index);
            Insert(&arr1, index, x);
            break;
        case 2:
            printf("Enter index ");
            scanf("%d", &index);
            x = Delete(&arr1, index);
            printf("Deleted Element is %d\n", x);
            break;
        case 3:
            Display(arr1);
        }
    } while (ch < 6);
    return 0;
}