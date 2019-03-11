// Class Implementation File Information //////////////////////
/**
 * @file MetaData.cpp
 * @brief Implementations for MetaData.h
 * @details Implemented most functions required for a user created class
 * @version 1.0
 * @author Pedram Safaei
 * @bug nothing that can catched
 * @note bugs have been catched according the instruction
 */

// Header Files /////////////////////////////////////////////////// 
//
#include "MetaData.h"
//

// Class/Data Structure Member Implementation ////////////////////// 
//
/**
 * @brief default constructor for Meta data class
 */
MetaData::MetaData(){

}
/**
 * @brief copy constructor for Meta data class
 */
MetaData::MetaData(const MetaData&copy){
    *this = copy;
}
/**
 * @brief parameterized constructor for Meta data class
 * It is used to assign values faster
 */
MetaData::MetaData(char inputcipher, std::string inputcaption, int inputperiod, std::string inputdata){
    cipher = inputcipher;
    caption = inputcaption;
    period = inputperiod;
    data = inputdata;
}

//setters //////////////////////////////////////
//
void MetaData::Set_StartTime(double ST){
    StartTime = ST;
}
void MetaData::Set_ProcessTime(double PT){
    ProcessTime = PT;
}
double MetaData::Get_StartTime(){
    return StartTime;
}
double MetaData::Get_ProcessTime(){
    return ProcessTime;
}
/**
 * @brief Setter for meta data class
 * used to set the cipher or code as this assignment calls it!
 */
void MetaData::Set_cipher(char inputcipher){
    cipher = inputcipher;
}
/**
 * @brief Setter for meta data class
 * used to set the caption, or the descriptor 
 */
void MetaData::Set_caption(std::string inputcaption){
    caption = inputcaption;
}
/**
 * @brief Setter for meta data class
 * used to set the cycle or the period 
 */
void MetaData::Set_period(int inputperiod){
    period = inputperiod;
}
/**
 * @brief Setter for meta data class
 * used to get the data 
 */
void MetaData::Set_data(std::string inputdata){
    data = inputdata;
}
/**
 * @brief Setter for meta data class
 * used to set the time 
 */
void MetaData::Set_time(int inputtime){
    Ptime = inputtime;
}
//

//getters //////////////////////////////////////
//
/**
 * @brief getter for meta data class
 * used to get the cipher (code) portion
 */
char MetaData::Get_cipher(){
    return cipher;
}
/**
 * @brief getter for meta data class
 * used to get the caption or description
 */
std::string MetaData::Get_caption(){
    return caption;
}
/**
 * @brief getter for meta data class
 * used to get the cycle or period
 */
int MetaData::Get_period(){
    return period;
}
/**
 * @brief getter for meta data class
 * used to get the data portion of meta data file
 */
std::string MetaData::Get_data(){
    return data;
}
/**
 * @brief getter for meta data class
 * used to get the time portion from the metadata data
 */
int MetaData::Get_time(){
    return Ptime;
}
/**
 * @brief getter for meta data class
 * used see if the metadata file is empty
 */
bool MetaData::is_empty(std::ifstream& File){
    return File.peek() == std::ifstream::traits_type::eof();
}
//

/**
 * @brief load the data from metadata
 * @param path: The path of the meta data file 
 * @param MetaDatadata: Vector of type meta data
 * @return VOID: Nothing
 */
void MetaData::LoadMataData(std::string path, std::vector<MetaData> &MetaDatadata) {
    std::ifstream MetaFile;
    MetaFile.open(path);

    if(is_empty(MetaFile)){
            throw_line("metadata File is empty!");
        }
    std::string text;
    std::string temp;
    std::vector<std::string> words;
    bool stop = false;
    char input;
    std::string caption;
    int period;

    while(MetaFile >> text){
        //we have hard [space] drive which fucks up this 
        //algorithm so I'll just append it
        if (text.find("hard") != std::string::npos){
            MetaFile >> temp;
            text.append(" ");
            text.append(temp);
        }
        words.push_back(text);
    }
    MetaFile.close();

    for (std::vector<std::string>::iterator it = words.begin() ; it != words.end(); it++){
        if (*it == "Start"){
            std::advance(it, 4);
        }
        if (*it == "End"){
            break;
        }
        if (stop){
            throw_line("Something went wrong, can't find end of the file the Meta data file");
        }
        text = *it;
        input = text[0];
        text.erase(0,2);
        caption = text.substr(0, text.find('}'));
        text.erase(0, text.find('}')+1);
        temp = text.substr(0, text.find(';')); 

        if (temp.find('.') != std::string::npos){
            stop = true;
            text.erase(text.find('.'), 1);
        }
        period = std::stoi(temp);

        text = *it;
        text.erase(std::remove(text.begin(), text.end(), ';'), text.end());
        
        
        MetaData TEMP(input, caption, period, text);
        MetaDatadata.push_back(TEMP);
    }    
    /*
    int numproc = 0;
    for (auto it= MetaDatadata.begin(); it!= MetaDatadata.end(); ++it){
        std::cout << it->Get_cipher() << " " << it->Get_caption() << std::endl;
        if(it->Get_cipher() == 'A' and it->Get_caption() == "begin"){
            ++numproc;
            std::cout << "Process " << numproc << std::endl;
        }
    }
    */
}