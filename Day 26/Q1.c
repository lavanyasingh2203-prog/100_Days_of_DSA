#include <stdio.h>
#include <stdlib.h>

// Structure for Doubly Linked List Node
struct node {
    int data;
    struct node* next;
    struct node* prev;
};

int main() {
    int n, i, value;
    struct node *head = NULL, *temp = NULL, *newnode = NULL;

    // Input number of nodes
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &value);

        // Allocate memory dynamically
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = value;
        newnode->next = NULL;
        newnode->prev = NULL;

        if(head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }

    // Traverse in forward direction
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}