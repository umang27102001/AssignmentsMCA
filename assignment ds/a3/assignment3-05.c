// Enrollment no: 22/10/JC/010
// Upload your menu driven implementation using C ( .c file ) to perform the following operations on a  queue (non-circular) of size n (implemented using array) depending on users choice (where the value of n is provided by the user as input)                                                                                    
// 1) Insert an element (provided by the user as input) to the queue     
// 2) Delete an element from the queue and display the deleted element    
// 3) Display the contents of the queue  
// [Note that your implementation should try to consume minimum number of variables/ memory  locations] 

#include <stdio.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void insert(int value) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full\n");
        return;
    }

    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        rear++;
    }
    queue[rear] = value;
    printf("Inserted value: %d\n", value);
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }

    printf("Deleted value: %d\n", queue[front]);
    front++;
}

void display() {
    int i;
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are: ");
    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("1. Insert element to queue\n");
        printf("2. Delete element from queue\n");
        printf("3. Display all elements of queue\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter the value to be inserted: ");
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