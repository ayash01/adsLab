#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    void *left;
    void *right;
} node;

node *insertNode(node *startNode, int data)
{
    if (startNode == NULL)
    {
        startNode = (node *)malloc(sizeof(node));
        startNode->data = data;
        startNode->left = NULL;
        startNode->right = NULL;
    }

    else if (data < startNode->data)
    {
        startNode->left = insertNode(startNode->left, data);
    }

    else
    {
        startNode->right = insertNode(startNode->right, data);
    }

    return startNode;
}

int getRootData(node *root)
{
    if (root == NULL)
    {
        return -1;
    }

    else
    {
        return (root->data);
    }
}

int getMinNode(node *root)
{
    if (root == NULL)
    {
        return -1;
    }

    else
    {
        while (root != NULL && root->left != NULL)
        {
            root = root->left;
        }
        return root->data;
    }
}

int getMaxNode(node *root)
{
    if (root == NULL)
    {
        return -1;
    }

    else
    {
        while (root != NULL && root->right != NULL)
            root = root->right;
        return root->data;
    }
}

void preOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d  ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    printf("%d  ", root->data);
    inOrder(root->right);
}

void postOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    printf("%d  ", root->data);
}

node *search(node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }

    else if (root->data == data)
    {
        return root;
    }

    else if (data < root->data)
    {
        search(root->left, data);
    }

    else
    {
        search(root->right, data);
    }
}

node *deleteNode(node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }

    else if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }

    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }

    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            return NULL;
        }

        else if (root->right == NULL)
        {
            node *ptr = root->left;
            free(root);
            return ptr;
        }

        else if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }

        node *ptr = root->right;

        while (ptr != NULL && ptr->left != NULL)
        {
            ptr = ptr->left;
        }

        root->data = ptr->data;
        root->right = deleteNode(root->right, ptr->data);
    }

    return root;
}

void main()
{

    int ch, data, rootData, mindata, maxdata, searchdata, delete;
    node *root = NULL, *searchResult;

    do
    {
        printf("\nPlease select an option:\n\n1. Insert a node\n2. Pre-order traversal\n3. In-order traversal\n4. Post-order traversal\n5. Display root\n6. Display min node\n7. Display max node\n8. Delete node\n9. Search node\n\n0. Exit\n\n-> ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 0:
            printf("Exiting program...");
            exit(0);
        case 1:
            printf("Enter a number to insert : ");
            scanf("%d", &data);
            root = insertNode(root, data);
            break;
        case 2:
            printf("Pre-order :\t");
            preOrder(root);
            printf("\n\n");
            break;
        case 3:
            printf("In-order :\t");
            inOrder(root);
            printf("\n\n");
            break;
        case 4:
            printf("Post-order :\t");
            postOrder(root);
            printf("\n\n");
            break;
        case 5:
            rootData = getRootData(root);
            if (rootData > 0)
                printf("Root: %d\n\n", rootData);
            else
                printf("The BST is empty\n\n");
            break;
        case 6:
            mindata = getMinNode(root);
            if (mindata > 0)
                printf("The min data is : %d\n\n", mindata);
            else
                printf("The BST is empty\n\n");
            break;
        case 7:
            maxdata = getMaxNode(root);
            if (maxdata > 0)
                printf("The max data is : %d\n\n", maxdata);
            else
                printf("The BST is empty\n\n");
            break;
        case 8:
            printf("Enter data to delete: ");
            scanf("%d", &delete);
            root = deleteNode(root, delete);
            break;
        case 9:
            printf("Enter data to search: ");
            scanf("%d", &searchdata);

            searchResult = search(root, searchdata);

            if (searchResult == NULL)
                printf("Element not found in BST\n\n");

            else
                printf("Data found at address %p\n\n", searchResult);

            break;

        default:
            printf("\n");
            break;
        }
    } while (ch != 0);
}