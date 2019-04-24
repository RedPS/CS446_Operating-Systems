// Program Information //////////////////////
/**
 * @file sim3.cpp
 * @brief The main driver for Project3
 * @details Everything is done in other functions, this file is just a driver
 * @version 1.3
 * @author Pedram Safaei
 * @bug nothing that can catched
 * @note bugs have been catched according the instruction
 */
#include "SystemOperation.h"
// Program Description/Support ///////////////////////////////////
/*
    This program will accept a set of instructions by what this course
    calls a metadata, it is basically a text file (mdf extention) with
    some sets of instructions.
    This program also uses a configuration file to set up Simulation
    evnvironment for us. Which is again just a textfile (conf extention)

                    Please run it by the following command

                            ./sim3 Config.conf
*/
// Main Function Implementation ///////////////////////////////////
//
int main(int argc, char* argv[]) {
    //
    // program code
    //
    try{
        if (argc == 2){
            std::string fileName(argv[1]);
            Config cf;
            
            OperatingSystem os(&cf, fileName);
             
            auto processQueue = os.getProcesses();
           
            os.processSystemApp("Simulator program starting", &cf);
            Scheduler::scheduleProcesses(&cf, processQueue);
            for(auto process : processQueue) {
                os.process(process, &cf);
                if ( cf.getMaxMemorySize() / cf.getMemoryBlockSize() == os.get_memoryblocksallocated())
                    os.resetMemory();
            }
            os.processSystemApp("Simulator program ending", &cf);
            return 0;
        }else if (argc < 2){
            throw_line("You need more than one arguments when running simulator");
        }else if (argc > 2){
            throw_line("You need less than 3, exactly 2, arguments when running simulator");
        }
    }catch(const std::runtime_error& e){
        std::cerr << e.what() << std::endl;
    }
}
//