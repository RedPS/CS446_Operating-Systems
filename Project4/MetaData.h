// Class Header Information /////////////////////////
/**
 * @file MetaData.h
 * @brief Header file for MetaData part of Project1
 * @details This is a class for metadata part of project1
 * @version 1.0
 * @author Pedram Safaei
 * @bug nothing that can catched
 * @note bugs have been catched according the instruction
 */

// Precompiler Directives //////////////////////////////////////////
//
#ifndef METADATACODE_H
#define METADATACODE_H

// Header Files /////////////////////////////////////////////////// 
//
#include "CustomException.h"
//

class MetaDataCode {
	public:
		MetaDataCode(char codeInput, std::string descriptorInput, int cyclesInput, std::string data);
		void setStartTime(double startTimeInput);
		void setProcessingTime(double processingTimeInput);
		static void readMetaDataFile(std::string, std::deque<MetaDataCode>&);
		char getCode();
		std::string getDescriptor();
		std::string getData();
		int getCycles();
		double getProcessingTime();
		double getStartTime();
	private:
		char code;
		std::string descriptor;
		std::string data;
		int cycles;
		double processingTime;
		double startTime;
};
// Terminating Precompiler Directives /////////////////////////////// 
//
#endif
//