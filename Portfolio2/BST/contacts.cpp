#include <iostream>
#include <string>
#include "BST.h"

using namespace std;

//contact info
struct Contact
{

  string firstName;
  string lastName;
  string phone;

  //make contact
  Contact(string first, string last, string number)
    : firstName(first), lastName(last), phone(number)
  {
  }

  //sort last then first
  bool operator<(const Contact& other) const
  {
    if (lastName != other.lastName)
      {
	return lastName < other.lastName;
      }

    return firstName < other.firstName;

  }
  //name check
  bool operator==(const Contact& other) const
  {
    return firstName == other.firstName && lastName == other.lastName;
  }
};


//print person

void printContact(const Contact& person)
{
  cout << person.firstName << " "
       << person.lastName << " "
       << person.phone << "\n";
}

int main()
{
  BST<Contact> contacts;
  string command;

  cout << "\n=================================\n";
  cout << "        CONTACT DIRECTORY\n";
  cout << "=================================\n";
  cout << "Available Commands:\n\n";
  cout << " ADD first last phone - Add contact\n";
  cout << " LOOKUP last           - Find contact\n";
  cout << " LIST                  - Show contacts\n";
  cout << " DELETE last           - Remove contacts\n";
  cout << " COUNT                 - Show count and height\n";
  cout << "\nExample: ADD Greyson Mullins 123-4567\n";
  cout << "Press Ctrl+D to exit.\n";
  cout << "---------------------------------\n";
  //command interface

  while (cin >> command)
    {
      //add
      if (command == "ADD")
	{
	  string first, last, phone;

	  //get contact
	  if (!(cin >> first >> last >> phone))
	    {
	      break;
	    }

	  Contact person(first, last, phone);

	  //find name duplication
	  if (contacts.search(person))
	    {
	      cout << "Name exists\n";
	    }
	  else
	    {
	        contacts.insert(person);
	        cout << "Person added\n";
	    }
	}

	//contacts display
	else if (command =="LIST")
	  {

	    if(contacts.size() == 0)
	      {
		cout << "No contact\n";
	      }
	    else
	      {
		cout << "Contacts:\n";
		contacts.forEachInorder(printContact);
	      }
	  }
	else if (command == "LOOKUP")
	  {
	    string last;
	    cin >> last;

	    bool found = false;

	    contacts.forEachInorder([&](const Contact& person)
	    {
	      if (person.lastName == last)
		{
		  printContact(person);
		  found = true;    
		}
	    });
	      if (!found)
		{
		  cout << "Not found\n";
		}
	     

	      }
	else if (command == "DELETE")
	  {
	    string last;
	    cin >> last;

	    int removed = 0;

	    while (true)
	      {
		bool found = false;
		Contact match("", "", "");

		contacts.forEachInorder([&](const Contact& person)
		{
		  if(!found && person.lastName == last)
		    {
		      match = person;
		      found = true;
		    }
		});

		if (!found)
		  {
		    break;
		  }

		contacts.remove(match);
		removed++;
	      }
	    if (removed == 0)
	      {
		cout << "Not found\n";
	      }
	    
	     else
            {
                cout << "Deleted " << removed << " contacts\n";
            }
        }

        else if (command == "COUNT")
        {
            cout << "Total contacts: " << contacts.size() << "\n";
            cout << "Tree height: " << contacts.height() << "\n";
        }
  
	    else
	      {
		cout << "Unkown Command\n";
	      }

	  }



      return 0;	 
  
}
