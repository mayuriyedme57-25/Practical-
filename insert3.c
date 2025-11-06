#include <stdio.h>
#include <stdlib.h>
#define MAX 5

char queue[MAX];
int front = -1, rear = -1;

void insert();
void delete();
void display();

int main() {
    int choice;

    while (1) {
        printf("\n\n----- QUEUE MENU -----\n");
        printf("1. Insert an Element (Enqueue)\n");
        printf("2. Delete an Element (Dequeue)\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

void insert() {
    char element;
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot insert element.\n");
        return;
    }
    printf("Enter character to insert: ");
    scanf(" %c", &element);

    if (front == -1) // first insertion
        front = 0;

    rear++;
    queue[rear] = element;
    printf("Inserted '%c' into queue.\n", element);
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! No elements to delete.\n");
        return;
    }
    printf("Deleted element: '%c'\n", queue[front]);
    front++;

    // Reset if queue becomes empty
    if (front > rear)
        front = rear = -1;
}

void display() {
    if (front == -1)
        printf("Queue is empty.\n");
    else {
        printf("Queue elements are:\n");
        for (int i = front; i <= rear; i++) {
            printf("%c ", queue[i]);
        }
        printf("\n");
    }
}
