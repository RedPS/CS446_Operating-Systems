
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
#ifndef PROCESS_H
#define PROCESS_H
//
// Header Files /////////////////////////////////////////////////// 
//
#include "MetaData.h"
#include "Configuration.h"
//

class Process {
    public:
        Process();
        enum class ProcessState { START, READY, RUNNING, WAIT, EXIT };
        void readOperations(Config); 
		static void createProcesses(std::deque<Process>&, std::deque<MetaDataCode>);
        void push(MetaDataCode);
        void incrementIOCount();
        int getIOCount();
        void incrementTaskCount();
        int getTaskCount();
        void setProcessCount(int);
        int getProcessCount();
        ProcessState getProcessState();
        void setProcessState(ProcessState);
        std::deque<MetaDataCode> getOperations();
        MetaDataCode popOperation();
    private:
        ProcessState processState;
        int numberOfIO; 
        int numberOfTasks; 
        int processCount;
        std::deque<MetaDataCode> operations;
};
// Terminating Precompiler Directives /////////////////////////////// 
//
#endif /* PROCESSCONTROL */
//