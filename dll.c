#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct node* insert(struct node*, int);
struct node* delete(struct node*, int);
struct node* search(struct node*, int);
void display(struct node*);
void main() {
    struct node* start = NULL; 
    int opt, data;
    do {
        printf("\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\nEnter your choice: ");
        scanf("%d", &opt);
        switch(opt) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                start = insert(start, data);
                break;
            case 2:
                printf("Enter the data to be deleted: ");
                scanf("%d", &data);
                start = delete(start, data);
                
                break;
            case 3:
                printf("Enter the element to be searched: ");
                scanf("%d", &data);
                if (search(start, data) == NULL)
                    printf("Item not found\n");
                else
                    printf("Item found\n");
                break;
            case 4:
                display(start);
                printf("\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while(1);
}
struct node* insert(struct node* s, int item) {
    struct node* t = (struct node*)malloc(sizeof(struct node));
    t->data = item;
    t->left = NULL; 
    t->right = s;   
    if (s != NULL) {
        s->left = t;
    }
    return t; 
}
//delete
struct node* delete(struct node* s, int item) {
    if (s == NULL) {
        printf("Empty list\n");
        return NULL;
    }

    struct node *t = search(s, item);
    if (t == NULL) {
        printf("Item not found\n");
        return s;
    }

    printf("The value deleted: %d\n", t->data);

    if (t->left == NULL && t->right == NULL) 
    { 
        s = NULL;   // Single node in the list
    }
     else if (t->left == NULL) // First node (head)
    {  
        s = t->right;                      
        if (s != NULL) {
            s->left = NULL;
        }
    }
    else if (t->right == NULL) 
    {  // Last node
        t->left->right = NULL; 
    }
    else 
    {  // Middle node
        t->left->right = t->right;  
        t->right->left = t->left;
    }

free(t);
return s;
}

//Search
struct node* search(struct node* s, int item) {
            if(s==0)
            return NULL;
    while (s != NULL && s->data != item) {
        s = s->right; 
    }
    return s; 
}
//Display
void display(struct node* s) 
{
            if(s==0)
            {
            printf("Empty list");
            return;
            }
        while (s != NULL) 
        {
            printf("%d\t", s->data);
            s = s->right; 
        }
}
