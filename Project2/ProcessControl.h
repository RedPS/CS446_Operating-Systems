#ifndef PROCESSCONTROL
#define PROCESSCONTROL

#include "CustomException.h"
#include "MetaData.h"

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
public:
    ProcessControl();

    void Set_ProcessState(int);
    int Get_ProcessState();
    void RunProcess(int, MetaData&);

};

#endif /* PROCESSCONTROL */