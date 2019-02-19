#ifndef CUSTOMEXCEPTION
#define CUSTOMEXCEPTION

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <iterator>
#include <algorithm>
#include <stdexcept>


#define throw_line(arg) throw CustomEexception(arg, __FILE__, __LINE__)

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

class CustomEexception : public std::runtime_error {
    private:
        std::string msg;
    public:
        CustomEexception(const std::string &arg, const char *file, int line);
        ~CustomEexception() throw();
        const char* what() const throw();
    
};


#endif /* !CUSTOMEXCEPTION */