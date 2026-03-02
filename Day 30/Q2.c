#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

// Create new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Insert at front (important for result)
struct ListNode* insertFront(struct ListNode* head, int val) {
    struct ListNode* newNode = createNode(val);
    newNode->next = head;
    return newNode;
}

// Add two numbers (MSD first)
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    int stack1[100], stack2[100];
    int top1 = -1, top2 = -1;

    // Push l1 into stack1
    while (l1 != NULL) {
        stack1[++top1] = l1->val;
        l1 = l1->next;
    }

    // Push l2 into stack2
    while (l2 != NULL) {
        stack2[++top2] = l2->val;
        l2 = l2->next;
    }

    int carry = 0;
    struct ListNode* result = NULL;

    // Add until stacks empty
    while (top1 >= 0 || top2 >= 0 || carry) {
        int sum = carry;

        if (top1 >= 0)
            sum += stack1[top1--];

        if (top2 >= 0)
            sum += stack2[top2--];

        carry = sum / 10;
        result = insertFront(result, sum % 10);
    }

    return result;
}

// Print linked list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d", head->val);
        if (head->next != NULL)
            printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

// Helper to insert at end (for input building)
struct ListNode* insertEnd(struct ListNode* head, int val) {
    struct ListNode* newNode = createNode(val);

    if (head == NULL)
        return newNode;

    struct ListNode* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

int main() {
    struct ListNode* l1 = NULL;
    struct ListNode* l2 = NULL;

    int n1, n2, x;

    printf("Enter number of digits in first number: ");
    scanf("%d", &n1);

    printf("Enter digits (MSD first): ");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &x);
        l1 = insertEnd(l1, x);
    }

    printf("Enter number of digits in second number: ");
    scanf("%d", &n2);

    printf("Enter digits (MSD first): ");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &x);
        l2 = insertEnd(l2, x);
    }

    struct ListNode* result = addTwoNumbers(l1, l2);

    printf("Result: ");
    printList(result);

    return 0;
}