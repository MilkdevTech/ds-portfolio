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

  cout << "Contact Directory\n";
  cout << "commands - ADD first , last , phone , LIST\n";
  cout << "Press CTRL + D to exit\n";

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
	else
	  {
	    cout << "invalid\n";
	  }
    }
	return 0;
	 


  
}
