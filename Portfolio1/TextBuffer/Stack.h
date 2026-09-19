#ifndef STACK_H
#define STACK_H

#include <cstddef>
#include <stdexcept>

template <typename T>
class Stack
{
private:
    T* data;                 // Stores the stack values
    std::size_t itemCount;   // Number of stored values
    std::size_t capacity;    // Size of the array

    // Doubles the array when it becomes full
    void expand()
    {
        std::size_t newCapacity = capacity * 2;
        T* newData = new T[newCapacity];

        // Copies the values into the larger array
        for (std::size_t i = 0; i < itemCount; ++i)
        {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    // Creates an empty stack
    Stack()
        : data(new T[10]), itemCount(0), capacity(10)
    {
    }

    // Deletes the stack array
    ~Stack()
    {
        delete[] data;
    }

    // Creates a deep copy of another stack
    Stack(const Stack<T>& other)
        : data(new T[other.capacity]),
          itemCount(other.itemCount),
          capacity(other.capacity)
    {
        for (std::size_t i = 0; i < itemCount; ++i)
        {
            data[i] = other.data[i];
        }
    }

    // Replaces this stack with a deep copy
    Stack<T>& operator=(const Stack<T>& other)
    {
        if (this != &other)
        {
            T* newData = new T[other.capacity];

            // Copies values before deleting the old array
            for (std::size_t i = 0; i < other.itemCount; ++i)
            {
                newData[i] = other.data[i];
            }

            delete[] data;
            data = newData;
            itemCount = other.itemCount;
            capacity = other.capacity;
        }

        return *this;
    }

    // Adds a value to the top
    void push(const T& value)
    {
        if (itemCount == capacity)
        {
            expand();
        }

        data[itemCount] = value;
        ++itemCount;
    }

    // Removes the top value
    bool pop()
    {
        if (isEmpty())
        {
            return false;
        }

        --itemCount;
        return true;
    }

    // Returns the top value
    T& top()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Cannot read an empty stack");
        }

        return data[itemCount - 1];
    }

    // Returns the top value without allowing changes
    const T& top() const
    {
        if (isEmpty())
        {
            throw std::runtime_error("Cannot read an empty stack");
        }

        return data[itemCount - 1];
    }

    // Returns true when the stack is empty
    bool isEmpty() const
    {
        return itemCount == 0;
    }

    // Returns the number of stored values
    std::size_t size() const
    {
        return itemCount;
    }

    // Removes every value
    void clear()
    {
        itemCount = 0;
    }
};

#endif
