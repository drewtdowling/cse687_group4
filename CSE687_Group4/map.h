#ifndef MAP_H
#define MAP_H
////////////////////////////////////////////////////////////////////////
// map.h - takes a sentence and breaks it into individual words       //
// ver 1.0                                                            //
// Language:    C++, Visual Studio 2022                               //
// Platform:    Windows 11                                            //
// Application: Mapping component, CSE687 - Object Oriented Design    //
// Author:      Kenzo Bird, Syracuse University                       //
//              ksbird@syr.edu                                        //
////////////////////////////////////////////////////////////////////////
/*
Package Operations:
-------------------
This package allows the input of a full line of text, breaks it down into
individual words and then strips the words of specified punctuation before
creating them into (word, 1) tuples.
The map() function takes the input string and breaks it down. format()
controls what filter() will check on each word. The lowercase() ensures the
word is in all lowercase before using filters.
Included is a flag to check if the object is in use in case of future
modifications that require it.

Maintenance History:
--------------------
ver 1.0 : 14 April 2023
-initial release
*/

#include <string>
#include <sstream>

class Map {
public:
  Map(); // Constructor

  std::string map(std::string); // Accepts a single line of raw data from file and tokenize into distinct words

  bool const GetFlag(); // Returns object's flag
  void SetFlag(bool); // Sets object's flag

private:
  bool flag_; // Flag for object when busy;

  std::string format(std::string); // Format and error check a single word taken from inputted string
  std::string lowercase(std::string); // Convert a string to all lowercase alphanumeric
  std::string filter(std::string, std::string, bool); // Removes filtered string from word input
  std::string tuplize(std::string); // Creates the ("word", 1) tuple given a single word
};


#endif  // MAP_H
