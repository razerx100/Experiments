#ifndef __HEAP_HPP__
#define __HEAP_HPP__
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
        public:
        Heap() : free_position(0) {}
        int Size() { return size; }
        void Insert(T value){
            if(free_position < size - 1){
                m_ptr[free_position] = value;
                fix_priority_upward(free_position++);
            }
        }
        inline T View_root(){ return m_ptr[0]; }
        void Delete_root(){
            if(free_position){
                m_ptr[0] = m_ptr[free_position - 1];
                m_ptr[--free_position] = 0;
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
    };
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
    };
}
#endif