#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *createNode(int value)
{
    struct node *n = (struct node *) malloc(sizeof(struct node));
    n->data = value;
    n->left = n->right = NULL;
    return n;
}

struct node *insertNode(struct node *root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    }
    else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }
    return root;
}

struct node *root = NULL;

void inorder(struct node *root)
{
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct node *root)
{
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root)
{
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void display()
{
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }
    printf("Tree elements:\n");
    inorder(root);
    printf("\n");
}

int main()
{
    int n, data, ch;

    printf("Construct the BST. Enter the no.of nodes: ");
    scanf("%d", &n);

    printf("Enter the data for the nodes:\n");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &data);
        root = insertNode(root, data);
    }

    printf("\nEnter the choice of operation:\n");
    printf("1: Insert a node\n2: Inorder\n3: Preorder\n4: Postorder\n5: Display\n0: Exit\n");
    scanf("%d", &ch);

    while (ch) {
        switch (ch) {
        case 1:
            printf("Enter data for the node: ");
            scanf("%d", &data);
            insertNode(root, data);
            printf("Node inserted.\n");
            break;

        case 2:
            inorder(root);
            printf("\n");
            break;

        case 3:
            preorder(root);
            printf("\n");
            break;

        case 4:
            postorder(root);
            printf("\n");
            break;

        case 5:
            display();
            break;

        case 0:
            printf("Exiting\n");
            break;

        default:
            printf("Invalid choice.\n");
        }

        printf("Your choice: ");
        scanf("%d", &ch);
    }
}
