#include "ProcessControl.h"
#include "Functions.h"

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
void ProcessControl::Set_processCount(int count){
    processcount = count;
}
int ProcessControl::Get_ProcessCount(){
    return processcount;
}
/*
void ProcessControl::createProcesses(std::deque<ProcessControl>& processes, std::vector<MetaData> operation ){
    int numproc = 0;
    for (auto it= operation.begin(); it!= operation.end(); ++it){
        std::cout << it->Get_cipher() << " " << it->Get_caption() << std::endl;
        if(it->Get_cipher() == 'A' and it->Get_caption() == "begin"){
            numproc++;
        }
    }
    std::cout << "Number of Processes: "<< numproc << std::endl;
}
*/

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