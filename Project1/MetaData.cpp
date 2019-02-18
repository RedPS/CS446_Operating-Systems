#include "MetaData.h"

MetaData::MetaData(){

}
MetaData::MetaData(const MetaData&copy){
    *this = copy;
    return *this;
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