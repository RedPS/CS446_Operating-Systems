#ifndef CUSTOMEXCEPTION
#define CUSTOMEXCEPTION

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