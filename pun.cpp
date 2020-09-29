#include<iostream>
class struc{
    private:
    int x, y, z;
    float fx, fy, fz;
    public:
    struc(int, float);
};
struc::struc(int x, float y) : x(x), y(x + 1), z(x + 2), fx(y), fy(y + 1.1f), fz(y + 2.2f) {}
int main(){
    struc var(5, 11.99f);
    int* int_array = (int*)&var;
    float* float_array = (float*)&var + 3;
    std::cout << "Integers Floats\n";
    for(int i = 0; i < 3; i++){
        std::cout << int_array[i] << " " << float_array[i] << "\n";
    }
    return 0;
}