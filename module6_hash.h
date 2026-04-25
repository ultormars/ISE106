#ifndef MODULE6_HASH_H
#define MODULE6_HASH_H

#include "common.h"
#include <iostream>

// Çarpýþmalarý çözmek için chaining
struct HashNode {
    Record data;
    HashNode* next;
};

// Hash tablosunu yönetecek class
class HashModule {
public:
    static const int TABLE_SIZE = 10;
    HashNode* table[TABLE_SIZE];

    HashModule() {
        for(int i = 0; i < TABLE_SIZE; i++) table[i] = NULL;
    }
    
    // index func
    int hashFunction(int id) {
        return id % TABLE_SIZE;
    }
    
    // hash insert
    void insert(Record data) {
        int index = hashFunction(data.id);
        HashNode* newNode = new HashNode{data, table[index]};
        table[index] = newNode;
        std::cout << "ID: " << data.id << " Hash tablosuna eklendi (Index: " << index << ")" << std::endl;
    }
    
    //Hash search func.
    Record* search(int id) {
    int index = hashFunction(id);
    HashNode* current = table[index];
    
    while (current != NULL) {
        if (current->data.id == id) {
            return &current->data; // Veriyi bulduk!
        }
        current = current->next; // Çarpýþma olduysa bir sonrakine bak
    }
    return NULL; // Bulunamadý
}
};

#endif
