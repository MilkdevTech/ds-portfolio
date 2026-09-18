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

        // Creates a new node
        Node(const T& newValue, Node* nextNode = nullptr)
            : value(newValue), next(nextNode)
        {
        }
    };

    Node* head;             // Points to the first node
    std::size_t itemCount;  // Tracks the number of nodes

    // Deletes every node in the list
    void clear()
    {
        while (head != nullptr)
        {
            Node* nodeToDelete = head;
            head = head->next;
            delete nodeToDelete;
        }

        itemCount = 0;
    }

    // Copies every value from another list
    void copyFrom(const LinkedList<T>& other)
    {
        Node* current = other.head;

        while (current != nullptr)
        {
            pushBack(current->value);
            current = current->next;
        }
    }

public:
    // Moves forward through the list
    class Iterator
    {
    private:
        Node* current;

    public:
        // Starts the iterator at a node
        Iterator(Node* node)
            : current(node)
        {
        }

        // Moves to the next node
        Iterator& operator++()
        {
            if (current != nullptr)
            {
                current = current->next;
            }

            return *this;
        }

        // Returns the current value
        T& operator*() const
        {
            return current->value;
        }

        // Compares two iterator positions
        bool operator!=(const Iterator& other) const
        {
            return current != other.current;
        }
    };

    // Creates an empty list
    LinkedList()
        : head(nullptr), itemCount(0)
    {
    }

    // Deletes all nodes when the list is destroyed
    ~LinkedList()
    {
        clear();
    }

    // Creates a deep copy of another list
    LinkedList(const LinkedList<T>& other)
        : head(nullptr), itemCount(0)
    {
        copyFrom(other);
    }

    // Replaces this list with a deep copy
    LinkedList<T>& operator=(const LinkedList<T>& other)
    {
        // Protects against self-assignment
        if (this != &other)
        {
            clear();
            copyFrom(other);
        }

        return *this;
    }

    // Returns the number of items
    std::size_t size() const
    {
        return itemCount;
    }

    // Returns true when the list is empty
    bool isEmpty() const
    {
        return itemCount == 0;
    }

    // Adds a value to the front
    void pushFront(const T& value)
    {
        head = new Node(value, head);
        ++itemCount;
    }

    // Adds a value to the back
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

            // Moves to the final node
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

        // Uses popFront when the head contains the value
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

    // Returns an iterator at the first node
    Iterator begin()
    {
        return Iterator(head);
    }

    // Returns an iterator past the final node
    Iterator end()
    {
        return Iterator(nullptr);
    }
};

#endif
