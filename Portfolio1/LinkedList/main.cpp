#include <iostream>
#include "LinkedList.h"

int main()
{
    LinkedList<int> original;

    original.pushBack(10);
    original.pushBack(20);
    original.pushBack(30);

    // Tests the copy constructor
    LinkedList<int> copied(original);
    copied.remove(20);
    copied.pushBack(40);

    std::cout << "Original size: " << original.size() << '\n';
    std::cout << "Original contains 20: "
              << original.contains(20) << '\n';

    std::cout << "Copied size: " << copied.size() << '\n';
    std::cout << "Copied contains 20: "
              << copied.contains(20) << '\n';
    std::cout << "Copied contains 40: "
              << copied.contains(40) << '\n';

    // Tests the copy assignment operator
    LinkedList<int> assigned;
    assigned.pushBack(99);
    assigned = original;
    assigned.popFront();

    std::cout << "Original size after assignment: "
              << original.size() << '\n';
    std::cout << "Assigned size: " << assigned.size() << '\n';

    // Tests self-assignment
    assigned = assigned;
    std::cout << "Assigned size after self-assignment: "
              << assigned.size() << '\n';

    return 0;
}
