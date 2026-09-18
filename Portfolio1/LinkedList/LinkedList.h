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

    // Adds a value to the front of the list
    void pushFront(const T& value)
    {
        head = new Node(value, head);
        ++itemCount;
    }

    // Adds a value to the back of the list
    void pushBack(const T& value)
    {
        Node* newNode = new Node(value);

        // Makes the new node the head if the list is empty
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node* current = head;

            // Moves to the last node
            while (current->next != nullptr)
            {
                current = current->next;
            }

            current->next = newNode;
        }

        ++itemCount;
    }
    // Removes the first node
    bool popFront()
    {
        if (head == nullptr)
        {
            return false;
        }

        Node* nodeToDelete = head;
        head = head->next;
        delete nodeToDelete;
        --itemCount;

        return true;
    }

    // Removes the first matching value
    bool remove(const T& value)
    {
        if (head == nullptr)
        {
            return false;
        }

        // Uses popFront if the head contains the value
        if (head->value == value)
        {
            return popFront();
        }

        Node* current = head;

        // Finds the node before the matching node
        while (current->next != nullptr &&
               !(current->next->value == value))
        {
            current = current->next;
        }

        if (current->next == nullptr)
        {
            return false;
        }

        Node* nodeToDelete = current->next;
        current->next = nodeToDelete->next;
        delete nodeToDelete;
        --itemCount;

        return true;
    }

    // Returns true if the list contains the value
    bool contains(const T& value) const
    {
        Node* current = head;

        while (current != nullptr)
        {
            if (current->value == value)
            {
                return true;
            }

            current = current->next;
        }

        return false;
    }
};

#endif
