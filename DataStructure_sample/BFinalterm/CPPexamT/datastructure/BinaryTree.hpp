#pragma once

#include <iostream>

template<typename T>
class BinaryTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(T val) : data(val), left(nullptr), right(nullptr) {}
    };
    Node* root;

    void insert(Node*& node, T val) {
        if (!node) {
            node = new Node(val);
        }
        else if (val < node->data) {
            insert(node->left, val);
        }
        else {
            insert(node->right, val);
        }
    }

    void inOrder(Node* node) const {
        if (node) {
            inOrder(node->left);
            std::cout << node->data << " ";
            inOrder(node->right);
        }
    }

public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree() {
        clear(root);
    }

    void insert(T val) {
        insert(root, val);
    }

    void inOrder() const {
        inOrder(root);
        std::cout << std::endl;
    }

    void clear(Node* node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }
};
