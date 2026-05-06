#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 7   // size of hash table (from sample input)
#define EMPTY -1

int hashTable[M];

// Hash function
int hash(int key) {
    return key % M;
}

// Insert using quadratic probing
void insert(int key) {
    int h = hash(key);
    for (int i = 0; i < M; i++) {
        int pos = (h + i * i) % M;
        if (hashTable[pos] == EMPTY) {
            hashTable[pos] = key;
            return;
        }
    }
    printf("Hash table full, cannot insert %d\n", key);
}

// Search using quadratic probing
void search(int key) {
    int h = hash(key);
    for (int i = 0; i < M; i++) {
        int pos = (h + i * i) % M;
        if (hashTable[pos] == EMPTY) {
            printf("NOT FOUND\n");
            return;
        }
        if (hashTable[pos] == key) {
            printf("FOUND\n");
            return;
        }
    }
    printf("NOT FOUND\n");
}

int main() {
    // initialize table
    for (int i = 0; i < M; i++) {
        hashTable[i] = EMPTY;
    }

    int n; // number of operations
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char op[10];
        int key;
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key);
        } else if (strcmp(op, "SEARCH") == 0) {
            search(key);
        }
    }

    return 0;
}