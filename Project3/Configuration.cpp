// Class Implementation File Information //////////////////////
/**
 * @file Configuration.cpp
 * @brief This file implements functions in Configuration.h
 * @details This Configuration file is used to throw a more useful error 
 * @version 1.3
 * @author Pedram Safaei
 * @bug nothing that can catched
 * @note bugs have been catched according the instruction
 */

// Header Files /////////////////////////////////////////////////// 
//
#include <iostream>
#include <string>
#include <fstream>
#include <deque>
#include <sstream>
#include <iomanip>
#include "Configuration.h"
//

/**
 * @brief destructor
 */
Config::Config() {
	harddriveResources = 1;
	projectorResources = 1;
}
/**
 * @brief: getter for the configuration class
 * @param pathToConfig: as name indicates the string gives path to config (name of config)
 * @return VOID: Nothing
*/
void Config::readConfigFile(std::string configPath) {
	std::ifstream configFile;
	configFile.open(configPath);
	if(!configFile) {
		throw_line("Can't open the configuration file");
	}
	std::deque<std::string> tokens;
	std::string s;

	while(configFile >> s) {
		tokens.push_back(s);
	}
	for(auto it = tokens.begin(); it != tokens.end(); it++) {
		if(*it == "Log:") {
			this->logTo = *(it+3);
		} else if(*it == "File") {
			s = *(it+2);
			if(s.find(".mdf") != std::string::npos) {
				this->filePath = s;
			}
		} else if(*it == "Version/Phase:") {
			this->version = std::stof(*(it+1));
		} else if(*it == "Log") {
			std::string temp = *(it+3);
			if(temp.find(".lgf") != std::string::npos) {
				this->logFilePath = temp;
			}
		} else if(*it == "Monitor") {
			this->monitorDisplayTime = std::stoi(*(it+4));
		} else if(*it == "Processor") {
			this->processorCycleTime = std::stoi(*(it+4));
		} else if(*it == "Scanner") {
			this->scannerCycleTime = std::stoi(*(it+4));
		} else if(*it == "Hard") {
			if(*(it+2) == "quantity:") {
				this->harddriveResources = std::stoi(*(it+3));
			} else {
				this->harddriveCycleTime = std::stoi(*(it+5));
			}
		} else if(*it == "Keyboard") {
			this->keyboardCycleTime = std::stoi(*(it+4));
		} else if(*it == "Memory") {

			if(*(it+1) == "cycle") {
				this->memoryCycleTime = std::stoi(*(it+4));
			} else if(*(it+1) == "block") {
				this->memoryBlockSize = std::stoi(*(it+4));
				this->memoryBlockType = *(it+3);
				this->convertMemoryType(this->memoryBlockSize, this->memoryBlockType);
			}
		} else if(*it == "Projector") {
			if(*(it+1) == "quantity:") {
				this->projectorResources = std::stoi(*(it+2));
			} else {
				this->projectorCycleTime = std::stoi(*(it+4));
			}
		} else if(*it == "System") {
			this->maxMemorySize = std::stoi(*(it+3));
			this->maxMemoryType = *(it+2);
			this->convertMemoryType(this->maxMemorySize, this->maxMemoryType);
		} 
	}
	configFile.close();
	if(!this->validate()) {
		throw_line("Some Data is missing");
	}
}
/**
 * @brief: convert the memory type
 * @param size, size of memory
 * @param type, type of memory 
 * @return VOID: Nothing
*/
void Config::convertMemoryType(int &size, std::string type) {
	if(type.find("Gbytes") != std::string::npos) {
		size *= 1000000;
	} else if(type.find("Mbytes") != std::string::npos) {
		size *= 1000;
	} else if(type.find("kbytes") == std::string::npos) {
		throw_line("The memory type is not valid!");
	}
}
/**
 * @brief: validateing the data
 * @return bool, true or false. If data is valid return true
*/
bool Config::validate() {
	bool monitor = monitorDisplayTime > 0;
	bool processor = processorCycleTime > 0;
	bool scanner = scannerCycleTime > 0;
	bool harddrive = harddriveCycleTime > 0;
	bool keyboard = keyboardCycleTime > 0;
	bool memory = memoryCycleTime > 0;
	bool projector = projectorCycleTime > 0;
	bool ver = this->version > 0;
	return monitor && processor && scanner && harddrive && keyboard && memory && projector && ver;
}
/**
 * @brief: getter for the configuration class
 * @returns logfilepath
*/
std::string Config::getFilePath() {
	return this->filePath;
}
/**
 * @brief: getter for the configuration class
 * @returns blocksizefor memmry
*/
int Config::getMemoryBlockSize() {
	return this->memoryBlockSize;
}
/**
 * @brief: getter for the configuration class
 * @returns max mem size
*/
int Config::getMaxMemorySize() {
	return this->maxMemorySize;
}
/**
 * @brief: getter for the configuration class
 * @returns monitor dispay time
*/
int Config::getMDT() {
	return this->monitorDisplayTime;
}
/**
 * @brief: getter for the configuration class
 * @returns processor cycle time
*/
int Config::getPCT() {
	return this->processorCycleTime;
}
/**
 * @brief: getter for the configuration class
 * @returns scanner cyvle time
*/
int Config::getSCT() {
	return this->scannerCycleTime;
}
/**
 * @brief: getter for the configuration class
 * @returns harddrive cycle time
*/
int Config::getHCT() {
	return this->harddriveCycleTime;
}
/**
 * @brief: getter for the configuration class
 * @returns keyboard cycle time
*/
int Config::getKCT() {
	return this->keyboardCycleTime;
}
/**
 * @brief: getter for the configuration class
 * @returns memory cycle time
*/
int Config::getMemCT() {
	return this->memoryCycleTime;
}
/**
 * @brief: getter for the configuration class
 * @returns projector cycle time
*/
int Config::getProCT() {
	return this->projectorCycleTime;
}
/**
 * @brief: getter for the configuration class
 * @returns logfilepath
*/
std::string Config::getLogTo() {
	return this->logTo;
}
/**
 * @brief: getter for the configuration class
 * @returns logfilepath
*/
std::string Config::getLogFilePath() {
	return this->logFilePath;
}
/**
 * @brief: getter for the configuration class
 * @returns hard drive resources
*/
int Config::getHarddriveResources() {
	return this->harddriveResources;
}
/**
 * @brief: getter for the configuration class
 * @returns projector resources
*/
int Config::getProjectorResources() {
	return this->projectorResources;
}