#include "ProcessControl.h"
#include "Functions.h"

void *TIMER(void *);

ProcessControl::ProcessControl(){

}

void ProcessControl::Set_ProcessState(int S){
    state = S;
}

int ProcessControl::Get_ProcessState(){
    return state;
}
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

void ProcessControl::RunProcess(int mili, MetaData& data){
    auto TimeCurrent = std::chrono::system_clock::now();
    data.Set_StartTime(std::chrono::duration<double>(TimeCurrent - TimeStart).count());
    auto TimeEnd = ProcessThread(mili);
    data.Set_ProcessTime(TimeEnd);
}