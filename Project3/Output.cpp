// Class Implementation File Information //////////////////////
/**
 * @file Output.cpp
 * @brief Implementations for Output.h
 * @details Implemented most functions required for a user created class
 * @version 1.3
 * @author Pedram Safaei
 * @bug nothing that can catched
 * @note bugs have been catched according the instruction
 */

// Header Files /////////////////////////////////////////////////// 
//
#include "Output.h"
//

bool Log::didFirstLog = false;
void Log::output(Config cf, std::string logOutput) {
	std::ofstream logFile;
	bool monitorFlag = false;
	bool logFileFlag = false;
	if(cf.getLogTo() == "Both") {
		monitorFlag = true;
		logFileFlag = true;
	} else if(cf.getLogTo() == "Monitor") {
		monitorFlag = true;
	} else if(cf.getLogTo() == "File") {
		logFileFlag = true;
	} else {
		throw_line("Unrecognized logging location please check the location!");
	}
	if(monitorFlag) {
		Log::outputToStream(std::cout, logOutput);
	}
	if(logFileFlag) {
		logFile.open(cf.getLogFilePath(), (checkFirstLog()) ? std::ofstream::app : std::ofstream::trunc);
		Log::outputToStream(logFile, logOutput);
		logFile.close();
	}
}
/**
 * @brief: where to putput
 * @param out, place to output
 * @param stirng what to output 
**/
void Log::outputToStream(std::ostream& out, std::string logOutput) {
    out << logOutput << std::endl;
}
/**
 * @brief: check log
 * return bool, true or false 
**/
bool Log::checkFirstLog() {
	if(didFirstLog == false) {
		didFirstLog = true;
		return false;
	} else {
		return didFirstLog;
	}
}