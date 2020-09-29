#ifndef __ITERATOR_HPP__
#define __ITERATOR_HPP__
namespace Kronos{
    template<typename T>
    class iterator{
        public:
        using ValueType = typename T::ValueType;
        using PointerType = ValueType*;
        using ReferenceType = ValueType&;
        public:
        iterator(PointerType ptr) : m_ptr(ptr) {}
        iterator& operator++(){
            m_ptr++;
            return *this;
        }
        iterator operator++(int){
            iterator it = *this;
            ++(*this);
            return it;
        }
        iterator& operator--(){
            m_ptr--;
            return *this;
        }
        iterator operator--(int){
            iterator it = *this;
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
        bool operator==(const iterator& other) const {
            return m_ptr == other.m_ptr;
        }
        bool operator!=(const iterator& other) const {
            return m_ptr != other.m_ptr;
        }
        private:
        PointerType m_ptr;
    };
}
#endif