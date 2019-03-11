#include "MemoryAllocation.h"

std::string MEMORYLOCATION::Get_MemoryLocation(){
    srand(time(NULL));
    input = std::to_string(rand()%10000000 + 10000000);
    return input;
}