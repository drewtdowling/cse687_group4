#include "FileManagement/FileManagement.h"
#include "map.h"
#include <iostream>
#include <string>
#include <sstream>

int main()
{
  FileManagement fileManagement = FileManagement();
  Map map = Map();
  std::stringstream test;
  string line = "";
  //std::stringstream interm;

  test << fileManagement.readInputFileToString("AsYouLikeIte.txt");

  while (getline(test, line, '\n')) {
    //interm << map.map(line);
    fileManagement.writeToIntermediateDirectoryWithString(map.map(line));
  }


}