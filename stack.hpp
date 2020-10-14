#ifndef __STACK_HPP__
#define __STACK_HPP__
#include<ostream>
namespace Kronos{
    template<typename T, int Size>
    class Stack{
        private:
        T m_data[Size];
        int m_head_location;
        public:
        Stack() : m_head_location(-1) {}
        int Length() {return Size;}
        T peek() {
            if(m_head_location >= 0){
                return m_data[m_head_location];
            }
            else{
                T n;
                puts("Stack underflow");
                return n;
            }
        }
        void pop() {
            if(m_head_location < 0){
                puts("Stack underflow.");
            }
            else{
                m_head_location--;
            }
        }
        void push(T value){
            if(m_head_location < Size - 1){
                m_data[++m_head_location] = value;
            }
            else{
                puts("Stack overflow.");
            }
        }
    };
}
#endif