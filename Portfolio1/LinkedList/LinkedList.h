#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstddef>

template <typename T>
class LinkedList
{
private:
    // Stores one value and a pointer to the next node
    struct Node
    {
        T value;
        Node* next;

        // Creates a node containing newValue
        Node(const T& newValue, Node* nextNode = nullptr)
            : value(newValue), next(nextNode)
        {
        }
    };

    Node* head;             // Points to the first node
    std::size_t itemCount;  // Tracks the number of nodes

public:
    // Creates an empty list
    LinkedList()
        : head(nullptr), itemCount(0)
    {
    }

    // Returns the number of items in the list
    std::size_t size() const
    {
        return itemCount;
    }

    // Returns true when the list has no items
    bool isEmpty() const
    {
        return itemCount == 0;
    }
};

#endif
