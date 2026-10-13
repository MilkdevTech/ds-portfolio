
#include <iostream>
#include "BST.h"

using namespace std;

int main()
{
    // Create an empty BST
    BST<int> numbers;

    cout << "Empty tree size: "
         << numbers.size() << '\n';

    // Add to the tree
    numbers.insert(50);
    numbers.insert(30);
    numbers.insert(70);
    numbers.insert(20);
    numbers.insert(40);

    cout << "Size after inserts: "
         << numbers.size() << '\n';

    // add a duplicate
    numbers.insert(30);

    cout << "Size after duplicate: "
         << numbers.size() << '\n';

    // Test searching
    cout << boolalpha;

    cout << "Searching for 40 - "
         << numbers.search(40) << '\n';

    cout << "Searching for 70 - "
         << numbers.search(70) << '\n';

    cout << "Searching for 99 - "
         << numbers.search(99) << '\n';

    return 0;
}
