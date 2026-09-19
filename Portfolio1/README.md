# Portfolio 1

My name is Greyson Mullins and this is my first Data Structures
portfolio.

## Part 1A

For Part 1A, I made a templated singly linked list. It includes adding
and removing items, searching, checking the size, printing the list, and
using a range based for loop. I also added the Rule of Three and tested
the list with integers, strings, and cool mushroom sample data.

To compile and run on Ludwig:

```bash
g++ -std=c++11 -Wall -Wextra -pedantic LinkedList/main.cpp -o linked_list
./linked_list


## Part 1B

For Part 1B, I made my own templated Stack class and used two stacks to make
an undo and redo text buffer. It supports typing text, deleting text, undoing
changes, redoing changes, and printing the document.

The commands are:

- `TYPE <text>`
- `DELETE <n>`
- `UNDO`
- `REDO`
- `PRINT`
- `QUIT`

To compile and run on Ludwig:

```bash
g++ -std=c++11 -Wall -Wextra -pedantic TextBuffer/main.cpp -o text_buffer
./text_buffer
```

## Limitations

The text buffer only adds and deletes text from the end of the document. It
does not have a movable cursor or load commands from a file.