#include <iostream>
#include "LinkedList.h"

int main()
{
    LinkedList<int> numbers;

    numbers.pushBack(10);
    numbers.pushBack(20);
    numbers.pushBack(30);

    // Uses the custom iterator
    for (int value : numbers)
    {
        std::cout << value << ' ';
    }

    std::cout << '\n';

    return 0;
}
