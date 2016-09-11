#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};


int claculateHeight(struct node *root) {
    int left, right;
    if(root == NULL) {
        return 0;
    } else {
        left = calculateHeight(root->left);
        right = calculateHeight(root->right);

        if(left > right)
            return left + 1;
        else
            return right + 1;
    }
}

struct node* newNode(int data) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
}

struct node *insert(struct node *root, int data) {
    if(root == NULL) {
        return newNode(data);
    }

    if(data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    return root;
}

void inorder(struct node* root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d\n",root->data);
        inorder(root->right);
    }
}

struct node *minValueNode(struct node* root) {
    struct node* temp = root;

    while(temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}

struct node *deleteNode(struct node* root, int data) {
    if(root == NULL) {
        return root;
    }

    if(data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if(root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        }

        if(root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);

        return root;
    }
}

int main()
{
    struct node *root = NULL;
    root = insert(root, 1);
    insert(root, 2);
    insert(root, 4);
    insert(root, 5);
    insert(root, 3);

    inorder(root);
    printf("height : %d\n", claculateHeight(root));
    printf("\n\n");
    deleteNode(root, 4);
    inorder(root);

    printf("height : %d\n", claculateHeight(root));
    return 0;
}
