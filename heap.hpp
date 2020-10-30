#ifndef __HEAP_HPP__
#define __HEAP_HPP__
#include<initializer_list>
namespace Chronos{
    template<typename T, int size>
    class Heap{
        protected:
        T m_ptr[size];
        int free_position;
        virtual void fix_priority_upward(int position) = 0;
        virtual void fix_priority_downward(int position) = 0;
        void swap(T &a, T &b){
            T temp = a;
            a = b;
            b = temp;
        }
        Heap() : free_position(0) {}
        public:
        int Size() { return size; }
        void Insert(T value){
            if(free_position < size){
                m_ptr[free_position] = value;
                fix_priority_upward(free_position++);
            }
        }
        inline T View_root(){ return m_ptr[0]; }
        void Delete_root(){
            if(free_position){
                swap(m_ptr[0], m_ptr[--free_position]);
                fix_priority_downward(0);
            }
        }
    };
    template<typename T, int size>
    class MaxHeap : public Heap<T, size> {
        private:
        // using Heap<T, size>::m_ptr;
        void fix_priority_upward(int position){
            if(position){
                int parent = position / 2;
                if(this->m_ptr[position] > this->m_ptr[parent]){
                    this->swap(this->m_ptr[position], this->m_ptr[parent]);
                    fix_priority_upward(parent);
                }
            }
        }
        void fix_priority_downward(int position){
            int child = position * 2;
            if(child + 1 < this->free_position){
                if(child + 2 < this->free_position){
                    if(this->m_ptr[child + 1] > this->m_ptr[child + 2]){
                        if(this->m_ptr[position] < this->m_ptr[child + 1]){
                            this->swap(this->m_ptr[position], this->m_ptr[child + 1]);
                            fix_priority_downward(child + 1);
                        }
                    }
                    else{
                        if(this->m_ptr[position] < this->m_ptr[child + 2]){
                            this->swap(this->m_ptr[position], this->m_ptr[child + 2]);
                            fix_priority_downward(child + 2);
                        }
                    }
                }
                else{
                    if(this->m_ptr[position] < this->m_ptr[child + 1]){
                        this->swap(this->m_ptr[position], this->m_ptr[child + 1]);
                        fix_priority_downward(child + 1);
                    }
                }
            }
        }
        public:
        MaxHeap() {}
        MaxHeap(std::initializer_list<T> list) {
            for(T i : list)
                this->Insert(i);
        }
        static MaxHeap Heapify(T* data){
            MaxHeap<T, size> var;
            for(int i = 0; i < size; i++)
                var.m_ptr[i] = data[i];
            var.free_position = size;
            for(int i = size; i >= 0; i-=2){
                int position = (i - 1) / 2;
                var.fix_priority_downward(position);
            }
            return var;
        }
        template<typename E, int length>
        friend void Heapsort(E* data);
    };
    template<typename T, int length>
    void Heapsort(T* data){
        MaxHeap<T, length> var = MaxHeap<T, length>::Heapify(data);
        for(int i = 0; i < length; i++)
            var.Delete_root();
        for(int i = 0; i < length; i++)
            data[i] = var.m_ptr[i];
    }
    template<typename T, int size>
    class MinHeap : public Heap<T, size> {
        private:
        void fix_priority_upward(int position){
            if(position){
                int parent = position / 2;
                if(this->m_ptr[position] < this->m_ptr[parent]){
                    this->swap(this->m_ptr[position], this->m_ptr[parent]);
                    fix_priority_upward(parent);
                }
            }
        }
        void fix_priority_downward(int position){
            int child = position * 2;
            if(child + 1 < this->free_position){
                if(child + 2 < this->free_position){
                    if(this->m_ptr[child + 1] < this->m_ptr[child + 2]){
                        if(this->m_ptr[position] > this->m_ptr[child + 1]){
                            this->swap(this->m_ptr[position], this->m_ptr[child + 1]);
                            fix_priority_downward(child + 1);
                        }
                    }
                    else{
                        if(this->m_ptr[position] > this->m_ptr[child + 2]){
                            this->swap(this->m_ptr[position], this->m_ptr[child + 2]);
                            fix_priority_downward(child + 2);
                        }
                    }
                }
                else{
                    if(this->m_ptr[position] > this->m_ptr[child + 1]){
                        this->swap(this->m_ptr[position], this->m_ptr[child + 1]);
                        fix_priority_downward(child + 1);
                    }
                }
            }
        }
        public:
        MinHeap() {}
        MinHeap(std::initializer_list<T> list) {
            for(T i : list)
                this->Insert(i);
        }
        static MinHeap Heapify(T* data){
            MinHeap<T, size> var;
            for(int i = 0; i < size; i++)
                var.m_ptr[i] = data[i];
            var.free_position = size;
            for(int i = size; i >= 0; i-=2){
                int position = (i - 1) / 2;
                var.fix_priority_downward(position);
            }
            return var;
        }
    };
}
#endif