// Class Header Information /////////////////////////
/**
 * @file Configuration.h
 * @brief Header file for Configuration part of Project1
 * @details This is a class for Configuration part of project1, made for error handling
 * @version 1.3
 * @author Pedram Safaei
 * @bug nothing that can catched
 * @note bugs have been catched according the instruction
 */

// Precompiler Directives //////////////////////////////////////////
//
#ifndef CONFIG_H
#define CONFIG_H
//

// Header Files /////////////////////////////////////////////////// 
//
#include "CustomException.h"
//

class Config {

private:
	float version;
	std::string filePath;
	int monitorDisplayTime;
	int processorCycleTime;
	int scannerCycleTime;
	int harddriveCycleTime;
	int keyboardCycleTime;
	int memoryCycleTime;
	int projectorCycleTime;

	int projectorResources;
	int harddriveResources;

	int memoryBlockSize;
	int maxMemorySize;
	std::string maxMemoryType;
	std::string memoryBlockType;
	std::string logTo;
	std::string logFilePath;
	std::string SchedulingAlg;

	bool validate();
	void convertMemoryType(int&, std::string);
public:
	Config();
	void readConfigFile(std::string configPath);
	void readMetaDataFile();
	std::string getFilePath();
	std::string getLogTo();
	std::string getLogFilePath();

	int getMDT();
	int getPCT();
	int getSCT();
	int getHCT();
	int getKCT();
	int getMemCT();
	int getProCT();
	float getVersion();
	int getMemoryBlockSize();
	int getMaxMemorySize();
	int getProjectorResources();
	int getHarddriveResources();
	std::string getSchedulingAlg();
		
};
// Terminating Precompiler Directives /////////////////////////////// 
//
#endif /* !CONFIGURATION */
//