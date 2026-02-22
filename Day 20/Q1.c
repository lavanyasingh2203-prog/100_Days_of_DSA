#include <stdio.h>
#include <stdlib.h>

#define SIZE 100000

// Simple hash structure
typedef struct Node {
    long long key;
    long long freq;
    struct Node* next;
} Node;

Node* hashTable[SIZE];

// Hash function
int hash(long long key) {
    return (abs(key) % SIZE);
}

// Insert or update frequency
void insert(long long key) {
    int index = hash(key);
    Node* temp = hashTable[index];

    while (temp != NULL) {
        if (temp->key == key) {
            temp->freq++;
            return;
        }
        temp = temp->next;
    }

    // Create new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->freq = 1;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// Get frequency
long long getFreq(long long key) {
    int index = hash(key);
    Node* temp = hashTable[index];

    while (temp != NULL) {
        if (temp->key == key) {
            return temp->freq;
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    long long arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    long long sum = 0;
    long long count = 0;

    // Important: prefix sum 0 occurs once initially
    insert(0);

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        count += getFreq(sum);
        insert(sum);
    }

    printf("%lld", count);

    return 0;
}