#include "FileManagement.h"

FileManagement::FileManagement()
{
	this->inputDirectory = "../FileManagement/inputs/";
	this->intermediateDirectory = "../FileManagement/intermediate/";
	this->outputDirectory = "../FileManagement/outputs/";
}

FileManagement::~FileManagement()
{

}

std::string FileManagement::readInputFileToString(std::string fileName)
{
	std::string inputName = this->inputDirectory + fileName;
	std::ifstream infile(inputName);

	if (infile)
	{
		std::string content((std::istreambuf_iterator<char>(infile)), (std::istreambuf_iterator<char>()));
		return content;
	}
	else
	{
		// Error handling here
		std::cerr << "Unable to open file from the input directory" << std::endl;
		return ""; // Just return an empty string so no null exceptions
	}
}

std::string FileManagement::readFromIntermediateDirectoryToString(std::string fileName)
{
	std::string inputName = this->intermediateDirectory + fileName;
	std::ifstream infile(inputName);

	if (infile)
	{
		std::string content((std::istreambuf_iterator<char>(infile)), (std::istreambuf_iterator<char>()));
		return content;
	}
	else
	{
		// Error handling here
		std::cerr << "Unable to Open File from input directory" << std::endl;
		return ""; // Just return an empty string so no null exceptions
	}
}

int FileManagement::writeToIntermediateDirectoryWithString(std::string nameOfFile, std::string stringToWrite)
{
	std::string fileToWrite = this->intermediateDirectory + nameOfFile;
	std::ofstream file(fileToWrite);
	if (!file.is_open())
	{
		std::cerr << "Failed to open file in writeToIntermediateDirectoryWithString" << std::endl;
		return -1;
	}

	file << stringToWrite;
	if (!file)
	{
		std::cerr << "Failed to write file in writeToIntermediateDirectoryWithString" << std::endl;
		return -1;
	}
	file.close();

	return 1;
}

int FileManagement::writeToOutputDirectoryWithString(std::string nameOfFile, std::string stringToWrite)
{
	std::string fileToWrite = this->outputDirectory + nameOfFile;
	std::ofstream file(fileToWrite);
	if (!file.is_open())
	{
		std::cerr << "Failed to open file in writeToOutputDirectoryWithString" << std::endl;
		return -1;
	}

	file << stringToWrite;
	if (!file)
	{
		std::cerr << "Failed to write file in writeToOutputDirectoryWithString" << std::endl;
		return -1;
	}
	file.close();

	return 1;
}

std::string FileManagement::getInputDirectory()
{
	return inputDirectory;
}

std::string FileManagement::getIntermediateDirectory()
{
	return intermediateDirectory;
}

std::string FileManagement::getOutputDirectory()
{
	return outputDirectory;
}

void FileManagement::setInputDirectory(std::string inputDirectory)
{
	inputDirectory = this->inputDirectory;
}

void FileManagement::setIntermediateDirectory(std::string intermediateDirectory)
{
	intermediateDirectory = this->intermediateDirectory;
}

void FileManagement::setOutputDirectory(std::string outputDirectory)
{
	outputDirectory = this->outputDirectory;
}