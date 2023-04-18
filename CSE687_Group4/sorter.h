#ifndef SORTER_H
#define SORTER_H
///////////////////////////////////////////////////////////////////////
// sorter.h - create single linked list to sort alphabetically       //
// ver 1.0                                                           //
// Language:    C++, Visual Studio 2022                              //
// Platform:    Dell Precision 7750, Windows 10                      //
// Application: Sorting component, CSE687 - Object Oriented Design   //
// Author:      Andrew Reichle, Syracuse University                  //
//              afreichl@syr.edu                                     //
///////////////////////////////////////////////////////////////////////
/*
Package Operations:
-------------------
This package provides a public LinkedList class and a private Node class.
LinkedList reads strings in and sorts the the strings into a single linked
list alphabetically.

The LinkedList class returns the strings as one list in the console using
displayList() or can return a single specific string using getNode(int index)
The number of elements in the linked list can be returned using getSize().
The first string in the list can be returned and removed from the list using
pop().

Maintenance History:
--------------------
ver 1.0 : 14 April 2023
-initial release
*/

#include <iostream>
#include <string>

class Node; //private node class

class LinkedList
{
public:
	//constructor
	LinkedList();
	//destructor
	~LinkedList();
	//insert a new node with a given value into the list in alphabetical order
	void insert(const std::string);
	//get the current size of the list
	int getSize() const;
	//get the value of the node at a specific index in the list
	std::string getNode(int) const;

private:
	Node* head; //pointer to the first node in the list
	int size{ 0 }; //number of nodes in the list
};
#endif