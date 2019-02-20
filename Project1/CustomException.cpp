// Class Implementation File Information //////////////////////
/**
 * @file CustomException.cpp
 * @brief This file implements functions in CustomException.h
 * @details This Custom Exception file is used to throw a more useful error 
 * @version 1.0
 * @author Pedram Safaei
 * @bug nothing that can catched
 * @note bugs have been catched according the instruction
 */

// Header Files /////////////////////////////////////////////////// 
//
#include "CustomException.h"
//

// Class/Data Structure Member Implementation ////////////////////// 
//
/**
 * @brief parameterized constructor for the exception class 
 * @param string, can be the file message
 * @param file, file where the error occured
 * @param line, it is the line number where the error occured
*/
CustomEexception::CustomEexception(const std::string &arg, const char *file, int line):
        std::runtime_error(arg) {
            std::ostringstream o;
            o << file << ":" << line << ": " << arg;
            msg = o.str();
        }
/**
 * @brief destructor
 */
 CustomEexception::~CustomEexception() throw() {

 }
 /**
 * @brief what the message is, it will return the error message
 * @return: error message
 */
 const char* CustomEexception::what() const throw() {
            return msg.c_str();
}