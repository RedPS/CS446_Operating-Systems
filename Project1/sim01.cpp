// Program Information //////////////////////
/**
 * @file sim01.cpp
 * @brief The main driver for Project1
 * @details Everything is done in other functions, this file is just a driver
 * @version 1.0
 * @author Pedram Safaei
 * @bug nothing that can catched
 * @note bugs have been catched according the instruction
 */
#include "Functions.h"

// Program Description/Support ///////////////////////////////////
/*
    This program will accept a set of instructions by what this course 
calls a metadata, it is basically a text file (mdf extention) with 
some sets of instructions.
    This program also uses a configuration file to set up Simulation 
evnvironment for us. Which is again just a textfile (conf extention)

                    Please run it by the following command

                            ./sim01 config.conf
*/
// Main Function Implementation /////////////////////////////////// 
//
int main(int argc, char *argv[]){
    //
    // program code
    //
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
                Functions::ProcessTheTime(config, i, status, pstatus);
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
//