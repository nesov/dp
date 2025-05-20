#include <iostream>
#include <bitset>
#include <iomanip>


void print (uint32_t res) {
    std::cout <<" : "<< std::bitset<32>(res) << std::endl;
}

int main(){

    uint32_t a = 0xAABBCCDD;
    uint32_t expected = 0xAAEECCDD;
    uint8_t b = 0xEE;

    a = (a & 0xFF00FFFF) | (b << 16);
    print(expected);
    print(a);
    return 0;
}