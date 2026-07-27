// WAP to implement hashing technique :
// 1) Insert
// 2) Search
// 3) Delete

#include <stdio.h>

#define SIZE 10
#define EMPTY -1

int hashTable[SIZE];

// Initialize hash table
void initialize() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = EMPTY;
    }
}

// Hash function
int hashFunction(int key) {
    return key % SIZE;
}

// INSERT (No collision handling)
void insert(int key) {
    int index = hashFunction(key);

    if (hashTable[index] == EMPTY) {
        hashTable[index] = key;
        printf("Inserted %d at index %d\n", key, index);
    } else {
        printf("Collision occurred! Cannot insert %d\n", key);
    }
}

// SEARCH
int search(int key) {
    int index = hashFunction(key);

    if (hashTable[index] == key) {
        return index;
    }

    return -1;
}

// DELETE
void deleteKey(int key) {
    int index = hashFunction(key);

    if (hashTable[index] == key) {
        hashTable[index] = EMPTY;
        printf("Deleted %d\n", key);
    } else {
        printf("Element not found\n");
    }
}

// DISPLAY
void display() {
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] == EMPTY)
            printf("Empty ");
        else
            printf("%d ", hashTable[i]);
    }
    printf("\n");
}

// MAIN
int main() {
    initialize();

    insert(5);
    insert(15);  // Collision with 5
    insert(25);  // Collision again

    display();

    printf("Search 5: %d\n", search(5));
    printf("Search 15: %d\n", search(15));

    deleteKey(5);
    display();

    return 0;
} 