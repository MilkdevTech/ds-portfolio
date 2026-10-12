#include <iostream>
#include "BST.h"

int main()
{
    // Tests my tree
    BST<int> numbers;

    std::cout << "Empty tree size: " << numbers.size() << '\n';

    
    // insert numbers
    numbers.insert(50);
    numbers.insert(30);
    numbers.insert(70);
    numbers.insert(20);
    numbers.insert(40);

    // Check size after adding numbers
    std::cout << "after inserts: "
              << numbers.size() << '\n';

    // add a a test duplicate
    numbers.insert(30);

    std::cout << "after duplicate: "
              << numbers.size() << '\n';

    return 0;
}
