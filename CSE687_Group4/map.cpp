////////////////////////////////////////////////////////////////////////
// map.cpp - takes a sentence and breaks it into individual words     //
// ver 1.1                                                            //
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

ver 1.1 : 21 April 2023
-fixed minor bugs (flag to flag_)
*/

#include "map.h"
#include <iostream>
#include <string>
#include <sstream>

using std::string;
using std::getline;
using std::stringstream;

Map::Map()
  : flag_(true)
{

}

string Map::map(string text) 
// string text : a full line of text to parse through
{
  stringstream ss_in;
  string output = "";
  string word = "";

  ss_in << text;
  while (getline(ss_in, word, ' ')) {
    word = format(word);
    if (word != "") {
      word = tuplize(word);
      output.append(word);
    }
  }

  return output;
}


bool const Map::GetFlag() // Returns object's flag
{
  return flag_;
}


void Map::SetFlag(bool new_flag) // Sets object's flag
{
  flag_ = new_flag;
}


string Map::format(string word) // Format and error check a single word taken from inputted string
{
  // Convert to lowercase
  word = lowercase(word);

  // Filter out given strings
  word = filter(word, "\'s", false);  // 's
  word = filter(word, "\'", true);    // starting with '
  word = filter(word, ".", false);    // .
  word = filter(word, ",", false);    // ,
  word = filter(word, "!", false);    // !
  word = filter(word, "-", false);    // -
  word = filter(word, "_", false);    // _

  return word;
}


string Map::lowercase(string word) // Convert a string to all lowercase alphanumeric
// string word : Input string
{
  for (unsigned int i = 0; i < word.length(); i++) {
    word[i] = tolower(word[i]);
  }

  return word;
}


string Map::filter(string word, string filter, bool starts_with) // Removes filtered string from word input
// string word : Input string (e.g. 'tis)
// string filter : Phrase to be removed from input string (e.g. ' )
// bool startsWith : Only checks if it starts with the filter and removes it (e.g. 'tisn't -> tisn't),
//                    if set to false, will remove all instances of filter (e.g. 'tisn't -> tisnt)
{
  std::size_t index = word.find(filter);

  if (index == size_t(0) && starts_with) // Only removes the first instance of filter if word starts with filter
  {
    word.replace(index, filter.length(), "");
    return word;
  }


  while (index != std::string::npos && !starts_with)
  {
    word.replace(index, filter.length(), "");
    index = word.find(filter);
  }

  return word;
}


string Map::tuplize(string word) // Creates the (word, 1) tuple given a single word
// string word : String to make into tuple
{
  string tuple;
  tuple = "(" + word + ", 1)\n";
  return tuple;
}