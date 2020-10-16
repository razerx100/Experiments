#ifndef __STRING_HPP__
#define __STRING_HPP__
#include<cstring>
#include<ostream>
namespace Chronos{
    class String{
        private:
        char* m_string;
        unsigned int m_size;
        public:
        String() : m_string(0), m_size(0) {}
        String(const char* str){
            m_size = strlen(str);
            m_string = new char[m_size + 1];
            memcpy(m_string, str, m_size);
            m_string[m_size] = '\0';
        }
        String(char* str) : m_size(strlen(str)){
            m_string = str;
            str = 0;
        }
        String(const String& str) : m_size(str.m_size){
            m_string = new char[str.m_size + 1];
            memcpy(m_string, str.m_string, str.m_size);
        }
        String(String&& other) : m_size(other.m_size) {
            m_string = other.m_string;
            other.m_size = 0;
            other.m_string = 0;
        }
        ~String(){
            if(m_string)
                delete[] m_string;
        }
        char operator[](int index){
            return m_string[index];
        }
        String& operator=(String&& other){
            if(this != &other){
                if(m_string)
                    delete[] m_string;
                m_size = other.m_size;
                m_string = other.m_string;

                other.m_size = 0;
                other.m_string = 0;
            }
            return *this;
        }
        String& operator=(String& other){
            if(this != &other){
                m_size = other.m_size;
                m_string = new char[other.m_size + 1];
                memcpy(m_string, other.m_string, other.m_size);
            }
            return *this;
        }
        String operator+(const char* str){
            unsigned int new_size = m_size + strlen(str);
            char* new_str =  new char[new_size + 1];
            memcpy(new_str, m_string, m_size);
            strcat(new_str, str);
            new_str[new_size] = '\0';
            return String(new_str);
        }
        String operator+(const String& other_str){
            unsigned int new_size = m_size + other_str.m_size;
            char* new_str = new char[new_size + 1];
            memcpy(new_str, m_string, m_size);
            strcat(new_str, other_str.m_string);
            new_str[new_size] = '\0';
            return String(new_str);
        }
        char* get_char_array(){
            char* new_memory = new char[m_size + 1];
            memcpy(new_memory, m_string, m_size);
            return new_memory;
        }
        unsigned int length() const {return m_size;}
        friend std::ostream& operator<<(std::ostream& cout, const String& str);
    };
    std::ostream& operator<<(std::ostream& cout, const String& str){
        cout << str.m_string;
        return cout;
    }
}
#endif