#include<stdio.h>
#include<stdlib.h>
// Define structure of the tree
struct node {
    int data;//
    struct node *left, *right;//pointers to left and right child
};

void main() {
    struct node *root = (struct node *)0; // null list
    struct node *insert(struct node*, int);
    void display(struct node*);
    struct node *search(struct node*, int);
    struct node *delete(struct node*, int);
    int opt, data;

    do {
        printf("\n 1.insert \n 2.search \n 3.delete \n 4.display \n 5.exit \n Your option:");
        scanf("%d", &opt);
        switch(opt) {
            case 1:
                printf("Data: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;

            case 2:
                printf("Data: ");
                scanf("%d", &data);
                if(search(root, data)) 
                    printf("Found the item\n");
                else
                    printf("Not found data\n");
                break;

            case 3:
                if(root == (struct node*)0) {
                    printf("Tree is empty\n");
                } else {
                    printf("Data: ");
                    scanf("%d", &data);
                    root = delete(root, data);
                }
                break;

            case 4:
                display(root);
                break;

            case 5:
                exit(0);
        }
    } while(1);
}
// Function to display the tree
void display(struct node *bst) {
    if(bst != (struct node*)0) {
        display(bst->left);
        printf("%d\t", bst->data);
        display(bst->right);
    } else {
        printf("Tree is empty\n");
    }
}
// Function to insert the node
struct node *insert(struct node *bst, int data) {
    struct node *t, *t1 = bst, *t2 = NULL;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = data;
    t->left = t->right = NULL;

    if(bst == (struct node*)0)
        bst = t;
    else {
        while(t1 != 0 && data != t1->data) {
            t2 = t1;
            if(data < t1->data)
                t1 = t1->left;
            else
                t1 = t1->right;
        }
        if(t1 == 0) { 
            if(data < t2->data)
                t2->left = t;
            else
                t2->right = t;
        } else {
            printf("Duplicate\n");
            free(t);
        }
    }
    return bst;
}
// Function to search node 
struct node *search(struct node *bst, int data) {
    while(bst != (struct node*)0 && bst->data != data) {
        if(data < bst->data)
            bst = bst->left;
        else
            bst = bst->right;
    }
    return bst;
}

struct node *delete(struct node *bst, int data) {
    struct node *t1 = bst, *t2 = NULL, *sucpar;

    while(t1 != 0 && t1->data != data) {
        t2 = t1;
        if(data < t1->data)
            t1 = t1->left;
        else
            t1 = t1->right;
    }

    if(t1 != (struct node*)0) {
        // Case 1: Node to be deleted has no children (leaf node)
        if(t1->left == 0 && t1->right == 0) {
            if(t1 == bst)
                return NULL;  
            else if(t2->left == t1)
                t2->left = 0;
            else
                t2->right = 0;
            free(t1);
        }
        // Case 2: Node to be deleted has one child
        else if(t1->left == 0 || t1->right == 0) {
            struct node *child = (t1->left != 0) ? t1->left : t1->right;
            if(t1 == bst)
                return child;  
            else if(t2->left == t1)
                t2->left = child;
            else
                t2->right = child;
            free(t1);
        }
        // Case 3: Node to be deleted has two children
        else {
            sucpar = t1;
            t2 = t1->right;
            while(t2->left != NULL) {
                sucpar = t2;
                t2 = t2->left;
            }
            t1->data = t2->data;
            if(sucpar->left == t2)
                sucpar->left = t2->right;
            else
                sucpar->right = t2->right;
            free(t2);
        }
    }
    return bst;
}
