// Class Header Information /////////////////////////
/**
 * @file ProcessControl.h
 * @brief Implementations for ProcessControl.h
 * @details Implemented most functions required for a user created class
 * @version 1.0
 * @author Pedram Safaei
 * @bug nothing that can catched
 * @note bugs have been catched according the instruction
 */

// Precompiler Directives //////////////////////////////////////////
//
#ifndef PROCESSCONTROL
#define PROCESSCONTROL
//

// Header Files /////////////////////////////////////////////////// 
//
#include "CustomException.h"
#include "MetaData.h"
#include <deque>
//

class ProcessControl{
private:
    /*
    0 = START
    1 = READY
    2 = RUNNING
    3 = WAITING
    4 = EXIT
    */
    int state;
    int processcount;
public:
    //enum class processstates{START, READY, RUNNING, WAIT, EXIT};
    //static void createProcesses(std::deque<ProcessControl>&, std::vector<MetaData> );
    ProcessControl();
    void Set_processCount(int);
    int Get_ProcessCount();
    void Set_ProcessState(int);
    int Get_ProcessState();
    void RunProcess(int, MetaData&);

};

#endif /* PROCESSCONTROL */