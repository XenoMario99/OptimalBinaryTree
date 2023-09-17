#pragma once

#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <vector>

template <typename T>
class BinaryTree {
   private:
    struct Node {
        T item;
        Node* left;
        Node* right;
        int depth;

        Node() : left(nullptr), right(nullptr), depth(0) {}
        Node(const T& it) : left(nullptr), right(nullptr), depth(0), item(it) {}
        ~Node() {
            if (left != nullptr) {
                delete left;
            }
            if (right != nullptr) {
                delete right;
            }
        }
    };

    Node* root;
    int depth;

    Node* makeOptimal(int i, int j, const std::vector<std::vector<int>>& R, const std::vector<T>& probabilities);

   public:
    BinaryTree();
    ~BinaryTree();

    const int getDepth() const { return depth; }
    Node* getRoot() { return root; }

    void buildTree(const std::vector<std::vector<int>>& R, const std::vector<T>& probabilities);
};

template <typename T>
BinaryTree<T>::BinaryTree() : depth(0) {
    root = new Node;
}

template <typename T>
BinaryTree<T>::~BinaryTree() {
    delete root;
}

template <typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::makeOptimal(int i, int j, const std::vector<std::vector<int>>& R, const std::vector<T>& probabilities) {
    try {
        int k = R.at(i).at(j);

        if (k != 0) {
            Node* node = new Node(probabilities.at(k - 1));

            node->left = makeOptimal(i, k - 1, R, probabilities);
            node->right = makeOptimal(k, j, R, probabilities);

            if (node->left != nullptr || node->right != nullptr)
                depth++;

            return node;
        } else {
            return nullptr;
        }
    } catch (const std::out_of_range& e) {
        std::cout << "ERROR: " << e.what();
        std::exit(EXIT_FAILURE);
    }
}

template <typename T>
void BinaryTree<T>::buildTree(const std::vector<std::vector<int>>& R, const std::vector<T>& probabilities) {
    if (root) {
        delete root;
    }

    root = makeOptimal(0, probabilities.size(), R, probabilities);
}