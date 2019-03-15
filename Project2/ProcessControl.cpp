// Class Implementation File Information //////////////////////
/**
 * @file Clock.cpp
 * @brief Implementations for Clock.h
 * @details Implemented most functions required for a user created class
 * @version 1.0
 * @author Pedram Safaei
 * @bug nothing that can catched
 * @note bugs have been catched according the instruction
 */

// Header Files /////////////////////////////////////////////////// 
//
#include "ProcessControl.h"
#include "Functions.h"
//

/**
 * @brief Timer, or wait function
 * @param na just a void* 
 * @return nothing, it is void
 * @detail: needed for the pthread to work
 */
void* TIMER(void* na){
    std::chrono::system_clock::time_point start;
    std::chrono::system_clock::time_point end;
    double cap = 0.1;
    std::chrono::duration<double> timer;
    start = std::chrono::system_clock::now();
    while(timer.count() < cap){
        end = std::chrono::system_clock::now();
        timer = end - start;
    }
    pthread_exit(NULL);
    return NULL;
}
/**
 * @brief It will give a momory location (generate one) based on config
 * @param count, the process count
 * @return nothing VOID  
 */
void ProcessControl::Set_processCount(int count){
    processcount = count;
}
/**
 * @brief It will give a momory location (generate one) based on config
 * @return int, the process count 
 */
int ProcessControl::Get_ProcessCount(){
    return processcount;
}
/**
 * @brief default constructor
 */
ProcessControl::ProcessControl(){

}
/**
 * @brief sets the process state
 * @param intgers just pass in state
 * @return nothing VOID 
 */
void ProcessControl::Set_ProcessState(int S){
    state = S;
}
/**
 * @brief gets the process state
 * @return int returns the state
 */
int ProcessControl::Get_ProcessState(){
    return state;
}
/**
 * @brief gets the process state
 * @return int returns the state
 */
double ProcessThread(int cap){
    int TIME = cap;
    pthread_t timeThr;
    auto EndTime = std::chrono::system_clock::now() + 
                   std::chrono::milliseconds(cap);
    while(std::chrono::system_clock::now() < EndTime ){
        pthread_create(&timeThr, NULL, TIMER, NULL);
        pthread_join(timeThr, NULL);
    }
    auto TimeCurent = std::chrono::system_clock::now();
    return std::chrono::duration<double>(TimeCurent - TimeStart).count();
}
/**
 * @brief run the process state
 * @param the meta data info
 * @return Nothing VOID
 */
void ProcessControl::RunProcess(int mili, MetaData& data){
    auto TimeCurrent = std::chrono::system_clock::now();
    data.Set_StartTime(std::chrono::duration<double>(TimeCurrent - TimeStart).count());
    auto TimeEnd = ProcessThread(mili);
    data.Set_ProcessTime(TimeEnd);
}