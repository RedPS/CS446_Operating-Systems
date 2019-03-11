// Program Information //////////////////////
/**
 * @file Functions.cpp
 * @brief implementation for Functions.h 
 * @details This file is more implementations of process time, logs, outputs.
 * @version 1.0
 * @author Pedram Safaei
 * @bug nothing that can catched
 * @note bugs have been catched according the instruction
 */

// Header Files /////////////////////////////////////////////////// 
//
#include"Functions.h"
//
namespace Functions
{
// Free Function Implementation /////////////////////////////////// 
//

/**
 * @brief Processes the time
 * @param config: Configuration object
 * @param data: Metadata object
 * @param status: status of the system
 * @param progstatus: status of the programstatus
 * @return VOID: Nothing
 */
void ProcessTheTime(Configuration config, MetaData& data) {
    int cap;
    ProcessControl p;
    p.Set_ProcessState(4);
    if (data.Get_cipher() == 'S'){
        if (data.Get_caption() == "begin" and p.Get_ProcessState() == 4){
             p.Set_ProcessState(0);
            auto TimeCurrent = std::chrono::system_clock::now();
            data.Set_StartTime(std::chrono::duration<double>(TimeCurrent - TimeStart).count());
            logf.push_back(std::to_string(data.Get_StartTime()) + " - " + "Simulator program starting");
        }
        else if (data.Get_caption() == "finish" and p.Get_ProcessState() == 1){
            p.Set_ProcessState(4);
            auto TimeCurrent = std::chrono::system_clock::now();
            data.Set_StartTime(std::chrono::duration<double>(TimeCurrent - TimeStart).count());
            logf.push_back(std::to_string(data.Get_StartTime()) + " - " + "Simulator program ending");
        }
        else {
            throw_line("\"begin\" or \"finish\" are missing CODE S (case sensitive)");
        }
    }
    else if (data.Get_cipher() == 'A'){
        if(data.Get_caption() == "begin" and p.Get_ProcessState() == 0){
            p.Set_ProcessState(1);
            auto TimeCurrent = std::chrono::system_clock::now();
            data.Set_StartTime(std::chrono::duration<double>(TimeCurrent - TimeStart).count());
            logf.push_back(std::to_string(data.Get_StartTime()) + " - " + "OS: starting process 1");
        }
        else if (data.Get_caption() == "finish" and p.Get_ProcessState() == 1){
            auto TimeCurrent = std::chrono::system_clock::now();
            data.Set_StartTime(std::chrono::duration<double>(TimeCurrent - TimeStart).count());
            logf.push_back(std::to_string(data.Get_StartTime()) + " - " + "OS: Removing process 1");
        }
        else {
            throw_line("\"begin\" or \"finish\" are missing CODE A (case sensitive) ");
        }
    }
    if (data.Get_cipher() == 'P' and data.Get_caption() == "run"){
        p.Set_ProcessState(2);
        cap = (data.Get_period() * config.Get_ProcessorTime());
        p.RunProcess(cap, data);
        logf.push_back(std::to_string(data.Get_StartTime()) + " - " + "Process 1: start Processing action");
        logf.push_back(std::to_string(data.Get_ProcessTime()) + " - " + "Process 1: end Processing action");
        p.Set_ProcessState(1);
    }
    if (data.Get_cipher() == 'I'){
        if (data.Get_caption() == "scanner"){
           p.Set_ProcessState(2);
            cap = (data.Get_period() * config.Get_ScannerTime());
            p.RunProcess(cap, data);
            logf.push_back(std::to_string(data.Get_StartTime()) + " - " + "Process 1: start scanner input");
            logf.push_back(std::to_string(data.Get_ProcessTime()) + " - " + "Process 1: end scanner input");
            p.Set_ProcessState(1);
        }
        else if(data.Get_caption() == "keyboard"){
            p.Set_ProcessState(2);
            cap = (data.Get_period() * config.Get_KeyboardTime());
            p.RunProcess(cap, data);
            logf.push_back(std::to_string(data.Get_StartTime()) + " - " + "Process 1: start keyboard input");
            logf.push_back(std::to_string(data.Get_ProcessTime()) + " - " + "Process 1: end keyboard input");
            p.Set_ProcessState(1);  
        }
        else if (data.Get_caption() == "hard drive"){
            p.Set_ProcessState(2);
            cap = (data.Get_period() * config.Get_HardDriveTime());
            p.RunProcess(cap, data);
            logf.push_back(std::to_string(data.Get_StartTime()) + " - " + "Process 1: start hard drive input");
            logf.push_back(std::to_string(data.Get_ProcessTime()) + " - " + "Process 1: end hard drive input");
            p.Set_ProcessState(1);
        }
        else{
            throw_line("Can't find the caption for cipher (CODE) \'I\'");
        }
    }
    if (data.Get_cipher() == 'O'){
        if (data.Get_caption() == "monitor"){
            p.Set_ProcessState(2);
            cap = (data.Get_period() * config.Get_MonitorTime());
            p.RunProcess(cap, data);
            logf.push_back(std::to_string(data.Get_StartTime()) + " - " + "Process 1: start monitor output");
            logf.push_back(std::to_string(data.Get_ProcessTime()) + " - " + "Process 1: end monitor output");
            p.Set_ProcessState(1);
        }
        else if(data.Get_caption() == "projector"){
            p.Set_ProcessState(2);
            cap = (data.Get_period() * config.Get_ProjectorTime());
            p.RunProcess(cap, data);
            logf.push_back(std::to_string(data.Get_StartTime()) + " - " + "Process 1: start projector output");
            logf.push_back(std::to_string(data.Get_ProcessTime()) + " - " + "Process 1: end projector output");
            p.Set_ProcessState(1);
        }
        else if (data.Get_caption() == "hard drive"){
            p.Set_ProcessState(2);
            cap = (data.Get_period() * config.Get_HardDriveTime());
            p.RunProcess(cap, data);
            logf.push_back(std::to_string(data.Get_StartTime()) + " - " + "Process 1: start hard drive output");
            logf.push_back(std::to_string(data.Get_ProcessTime()) + " - " + "Process 1: end hard drive output");
            p.Set_ProcessState(1);
        }
        else{
            throw_line("Can't find the caption for cipher (CODE) \'O\'");
        }
    }
    if (data.Get_cipher() == 'M'){
        if (data.Get_caption() == "allocate"){
            MEMORYLOCATION M;
            p.Set_ProcessState(2);
            cap = (data.Get_period() * config.Get_MemoryTime());
            p.RunProcess(cap, data);
            logf.push_back(std::to_string(data.Get_StartTime()) + " - " + "Process 1: allocating memory");
            logf.push_back(std::to_string(data.Get_ProcessTime()) + " - " + "Process 1: memory allocated at 0x" + M.Get_MemoryLocation() );
            p.Set_ProcessState(1);
        }
        else if(data.Get_caption() == "block"){
            p.Set_ProcessState(2);
            cap = (data.Get_period() * config.Get_MemoryTime());
            p.RunProcess(cap, data);
            logf.push_back(std::to_string(data.Get_StartTime()) + " - " + "Process 1: start memory blocking");
            logf.push_back(std::to_string(data.Get_ProcessTime()) + " - " + "Process 1: end memory blocking");
            p.Set_ProcessState(1);
        }
        else{
            throw_line("Can't find the caption (description) for cipher (code) \'M\'");
        }
    }

}
//

// Free Function Implementation /////////////////////////////////// 
//
/**
 * @brief logtofile
 * @param config: Configuration object
 * @param data: Metadata object
 * @return VOID: Nothing
 */
void logtofile(Configuration config, std::vector<MetaData> data){
    std::ofstream logout;
    bool to_monitor = false;
    bool to_file = false;
    bool to_both = false;

    if (config.Get_LogToObject() == "Both") {
        to_both = true;
    }
    else if ((config.Get_LogToObject() == "monitor")){
        to_monitor = true;
    }
    else if ((config.Get_LogToObject() == "file")){
        to_file = true;
    }
    else{
        throw_line("The given log location is invalid (valid locatons are Both, monitor, file [case sensitive])");
    }

    if (to_both){
        logoutput(config, std::cout, 1, data);
        logout.open(config.Get_LogFilePath());
        logoutput(config, logout, 1, data);
        logout.close();
    }
    if (to_monitor){
        logoutput(config, std::cout, 2 , data);
    }
    if(to_file){
        logout.open(config.Get_LogFilePath());
        logoutput(config, logout, 3, data);
        logout.close();
    }
}
//
// Free Function Implementation /////////////////////////////////// 
//
/**
 * @brief logtofile
 * @param config: Configuration object
 * @param output: ostream so we know where to print
 * @param status: system status tells where it is printing, (both,  monitor, file)
 * @param data: vector of metadata object type holds the metadata data
 * @return VOID: Nothing
 */
void logoutput(Configuration config, std::ostream& output, int status, std::vector<MetaData> data){
  /*
    output << "Configuration File Data \n";
    output << "Monitor = "    << config.Get_MonitorTime()   << " ms/cycle \n";
    output << "Processor = "  << config.Get_ProcessorTime() << " ms/cycle \n";
    output << "Scanner = "    << config.Get_ScannerTime()   << " ms/cycle \n";
    output << "Hard Drive = " << config.Get_HardDriveTime() << " ms/cycle \n";
    output << "Keyboard = "   << config.Get_KeyboardTime()  << " ms/cycle \n";
    output << "Memory = "     << config.Get_MemoryTime()    << " ms/cycle \n";
    output << "Projector = "  << config.Get_ProjectorTime() << " ms/cycle \n";

    if (status == 1 ){
        output << "Logged to: monitor and " << config.Get_LogFilePath() << std::endl;
    }
    if (status == 2){
        output << "Logged to " << config.Get_LogToObject() << std::endl;
    }
    if (status == 3){
        output << "Logged to " << config.Get_LogFilePath() << std::endl;
    }
    output << std::endl;
    output << "Meta-Data Metrics \n";

    for (std::vector<MetaData>::iterator it = data.begin() ; it != data.end(); ++it){
        MetaData DATA = *it;
        if (!(DATA.Get_cipher() == 'S') and !(DATA.Get_cipher() == 'A')){
            output << DATA.Get_data() << " - " << DATA.Get_time() << " ms\n";
        }
    }
    */
   for (auto it= logf.begin(); it != logf.end(); it++){
       output << std::fixed << std::setprecision(6) << *it << std::endl;
   }
}
//
}