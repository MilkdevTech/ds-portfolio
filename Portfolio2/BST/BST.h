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

    // Searches for value in the tree
    bool searchNode(Node* current, const T& target) const
    {
        // Value not found
        if (current == nullptr)
        {
            return false;
        }

        // value found
        if (target == current->value)
        {
            return true;
        }

        // left side
        if (target < current->value)
        {
            return searchNode(current->left, target);
        }

        // switch ro right side
        return searchNode(current->right, target);
    }

    // to find the smallest node
    Node* findMin(Node* current) const
    {
        while (current->left != nullptr)
        {
            current = current->left;
        }

        return current;
    }

    // remove using recursion
    Node* removeNode(Node* current, const T& target)
    {
        if (current == nullptr)
        {
            return nullptr;
        }

        if (target < current->value)
        {
            current->left = removeNode(current->left, target);
        }
        else if (current->value < target)
        {
            current->right = removeNode(current->right, target);
        }
        else
        {
            // No children means return nullptr
            if (current->left == nullptr &&
                current->right == nullptr)
            {
                delete current;
                return nullptr;
            }

            // return right child
            if (current->left == nullptr)
            {
                Node* child = current->right;
                delete current;
                return child;
            }

            // return left child
            if (current->right == nullptr)
            {
                Node* child = current->left;
                delete current;
                return child;
            }

            // Both children
            Node* successor = findMin(current->right);
            current->value = successor->value;

            current->right = removeNode(current->right,
                                        successor->value);
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

    // Checks whether a value exists
    bool search(const T& target) const
    {
        return searchNode(root, target);
    }

    //removal in BST
    void remove(const T& target)
    {
        root = removeNode(root, target);
    }

    // total nodes in tree
    std::size_t size() const
    {
        return countNodes(root);
    }
};

#endif
