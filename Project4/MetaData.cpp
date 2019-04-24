// Class Implementation File Information //////////////////////
/**
 * @file MetaData.cpp
 * @brief Implementations for MetaData.h
 * @details Implemented most functions required for a user created class
 * @version 1.0
 * @author Pedram Safaei
 * @bug nothing that can catched
 * @note bugs have been catched according the instruction
 */

// Header Files /////////////////////////////////////////////////// 
//
#include "MetaData.h"
//

// Class/Data Structure Member Implementation ////////////////////// 
//

/**
 * @brief default parametrized constructor for Meta data class
 */
MetaDataCode::MetaDataCode(char codeInput, std::string descriptorInput, int cyclesInput, std::string dataInput) {
	this->code = codeInput;
	this->descriptor = descriptorInput;
	this->cycles = cyclesInput;
	this->data = dataInput;
}
//setters //////////////////////////////////////
//
void MetaDataCode::setProcessingTime(double processingTimeInput) {
	this->processingTime = processingTimeInput;
}
void MetaDataCode::setStartTime(double startTimeInput) {
	this->startTime = startTimeInput;
}
char MetaDataCode::getCode() {
	return this->code;
}
//

//getters //////////////////////////////////////
//
std::string MetaDataCode::getDescriptor() {
	return this->descriptor;
}

int MetaDataCode::getCycles() {
	return this->cycles;
}

std::string MetaDataCode::getData() {
	return this->data;
}

double MetaDataCode::getProcessingTime() {
	return this->processingTime;
}

double MetaDataCode::getStartTime() {
	return this->startTime;
}
//

/**
 * @brief load the data from metadata
 * @param path: The path of the meta data file 
 * @param MetaDatadata: Vector of type meta data
 * @return VOID: Nothing
 */
void MetaDataCode::readMetaDataFile(std::string filePath, std::deque<MetaDataCode>& MetaDataVector) {
	std::ifstream metaDataFile;
	metaDataFile.open(filePath);
	std::deque<std::string> tokens;
	std::string s;
	std::string temp;
	char codeInput;
	std::string descriptorInput;
	int cyclesInput;
	bool readOverFlag = false;

	while(metaDataFile >> s) {
		if(s.find("hard") != std::string::npos) {
			metaDataFile >> temp;
			s.append(" ");
			s.append(temp);
		}
		tokens.push_back(s);
	}
	metaDataFile.close();
	for(auto it = tokens.begin(); it != tokens.end(); it++) {
		if(*it == "Start") {
			std::advance(it, 4);
		} else if(*it == "End") {
			break;
		} else if(readOverFlag) {
			throw_line("Can't find the end of the file in Meta Data file! ");
		}
		s = *it;
		codeInput = s[0];
		s.erase(0, 2);
		descriptorInput = s.substr(0, s.find('}'));
		s.erase(0, s.find('}')+1);
		temp = s.substr(0, s.find(';'));
		if(temp.find('.') != std::string::npos) {
			readOverFlag = true;
			s.erase(s.find('.'), 1);
		}
		cyclesInput = std::stoi(temp);
		s = *it;
		s.erase(std::remove(s.begin(), s.end(), ';'), s.end());
		MetaDataCode mdcTemp(codeInput, descriptorInput, cyclesInput, s);
		MetaDataVector.push_back(mdcTemp);
	}
}
//