#include<iostream>

float operator "" _Celsius(long double value){
    return value;
}
float operator "" _Fahrenheit(long double value){
    return value * 1.8f + 32;
}

int main(){
    std::cout << 1.0_Fahrenheit;
    return 0;
}