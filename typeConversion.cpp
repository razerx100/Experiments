#include<iostream>
struct XMFLOAT3{
    float x;
    float y;
    float z;
}var1;
void Print(float* struc){
    std::cout << "X = " << *struc << ", Y = " << *(struc + 1) << ", Z = " << *(struc + 2) << "\n";
}
int main(){
    var1.x = 2.5f;
    var1.y = 3.6f;
    var1.z = 1.9f;
    Print((float*)&var1);
    return 0;
}