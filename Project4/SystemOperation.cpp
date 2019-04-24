// Program Information //////////////////////
/**
 * @file SystemOperations.cpp
 * @brief implementation for SystemOperations.h 
 * @details This file is more implementations of process time, logs, outputs.
 * @version 1.0
 * @author Pedram Safaei
 * @bug nothing that can catched
 * @note bugs have been catched according the instruction
 */

// Header Files /////////////////////////////////////////////////// 
//
#include "CustomException.h"
#include "SystemOperation.h"
#include "Output.h"
//

/**
 * @brief constuctor for the heart of this program, reads config file, takes care of mutex and semaphore
 * @param configuration file
 * @param path to the config file
 **/
OperatingSystem::OperatingSystem(Config *cf, std::string configFilePath) {
    cf->readConfigFile(configFilePath);
    std::deque<MetaDataCode> systemOperations;
    MetaDataCode::readMetaDataFile(cf->getFilePath(), systemOperations);
    Process::createProcesses(this->processes, systemOperations);
	pthread_mutex_init(&this->projectorLock, NULL);
	pthread_mutex_init(&this->harddriveLock, NULL);
	pthread_mutex_init(&this->monitorLock, NULL);
	pthread_mutex_init(&this->scannerLock, NULL);
	pthread_mutex_init(&this->keyboardLock, NULL);
	sem_init(&this->harddriveSemaphore, 0, cf->getHarddriveResources()); 
	sem_init(&this->monitorSemaphore, 0, 1); 
	sem_init(&this->keyboardSemaphore, 0, 1); 
	sem_init(&this->scannerSemaphore, 0, 1); 
	sem_init(&this->projectorSemaphore, 0, cf->getProjectorResources()); 
    this->START_TIME = std::chrono::system_clock::now();
    this->harddriveInCount = 0;
    this->harddriveOutCount = 0;
    this->projectorCount = 0;
    this->memoryBlocksAllocated = 0;
}

/**
 * @brief Timer, or wait function
 * @param na just a void* 
 * @return nothing, it is void
 * @detail: needed for the pthread to work
 */
void* OperatingSystem::timer(void *emp) {
	std::chrono::system_clock::time_point start;
	std::chrono::system_clock::time_point end;
	double limit = 0.1;
	std::chrono::duration<double> elapsedTime;
	start = std::chrono::system_clock::now();
	while(elapsedTime.count() < limit) {
		end = std::chrono::system_clock::now();
		elapsedTime = end - start;
	}
	pthread_exit(NULL);
	return NULL;
}

/**
 * @brief process the thread
 * @param time limit 
 * @return double (it could be a float as well)
 * @detail: needed for the pthread to work
 */
double OperatingSystem::processThread(int timeLimit) {
	int time = timeLimit;
	pthread_t timerThread;
	auto timeEnd = std::chrono::system_clock::now() + std::chrono::milliseconds(timeLimit);
	while(std::chrono::system_clock::now() < timeEnd) {
		pthread_create(&timerThread, NULL, this->timer, NULL);
		pthread_join(timerThread, NULL);
	}
	auto currentTime = std::chrono::system_clock::now();
	return std::chrono::duration<double>(currentTime-this->START_TIME).count();
}

/**
 * @brief thread operation
 * @param timelimit 
 * @param queue of metadata
 * @param semaphore
 * @param mutex
 * @return nothing, it is void
 * @detail: needed for the pthread to work
 */
void OperatingSystem::threadOperation(int timeLimit, MetaDataCode &mdc, sem_t &semaphore, pthread_mutex_t &mutex) {
    sem_wait(&semaphore);
    pthread_mutex_lock(&mutex);
    auto endTime = processThread(timeLimit);
    pthread_mutex_unlock(&mutex);
    mdc.setProcessingTime(endTime);
    sem_post(&semaphore);
}

/**
 * @brief generate memory addresss
 * @param memeory block
 * @return string (memory location)
 * @detail: generates a memory address best suited for the program
 */
std::string OperatingSystem::generateMemoryLocation(int memory) {
    std::string input;
    std::stringstream sstr;
    sstr << std::hex << std::setw(8) << std::setfill('0') << memory;
    return sstr.str();
}

/**
 * @brief Process system application
 * @param string of words to print on the terminal or file (or both)
 * @return nothing, it is void
 * @detail: process the operations 
 */
void OperatingSystem::processSystemApp(std::string printout, Config* cf) {
    auto currentTime = std::chrono::system_clock::now();
    auto timed = (std::chrono::duration<double>(currentTime-this->START_TIME).count());
    Log::output(*cf, std::to_string(timed) + " - " + printout);
}

/**
 * @brief process I/O
 * @param metadata queue
 * @param confuguartion file
 * @param semaphores
 * @param mutex
 * @param counter for the resources
 * @param processess number
 * @param cycle time 
 * @param string of words to print
 * @param string of words to print (slighty different than previous)
 * @return nothing, it is void
 * @detail: process the input and output operations
 */
void OperatingSystem::processIOOperation(MetaDataCode mdc, Config* cf, sem_t &semaphore, pthread_mutex_t &lock, int& count, int processNumber, int cycleTime, std::string printout, std::string printout2 ) {
    int timeLimit = mdc.getCycles() * cycleTime;
    auto currentTime = std::chrono::system_clock::now();
    mdc.setStartTime(std::chrono::duration<double>(currentTime-this->START_TIME).count());

    if( count >=0 ){
       // Log::output(*cf, std::to_string(mdc.getStartTime())  + " - " + "Process " + std::to_string(processNumber) + ": start " + printout + " " + std::to_string(count));
        Log::output(*cf, std::to_string(mdc.getStartTime())  + " - " + "Process " + std::to_string(processNumber) + ": start " + printout);
        this->threadOperation(timeLimit, mdc, semaphore, lock);
        Log::output(*cf, std::to_string(mdc.getProcessingTime()) + " - " + "Process " + std::to_string(processNumber) + ": end " + printout2);
        count++;
    }else {
        Log::output(*cf, std::to_string(mdc.getStartTime()) + " - " + "Process " + std::to_string(processNumber) + ": start " + printout); 
        this->threadOperation(timeLimit, mdc, semaphore, lock);
        Log::output(*cf, std::to_string(mdc.getProcessingTime()) + " - " + "Process " + std::to_string(processNumber) + ": end " + printout2);
    }
}
/**
 * @brief Processes the actions 
 * @param string of words to print
 * @param config: Configuration object
 * @param data: Metadata object
 * @param prpcess number
 * @param cycle time
 * @return VOID: Nothing
 */
void OperatingSystem::processAction(std::string printout, Config* cf, MetaDataCode mdc, int processNumber, int cycleTime) {
    auto timeLimit = mdc.getCycles() * cycleTime;
    auto currentTime = std::chrono::system_clock::now();
    mdc.setStartTime(std::chrono::duration<double>(currentTime-this->START_TIME).count());
    Log::output(*cf, std::to_string(mdc.getStartTime()) + " - " + "Process " + std::to_string(processNumber) + ": start " + printout);
    mdc.setProcessingTime(this->processThread(timeLimit));
    Log::output(*cf, std::to_string(mdc.getProcessingTime()) + " - " + "Process " + std::to_string(processNumber) + ": end " + printout);
}
/**
 * @brief Processes the time
 * @param process in the program
 * @param config: Configuration object
 * @return VOID: Nothing
 */
void OperatingSystem::process(Process &p, Config* cf) {
    auto processOperations = p.getOperations();
    int noResources = -1;
    this->processSystemApp("OS: preparing process " + std::to_string(p.getProcessCount()), cf);
    this->processSystemApp("OS: starting process " + std::to_string(p.getProcessCount()), cf);
        p.setProcessState(Process::ProcessState::READY);
    for(auto mdc : processOperations) {
        if(mdc.getCode() == 'P' && mdc.getDescriptor() == "run") {
            this->processAction("processing action", cf, mdc, p.getProcessCount(), cf->getPCT());
        } else if(mdc.getCode() == 'I') {
            if(mdc.getDescriptor() == "hard drive") {
                p.setProcessState(Process::ProcessState::RUNNING);
                if (this->harddriveInCount >= cf->getHarddriveResources()){
                    this->harddriveInCount = 0;
                }
                this->processIOOperation(mdc, cf, this->harddriveSemaphore, this->harddriveLock, this->harddriveInCount, p.getProcessCount(), cf->getHCT(), "hard drive input", "hard drive input");
                p.setProcessState(Process::ProcessState::READY);

            } else if(mdc.getDescriptor() == "keyboard") {
                p.setProcessState(Process::ProcessState::RUNNING);
                this->processIOOperation(mdc, cf, this->keyboardSemaphore, this->keyboardLock, noResources, p.getProcessCount(), cf->getKCT(), "keyboard input","keyboard input");
                p.setProcessState(Process::ProcessState::READY);
            } else if(mdc.getDescriptor() == "scanner") {
                p.setProcessState(Process::ProcessState::RUNNING);
                this->processIOOperation(mdc, cf, this->scannerSemaphore, this->scannerLock, noResources, p.getProcessCount(), cf->getSCT(), "scanner input", "scanner input");
                p.setProcessState(Process::ProcessState::READY);
            } else {
                throw_line("There is an invalid descriptor for the code \"I\" ");
            }
        } else if(mdc.getCode() == 'O') {
            if(mdc.getDescriptor() == "hard drive") {
                p.setProcessState(Process::ProcessState::RUNNING);
                if (this->harddriveOutCount >= cf->getHarddriveResources()){
                    this->harddriveOutCount = 0;
                }
                this->processIOOperation(mdc, cf, this->harddriveSemaphore, this->harddriveLock, this->harddriveOutCount, p.getProcessCount(), cf->getHCT(), "hard drive output", "hard drive output");
                p.setProcessState(Process::ProcessState::READY);
            } else if(mdc.getDescriptor() == "monitor") {
                p.setProcessState(Process::ProcessState::RUNNING);
                this->processIOOperation(mdc, cf, this->monitorSemaphore, this->monitorLock, noResources, p.getProcessCount(), cf->getMDT(), "monitor output", "monitor output");
                p.setProcessState(Process::ProcessState::READY);
            } else if(mdc.getDescriptor() == "projector") {
                p.setProcessState(Process::ProcessState::RUNNING);
                if (this->projectorCount >= cf->getProjectorResources()){
                    this->projectorCount = 0;
                }
                this->processIOOperation(mdc, cf, this->projectorSemaphore, this->projectorLock, this->projectorCount, p.getProcessCount(), cf->getProCT(),  "projector output", "projector output");
                p.setProcessState(Process::ProcessState::READY);
            } else {
                throw_line("There is an invalid descriptor for the code \"O\" ");
            }
        } else if(mdc.getCode() == 'M') {
            if(mdc.getDescriptor() == "block") {
                p.setProcessState(Process::ProcessState::RUNNING);
                this->processAction("memory blocking", cf, mdc, p.getProcessCount(), cf->getMemCT());
                p.setProcessState(Process::ProcessState::READY);
            } else if(mdc.getDescriptor() == "allocate") {
                p.setProcessState(Process::ProcessState::RUNNING);
                auto timeLimit = mdc.getCycles() * cf->getMemCT();
                auto currentTime = std::chrono::system_clock::now();
                this->memoryBlocksAllocated = (this->memoryBlocksAllocated > ((float) cf->getMaxMemorySize()/(float) cf->getMemoryBlockSize())) ? 0 : this->memoryBlocksAllocated;
                auto memory = this->memoryBlocksAllocated * cf->getMemoryBlockSize();
                mdc.setStartTime(std::chrono::duration<double>(currentTime-START_TIME).count());
                Log::output(*cf, std::to_string(mdc.getStartTime()) + " - " + "Process " + std::to_string(p.getProcessCount()) + ": " + "allocating memory");
                mdc.setProcessingTime(this->processThread(timeLimit));
                Log::output(*cf, std::to_string(mdc.getProcessingTime()) + " - " + "Process " + std::to_string(p.getProcessCount()) + ": " + "memory allocated at 0x" + this->generateMemoryLocation(memory));
                this->memoryBlocksAllocated++;
                p.setProcessState(Process::ProcessState::READY);
            } else {
                throw_line("There is an invalid descriptor for the code \"M\" ");
            }
        }
    }
    this->processSystemApp("OS: End process " + std::to_string(p.getProcessCount()), cf);
    p.setProcessState(Process::ProcessState::EXIT);
}
/**
 * @brief getter for the processes
 * @return queue of processes
 */
std::deque<Process> OperatingSystem::getProcesses() {
    return this->processes;
}
/**
 * @brief reset memory locations
 * @return VOID: Nothing
 */
void OperatingSystem::resetMemory() {
    this->memoryBlocksAllocated = 0;
}
/**
 * @brief get the memory block location
 * @return integer, memoery block location
 */
int OperatingSystem::get_memoryblocksallocated(){
    return this->memoryBlocksAllocated;
}