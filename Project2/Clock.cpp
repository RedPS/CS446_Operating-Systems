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
#include "Clock.h"
//

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