#include "Functions.cpp"

int main(int argc, char *argv[]){
    Configuration config;
    MetaData data;
    int status = 0;
    int pstatus = 0;
    if (argc == 2){
        std::vector<MetaData> MetaDatadata;
        config.LoadConfigurationFile(argv[1]);
        data.LoadMataData(config.Get_MetaDataFilePath(), MetaDatadata);
        for (auto& i : MetaDatadata){
            ProcTime(config, i, status, pstatus);
        }
        logtofile(config, MetaDatadata);
        return 0;
    }
    else if (argc < 2)
    {
        throw std::runtime_error("You need more than one arguments when running simulator");
    }
    else if (argc > 2)
    {
        throw std::runtime_error("You need less than 3, exactly 2, arguments when running simulator");
    }
}