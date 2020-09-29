#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__
#include<initializer_list>
#include"Iterator.hpp"
#include"myExceptions.hpp"
namespace Kronos{
    template<class Q, int Size>
    class Array{
        public:
        using ValueType = Q;
        using Iterator = iterator<Array<Q, Size>>;
        Array() {};
        Array(Q default_value){
            for(Q& i : m_data)
                i = default_value;
        };
        Array(std::initializer_list<Q> init){
            if(init.size() != Size)
                throw InitializerListException("Array");
            else{
                int pos = 0;
                for(Q i : init){
                    m_data[pos] = i;
                    pos++;
                }
            }
        }
        int size(){return Size;}
        Q& operator[](int index){
            if(index >= Size)
                throw RangeException("Array");
            else
                return m_data[index];
        }
        Iterator begin(){
            return Iterator(m_data);
        }
        Iterator end(){
            return Iterator(m_data + Size);
        }
        private:
        Q m_data[Size];
    };
}
#endif