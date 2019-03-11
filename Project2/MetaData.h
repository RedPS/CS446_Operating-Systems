// Class Header Information /////////////////////////
/**
 * @file MetaData.h
 * @brief Header file for MetaData part of Project1
 * @details This is a class for metadata part of project1
 * @version 1.0
 * @author Pedram Safaei
 * @bug nothing that can catched
 * @note bugs have been catched according the instruction
 */

// Precompiler Directives //////////////////////////////////////////
//
#ifndef METADATA
#define METADATA
//

// Header Files /////////////////////////////////////////////////// 
//
#include "CustomException.h"
//

class MetaData {
    private:
        char cipher;
        std::string caption;
        int period;
        std::string data;
        int Ptime;

        double ProcessTime;
        double StartTime;

    public:
        MetaData();
        MetaData(const MetaData &copy);
        MetaData(char, std::string, int, std::string);

        bool is_empty(std::ifstream& File);
        void LoadMataData(std::string path, std::vector<MetaData> &MetaDatadata) ;
        //setters
        void Set_cipher(char);
        void Set_caption(std::string);
        void Set_period(int);
        void Set_data(std::string);
        void Set_time(int);
        void Set_StartTime(double);
        void Set_ProcessTime(double);
        //getters
        char Get_cipher();
        std::string Get_caption();
        int Get_period();
        std::string Get_data();
        int Get_time();
        double Get_StartTime();
        double Get_ProcessTime();
};

// Terminating Precompiler Directives /////////////////////////////// 
//
#endif /* !METADATA */
//