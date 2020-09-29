#ifndef __MY_EXCEPTIONS__
#define __MY_EXCEPTIONS__
#include<stdexcept>
#include"string.hpp"
namespace Kronos{
    class RangeException: public std::exception{
        const char* name;
        public:
        RangeException(const char*name) : name(name) {}
        virtual const char* what() const throw(){
            return (String(name) + " index out of bound, Exception!").get_char_array();
        }
    };
    class InitializerListException: public std::exception{
        const char* name;
        public:
        InitializerListException(const char* name) : name(name) {}
        virtual const char* what() const throw(){
            return (String(name) + " initializer list size mismatch, Exception!").get_char_array();
        }
    };
}
#endif