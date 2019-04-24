// Class Implementation File Information //////////////////////
/**
 * @file Scheduling.cpp
 * @brief Implementations for scheduling.h
 * @details Implemented most functions required for a user created class
 * @version 1.0
 * @author Pedram Safaei
 * @bug nothing that can catched
 * @note bugs have been catched according the instruction
 */

// Header Files /////////////////////////////////////////////////// 
//
#include "Scheduling.h"


/**
 * @brief this function gets a queue of processes and will schedule according to the given algorithm
 * @param configuration file
 * @param queue of processes 
 * @return VOID
 */
void Scheduler::scheduleProcesses(Config* cf, std::deque<Process> &processes) {
    // if no scheduler present, then quit
    if(cf->getSchedulingAlg() == "") return;

    // schedule processes based on choice
    if(cf->getSchedulingAlg() == "FIFO") {
        // do nothing since already sorted as is
    } else if(cf->getSchedulingAlg()== "PS") {
        priority(processes);
    } else if(cf->getSchedulingAlg() == "SJF") {
        shortestJobFirst(processes);
    } else {
        throw_line("Scheduling Algorithm is not valid!");
    }
}

/**
 * @brief Sorting by priority
 * @param queue of processes 
 * @return VOID
 */
void Scheduler::priority(std::deque<Process> &processes) {
    std::sort(processes.begin(), processes.end(), sortByPriority);
}

/**
 * @brief Sorting by shortest job first
 * @param queue of processes 
 * @return VOID
 */
void Scheduler::shortestJobFirst(std::deque<Process> &processes) {
    std::sort(processes.begin(), processes.end(), sortByShortest);
}


/**
 * @brief Sorting by greatest IO to smallest
 * @param queue of processes 
 * @return VOID
 */
bool Scheduler::sortByPriority(Process p1, Process p2) {
    return p1.getIOCount() > p2.getIOCount();
}


/**
 * @brief Sorting by shortest to greater
 * @param queue of processes 
 * @return VOID
 */
bool Scheduler::sortByShortest(Process p1, Process p2) {
    return p1.getTaskCount() < p2.getTaskCount();
}