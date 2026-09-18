#include <iostream>
#include "LinkedList.h"

int main()
{
    // Creates an empty integer list
    LinkedList<int> numbers;

    std::cout << "Starting size: " << numbers.size() << '\n';
    std::cout << "Starting empty: " << numbers.isEmpty() << '\n';

    // Adds values to both ends of the list
    numbers.pushFront(10);
    numbers.pushFront(5);
    numbers.pushBack(20);

    std::cout << "Size after adding: " << numbers.size() << '\n';
    std::cout << "Empty after adding: " << numbers.isEmpty() << '\n';

    return 0;
}
