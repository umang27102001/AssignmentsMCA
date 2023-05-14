// Enrollment no: 22/10/JC/010

// Upload your menu driven implementation using C ( .c file ) to perform the following operations on a circular queue of size n (implemented using array) depending on users choice (where the value of n is provided by the user as input)                                                                                   
// 1) Insert an element (provided by the user as input) to the circular 
// queue                                                                                                                                     
// 2) Delete an element from the circular queue and display the deleted element                                                                       
// 3) Display the contents of the circular queue              
// [Note that your implementation should try to consume minimum number of variables/ memory locations]  



#include <stdio.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

void insert(int value) {
    if ((rear + 1) % MAX_SIZE == front) {
        printf("Error: Queue overflow\n");
    } else {
        if (front == -1) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }
        queue[rear] = value;
    }
}

void delete() {
    if (front == -1) {
        printf("Error: Queue underflow\n");
    } else {
        printf("Deleted element: %d\n", queue[front]);
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Error: Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i != rear; i = (i + 1) % MAX_SIZE) {
            printf("%d ", queue[i]);
        }
        printf("%d\n", queue[rear]);
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an element: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}