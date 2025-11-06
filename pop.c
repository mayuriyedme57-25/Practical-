#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;

// Function declarations
void push(int element);
void pop();
void display();
void checkPalindrome();
int isFull();
int isEmpty();

int main() {
    int choice, element;

    while (1) {
        printf("\n\n----- STACK MENU -----\n");
        printf("1. Push an Element\n");
        printf("2. Pop an Element\n");
        printf("3. Check Palindrome\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                push(element);
                break;
            case 2:
                pop();
                break;
            case 3:
                checkPalindrome();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

int isFull() {
    return top == MAX - 1;
}

int isEmpty() {
    return top == -1;
}

void push(int element) {
    if (isFull()) {
        printf("Stack Overflow! Cannot insert element.\n");
    } else {
        top++;
        stack[top] = element;
        printf("%d pushed onto stack.\n", element);
    }
}

void pop() {
    if (isEmpty()) {
        printf("Stack Underflow! No elements to pop.\n");
    } else {
        printf("Popped element: %d\n", stack[top]);
        top--;
    }
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

void checkPalindrome() {
    char str[50];
    char rev[50];
    int i, len;

    printf("Enter a string to check palindrome: ");
    scanf("%s", str);

    len = strlen(str);
    int tempTop = -1;

    // Push all characters onto stack
    for (i = 0; i < len; i++) {
        if (tempTop < MAX - 1) {
            stack[++tempTop] = str[i];
        } else {
            printf("Stack Overflow while checking palindrome!\n");
            return;
        }
    }

    // Pop characters to form reversed string
    for (i = 0; i < len; i++) {
        rev[i] = stack[tempTop--];
    }
    rev[i] = '\0';

    if (strcmp(str, rev) == 0)
        printf("The string '%s' is a palindrome.\n", str);
    else
        printf("The string '%s' is NOT a palindrome.\n", str);
}
