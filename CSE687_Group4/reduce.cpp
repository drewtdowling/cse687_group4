///////////////////////////////////////////////////////////////////////
// reduce.cpp - converts string to reduced format                    //
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

#include <iostream>
#include <string>
#include <vector>
#include "reduce.h"

//default constructor
Reducer::Reducer()
{

}

//overlaoded constructor
Reducer::Reducer(std::string str)
{
  //extract the word from the string
  int word_start = str.find("(") + 1;
  int word_end = str.find(",");
  word = str.substr(word_start, word_end - word_start);

  //extract the values from the string
  int valuesStart = str.find("[") + 1;
  int valuesEnd = str.find("]");
  std::string valueString = str.substr(valuesStart, valuesEnd - valuesStart);



  //parse the values as integers and sum them up
  std::vector<int> totalValues;
  int pos = 0;

  //find the commas in the value string
  while ((pos = valueString.find(",")) != std::string::npos)
  {
    //extract substring "1"
    std::string token = valueString.substr(0, pos);
    //erases substring from the valueString
    valueString.erase(0, pos + 1);
    //converts the token string "1" to an integer and adds it to totalValues
    totalValues.push_back(std::stoi(token));
  }
  //add the last count, or only count if valueString only had one value
  totalValues.push_back(std::stoi(valueString));

  //set count for total of values in valueString
  for (int c : totalValues)
  {
    count += c;
  }
}

//takes in string and reduces to key value pair
std::string Reducer::reduce(std::string str)
{
  //clear count
  count = 0;
  //extract the word from the string
  int word_start = str.find("(") + 1;
  int word_end = str.find(",");
  word = str.substr(word_start, word_end - word_start);

  //extract the values from the string
  int valuesStart = str.find("[") + 1;
  int valuesEnd = str.find("]");
  std::string valueString = str.substr(valuesStart, valuesEnd - valuesStart);



  //parse the values as integers and sum them up
  std::vector<int> totalValues;
  int pos = 0;

  //find the commas in the value string
  while ((pos = valueString.find(",")) != std::string::npos)
  {
    //extract substring "1"
    std::string token = valueString.substr(0, pos);
    //erases substring from the valueString
    valueString.erase(0, pos + 1);
    //converts the token string "1" to an integer and adds it to totalValues
    totalValues.push_back(std::stoi(token));
  }
  //add the last count, or only count if valueString only had one value
  totalValues.push_back(std::stoi(valueString));

  //set count for total of values in valueString
  for (int c : totalValues)
  {
    count += c;
  }

  return Reducer::exporter(word, count);
}

//gets the reducer value as a string
std::string Reducer::exporter(std::string str, int value)
{
  return "(" + str + ", " + std::to_string(value) + ")";
}