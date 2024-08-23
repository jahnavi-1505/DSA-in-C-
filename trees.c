#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the binary tree
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a binary tree (recursive)
struct TreeNode* createBinaryTree() {
    int data;
    struct TreeNode* newNode;

    printf("Enter data for the node (or -1 for no node): ");
    scanf("%d", &data);

    if (data == -1) {
        return NULL; // Base case: no node
    }

    newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->data = data;
    printf("Enter the left child of %d:\n", data);
    newNode->left = createBinaryTree();
    printf("Enter the right child of %d:\n", data);
    newNode->right = createBinaryTree();

    return newNode;
}

// Function to print a binary tree (recursive)
void printBinaryTree(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    // In-order traversal: Left-Root-Right
    printBinaryTree(root->left);
    printf("%d ", root->data);
    printBinaryTree(root->right);
}

int main() {
    struct TreeNode* root = NULL;

    printf("Create a binary tree:\n");
    root = createBinaryTree();

    printf("Printing the binary tree (In-order traversal):\n");
    printBinaryTree(root);
    printf("\n");

    return 0;
}
