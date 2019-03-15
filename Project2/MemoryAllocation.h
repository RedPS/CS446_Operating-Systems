// Class Header Information /////////////////////////
/**
 * @file MemoryAllocation.h
 * @brief Implementations for MemoryAllocation.h
 * @details Implemented most functions required for a user created class
 * @version 1.0
 * @author Pedram Safaei
 * @bug nothing that can catched
 * @note bugs have been catched according the instruction
 */

// Precompiler Directives //////////////////////////////////////////
//
#ifndef MEMORYALOCATION
#define MEMORYALOCATION
//

// Header Files /////////////////////////////////////////////////// 
//
#include "CustomException.h"
//
class MEMORYLOCATION{
private:
    std::string input;
public:
    std::string Get_MemoryLocation();
};

#endif /* MEMORYALOCATION */