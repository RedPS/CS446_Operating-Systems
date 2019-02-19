#include "CustomException.h"

CustomEexception::CustomEexception(const std::string &arg, const char *file, int line):
        std::runtime_error(arg) {
            std::ostringstream o;
            o << file << ":" << line << ": " << arg;
            msg = o.str();
        }

 CustomEexception::~CustomEexception() throw() {

 }
 const char* CustomEexception::what() const throw() {
            return msg.c_str();
}