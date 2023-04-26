////////////////////////////////////////////////////////////////////////
// main.cpp - Workflow and Executive component for the Map-Reduce     //
// ver 1.2                                                            //
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

ver 1.2 : 23 April 2023
-file management commands included
-comments added
*/

#include "FileManagement/FileManagement.h"
#include "map.h"
#include "sorter.h"
#include "reduce.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

std::vector<std::string> splitStringByNewLine(const std::string& str)
{
  auto result = std::vector<std::string>{};
  auto ss = std::stringstream{ str };

  for (std::string line; std::getline(ss, line, '\n');)
    result.push_back(line);

  return result;
}

int main()
{
#pragma region FileManagement
  // --------------------------------- File Management ---------------------------------
  FileManagement fileManagement = FileManagement();
  std::string intermediateBeforeSorting = "intermediateBeforeSorting.txt";
  std::string intermediateAfterSorting = "intermediateAfterSorting.txt";

  // Clears the files
  fileManagement.truncateIntermediateFile(intermediateBeforeSorting);
  fileManagement.truncateIntermediateFile(intermediateAfterSorting);
  fileManagement.truncateOutputFile("output.txt");
#pragma endregion FileManagement


#pragma region Map
  // --------------------------------- Map ---------------------------------
  Map map = Map();
  std::stringstream mapStream;
  std::string line = "";

  std::string filesInInput = fileManagement.executePowerShellCommand("dir ../FileManagement/inputs -Name");
  std::vector<std::string> fileNames = splitStringByNewLine(filesInInput);
  std::string concatFilesString = "";
  for (unsigned int i = 0; i < fileNames.size(); i++)
  {
    if (i != fileNames.size() - 1) {
      concatFilesString += ("../FileManagement/inputs/" + fileNames[i] + ", ");
    }
    else {
      concatFilesString += ("../FileManagement/inputs/" + fileNames[i]);
    }
  }
  fileManagement.executePowerShellCommand("Get-Content " + concatFilesString + " | " + "Set-Content ../FileManagement/inputs/input.txt");
  mapStream << fileManagement.readInputFileToString("input.txt");
  while (getline(mapStream, line, '\n')) {
    fileManagement.writeToIntermediateDirectoryWithString(intermediateBeforeSorting, map.map(line));
  }
#pragma endregion Map


#pragma region Sort
  // --------------------------------- Sort ---------------------------------
  LinkedList linkedlist;
  std::string nodeline = "";
  std::stringstream sortStream;

  sortStream << fileManagement.readFromIntermediateDirectoryToString(intermediateBeforeSorting);
  while (getline(sortStream, nodeline, '\n')) {
    linkedlist.insert(nodeline);
  }
  for (int i = 0; i < linkedlist.getSize(); i++) {
    std::string currNode = linkedlist.getNode(i) + "\n";
    fileManagement.writeToIntermediateDirectoryWithString(intermediateAfterSorting, currNode);
  }
#pragma endregion Sort


#pragma region Reduce
  // --------------------------------- Reduce ---------------------------------
  Reducer reducer = Reducer();
  std::string sortedline = "";
  std::stringstream reduceStream;

  reduceStream << fileManagement.readFromIntermediateDirectoryToString(intermediateAfterSorting);
  while (getline(reduceStream, sortedline, '\n')) {
    std::string reduceOutput = reducer.reduce(sortedline) + "\n";
    fileManagement.writeToOutputDirectoryWithString(reduceOutput);
  }
#pragma endregion Reduce

  // output success file
  fileManagement.outputSuccess();
}