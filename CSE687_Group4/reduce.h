#ifndef REDUCER_H
#define REDUCER_H
///////////////////////////////////////////////////////////////////////
// reduce.h - converts string to reduced format                      //
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
This package provides a public Reducer class.
Reducer reads strings in the format of a word followed by a array of integers
and converts it to a string in the format of a word followed by an integer
representing the total of the integers in the input array

The Reducer class returns the reduced string using the function
getReduceString().

Maintenance History:
--------------------
ver 1.0 : 19 April 2023
-initial release
*/
class Reducer {

public:
  //default constructor
  Reducer();

  //overloaded constructor
  Reducer(std::string str);

  //takes in string and reduces to key value pair
  std::string reduce(std::string str);

  //gets the reducer value as a string
  std::string exporter(std::string, int);

private:
  std::string word;
  int count{ 0 };
};
#endif