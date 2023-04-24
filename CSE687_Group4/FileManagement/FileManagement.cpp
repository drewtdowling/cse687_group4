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