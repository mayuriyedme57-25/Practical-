#include <stdio.h>
#include <stdlib.h>

// Structure definition for linked list node
struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int value, count = 0;

    printf("Enter integers to add to the linked list (enter 0 to stop):\n");

    while (1) {
        scanf("%d", &value);
        if (value == 0)
            break;

        // Create a new node
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    printf("\nLinked List Elements:\n");
    temp = head;

    while (temp != NULL) {
        printf("%d => ", temp->data);
        count++;
        temp = temp->next;
    }

    printf("NULL\n");
    printf("\nTotal number of nodes in the list = %d\n", count);

    return 0;
}
