#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define a basic structure for a binary tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Structure to represent a node in the doubly linked list for each vertical column
struct ListNode {
    int data;
    struct ListNode* next;
    struct ListNode* prev;
};

// Function to create a new node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to create a new list node
struct ListNode* createListNode(int data) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

// Function to perform vertical order traversal
void verticalOrderTraversal(struct TreeNode* root, int horizontalDistance, struct ListNode* columns[]) {
    if (root == NULL) {
        return;
    }

    // Create a new list node for the current tree node
    struct ListNode* newNode = createListNode(root->data);

    // Attach the new node to the corresponding column
    if (columns[horizontalDistance] == NULL) {
        columns[horizontalDistance] = newNode;
    } else {
        struct ListNode* current = columns[horizontalDistance];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }

    // Recur for the left and right subtrees with updated horizontal distances
    verticalOrderTraversal(root->left, horizontalDistance - 1, columns);
    verticalOrderTraversal(root->right, horizontalDistance + 1, columns);
}

// Function to print the vertical order
void printVerticalOrder(struct ListNode* column) {
    while (column != NULL) {
        printf("%d ", column->data);
        column = column->next;
    }
    printf("\n");
}

int main() {
    // Create a sample binary tree
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Find the minimum and maximum horizontal distances
    int minHD = INT_MAX, maxHD = INT_MIN;
    void findMinMax(struct TreeNode* root, int horizontalDistance) {
        if (root == NULL) {
            return;
        }
        minHD = (horizontalDistance < minHD) ? horizontalDistance : minHD;
        maxHD = (horizontalDistance > maxHD) ? horizontalDistance : maxHD;
        findMinMax(root->left, horizontalDistance - 1);
        findMinMax(root->right, horizontalDistance + 1);
    }
    findMinMax(root, 0);

    // Create an array of linked lists for each vertical column
    struct ListNode* columns[maxHD - minHD + 1];
    for (int i = 0; i < maxHD - minHD + 1; i++) {
        columns[i] = NULL;
    }

    // Perform vertical order traversal
    verticalOrderTraversal(root, -minHD, columns);

    // Print the vertical order
    printf("Vertical order of the tree:\n");
    for (int i = 0; i < maxHD - minHD + 1; i++) {
        printVerticalOrder(columns[i]);
    }

    return 0;
}
