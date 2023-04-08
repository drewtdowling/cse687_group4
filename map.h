#ifndef MAP
#define MAP

#include <string>
using std::string;

class Map {
public:
  void map(); // Accepts a single line of raw data from file and tokenize into distinct words
  void export(); // Takes key and value and buffer output in memory to write out

  
private:
  string inputdir; // File directory of input file
  string intermdir; // File directory of intermediary files
  string outputdir; // File directory of output file
};


#endif  // MAP
