#include <stdio.h>
#include <stdlib.h>

// Structure for BST node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

// Function to search a node
void search(struct Node* root, int key) {
    if (root == NULL) {
        printf("Element not found!\n");
        return;
    }
    if (key == root->data)
        printf("Element %d found in the tree.\n", key);
    else if (key < root->data)
        search(root->left, key);
    else
        search(root->right, key);
}

// Function to delete a leaf node only
struct Node* deleteLeaf(struct Node* root, int key) {
    if (root == NULL)
        return NULL;

    if (key < root->data)
        root->left = deleteLeaf(root->left, key);
    else if (key > root->data)
        root->right = deleteLeaf(root->right, key);
    else {
        // Check if it is a leaf node
        if (root->left == NULL && root->right == NULL) {
            printf("Deleting leaf node %d\n", root->data);
            free(root);
            return NULL;
        } else {
            printf("Node %d is not a leaf node. Cannot delete!\n", root->data);
        }
    }
    return root;
}

// Inorder traversal to display tree
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n\n--- Binary Search Tree Operations ---\n");
        printf("1. Insert Node\n");
        printf("2. Search Element\n");
        printf("3. Delete Leaf Node\n");
        printf("4. Display (Inorder)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;
        case 2:
            printf("Enter element to search: ");
            scanf("%d", &value);
            search(root, value);
            break;
        case 3:
            printf("Enter leaf node value to delete: ");
            scanf("%d", &value);
            root = deleteLeaf(root, value);
            break;
        case 4:
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
            break;
        case 5:
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
