////////////////////////////////////////////////////////////////////////
// main.cpp - Workflow and Executive component for the Map-Reduce     //
// ver 1.1                                                            //
// Language:    C++, Visual Studio 2022                               //
// Platform:    Windows 11                                            //
// Application: Executive component, CSE687 - Object Oriented Design  //
// Author:      Kenzo Bird, Drew Dowling, Andrew Reichle,             //
//              Syracuse University                                   //
//              ksbird@syr.edu, drdowlin@syr.edu, afreichl@syr.edu    //
////////////////////////////////////////////////////////////////////////
/*
Package Operations:
-------------------


Maintenance History:
--------------------
ver 1.0 : 21 April 2023
-initial release

ver 1.1 : 21 April 2023
-sorter and reducer included
*/

#include "FileManagement/FileManagement.h"
#include "map.h"
#include "sorter.h"
#include "reduce.h"
#include <iostream>
#include <string>
#include <sstream>

int main()
{

  FileManagement fileManagement = FileManagement();

  Map map = Map();
  std::stringstream map_stream;
  std::string line = "";

  std::stringstream temp; // delete later

  map_stream << fileManagement.readInputFileToString("AsYouLIkeIte.txt");
  while (getline(map_stream, line, '\n')) {
    temp << map.map(line); // delete later
    //fileManagement.writeToIntermediateDirectoryWithString(map.map(line));
  }

  LinkedList linkedlist;
  std::string nodeline = "";
  std::stringstream sort_stream;

  //sort_stream << fileManagement.__();
  while (getline(temp, nodeline, '\n')) { // (getline(sort_stream, nodeline, '\n')){
    linkedlist.insert(nodeline);
  }

  std::stringstream temp2; // delete later

  for (int i = 0; i < linkedlist.getSize(); i++) {
    temp2 << linkedlist.getNode(i) << "\n"; // delete later
    //fileManagement.__(list.getNode(i));
  }

  Reducer reducer = Reducer();
  std::string sortedline = "";
  std::stringstream reduce_stream;

  //reduce_stream << fileManagement.__();
  std::stringstream temp3; // delete later
  while (getline(temp2, sortedline, '\n')) { // (getline(reduce_stream, sortedline, '\n')){
    temp3 << reducer.reduce(sortedline) << "\n"; // delete later
    //fileManagement.__(reducer.reduce(sortedline));
  }

  // testing print to console, delete below
  std::string tempstring = "";
  while (getline(temp3, tempstring, '\n')) {
    std::cout << tempstring << "\n";
  }

  // output success file

}