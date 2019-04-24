
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
#ifndef SCHEDULER_H
#define SCHEDULER_H
//
// Header Files /////////////////////////////////////////////////// 
//
#include "Configuration.h"
#include "ProcessControl.h"
//

class Scheduler {
    public:
        static void scheduleProcesses(Config*, std::deque<Process>&);
    private:
       static void priority(std::deque<Process>&);
       static void shortestJobFirst(std::deque<Process>&);
       static bool sortByPriority(Process, Process);
       static bool sortByShortest(Process, Process);

};
#endif /* Scheduler */
//