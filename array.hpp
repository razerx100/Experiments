#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__
#include<initializer_list>
#include"myExceptions.hpp"
namespace Chronos{
    template<typename T>
    class ArrayIterator{
        public:
        using ValueType = typename T::ValueType;
        using PointerType = ValueType*;
        using ReferenceType = ValueType&;
        private:
        PointerType m_ptr;
        public:
        ArrayIterator(PointerType ptr) : m_ptr(ptr) {}
        ArrayIterator& operator++(){
            m_ptr++;
            return *this;
        }
        ArrayIterator operator++(int){
            ArrayIterator it = *this;
            ++(*this);
            return it;
        }
        ArrayIterator& operator--(){
            m_ptr--;
            return *this;
        }
        ArrayIterator operator--(int){
            ArrayIterator it = *this;
            --(*this);
            return it;
        }
        ReferenceType operator[](int index){
            return *(m_ptr + index);
        }
        PointerType operator->(){
            return m_ptr;
        }
        ReferenceType operator*(){
            return *m_ptr;
        }
        bool operator==(const ArrayIterator& other) const {
            return m_ptr == other.m_ptr;
        }
        bool operator!=(const ArrayIterator& other) const {
            return m_ptr != other.m_ptr;
        }
    };
    template<class Q, int Size>
    class Array{
        public:
        using ValueType = Q;
        using Iterator = ArrayIterator<Array<Q, Size>>;
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