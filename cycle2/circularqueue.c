#include <stdio.h>

#define MAX_SIZE 100

int circularQueue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if ((rear + 1) % MAX_SIZE == front) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % MAX_SIZE;
    circularQueue[rear] = value;
}

void dequeue() {
    if (front == -1) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    printf("Dequeued element: %d\n", circularQueue[front]);

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX_SIZE;
}

void displayFrontRear() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Front element: %d\n", circularQueue[front]);
    printf("Rear element: %d\n", circularQueue[rear]);
}

int main() {
    int choice, value;

    do {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Front & Rear\n");
        printf("4. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                displayFrontRear();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
