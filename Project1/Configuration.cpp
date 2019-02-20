// Class Implementation File Information //////////////////////
/**
 * @file Configuration.cpp
 * @brief Implementations for Configuration.h
 * @details Implemented most functions required for a user created class
 * @version 1.0
 * @author Pedram Safaei
 * @bug nothing that can catched
 * @note bugs have been catched according the instruction
 */

// Header Files /////////////////////////////////////////////////// 
//
#include "Configuration.h"
//

// Class/Data Structure Member Implementation ////////////////////// 
//

/**
 * @brief: default constructor
 * used for the configuration class
*/
Configuration::Configuration() {

}
/**
 * @brief: copy constructor
 * used for the configuration class
*/
Configuration::Configuration(const Configuration &copy){
    *this = copy;
}
/**
 * @brief: destructor constructor
 * used for the configuration class
*/
Configuration::~Configuration(){

}
//setters
/**
 * @brief: setter for the configuration class
 * takes a double because of the version number
*/
void Configuration::Set_Version_Phase(double VP){
    Version_Phase = VP;
}
/**
 * @brief: setter for the configuration class
 * takes a string for file path 
*/
void Configuration::Set_MetaDataFilePath(std::string MDFP){
    MetaDataFilePath = MDFP;
}

/**
 * @brief: setter for the configuration class
 * takes a int for minitor time
*/
void Configuration::Set_MonitorTime(int MONT){
    MonitorTime = MONT;
}
/**
 * @brief: setter for the configuration class
 * takes int for processor time 
*/
void Configuration::Set_ProcessorTime(int PROCT){
    ProcessorTime = PROCT;
}

/**
 * @brief: setter for the configuration class
 * takes an int for ScannerTime
*/
void Configuration::Set_ScannerTime(int ST){
    ScannerTime = ST;
}

/**
 * @brief: setter for the configuration class
 * take an int for hard drive time
*/
void Configuration::Set_HardDriveTime(int HD){
    HardDriveTime = HD;
}
/**
 * @brief: setter for the configuration class
 * take an int for keyboard time
*/
void Configuration::Set_KeyboardTime(int KT){
    KeyboardTime = KT;
}
/**
 * @brief: setter for the configuration class
 * takes an int for memory time
*/
void Configuration::Set_MemoryTime(int MEMT){
    MemoryTime = MEMT;
}
/**
 * @brief: setter for the configuration class
 * takes an int for projector time
*/
void Configuration::Set_ProjectorTime(int PROJT){
    ProjectorTime = PROJT;
}
/**
 * @brief: setter for the configuration class
 * takes a string to see where to log to
*/
void Configuration::Set_LogToObject(std::string LTO){
    LogToObject = LTO;
}
/**
 * @brief: setter for the configuration class
 * takes a string which indicates what the logfile path (name) is
*/
void Configuration::Set_LogFilePath(std::string LFP){
    LogFilePath = LFP;
}

//getters
/**
 * @brief: getter for the configuration class
 * @returns version phase
*/
double Configuration::Get_Version_Phase(){
    return Version_Phase;
}
/**
 * @brief: getter for the configuration class
 * @returns metadata file path
*/
std::string Configuration::Get_MetaDataFilePath(){
    return MetaDataFilePath;
}

/**
 * @brief: getter for the configuration class
 * @returns time for monitor
*/
int Configuration::Get_MonitorTime(){
    return MonitorTime;
}
/**
 * @brief: getter for the configuration class
 * @returns time for processor
*/
int Configuration::Get_ProcessorTime(){
    return ProcessorTime;
}
/**
 * @brief: getter for the configuration class
 * @returns time for scanner
*/
int Configuration::Get_ScannerTime(){
    return ScannerTime;
}
/**
 * @brief: getter for the configuration class
 * @returns time for hard drive
*/
int Configuration::Get_HardDriveTime(){
    return HardDriveTime;
}
/**
 * @brief: getter for the configuration class
 * @returns time for keyboard
*/
int Configuration::Get_KeyboardTime(){
    return KeyboardTime;
}
/**
 * @brief: getter for the configuration class
 * @returns time for memory
*/
int Configuration::Get_MemoryTime(){
    return MemoryTime;
}
/**
 * @brief: getter for the configuration class
 * @returns time for projector
*/
int Configuration::Get_ProjectorTime(){
    return ProjectorTime;
}
/**
 * @brief: getter for the configuration class
 * @returns Logtoobject
*/
std::string Configuration::Get_LogToObject(){
    return LogToObject;
}
/**
 * @brief: getter for the configuration class
 * @returns logfilepath
*/
std::string Configuration::Get_LogFilePath(){
    return LogFilePath;
}
/**
 * @brief: getter for the configuration class
 * @returns a boolean value indicating is file is empty or not
*/
bool Configuration::is_empty(std::ifstream& File){
    return File.peek() == std::ifstream::traits_type::eof();
}
/**
 * @brief: getter for the configuration class
 * @param pathToConfig: as name indicates the string gives path to config (name of config)
 * @return VOID: Nothing
*/
void Configuration::LoadConfigurationFile(std::string PathToConfig){
    std::ifstream ConfigurationFile;
    ConfigurationFile.open(PathToConfig);

    if(ConfigurationFile){
        if(is_empty(ConfigurationFile)){
            throw_line("Config File is empty!");
        }
        std::string text;
        std::string FilePath;
        std::vector<std::string> words;

        while(ConfigurationFile >> text){
            words.push_back(text);
        }
        for (std::vector<std::string>::iterator it = words.begin() ; it != words.end(); it++){
            if (*it == "File"){
                if (*(it+1) =="Path:" and *(it-1) != "Log")
                { 
                    FilePath = *(it+2);
                    if (FilePath.substr(FilePath.find_last_of(".") + 1) == "mdf"){
                        Set_MetaDataFilePath(FilePath);        
                    }
                    else{
                        throw_line("File Path for Meta Data does not have \"mdf\" extension");
                    }
                }
            }
            if (*it == "Version/Phase:"){
                Set_Version_Phase(std::stod(*(it+1)));
            }
            if (*it == "Monitor"){
                Set_MonitorTime(std::stoi(*(it+4)));
            }
            if (*it == "Processor"){
                Set_ProcessorTime(std::stoi(*(it+4)));
            }
            if (*it == "Scanner"){
                Set_ScannerTime(std::stoi(*(it+4)));
            }
            if (*it == "Hard"){
                Set_HardDriveTime(std::stoi(*(it+5)));
            }
            if (*it == "Keyboard"){
                Set_KeyboardTime(std::stoi(*(it+4)));
            }
            if (*it == "Memory"){
                Set_MemoryTime(std::stoi(*(it+4)));
            }
            if (*it == "Projector"){
                Set_ProjectorTime(std::stoi(*(it+4)));
            }
            if (*it == "Log:"){
                Set_LogToObject(*(it+3));
            }
            if (*it == "Log" and *(it+1) != "to"){
                    FilePath = *(it+3);
                    if (FilePath.substr(FilePath.find_last_of(".") + 1) == "lgf"){
                    Set_LogFilePath(FilePath);
                    }
                    else{
                        throw_line("File Path for Log File does not have \"lgf\" extension");
                    }
            }
        }
    }
    else{
        throw_line("error: Can't open the configuration file");
    }

    ConfigurationFile.close();

    if (!( (Version_Phase > 0) and 
           (MonitorTime   > 0) and 
           (ProcessorTime > 0) and 
           (ScannerTime   > 0) and 
           (HardDriveTime > 0) and 
           (KeyboardTime  > 0) and 
           (MemoryTime    > 0) and 
           (ProjectorTime > 0) )){
               throw_line("error: Wrong data in configuration");
           }
}