// Enrollment no: 22/10/JC/010

// Upload your menu driven implementation using C ( .c file ) to perform the following operations on a stack of size n (implemented using array) depending on users choice (where the value of n is provided by the user as         input)                                                                                                    
// 1) Push k number of elements provided by the user as input to the stack (where the value of k is provided by the user as input)                                                                                                                                    2) Pop an element from the stack and print the popped (deleted) element                                                                                                                                   3) Display the contents of the stack  

// [Note that your implementation should try to consume minimum number of variables/ memory locations] 


#include <stdio.h>
#include <stdlib.h>

int top = -1, n;
int stack[100];

void push();
void pop();
void display();

int main() {
    int choice;
    printf("Enter the size of the stack: ");
    scanf("%d", &n);
    while (1) {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

void push() {
    int item;
    if (top == n - 1) {
        printf("Stack overflow.\n");
    } else {
        printf("Enter the item to be pushed: ");
        scanf("%d", &item);
        top++;
        stack[top] = item;
    }
}

void pop() {
    int deleted_item;
    if (top == -1) {
        printf("Stack underflow.\n");
    } else {
        deleted_item = stack[top];
        top--;
        printf("The deleted item is %d\n", deleted_item);
    }
}

void display() {
    int i;
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("The contents of the stack are: \n");
        for (i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}
