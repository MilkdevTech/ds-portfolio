#ifndef BST_H
#define BST_H

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
    }
    ;

    Node* root;  // Points at top node

public:
    // Create the first empty tree
    BST()
        : root(nullptr)
    {
    }
};

#endif
