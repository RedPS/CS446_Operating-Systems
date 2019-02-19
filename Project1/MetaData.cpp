#include "MetaData.h"

MetaData::MetaData(){

}
MetaData::MetaData(const MetaData&copy){
    *this = copy;
}
MetaData::MetaData(char inputcipher, std::string inputcaption, int inputperiod, std::string inputdata){
    cipher = inputcipher;
    caption = inputcaption;
    period = inputperiod;
    data = inputdata;
}

//setters
void MetaData::Set_cipher(char inputcipher){
    cipher = inputcipher;
}
void MetaData::Set_caption(std::string inputcaption){
    caption = inputcaption;
}
void MetaData::Set_period(int inputperiod){
    period = inputperiod;
}
void MetaData::Set_data(std::string inputdata){
    data = inputdata;
}
void MetaData::Set_time(int inputtime){
    Ptime = inputtime;
}

//getters
char MetaData::Get_cipher(){
    return cipher;
}
std::string MetaData::Get_caption(){
    return caption;
}
int MetaData::Get_period(){
    return period;
}
std::string MetaData::Get_data(){
    return data;
}
int MetaData::Get_time(){
    return Ptime;
}

void MetaData::LoadMataData(std::string path, std::vector<MetaData> &MetaDatadata) {
    std::ifstream MetaFile;
    MetaFile.open(path);

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
            throw_line("Something went wrong in the Meta data file");
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

       //std::cout << temp << std::endl;
        period = std::stoi(temp);

        text = *it;
        text.erase(std::remove(text.begin(), text.end(), ';'), text.end());

        MetaData TEMP(input, caption, period, text);
        MetaDatadata.push_back(TEMP);
    }    
}