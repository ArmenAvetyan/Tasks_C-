#pragma once
#include <algorithm>

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

class BST {
    private:
        Node* root;

        Node* insert(Node* node, int value) {
            if(!node) return new Node(value);

            if(value < node->val)
                node->left = insert(node->left, value);
            else if(node->val < value)
                node->right = insert(node->right, value);
            
            return node;
        }

        Node* remove(Node* node, int value) {
            if(!node) return nullptr;
            if(node->val < value)
                node->right = remove(node->right, value);
            else if(node->val > value)
                node->left = remove(node->left, value);
            else {
                if(!node->left) {
                    Node* temp = node->right;
                    delete node;
                    return temp;
                }
                if(!node->right) {
                    Node* temp = node->left;
                    delete node;
                    return temp;
                }
                Node* temp = minimum(node->right);
                node->val = temp->val;
                node->right = remove(node->right, temp->val);
            }
            return node;
        }

        Node* minimum(Node* node) const {
            if(!node) return nullptr;
            while(node->left)
                node = node->left;
            return node;
        }

        Node* maximum(Node* node) const {
            if(!node) return nullptr;
            while(node->right)
                node = node->right;
            return node;
        }

        int getHeight(Node* node) {
            if(!node) return -1;
            return 1 + std::max(getHeight(node->left),
                            getHeight(node->right));
        }

    public:
        BST() : root(nullptr) {}

        void insert(int value) {
            root = insert(root, value);
        }

        void remove(int value) {
            root = remove(root, value);
        }

        Node* search(int value) const {
            Node* curr = root;

            while(curr) {
                if(curr->val == value)
                    return curr;
                else if(curr->val < value)
                    curr = curr->right;
                else
                    curr = curr->left;
            }
            return nullptr;
        }

        Node* minimum() const {
            return minimum(root);
        }

        Node* maximum() const {
            return maximum(root);
        }

        Node* successor(int value) const {
            Node* curr = root;
            Node* successor = nullptr;

            while(curr) {
                if(value < curr->val) {
                    successor = curr;
                    curr = curr->left;
                } else if(value > curr->val) {
                    curr = curr->right;
                } else {
                    if(curr->right)
                        return minimum(curr->right);
                    break;
                }
            }
            return successor;
        }

        Node* predecessor(int value) const {
            Node* curr = root;
            Node* predecessor = nullptr;

            while(curr) {
                if(value > curr->val) {
                    predecessor = curr;
                    curr = curr->right;
                } else if(value < curr->val) {
                    curr = curr->left;
                } else {
                    if(curr->left)
                        return maximum(curr->left);
                    break;
                }
            }
            return predecessor;
        }

        int height() {
            return getHeight(root);
        }
};
