#ifndef CONFIGURATION
#define CONFIGURATION

#include <iosteam>
#include <string>

class Configuration {

    private:
    //start 
        //get the version, metadata path
        double Version_Phase;
        std::string MetaDataFilePath;
        //get the times
        int MonitorTime;
        int ProcessorTime;
        int ScannerTime;
        int HardDriveTime;
        int KeyboardTime;
        int MemoryTime;
        int ProjectorTime;
        //get the outpout log info
        std::string LogToObject;
        std::string LogFilePath;
    //end
    
    public:
        //constructors
        Configuration();
        Configuration(const Configuration &copy);
        ~Configuration();
        //Read all the info
        void LoadConfigurationFile() throw (runtime_error);

        //setters
        void Set_Version_Phase(double VP);
        void Set_MetaDataFilePath(std::string MDFP);
        
        void Set_MonitorTime(int MONT);
        void Set_ProcessorTime(int PROCT);
        void Set_ScannerTime(int ST);
        void Set_HardDriveTime(int HD);
        void Set_KeyboardTime(int KT);
        void Set_MemoryTime(int MEMT);
        void Set_ProjectorTime(int PROJT);
        
        void Set_LogToObject(std::string LTO);
        void Set_LogFilePath(std::string LFP);

        //getters

        double Get_Version_Phase();
        std::string Get_MetaDataFilePath();
        
        int Get_MonitorTime();
        int Get_ProcessorTime();
        int Get_ScannerTime();
        int Get_HardDriveTime();
        int Get_KeyboardTime();
        int Get_MemoryTime();
        int Get_ProjectorTime();
        
        std::string Get_LogToObject();
        std::string Get_LogFilePath();


};

#endif /* !CONFIGURATION */