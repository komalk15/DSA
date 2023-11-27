#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}



void preorder(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printf("%d->", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d->", root->data);
}

void inorder(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d->", root->data);
    inorder(root->right);
}

int main() {
   
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Preorder is :   ");
    preorder(root);
    printf("\n");

    printf("Inorder is :   ");
    inorder(root);
    printf("\n");

    printf("Postorder is :   ");
    postorder(root);
    printf("\n");

    
    return 0;
}
