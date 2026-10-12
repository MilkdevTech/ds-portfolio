#ifndef BST_H
#define BST_H

#include <cstddef>

template <typename T>
class BST
{
private:
    // basic node structure
    // one value two children
    struct Node
    {
        T value;
        Node* left;
        Node* right;

        // Node without children
        Node(const T& newValue)
            : value(newValue), left(nullptr), right(nullptr)
        {

        }
    };

    Node* root;  // Points at top node

    // counts nodes
    std::size_t countNodes(Node* current) const
    {
        // no node here
        if (current == nullptr)
        {
            return 0;
        }

        // this node plus both sides
        return 1 + countNodes(current->left)
                 + countNodes(current->right);
    }

public:
    // empty tree
    BST()
        : root(nullptr)
    {

    }

    // total nodes in tree
    std::size_t size() const
    {
        return countNodes(root);
    }
};

#endif
