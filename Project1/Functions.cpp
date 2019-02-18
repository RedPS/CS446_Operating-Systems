#include "Configuration.cpp"
#include "MetaData.cpp"


void ProcTime(Configuration config, MetaData& data, int& status, int progstatus) throw (runtime_error) {
    if (data.Get_cipher() == "S"){
        if (data.Get_caption() == "begin" and status == 0){
            status = 1;
        }
        else if (data.Get_caption() == "finish" and status == 1 and !progstatus){
            status = 2;
        }
        else {
            throw runtime_error("\"begin\" or \"finish\" are missing ");
        }
    }
    if (data.Get_cipher() == 'A'){
        if(data.Get_caption() == "begin" and progstatus == 0){
            progstatus = 1;
        }
        else if (data.Get_caption() == "finish" and progstatus == 1){
            progstatus = 0;
        }
        else {
            throw runtime_error("\"begin\" or \"finish\" are missing ");
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
            throw runtime_error("Can't find the caption for cipher \'I\'");

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
            throw runtime_error("Can't find the caption for cipher \'O\'");
        }
    }
    if (data.Get_cipher() == 'M'){
        if (data.Get_caption() == "allocate"){
            data.Set_time(data.Get_period() * config.Get_MonitorTime());
        }
        else if(data.Get_caption() == "block"){
            data.Set_time(data.Get_period() * config.Get_MemoryTime());
        }
        else{
            throw runtime_error("Can't find the caption for cipher \'M\'");
        }
    }

}