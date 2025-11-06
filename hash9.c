#include <stdio.h>

#define SIZE 7

void insert(int hashTable[], int key) {
    int index = key % SIZE;
    int i = 0;

    // Linear probing
    while (hashTable[(index + i) % SIZE] != -1) {
        i++;
        if (i == SIZE) {
            printf("Hash table is full!\n");
            return;
        }
    }

    hashTable[(index + i) % SIZE] = key;
}

void display(int hashTable[]) {
    int i;
    printf("\nHash Table:\n");
    for (i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1)
            printf("Index %d --> %d\n", i, hashTable[i]);
        else
            printf("Index %d --> NULL\n", i);
    }
}

int main() {
    int hashTable[SIZE];
    int n, key;

    // Initialize hash table
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    printf("Enter the number of keys to insert: ");
    scanf("%d", &n);

    printf("Enter %d keys:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(hashTable, key);
    }

    display(hashTable);
    return 0;
}
