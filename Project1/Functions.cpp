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
void ProcessTheTime(Configuration config, MetaData& data, int& status, int &progstatus) {
    if (data.Get_cipher() == 'S'){
        if (data.Get_caption() == "begin" and status == 0){
            status = 1;
        }
        else if (data.Get_caption() == "finish" and status == 1 and !progstatus){
            status = 2;
        }
        else {
            throw_line("\"begin\" or \"finish\" are missing CODE S (case sensitive)");
        }
    }
    else if (data.Get_cipher() == 'A'){
        if(data.Get_caption() == "begin" and progstatus == 0){
            progstatus = 1;
        }
        else if (data.Get_caption() == "finish" and progstatus == 1){
            progstatus = 0;
        }
        else {
            throw_line("\"begin\" or \"finish\" are missing CODE A (case sensitive) ");
        }
    }
    if (data.Get_cipher() == 'P' and data.Get_caption() == "run"){
        data.Set_time(data.Get_period() * config.Get_ProcessorTime());
    }
    if (data.Get_cipher() == 'I'){
        if (data.Get_caption() == "scanner"){
            data.Set_time(data.Get_period() * config.Get_ScannerTime());
        }
        else if(data.Get_caption() == "keyboard"){
            data.Set_time(data.Get_period() * config.Get_KeyboardTime());
        }
        else if (data.Get_caption() == "hard drive"){
            data.Set_time(data.Get_period() * config.Get_HardDriveTime());
        }
        else{
            throw_line("Can't find the caption for cipher (CODE) \'I\'");

        }
    }
    if (data.Get_cipher() == 'O'){
        if (data.Get_caption() == "monitor"){
            data.Set_time(data.Get_period() * config.Get_MonitorTime());
        }
        else if(data.Get_caption() == "projector"){
            data.Set_time(data.Get_period() * config.Get_ProjectorTime());
        }
        else if (data.Get_caption() == "hard drive"){
            data.Set_time(data.Get_period() * config.Get_HardDriveTime());
        }
        else{
            throw_line("Can't find the caption for cipher (CODE) \'O\'");
        }
    }
    if (data.Get_cipher() == 'M'){
        if (data.Get_caption() == "allocate"){
            data.Set_time(data.Get_period() * config.Get_MemoryTime());
        }
        else if(data.Get_caption() == "block"){
            data.Set_time(data.Get_period() * config.Get_MemoryTime());
        }
        else{
            throw_line("Can't find the caption (description) for cipher (code) \'M\'");
        }
    }

}
//

// Free Function Implementation /////////////////////////////////// 
//
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
void logoutput(Configuration config, std::ostream& output, int status, std::vector<MetaData> data){
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
}
// Free Function Implementation /////////////////////////////////// 
//
}