// Class Implementation File Information //////////////////////
/**
 * @file ProcessControl.cpp
 * @brief Implementations for ProcessControl.h
 * @details Implemented most functions required for a user created class
 * @version 1.0
 * @author Pedram Safaei
 * @bug nothing that can catched
 * @note bugs have been catched according the instruction
 */

// Header Files /////////////////////////////////////////////////// 
//
#include "ProcessControl.h"
#include "MetaData.h"
//

/**
 * @brief default constructor
 **/
Process::Process() {
    this->processState = ProcessState::START;
    this->numberOfIO = 0;
    this->numberOfTasks = 0;
}
/**
 * @brief create processes
 * @param queue of processes
 * @param queue of metadata Data
 * return NOTHING VOID
 **/
void Process::createProcesses(std::deque<Process>& processes, std::deque<MetaDataCode> systemOperations) {
    int numberOfProcesses = 1;
    for(auto it = systemOperations.begin(); it != systemOperations.end(); ++it) {
        if(it->getCode() == 'A' && it->getDescriptor() == "begin") {
            Process p;
            p.setProcessCount(numberOfProcesses);
            auto tempIterator = it;
            if(tempIterator->getCode() != 'S' && tempIterator->getDescriptor() != "finish")  {
                tempIterator = it+1;
            }
            while(tempIterator->getDescriptor() != "finish") {
                if(tempIterator->getCode() == 'O' || tempIterator->getCode() == 'I') {
                    p.incrementIOCount(); 
                }
                p.incrementTaskCount();
                p.push(*tempIterator);
                std::advance(tempIterator, 1);
            }
            processes.push_back(p);
            numberOfProcesses++;
        }
    }
}
/**
 * @berif push metadata
 * @param metadata data
 **/
void Process::push(MetaDataCode mdc) {
    this->operations.push_back(mdc);
}
/**
 * @berif increment IO operations
 **/
void Process::incrementIOCount() {
    this->numberOfIO++;
}
/**
 * @berif increment task count
 **/
void Process::incrementTaskCount() {
    this->numberOfTasks++;
}
/**
 * @berif update process count 
 * @param count
 **/
void Process::setProcessCount(int count) {
    this->processCount = count;
}
/**
 * @berif get process count 
 * @return intget -> process count
 **/
int Process::getProcessCount() {
    return this->processCount;
}
/**
 * @berif pop from the queue
 * @return queue
 **/
MetaDataCode Process::popOperation() {
    auto mdc = this->operations.front();
    this->operations.pop_front();
    return mdc;
}
///getters ////////////////////////////////////////
//
std::deque<MetaDataCode> Process::getOperations() {
    return this->operations;
}
Process::ProcessState Process::getProcessState() {
    return this->processState;
}
int Process::getIOCount() {
    return this->numberOfIO;
}

int Process::getTaskCount() {
    return this->numberOfTasks;
}
//
///setters ////////////////////////////////////////
//
void Process::setProcessState(Process::ProcessState stateChange) {
    this->processState = stateChange; 
}
//

