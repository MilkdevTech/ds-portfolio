#include <iostream>
#include "BST.h"

using namespace std;

int main()
{
    // Create an empty BST
    BST<int> numbers;

    cout << "Empty tree size - "
         << numbers.size() << '\n';

    // Add to the tree
    numbers.insert(50);
    numbers.insert(30);
    numbers.insert(70);
    numbers.insert(20);
    numbers.insert(40);

    cout << "Size after inserts - "
         << numbers.size() << '\n';

    // add a duplicate
    numbers.insert(30);
    cout << "Size after duplicate - "
         << numbers.size() << '\n';

    // Test searching
    cout << boolalpha;

    cout << "Searching for 40 - "
         << numbers.search(40) << '\n';

    cout << "Searching for 70 - "
         << numbers.search(70) << '\n';

    cout << "Searching for 99 - "
         << numbers.search(99) << '\n';

    // Add more numbers for removal
    numbers.insert(60);
    numbers.insert(80);

    cout << "Size before removal - "
         << numbers.size() << '\n';

    // Remove a leaf
    numbers.remove(20);
    cout << "Size after removing 20 - "
         << numbers.size() << '\n';

    // Remove a node with one child
    numbers.remove(30);
    cout << "Size after removing 30 - "
         << numbers.size() << '\n';

    cout << "Searching for 40 - "
         << numbers.search(40) << '\n';

    // Remove a node with two children
    numbers.remove(50);
    cout << "Size after removing 50 - "
         << numbers.size() << '\n';

    cout << "Searching for 50 - "
         << numbers.search(50) << '\n';

    cout << "Searching for 60 - "
         << numbers.search(60) << '\n';

    // Try removing a number not in the tree
    numbers.remove(99);
    cout << "Size after removing 99 - "
         << numbers.size() << '\n';

    return 0;
}
