# Portfolio 2: BST and Contact Directory

**CSC 2180 Data Structures**

## Overview

For Portfolio 2, I created a Binary Search Tree and then used it to build a Contact Directory application.

## Part A: Binary Search Tree

I built a templated BST that supports inserting, searching, removing, counting nodes, and finding tree height. I also implemented inorder, preorder, postorder, and level order traversals.

I used the Rule of Three for copying, assignment, and memory cleanup.

## Part B: Contact Directory

I used my BST to store contacts with a first name, last name, and phone number. Contacts are sorted by last name and then first name.

The program supports ADD, LOOKUP, DELETE, LIST, and COUNT. COUNT also displays the height of the BST.

I made a terminal interface that explains the available commands and gives an example so someone using it can understand what to do.

## Compiling on Ludwig

Navigate to the `Portfolio2/BST` directory.

To compile and run the BST tests:

`g++ -std=c++11 -Wall -Wextra -pedantic main.cpp -o bst_test`

`./bst_test`

To compile and run the Contact Directory:

`g++ -std=c++11 -Wall -Wextra -pedantic contacts.cpp -o contacts`

`./contacts`

Press Ctrl+D to exit the Contact Directory.

## Challenges and What I Learned

The hardest part for me was going back and forth between private and public functions. Sometimes it felt like I was doing the same thing twice just to get functions to call each other.

I think the biggest thing I learned was recursion. We used it constantly throughout the BST, and having to work with it so much helped me understand it better.

## My Favorite Part

My favorite part of development is when the frontend actually works. I enjoyed making the Contact Directory interface look good, even though it is only a terminal program.

I wanted it to be clean and easy to understand, which I think accomplished the goal of making the application user friendly.

## Known Limitations and Future Improvements

Contacts are stored in memory and aren't saved when the program closes. Names must be entered as single words, and capitalization matters.

The DELETE command removes everyone with the same last name. I think this could be improved because users should be able to choose which specific contact they want to delete.

If I had more time, I would make the Contact Directory open in its own window. I would also add buttons and selectable options so people wouldn't have to type commands for everything.