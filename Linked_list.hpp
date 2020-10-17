#ifndef __LINKED_LIST_HPP__
#define __LINKED_LIST_HPP__
#include<ostream>
namespace Chronos{
    template<typename T>
    class Node{
        public:
        T value;
        Node<T> *next, *previous;
        Node(T value) : value(value), next(0), previous(0) {}
        friend std::ostream& operator<<(std::ostream& out, const Node<T>& item){
            out << item.value;
            return out;
        }
    };
    template<typename T>
    class ListIterator{
        public:
        using ValueType = typename T::Valuetype;
        private:
        Node<ValueType>* m_ptr;
        public:
        ListIterator(Node<ValueType>* ptr) : m_ptr(ptr) {}
        Node<ValueType>* operator->(){
            return m_ptr;
        }
        Node<ValueType>& operator*(){
            return *m_ptr;
        }
        ListIterator& operator++(){
            m_ptr = m_ptr->next;
            return *this;
        }
        ListIterator& operator--(){
            m_ptr = m_ptr->previous;
            return *this;
        }
        bool operator==(const ListIterator& other) const {
            return m_ptr == other.m_ptr;
        }
        bool operator!=(const ListIterator& other) const {
            return m_ptr != other.m_ptr;
        }
    };
    template<typename T>
    class List{
        private:
        Node<T> *head, *tail;
        public:
        using Valuetype = T;
        using Iterator = ListIterator<List<T>>;
        List() : head(0), tail(0) {}
        ~List(){
            Node<T>* temp = 0;
            for(Node<T>* i = head; i != 0; i=i->next){
                delete temp;
                temp = i;
            }
            delete temp;
        }
        void push_back(T value){
            Node<T> *new_item = new Node<T>(value);
            if(!head){
                head = tail = new_item;
            }
            else{
                tail->next = new_item;
                new_item->previous = tail;
                tail = new_item;
            }
        }
        void push_front(T value){
            Node<T> *new_item = new Node<T>(value);
            if(!head){
                head = tail = new_item;
            }
            else{
                new_item->next = head;
                head->previous = new_item;
                head = new_item;
            }
        }
        T back(){return tail->value;}
        T front(){return head->value;}
        void pop_back(){
            if(head){
                Node<T> *temp;
                if(head->next){
                    temp = tail;
                    tail = tail->previous;
                }
                else{
                    temp = head;
                    head = tail = 0;
                }
                delete temp;
            }
        }
        void pop_front(){
            if(head){
                Node<T> *temp;
                if(head->next){
                    temp = head;
                    head = head->next;
                }
                else{
                    temp = head;
                    head = tail = 0;
                }
                delete temp;
            }
        }
        void pop(T value){
            for(Node<T>* i = head; i != nullptr; i=i->next){
                if(i->value == value){
                    if(i->previous){
                        if(i->next){
                            i->previous->next = i->next;
                            i->next->previous = i->previous;
                        }
                        else{
                            i->previous->next = 0;
                            tail = i->previous;
                        }
                    }
                    else{
                        if(i->next){
                            i->next->previous = 0;
                            head = i->next;
                        }
                        else
                            head = tail = 0;
                    }
                    delete i;
                }
            }
        }
        Iterator begin(){
            return Iterator(head);
        }
        Iterator end(){
            if(tail)
                return Iterator(tail->next);
            else
                return Iterator(tail);
        }
    };
}
#endif