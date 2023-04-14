///////////////////////////////////////////////////////////////////////
// Sorter.cpp - create single linked list to sort alphabetically     //
// ver 4.2                                                           //
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
#include"Sorter.h"

//Node class represents a node in the linked list
class Node
{
public:
    std::string data; // the data value of the node
    Node* next; // pointer to the next node in the list

    //constructor that initializes the node with a value
    Node(const std::string& value) : data(value), next(nullptr) {}
};

//LinkedList class represents a linked list data structure
//constructor that initializes the list with an empty head node
LinkedList::LinkedList() : head(nullptr), size(0) {}

//destructor that frees up the memory allocated by the list nodes
LinkedList::~LinkedList()
{
    Node* current = head;
    while (current != nullptr)
    {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    size = 0;
}

//insert a new node with a given value into the list in alphabetical order
void LinkedList::insertNode(const std::string& value)
{
    Node* newNode = new Node(value);

    //if the list is empty or the new node should be inserted at the beginning of the list
    if (head == nullptr || head->data >= value)
    {
        newNode->next = head;
        head = newNode;
    }
    else {
        //find the position to insert the new node in the list
        Node* current = head;
        while (current->next != nullptr && current->next->data < value)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    size++;
}

//display the values of the nodes in the list in order
void LinkedList::displayList() const
{
    Node* current = head;
    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

//get the current size of the list
int LinkedList::getSize() const
{
    return size;
}

//get the value of the node at a specific index in the list
std::string LinkedList::getNode(int index) const
{
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    Node* current = head;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    return current->data;
}

//get the first node in the list and remove it from the list
std::string LinkedList::pop()
{
    if (head == nullptr)
    {
        throw std::out_of_range("List is empty");
    }
    std::string value = head->data;
    Node* temp = head;
    head = head->next;
    delete temp;
    //shrink size of list to account for deleted node
    size--;
    return value;
}


//test main function to test the LinkedList class
//int main() {
//  LinkedList myList;
//  myList.insertNode("(a,1)");
//  myList.insertNode("(this,1)");
//  myList.insertNode("(pie,1)");
//  myList.insertNode("(date,1)");
//  myList.insertNode("(shakespeare,1)");
//  myList.insertNode("(romeo,1)");
//  myList.insertNode("('ost,1)");
//  myList.insertNode("(shakespeare,1)");
//  myList.insertNode("(shakespeare,1)");
//  myList.displayList();
//  std::cout << "\n";
//  myList.pop();
//  myList.displayList();
//  return 0;
//}