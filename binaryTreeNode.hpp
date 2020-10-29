#ifndef __BINARY_TREE_NODE_HPP__
#define __BINARY_TREE_NODE_HPP__
#include<ostream>
namespace Chronos{
    class BTNode{
        public:
        int value;
        BTNode *left_child, *right_child, *parent;
        BTNode(int value) : value(value), left_child(0), right_child(0), parent(0) {}
        friend std::ostream& operator<<(std::ostream& out, const BTNode& other){
            out << other.value;
            return out;
        }
    };
}
#endif