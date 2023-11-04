#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new BST node
void createNode(struct Node** newNode, int data) {
    *newNode = (struct Node*)malloc(sizeof(struct Node));
    (*newNode)->data = data;
    (*newNode)->left = (*newNode)->right = NULL;
}

// Function to insert a node into the BST
void insert(struct Node** root, int data) {
    if (*root == NULL) {
        createNode(root, data);
    } else if (data < (*root)->data) {
        insert(&((*root)->left), data);
    } else if (data > (*root)->data) {
        insert(&((*root)->right), data);
    }
}

// Function to find the minimum value node in a BST
struct Node* findMin(struct Node* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Function to delete a node from the BST
void deleteNode(struct Node** root, int key) {
    if (*root == NULL) {
        return;
    }

    if (key < (*root)->data) {
        deleteNode(&((*root)->left), key);
    } else if (key > (*root)->data) {
        deleteNode(&((*root)->right), key);
    } else {
        // Node with one child or no child
        if ((*root)->left == NULL) {
            struct Node* temp = *root;
            *root = (*root)->right;
            free(temp);
        } else if ((*root)->right == NULL) {
            struct Node* temp = *root;
            *root = (*root)->left;
            free(temp);
        } else {
            // Node with two children, get the inorder successor (min value in the right subtree)
            struct Node* temp = findMin((*root)->right);
            (*root)->data = temp->data;
            deleteNode(&((*root)->right), temp->data);
        }
    }
}

// Function to perform an inorder traversal
void inorderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Function to perform a preorder traversal
void preorderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Function to perform a postorder traversal
void postorderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

int main() {
    struct Node* root = NULL;
    int choice, data;

    while (1) {
        printf("\nBinary Search Tree Menu:\n");
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert(&root, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(&root, data);
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Preorder Traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Postorder Traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
