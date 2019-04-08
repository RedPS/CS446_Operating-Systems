// Class Header Information /////////////////////////
/**
 * @file CustomException.h
 * @brief Header file for CustomException part of Project1
 * @details This is a class for CustomException part of project1, made for error handling
 * @version 1.0
 * @author Pedram Safaei
 * @bug nothing that can catched
 * @note bugs have been catched according the instruction
 */

// Precompiler Directives //////////////////////////////////////////
//
#ifndef CUSTOMEXCEPTION
#define CUSTOMEXCEPTION
//

// Header Files /////////////////////////////////////////////////// 
//
#include <iostream>
#include <deque>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <semaphore.h>
#include <iterator>
#include <algorithm>
#include <stdexcept>
#include <chrono>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>

//

// Class Definitions ////////////////////////////////////////////// 
//
#define throw_line(arg) throw CustomEexception(arg, __FILE__, __LINE__)
//

class CustomEexception : public std::runtime_error {
    private:
        std::string msg;
    public:
        CustomEexception(const std::string &arg, const char *file, int line);
        ~CustomEexception() throw();
        const char* what() const throw();
    
};

// Terminating Precompiler Directives /////////////////////////////// 
//
#endif /* !CUSTOMEXCEPTION */
//