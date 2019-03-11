#include "Clock.h"

void* Clock::TIMER(void* na){
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