#ifndef __BST_HPP__
#define __BST_HPP__
#include<iostream>
namespace Chronos{
    class BstNode{
        public:
        int value;
        BstNode *left_child, *right_child, *parent;
        BstNode(int value) : value(value), left_child(0), right_child(0), parent(0) {}
        friend std::ostream& operator<<(std::ostream& out, const BstNode& other){
            out << other.value;
            return out;
        }
    };
    class BstIterator{
        private:
        BstNode* m_ptr;
        public:
        BstIterator(BstNode* ptr) : m_ptr(ptr) {}
        BstNode& operator*(){
            return *m_ptr;
        }
        BstNode* operator->(){
            return m_ptr;
        }
        bool operator==(const BstIterator& other) const {
            return m_ptr == other.m_ptr;
        }
        bool operator!=(const BstIterator& other) const {
            return m_ptr != other.m_ptr;
        }
        BstIterator& operator++(){
            //TO DO
        }
        BstIterator& operator--(){
            //TO DO
        }
    };
    class Bst{
        private:
        BstNode *root;
        void recursive_insert(BstNode* node, int value){
            if(value < node->value){
                if(node->left_child)
                    recursive_insert(node->left_child, value);
                else{
                    BstNode *var = new BstNode(value);
                    node->left_child = var;
                    var->parent = node;
                }
            }
            else if(value > node->value){
                if(node->right_child)
                    recursive_insert(node->right_child, value);
                else{
                    BstNode *var = new BstNode(value);
                    node->right_child = var;
                    var->parent = node;
                }
            }
        }
        BstNode* search(int value, BstNode *node){
            if(value < node->value){
                if(node->left_child)
                    return search(value, node->left_child);
            }
            else if(value == node->value){
                return node;
            }
            else{
                if(node->right_child)
                    return search(value, node->right_child);
            }
            return 0;
        }
        void insert_branch(BstNode* root, BstNode* node){
            if(root->value > node->value){
                if(root->left_child)
                    insert_branch(root->left_child, node);
                else{
                    root->left_child = node;
                    node->parent = root;
                }
            }
            else if(root->value < node->value){
                if(root->right_child)
                    insert_branch(root->right_child, node);
                else{
                    root->right_child = node;
                    node->parent = root;
                }
            }
        }
        public:
        Bst() : root(0) {}
        using Iterator = BstIterator;
        void Insert(int value){
            BstNode *var = new BstNode(value);
            if(!root){
                root = var;
            }
            else{
                recursive_insert(root, value);
            }
        }
        void Delete(int value){
            BstNode *node = search(value, root);
            if(node->left_child and node->right_child){
                if(node == root){
                    root = node->right_child;
                    root->parent = 0;
                }
                else{
                    BstNode* ptr = node->parent;
                    if(node == ptr->left_child){
                        ptr->left_child = node->right_child;
                        node->right_child->parent = ptr;
                    }
                    else{
                        ptr->right_child = node->right_child;
                        node->right_child->parent = ptr;
                    }
                }
                insert_branch(node->right_child, node->left_child);
            }
            else if(node->left_child){
                if(node == root){
                    root = node->left_child;
                    root->parent = 0;
                }
                else{
                    node->parent->right_child = 0;
                    insert_branch(node->parent, node->left_child);
                }
            }
            else if(node->right_child){
                if(node == root){
                    root = node->right_child;
                    root->parent = 0;
                }
                else{
                    node->parent->left_child = 0;
                    insert_branch(node->parent, node->right_child);
                }
            }
            else{
                if(node == root){
                    root = 0;
                }
                else{
                    BstNode *ptr = node->parent;
                    if(node == ptr->left_child){
                        ptr->left_child = 0;
                    }
                    else{
                        ptr->right_child = 0;
                    }
                }
            }
            delete node;
        }
        Iterator begin(){
            //TO DO
        }
        Iterator end(){
            //TO DO
        }
    };
}
#endif