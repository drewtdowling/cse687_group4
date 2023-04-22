////////////////////////////////////////////////////////////////////////
// main.cpp - Workflow and Executive component for the Map-Reduce     //
// ver 1.0                                                            //
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
*/

#include "FileManagement/FileManagement.h"
#include "map.h"
#include <iostream>
#include <string>
#include <sstream>

int main()
{

  FileManagement fileManagement = FileManagement();

  Map map = Map();
  std::stringstream map_stream;
  string line = "";

  map_stream << fileManagement.readInputFileToString("AsYouLIkeIte.txt");
  while (getline(map_stream, line, '\n')) {
    //std::cout << map.map(line);
    fileManagement.writeToIntermediateDirectoryWithString(map.map(line));
  }


}