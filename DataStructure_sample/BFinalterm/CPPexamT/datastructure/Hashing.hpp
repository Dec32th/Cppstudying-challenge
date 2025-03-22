#pragma once
#include <iostream>
#include <vector>
#include <list>

template<typename K, typename V>
class HashMap {
private:
    std::vector<std::list<std::pair<K, V>>> table;
    int size;

    int hashFunction(K key) const {
        return std::hash<K>()(key) % size;
    }

public:
    HashMap(int s) : size(s), table(s) {}

    void insert(K key, V value) {
        int index = hashFunction(key);
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
        table[index].emplace_back(key, value);
    }

    bool search(K key, V& value) const {
        int index = hashFunction(key);
        for (const auto& pair : table[index]) {
            if (pair.first == key) {
                value = pair.second;
                return true;
            }
        }
        return false;
    }

    void remove(K key) {
        int index = hashFunction(key);
        table[index].remove_if([key](const std::pair<K, V>& pair) { return pair.first == key; });
    }

    void display() const {
        for (int i = 0; i < size; ++i) {
            std::cout << i << ": ";
            for (const auto& pair : table[i]) {
                std::cout << "(" << pair.first << ", " << pair.second << ") ";
            }
            std::cout << std::endl;
        }
    }
};



                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       