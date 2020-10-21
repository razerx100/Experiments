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
                recursive_insert(node->left_child, value);
        }
        else if(value == node->value){
            return node;
        }
        else{
            if(node->right_child)
                recursive_insert(node->right_child, value);
        }
        return 0;
    }
    public:
    Bst() : root(0) {}
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
        //TO DO
    }
};
}
#endif