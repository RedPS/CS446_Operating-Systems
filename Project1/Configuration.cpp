#include "Configuration.h"
#include "CustomException.cpp"


Configuration::Configuration() {

}
Configuration::Configuration(const Configuration &copy){
    *this = copy;
}
Configuration::~Configuration(){

}
//setters
void Configuration::Set_Version_Phase(double VP){
    Version_Phase = VP;
}
void Configuration::Set_MetaDataFilePath(std::string MDFP){
    MetaDataFilePath = MDFP;
}

void Configuration::Set_MonitorTime(int MONT){
    MonitorTime = MONT;
}
void Configuration::Set_ProcessorTime(int PROCT){
    ProcessorTime = PROCT;
}
void Configuration::Set_ScannerTime(int ST){
    ScannerTime = ST;
}
void Configuration::Set_HardDriveTime(int HD){
    HardDriveTime = HD;
}
void Configuration::Set_KeyboardTime(int KT){
    KeyboardTime = KT;
}
void Configuration::Set_MemoryTime(int MEMT){
    MemoryTime = MEMT;
}
void Configuration::Set_ProjectorTime(int PROJT){
    ProjectorTime = PROJT;
}

void Configuration::Set_LogToObject(std::string LTO){
    LogToObject = LTO;
}
void Configuration::Set_LogFilePath(std::string LFP){
    LogFilePath = LFP;
}

//getters
double Configuration::Get_Version_Phase(){
    return Version_Phase;
}
std::string Configuration::Get_MetaDataFilePath(){
    return MetaDataFilePath;
}

int Configuration::Get_MonitorTime(){
    return MonitorTime;
}
int Configuration::Get_ProcessorTime(){
    return ProcessorTime;
}
int Configuration::Get_ScannerTime(){
    return ScannerTime;
}
int Configuration::Get_HardDriveTime(){
    return HardDriveTime;
}
int Configuration::Get_KeyboardTime(){
    return KeyboardTime;
}
int Configuration::Get_MemoryTime(){
    return MemoryTime;
}
int Configuration::Get_ProjectorTime(){
    return ProjectorTime;
}

std::string Configuration::Get_LogToObject(){
    return LogToObject;
}
std::string Configuration::Get_LogFilePath(){
    return LogFilePath;
}

void Configuration::LoadConfigurationFile(std::string PathToConfig){
    std::ifstream ConfigurationFile;
    ConfigurationFile.open(PathToConfig);

    if(ConfigurationFile){
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
        throw std::runtime_error("error: Can't open the configuration file");
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
               throw std::runtime_error("error: Wrong data in configuration");
           }
}