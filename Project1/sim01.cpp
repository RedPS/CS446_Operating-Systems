#include "Functions.cpp"

int main(int argc, char *argv[]){
    Configuration config;
    MetaData data;

    if (argc == 2){
        std::vector<MetaData> MetaDatadata;
        config.LoadConfigurationFile(argv[1]);

        data.LoadMataData(config.Get_LogFilePath, MetaDatadata);

        for (auto& i : MetaDatadata){

        }
        
    }
    else if (argc < 2)
    {
        throw runtime_error("You need more than one arguments when running simulator");
    }
    else if (argc > 2)
    {
        throw runtime_error("You need less than 3, exactly 2, arguments when running simulator");

    }
}