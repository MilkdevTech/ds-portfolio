#include <iostream>
#include "LinkedList.h"

int main()
{
    // Creates an empty integer list
    LinkedList<int> numbers;

    std::cout << "Size: " << numbers.size() << '\n';
    std::cout << "Is empty: " << numbers.isEmpty() << '\n';

    return 0;
}
