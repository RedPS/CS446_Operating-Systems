#ifndef METADATA
#define METADATA


#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <iterator>
#include <algorithm>

class MetaData{
    private:
        char cipher;
        std::string caption;
        int period;
        std::string data;
        int Ptime;

    public:
        MetaData();
        MetaData(const MetaData &copy);
        MetaData(char, std::string, int, std::string);

        void LoadMataData(std::string path, std::vector<MetaData> &MetaDatadata) throw (runtime_error) ;
        //setters
        void Set_cipher(char);
        void Set_caption(std::string);
        void Set_period(int);
        void Set_data(std::string);
        void Set_time(int);

        //getters
        char Get_cipher();
        std::string Get_caption();
        int Get_period();
        std::string Get_data();
        int Get_time();
};

#endif /* !METADATA */