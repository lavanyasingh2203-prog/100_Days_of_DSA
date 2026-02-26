#include <stdio.h>
#include <stdlib.h>

// Define structure of node
struct node {
    int data;
    struct node* next;
};

int main() {
    int n, i, value, key, count = 0;
    struct node *head = NULL, *temp = NULL, *newnode = NULL;

    // Input number of nodes
    scanf("%d", &n);

    // Create linked list
    for(i = 0; i < n; i++) {
        scanf("%d", &value);

        // Allocate memory dynamically
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = value;
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    // Input key to count
    scanf("%d", &key);

    // Traverse and count occurrences
    temp = head;
    while(temp != NULL) {
        if(temp->data == key) {
            count++;
        }
        temp = temp->next;
    }

    // Output result
    printf("%d", count);

    return 0;
}