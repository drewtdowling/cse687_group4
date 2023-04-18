///////////////////////////////////////////////////////////////////////
// sorter.cpp - create single linked list to sort alphabetically     //
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
#include <sstream>
#include <string>
#include <vector>

#include "sorter.h"

class Node {
public:
    std::string word;
    std::vector<std::string> values;
    Node* next;

    //default constructor
    Node() {
        this->word = " ";
        this->values.push_back("0");
        this->next = nullptr;
    }

    //overloaded constructor
    Node(std::string word, std::string value) {
        this->word = word;
        this->values.push_back(value);
        this->next = nullptr;
    }

    //destructor
    ~Node() {

    }
};

//constructor
LinkedList::LinkedList()
{
    head = nullptr;
    size = 0;
}

//destructor
LinkedList::~LinkedList()
{
    Node* current = head;
    Node* next;
    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
}

//insert a new node with a given value into the list in alphabetical order
void LinkedList::insert(std::string str)
{
    //parse the input string to get the word and count
    int commaPos = str.find(',');
    std::string word = str.substr(1, commaPos - 1);
    std::string value = str.substr(commaPos + 2, str.length() - commaPos - 3);

    //create a new node with the word and count
    Node* newNode = new Node(word, value);

    //if list is empty, set new node as head and increase list size
    if (this->head == nullptr) {
        this->head = newNode;
        size++;
        return;
    }

    Node* currNode = this->head;
    Node* prevNode = nullptr;

    //traverse list to find correct position to insert new node
    while (currNode != nullptr && currNode->word < word) {
        prevNode = currNode;
        currNode = currNode->next;
    }
    //if a node with the same word already exists in the list, append the 
    //value to its values vector
    if (currNode != nullptr && currNode->word == word) {
        currNode->values.push_back(value);
        delete newNode;
    }
    //otherwise, insert the new node into the list
    else {
        if (prevNode == nullptr) {
            this->head = newNode;
        }
        else {
            prevNode->next = newNode;
        }
        newNode->next = currNode;
        size++;
    }

}

//get the current size of the list
int LinkedList::getSize() const
{
    return size;
}

//get the value of the node at a specific index in the list
std::string LinkedList::getNode(int index) const
{
    //ensure requested index is valid
    if (index < 0 || index >= size) {
        throw std::out_of_range("Invalid index");
    }

    //find the specified index in the list
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    //declare valuesOut string that contains all values formatted for a node
    std::string valuesOut = "[";

    //append each value in values to valuesOut string
    for (auto s = current->values.begin(); s != current->values.end(); s++) {
        valuesOut += *s;

        //insert commas between values in valuesOut string
        if (s != current->values.end() - 1) {
            valuesOut += ", ";
        }
    }
    //append closing square bracket to valuesOut
    valuesOut += "]";

    //put word value and valuesOut into single string and return
    std::stringstream ss;
    ss << "(" << current->word << ", " << valuesOut << ")";
    return ss.str();
}