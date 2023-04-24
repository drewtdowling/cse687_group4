////////////////////////////////////////////////////////////////////////
// FileManagement.cpp - does all File I/O operations                  //
// ver 1.2                                                            //
// Language:    C++, Visual Studio 2022                               //
// Platform:    Windows 11                                            //
// Application: Mapping component, CSE687 - Object Oriented Design    //
// Author:      Drew Dowling , Syracuse University                    //
//              drdowlins@syr.edu                                    //
////////////////////////////////////////////////////////////////////////
/*
Package Operations:
-------------------

This package allows read/write operations of multiple files including input,
output, and intermediate directories

Can also set the input, intermediate, and output directories

Maintenance History:
--------------------
ver 1.0 : 14 April 2023
-initial release

ver 1.1 : 21 April 2023
-fixed minor bugs (flag to flag_)

ver 1.2 : 21 April 2023
-added more

ver 1.3 23 April 2023
-fixed bug where it overwrites itself

ver 1.4 23 April 2023
-added this header
*/

#include "FileManagement.h"

FileManagement::FileManagement()
{
	this->_inputDirectory = "../FileManagement/inputs/";
	this->_intermediateDirectory = "../FileManagement/intermediate/";
	this->_outputDirectory = "../FileManagement/outputs/";
}

FileManagement::~FileManagement()
{

}

std::string FileManagement::readInputFileToString(std::string fileName)
{
	std::string inputName = this->_inputDirectory + fileName;
	std::ifstream infile(inputName);

	if (infile) {
		std::string content((std::istreambuf_iterator<char>(infile)), (std::istreambuf_iterator<char>()));
		return content;
	}
	else {
		// Error handling here
		std::cerr << "Unable to open file from the input directory" << std::endl;
		return ""; // Just return an empty string so no null exceptions
	}
}

std::string FileManagement::readFromIntermediateDirectoryToString(std::string fileName)
{
	std::string inputName = this->_intermediateDirectory + fileName;
	std::ifstream infile(inputName);

	if (infile) {
		std::string content((std::istreambuf_iterator<char>(infile)), (std::istreambuf_iterator<char>()));
		return content;
	}
	else {
		// Error handling here
		std::cerr << "Unable to Open File from intermediate directory" << std::endl;
		return ""; // Just return an empty string so no null exceptions
	}
}

int FileManagement::writeToIntermediateDirectoryWithString(std::string fileName, std::string stringToWrite)
{
	std::string fileToWrite = this->_intermediateDirectory + fileName;
	std::ofstream file;
	file.open(fileToWrite, std::ios::app);
	if (!file.is_open()) {
		std::cerr << "Failed to open file in writeToIntermediateDirectoryWithString" << std::endl;
		return -1;
	}

	file << stringToWrite;
	if (!file) {
		std::cerr << "Failed to write file in writeToIntermediateDirectoryWithString" << std::endl;
		return -1;
	}
	file.close();

	return 1;
}

int FileManagement::writeToOutputDirectoryWithString(std::string stringToWrite)
{
	std::string fileToWrite = this->_outputDirectory + "output.txt";
	std::ofstream file;
	file.open(fileToWrite, std::ios::app);
	if (!file.is_open()) {
		std::cerr << "Failed to open file in writeToOutputDirectoryWithString" << std::endl;
		return -1;
	}

	file << stringToWrite;
	if (!file) {
		std::cerr << "Failed to write file in writeToOutputDirectoryWithString" << std::endl;
		return -1;
	}
	file.close();

	return 1;
}

int FileManagement::outputSuccess()
{
	std::string fileToWrite = this->_outputDirectory + "success.txt";
	std::ofstream file;
	file.open(fileToWrite, std::ios::app);
	if (!file.is_open()) {
		std::cerr << "Failed to open file in writeToOutputDirectoryWithString" << std::endl;
		return -1;
	}

	file << "SUCCESS";
	if (!file) {
		std::cerr << "Failed to write file in writeToOutputDirectoryWithString" << std::endl;
		return -1;
	}
	file.close();

	return 1;
}

int FileManagement::truncateIntermediateFile(std::string fileName)
{
	std::ofstream outfile;
	outfile.open(_intermediateDirectory + fileName, std::ios::trunc); // open file in truncate mode
	if (!outfile.is_open()) {
		std::cerr << "Failed to open file!" << std::endl;
		return -1;
	}

	outfile.close(); // close file
	return 1;
}

int FileManagement::truncateOutputFile(std::string fileName)
{
	std::ofstream outfile;
	outfile.open(_outputDirectory + fileName, std::ios::trunc); // open file in truncate mode
	if (!outfile.is_open()) {
		std::cerr << "Failed to open file!" << std::endl;
		return -1;
	}

	outfile.close(); // close file
	return 1;
}

std::string FileManagement::getInputDirectory()
{
	return _inputDirectory;
}

std::string FileManagement::getIntermediateDirectory()
{
	return _intermediateDirectory;
}

std::string FileManagement::getOutputDirectory()
{
	return _outputDirectory;
}

void FileManagement::setInputDirectory(std::string inputDirectory)
{
	inputDirectory = this->_inputDirectory;
}

void FileManagement::setIntermediateDirectory(std::string intermediateDirectory)
{
	intermediateDirectory = this->_intermediateDirectory;
}

void FileManagement::setOutputDirectory(std::string outputDirectory)
{
	outputDirectory = this->_outputDirectory;
}