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
// insert using recursion 
Node* insertNode(Node* current, const T& newValue)
    {
        if (current == nullptr)
        {
            return new Node(newValue);
        }

        if (newValue < current->value)
        {
            current->left = insertNode(current->left, newValue);
        }
        else if (current->value < newValue)
        {
            current->right = insertNode(current->right, newValue);
        }

        return current;
    }

public:
// empty tree
    BST()
        : root(nullptr)
    {

    }
// Adds a value to tree
    void insert(const T& newValue)
    {
        root = insertNode(root, newValue);
    }
    // total nodes in tree
    std::size_t size() const
    {
        return countNodes(root);
    }
};

#endif
