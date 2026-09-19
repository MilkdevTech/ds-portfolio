#include <iostream>
#include <sstream>
#include <string>
#include "Stack.h"

// Describes the type of document change
enum ActionType
{
    TYPE_ACTION,
    DELETE_ACTION
};

// Stores information needed to undo an action
struct EditAction
{
    ActionType type;
    std::string text;
};

int main()
{
    std::string document;
    std::string input;

    Stack<EditAction> undoStack;
    Stack<EditAction> redoStack;

    std::cout << "Undo/Redo Text Buffer\n";
    std::cout << "Commands: TYPE <text>, DELETE <n>, PRINT, QUIT\n";

    while (true)
    {
        std::cout << "\n> ";
        std::getline(std::cin, input);

        // Adds text to the end of the document
        if (input.compare(0, 5, "TYPE ") == 0)
        {
            std::string typedText = input.substr(5);
            document += typedText;

            EditAction action = {TYPE_ACTION, typedText};
            undoStack.push(action);

            // A new edit clears the redo history
            redoStack.clear();
        }
        // Deletes characters from the end of the document
        else if (input.compare(0, 7, "DELETE ") == 0)
        {
            std::istringstream parser(input.substr(7));
            std::size_t amount;

            if (!(parser >> amount))
            {
                std::cout << "Invalid DELETE command\n";
                continue;
            }

            // Prevents deleting past the beginning
            if (amount > document.size())
            {
                amount = document.size();
            }

            std::string deletedText =
                document.substr(document.size() - amount);

            document.erase(document.size() - amount);

            EditAction action = {DELETE_ACTION, deletedText};
            undoStack.push(action);

            // A new edit clears the redo history
            redoStack.clear();
        }
        // Displays the current document
        else if (input == "PRINT")
        {
            std::cout << "Document: " << document << '\n';
        }
        // Ends the program
        else if (input == "QUIT")
        {
            break;
        }
        else
        {
            std::cout << "Unknown command\n";
        }
    }

    return 0;
}
