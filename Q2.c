// WAP tp avoide collision using:
// 1) Chaining
// 2) Linear Probing
// 3) Quadratic Probing
// 4) Double Hashing

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
#define EMPTY -1
int hashTable[SIZE];
void initialize() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = EMPTY;
    }
}
int hashFunction(int key) {
    return key % SIZE;
}
void insert(int key) {
    int index = hashFunction(key);
    while (hashTable[index] != EMPTY) {
        index = (index + 1) % SIZE; 