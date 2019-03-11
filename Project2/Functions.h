// Program Header Information /////////////////////////
/**
 * @file Functions.h
 * @brief Header file for Functions part of Project1
 * @details This is a class for Functions part of project1, made to calculate process time, log, and output
 * @version 1.0
 * @author Pedram Safaei
 * @bug nothing that can catched
 * @note bugs have been catched according the instruction
 */

// Header Files /////////////////////////////////////////////////// 
//
#include "Configuration.h"
#include "MetaData.h"
#include "Clock.h"
#include "ProcessControl.h"
#include "MemoryAllocation.h"
const auto TimeStart = std::chrono::system_clock::now();
static std::vector<std::string> logf;
//


namespace Functions {
    // Free Function Prototypes /////////////////////////////////////// 
    //
    double ProcessThread(int);
    void logoutput(Configuration config, std::ostream& output, int status, std::vector<MetaData> data);
    void logtofile(Configuration config, std::vector<MetaData> data);
    void ProcessTheTime(Configuration config, MetaData& data);
    //
}
