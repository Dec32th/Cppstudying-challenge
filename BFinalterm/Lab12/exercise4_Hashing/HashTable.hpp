#pragma once
#include <cstring>
#include "Student.h"

template<class ItemType>
class HashTable {
public:
    HashTable(int maxItems = 1000);
    ~HashTable();
    void InsertItem(const ItemType& item);
    void RetrieveItem(ItemType& item, bool& found) const;
    void SetEmptyItem(ItemType& item);

private:
    int Hash(const char* key) const;
    ItemType* info;
    ItemType emptyItem;
    int length;
    int MAX_ITEMS;
};


int getIntFromString(const char* key) {
    unsigned int sum = 0;
    int len = strlen(key);
    if (len % 2 == 1) len++;
    for (int j = 0; j < len; j += 2)
        sum = (sum + 100 * key[j] + key[j + 1]) % 19937;
    return sum;
}

template<class ItemType>
int HashTable<ItemType>::Hash(const char* key) const {
    return (getIntFromString(key) % MAX_ITEMS);
}

template<class ItemType>
HashTable<ItemType>::HashTable(int maxItems) {
    MAX_ITEMS = maxItems;
    info = new ItemType[MAX_ITEMS];
    length = 0;
    for (int i = 0; i < MAX_ITEMS; i++) {
        info[i] = emptyItem;
    }
}

template<class ItemType>
HashTable<ItemType>::~HashTable() {
    delete[] info;
}

template<class ItemType>
void HashTable<ItemType>::InsertItem(const ItemType& item) {
    int location = Hash(item.Key());
    while (info[location] != emptyItem) {
        location = (location + 1) % MAX_ITEMS;
    }
    info[location] = item;
    length++;
}

template<class ItemType>
void HashTable<ItemType>::RetrieveItem(ItemType& item, bool& found) const {
    int location = Hash(item.Key());
    int startLoc = location;
    bool moreToSearch = true;

    do {
        if (info[location] == item || info[location] == emptyItem) {
            moreToSearch = false;
        }
        else {
            location = (location + 1) % MAX_ITEMS;
        }
    } while (moreToSearch && location != startLoc);

    found = (info[location] == item);
    if (found) {
        item = info[location];
    }
}

template<class ItemType>
void HashTable<ItemType>::SetEmptyItem(ItemType& item) {
    emptyItem = item;
    for (int i = 0; i < MAX_ITEMS; i++) {
        info[i] = emptyItem;
    }
}
