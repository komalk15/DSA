#include <stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* newNode(int data);
struct node* newNode(int data)
{
    struct node* node= (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return (node);
}

int height(struct node * node) {
  if (node == NULL)
    return 0;
  else {
    int lheight = height(node -> left);
    int rheight = height(node -> right);
    if (lheight > rheight)
      return (lheight + 1);
    else return (rheight + 1);
  }
}

void CurrentLevel(struct node * root, int level) {
  if (root == NULL)
    return;
  if (level == 1)
    printf("%d ", root -> data);
  else if (level > 1) {
    CurrentLevel(root -> left, level - 1);
    CurrentLevel(root -> right, level - 1);
  }
}


void LevelOrder(struct node * root) {
  int h = height(root);
  int i;
  for (i = 1; i <= h; i++)
    CurrentLevel(root, i);
}

int main() {
	// Your code goes here;
	struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    root->right->left = newNode(6);
    root->left->right = newNode(7);	
    LevelOrder(root);
	return 0;
}
