#pragma once
#include <algorithm>

struct AVLNode{
	int val;
	int height;
	AVLNode* left;
	AVLNode* right;

	AVLNode(int v) : val(v), height(1),
		left(nullptr), right(nullptr) {}
};

class AVL{
	private:
		AVLNode* root;

		int height(AVLNode* node) {
			return node ? node->height : 0;
		}

		int getBalance(AVLNode* node) {
			return node ? height(node->left) - height(node->right) : 0;
		}

		void updateHeight(AVLNode* node) {
			node->height = 1 + std::max(height(node->left), height(node->right));
		}

		AVLNode* rotateRight(AVLNode* y) {
			AVLNode* x = y->left;

			y->left = x->right;
			x->right = y;

			updateHeight(y);
			updateHeight(x);

			return x;
		}

		AVLNode* rotateLeft(AVLNode* x) {
			AVLNode* y = x->right;

			x->right = y->left;
			y->left = x;

			updateHeight(x);
			updateHeight(y);

			return y;
		}

		AVLNode* min(AVLNode* node) {
			AVLNode* curr = node;

			while(curr->left)
				curr = curr->left;

			return curr;
		}

		AVLNode* insert(AVLNode* node, int val) {
			if(!node) return new AVLNode(val);

			if(val < node->val)
				node->left = insert(node->left, val);
			else if(val > node->val)
				node->right = insert(node->right, val);
			else
				return node;

			updateHeight(node);

			int balance = getBalance(node);

			if(balance > 1 && val < node->left->val)
				return rotateRight(node);
			if(balance < -1 && val > node->right->val)
				return rotateLeft(node);
			if(balance > 1 && val > node->left->val) {
				node->left = rotateLeft(node->left);
				return rotateRight(node);
			}
			if(balance < -1 && val < node->right->val) {
				node->right = rotateRight(node->right);
				return rotateLeft(node);
			}
			return node;
		}

		AVLNode* remove(AVLNode* node, int val) {
			if(!node) return nullptr;

			if(val < node->val) {
				node->left = remove(node->left, val);
			} else if(val > node->val) {
				node->right = remove(node->right, val);
			} else {
				if(!node->left || !node->right) {
					AVLNode* temp = node->left ? node->left : node->right;
					delete node;
					return temp;
				}
			
				AVLNode* temp = min(node->right);
				node->val = temp->val;
				node->right = remove(node->right, temp->val);
			}

			updateHeight(node);

			int balance = getBalance(node);

			if(balance > 1 && 0 <= getBalance(node->left))
				return rotateRight(node);
			if(balance < -1 && 0 >= getBalance(node->right))
				return rotateLeft(node);
			if(balance > 1 && 0 > getBalance(node->left)) {
				node->left = rotateLeft(node->left);
				return rotateRight(node);
			}
			if(balance < -1 && 0 < getBalance(node->right)) {
				node->right = rotateRight(node->right);
				return rotateLeft(node);
			}
			return node;
		}

		void destroy(AVLNode* node) {
			if(!node) return;

			destroy(node->left);
			destroy(node->right);

			delete node;
		}
		
	public:
		AVL() : root(nullptr) {}

		~AVL() {
			destroy(root);
		}

		AVL(const AVL&) = delete;
		AVL& operator=(const AVL&) = delete;

		void insert(int val) {
			root = insert(root, val);
		}

		void remove(int val) {
			root = remove(root, val);
		}
};
