// Program Header Information /////////////////////////
/**
 * @file SystemOperation.h
 * @brief Header file for SystemOperation part of Project1
 * @details This is a class for SystemOperation part of project1, made to calculate process time, log, and output
 * @version 1.0
 * @author Pedram Safaei
 * @bug nothing that can catched
 * @note bugs have been catched according the instruction
 */

// Precompiler Directives //////////////////////////////////////////
//
#ifndef OPERATINGSYSTEM_H
#define OPERATINGSYSTEM_H
//
// Header Files /////////////////////////////////////////////////// 
//
#include "CustomException.h"
#include "Configuration.h"
#include "ProcessControl.h"
#include "MetaData.h"
//

class OperatingSystem {
public:
    OperatingSystem(Config*, std::string);
    void process(Process&, Config*);
    void processSystemApp(std::string, Config*);
    void resetMemory();
    std::deque<Process> getProcesses();
    int get_memoryblocksallocated();
private:
    static void* timer(void*);
    double processThread(int);
    void runProcess(int, MetaDataCode&);
    void threadOperation(int, MetaDataCode&, sem_t&, pthread_mutex_t&);
    void processIOOperation(MetaDataCode, Config*, sem_t&, pthread_mutex_t&, int&, int, int, std::string, std::string);
    void processAction(std::string, Config*, MetaDataCode, int, int);
    std::string generateMemoryLocation(int);
    std::chrono::time_point<std::chrono::system_clock> START_TIME;
    sem_t projectorSemaphore;
    sem_t harddriveSemaphore;
    sem_t scannerSemaphore;
    sem_t monitorSemaphore;
    sem_t keyboardSemaphore;
    pthread_mutex_t projectorLock;
    pthread_mutex_t harddriveLock;
    pthread_mutex_t scannerLock;
    pthread_mutex_t monitorLock;
    pthread_mutex_t keyboardLock;
    int harddriveOutCount;
    int harddriveInCount;
    int projectorCount;
    int memoryBlocksAllocated;
    std::deque<Process> processes;     
};
// Terminating Precompiler Directives /////////////////////////////// 
//
#endif
//