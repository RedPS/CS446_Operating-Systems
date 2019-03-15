// Class Implementation File Information //////////////////////
/**
 * @file MemoryAllocation.cpp
 * @brief Implementations for MemoryAllocation.h
 * @details Implemented most functions required for a user created class
 * @version 1.0
 * @author Pedram Safaei
 * @bug nothing that can catched
 * @note bugs have been catched according the instruction
 */

// Header Files /////////////////////////////////////////////////// 
//
#include "MemoryAllocation.h"
//

/**
 * @brief It will give a momory location (generate one) based on config
 * @param Nothing
 * @return the generated location as a string  
 */
std::string MEMORYLOCATION::Get_MemoryLocation(){
    srand(time(NULL));
    input = std::to_string(rand()%10000000 + 10000000);
    return input;
}