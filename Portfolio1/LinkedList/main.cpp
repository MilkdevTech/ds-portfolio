#include <iostream>
#include "LinkedList.h"

int main()
{
    LinkedList<int> numbers;

    // Builds the list with three values
    numbers.pushFront(10);
    numbers.pushFront(5);
    numbers.pushBack(20);

    std::cout << "Starting size: " << numbers.size() << '\n';
    std::cout << "Contains 10: " << numbers.contains(10) << '\n';
    std::cout << "Contains 99: " << numbers.contains(99) << '\n';

    // Removes a value from the middle
    std::cout << "Remove 10: " << numbers.remove(10) << '\n';
    std::cout << "Size after remove: " << numbers.size() << '\n';

    // Removes the first value
    std::cout << "Pop front: " << numbers.popFront() << '\n';
    std::cout << "Size after pop: " << numbers.size() << '\n';

    // Tries to remove a value that is not present
    std::cout << "Remove 99: " << numbers.remove(99) << '\n';

    return 0;
}
