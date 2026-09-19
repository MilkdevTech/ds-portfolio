#include <iostream>
#include <string>
#include "Stack.h"

int main()
{
    Stack<int> numbers;

    // Tests push, top, size, and pop
    numbers.push(10);
    numbers.push(20);
    numbers.push(30);

    std::cout << "Top: " << numbers.top() << '\n';
    std::cout << "Size: " << numbers.size() << '\n';

    numbers.pop();

    std::cout << "Top after pop: " << numbers.top() << '\n';

    // Tests the copy constructor
    Stack<int> copied = numbers;
    copied.push(40);

    std::cout << "Original top: " << numbers.top() << '\n';
    std::cout << "Copied top: " << copied.top() << '\n';

    // Tests the assignment operator with strings
    Stack<std::string> words;
    words.push("undo");
    words.push("redo");

    Stack<std::string> assigned;
    assigned = words;

    std::cout << "Assigned top: " << assigned.top() << '\n';

    return 0;
}
