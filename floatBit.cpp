#include<iostream>
class Binary {
    union {
        float Floating;
        int Integer;
    };
public:
    Binary() {}
    Binary(int value) : Integer(value) {}
    Binary(float value) : Floating(value) {}
    void ShowBinaryValue() {
        int num = Integer;
        unsigned int ref = 1 << 31;
        std::cout << ((num & ref) ? 1 : 0) << " ";
        ref = (ref >> 1);
        for(int j = 0; j < 31; ref = (ref >> 1), j++){
            if(j == 8)
                std::cout << " ";
            std::cout << ((num & ref) ? 1 : 0);
        }
    }
};
int main(){
    Binary var = 8.0f;
    var.ShowBinaryValue();
    return 0;
}