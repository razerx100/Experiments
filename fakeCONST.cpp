#include<iostream>
int main(){
    const int x = 19;
    int* proof = (int*)&x;
    *proof = 666;
    std::cout << x;
    //Memory changes but value remains???
    return 0;
}