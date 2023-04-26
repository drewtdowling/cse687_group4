#ifndef FILE_MANAGEMENT_H
#define FILE_MANAGEMENT_H

#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>

class FileManagement
{
public:
	FileManagement();
	~FileManagement();

	// I/O operations
	std::string executePowerShellCommand(std::string);
	std::string readInputFileToString(std::string);
	std::string readFromIntermediateDirectoryToString(std::string);
	int writeToIntermediateDirectoryWithString(std::string, std::string);
	int writeToOutputDirectoryWithString(std::string);
	int truncateIntermediateFile(std::string);
	int truncateOutputFile(std::string);
	int outputSuccess();

	// Getters
	std::string getInputDirectory(void);
	std::string getIntermediateDirectory(void);
	std::string getOutputDirectory(void);

	// Setters
	void setInputDirectory(std::string);
	void setIntermediateDirectory(std::string);
	void setOutputDirectory(std::string);

private:
	std::string _inputDirectory;
	std::string _intermediateDirectory;
	std::string _outputDirectory;
};

#endif