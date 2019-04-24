// Class Header Information /////////////////////////
/**
 * @file Output.h
 * @brief Header file for Output part of Project1
 * @details This is a class for Output part of project1
 * @version 1.3
 * @author Pedram Safaei
 * @bug nothing that can catched
 * @note bugs have been catched according the instruction
 */

// Precompiler Directives //////////////////////////////////////////
//
#ifndef LOG_H
#define LOG_H
//

// Header Files /////////////////////////////////////////////////// 
//
#include "CustomException.h"
#include "Configuration.h"
//

class Log {
    private:
        static bool didFirstLog;
        static bool checkFirstLog();
    public:
        static void outputToStream(std::ostream&, std::string);
        static void output(Config, std::string);       
};
// Terminating Precompiler Directives /////////////////////////////// 
//
#endif
//