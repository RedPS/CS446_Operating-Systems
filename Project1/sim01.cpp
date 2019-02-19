#include "Functions.h"

int main(int argc, char *argv[]){
    try{
        Configuration config;
        MetaData data;
        int status = 0;
        int pstatus = 0;
        if (argc == 2){
            std::vector<MetaData> MetaDatadata;
            config.LoadConfigurationFile(argv[1]);
            data.LoadMataData(config.Get_MetaDataFilePath(), MetaDatadata);
            for (auto& i : MetaDatadata){
                Functions::ProcTime(config, i, status, pstatus);
            }
            Functions::logtofile(config, MetaDatadata);
            return 0;
        }
        else if (argc < 2){
            throw_line("You need more than one arguments when running simulator");
        }
        else if (argc > 2){
            throw_line("You need less than 3, exactly 2, arguments when running simulator");
        }
    }catch(const std::runtime_error& e){
        std::cerr << e.what() << std::endl;
    }
}

/*
try{
     throw_line();
}catch(const std::runtime_error& e){
    std::cerr << e.what() << std::endl;
}
*/