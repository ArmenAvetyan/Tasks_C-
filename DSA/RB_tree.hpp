#pragma once
#include <utility>
#include <limits>

enum class Color : bool {
    RED,
    BLACK
};

struct RBNode {
    int val;
    Color color;
    RBNode* left;
    RBNode* right;
    RBNode* parent;

    RBNode(int v) : val(v), color(Color::RED), left(nullptr),
                    right(nullptr), parent(nullptr) {}
};

class RBTree {
    private:
        RBNode* root;
        RBNode* NIL;

        void leftRotate(RBNode* x) {
            RBNode* y = x->right;
            x->right = y->left;

            if(y->left != NIL) y->left->parent = x;
            
            y->parent = x->parent;
            if(x->parent == NIL) root = y;
            else if(x->parent->left == x) x->parent->left = y;
            else x->parent->right = y;

            y->left = x;
            x->parent = y;
        }

        void rightRotate(RBNode* x) {
            RBNode* y = x->left;
            x->left = y->right;

            if(y->right != NIL) y->right->parent = x;

            y->parent = x->parent;
            if(x->parent == NIL) root = y;
            else if(x == x->parent->right) x->parent->right = y;
            else x->parent->left = y;

            y->right = x;
            x->parent = y;
        }

        void tp(RBNode* u, RBNode* v) {
            v->parent = u->parent;

            if(u->parent == NIL)
                root = v;
            else if(u == u->parent->left)
                u->parent->left = v;
            else
                u->parent->right = v;
        }

        RBNode* min(RBNode* node) {
            while(node->left != NIL)
                node = node->left;
            return node;
        }

        RBNode* max(RBNode* node) {
            while(node->right != NIL)
                node = node->right;
            return node;
        }

        RBNode* lower_bound(RBNode* root, int val) {
            RBNode* res = nullptr;

            while(root != NIL) {
                if(root->val >= val) {
                    res = root;
                    root = root->left;
                } else {
                    root = root->right;
                }
            }
            return res;
        }

        RBNode* upper_bound(RBNode* root, int val) {
            RBNode* res = nullptr;

            while(root != NIL) {
                if(root->val > val) {
                    res = root;
                    root = root->left;
                } else {
                    root = root->right;
                }
            }
            return res;
        }

        std::pair<RBNode*, RBNode*> equal_range(RBNode* root, int val) {
            return {lower_bound(root, val), upper_bound(root, val)};
        }

        int valid_bh(RBNode* root) {
            if(root == NIL)
                return 1;
            if(root->color == Color::RED &&
                    (root->left->color == Color::RED ||
                    root->right->color == Color::RED))
                return 0;
            int left = valid_bh(root->left);
            if(left == 0) return 0;
            int right = valid_bh(root->right);
            if(right == 0 || left != right) return 0;
            return left + (root->color == Color::BLACK);
        }

        bool validBST(RBNode* root, long long min, long long max) {
            if(root == NIL) return true;

            if(root->val >= max)
                return false;
            if(root->val <= min)
                return false;
            return validBST(root->left, min, root->val) &&
                    validBST(root->right, root->val, max);
        }

        void fixupInsert(RBNode* node) {
            while(node != root && node->parent->color == Color::RED) {
                if(node->parent == node->parent->parent->left) {
                    RBNode* u = node->parent->parent->right;

                    if(u->color == Color::RED) {
                        node->parent->color = Color::BLACK;
                        u->color = Color::BLACK;
                        node->parent->parent->color = Color::RED;
                        node = node->parent->parent;
                    } else {
                        if(node == node->parent->right) {
                            node = node->parent;
                            leftRotate(node);
                        }

                        node->parent->color = Color::BLACK;
                        node->parent->parent->color = Color::RED;
                        rightRotate(node->parent->parent);
                    }
                } else {
                    RBNode* u = node->parent->parent->left;

                    if(u->color == Color::RED) {
                        node->parent->color = Color::BLACK;
                        u->color = Color::BLACK;
                        node->parent->parent->color = Color::RED;
                        node = node->parent->parent;
                    } else {
                        if(node == node->parent->left) {
                            node = node->parent;
                            rightRotate(node);
                        }

                        node->parent->color = Color::BLACK;
                        node->parent->parent->color = Color::RED;
                        leftRotate(node->parent->parent);
                    }
                }
            }
            root->color = Color::BLACK;
        }

        void fixupRemove(RBNode* x) {
            while(x != root && x->color == Color::BLACK) {
                if(x == x->parent->left) {
                    RBNode* w = x->parent->right;
                    
                    //case 1
                    if(w->color == Color::RED) {
                        w->color = Color::BLACK;
                        x->parent->color = Color::RED;

                        leftRotate(x->parent);
                        w = x->parent->right;
                    }

                    //case 2
                    if(w->left->color == Color::BLACK &&
                        w->right->color == Color::BLACK) {
                        
                        w->color = Color::RED;
                        x = x->parent;
                    
                    //case 3
                    } else {
                        if(w->right->color == Color::BLACK) {
                            w->left->color = Color::BLACK;
                            w->color = Color::RED;

                            rightRotate(w);
                            w = x->parent->right;
                        }

                        //case 4
                        w->color = x->parent->color;
                        x->parent->color = Color::BLACK;
                        w->right->color = Color::BLACK;

                        leftRotate(x->parent);
                        x = root;
                    }
                } else {
                    RBNode* w = x->parent->left;
                    
                    //case 1
                    if(w->color == Color::RED) {
                        w->color = Color::BLACK;
                        x->parent->color = Color::RED;

                        rightRotate(x->parent);
                        w = x->parent->left;
                    }

                    //case 2
                    if(w->left->color == Color::BLACK &&
                        w->right->color == Color::BLACK) {
                        
                        w->color = Color::RED;
                        x = x->parent;
                        
                    //case 3
                    } else {
                        if(w->left->color == Color::BLACK) {
                            w->right->color = Color::BLACK;
                            w->color = Color::RED;

                            leftRotate(w);
                            w = x->parent->left;
                        }

                        //case 4
                        w->color = x->parent->color;
                        x->parent->color = Color::BLACK;
                        w->left->color = Color::BLACK;

                        rightRotate(x->parent);
                        x = root;
                    }
                }
            }
            x->color = Color::BLACK;
        }

    public:
        RBTree() {
            NIL = new RBNode(0);
            NIL->color = Color::BLACK;
            NIL->left = NIL->right = NIL->parent = NIL;
            root = NIL;
        }

        RBNode* lower_bound(int val) {
            return lower_bound(root, val);
        }

        RBNode* upper_bound(int val) {
            return upper_bound(root, val);
        }

        std::pair<RBNode*, RBNode*> equal_range(int val) {
            return equal_range(root, val);
        }

        RBNode* successor(RBNode* x) {
            if(x->right != NIL)
                return min(x->right);

            RBNode* p = x->parent;

            while(p != NIL && x == p->right) {
                x = p;
                p = p->parent;
            }
            return p == NIL ? nullptr : p;
        }

        RBNode* predecessor(RBNode* x) {
            if(x->left != NIL)
                return max(x->left);

            RBNode* p = x->parent;

            while(p != NIL && x == p->left) {
                x = p;
                p = x->parent;
            }
            return p == NIL ? nullptr : p;
        }

        bool validate() {
            if(root->color != Color::BLACK)
                return false;
            if(!validBST(root, std::numeric_limits<long long>::lowest(), std::numeric_limits<long long>::max()))
                return false;
            if(!valid_bh(root))
                return false;
            return true;
        }

        void insert(int val) {
            RBNode* node = new RBNode(val);
            node->left = node->right = NIL;

            RBNode* par = NIL;
            RBNode* curr = root;

            while(curr != NIL) {
                par = curr;
                curr = val < curr->val ? curr->left : curr->right;
            }

            node->parent = par;

            if(par == NIL) {
                root = node;
                root->color = Color::BLACK;
                return;
            } else if (val < par->val) {
                par->left = node;
            } else {
                par->right = node;
            }

            if(node->parent->parent == NIL)
                return;

            fixupInsert(node);
        }

        void remove(RBNode* node) {
            RBNode* y = node;
            RBNode* x = nullptr;
            Color orig = node->color;

            if(node->right == NIL) {
                x = node->left;
                tp(node, node->left);
            } else if(node->left == NIL) {
                x = node->right;
                tp(node, node->right);
            } else {
                y = min(node->right);
                orig = y->color;
                x = y->right;

                if(y->parent == node) {
                    x->parent = y;
                } else {
                    tp(y, y->right);
                    y->right = node->right;
                    y->right->parent = y;
                }

                tp(node, y);
                
                y->left = node->left;
                y->left->parent = y;
                y->color = node->color;
            }

            delete node;
            if(orig == Color::BLACK)
                fixupRemove(x);
        }
};
