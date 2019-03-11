#ifndef PROCESSCONTROL
#define PROCESSCONTROL

#include "CustomException.h"
#include "MetaData.h"

#include <deque>

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