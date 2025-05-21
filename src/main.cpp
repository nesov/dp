#include <iostream>
#include <iomanip>
#include <assert.h>



inline void print (uint32_t res) {
    std::cout <<" : "<< std::bitset<32>(res) << std::endl;
}

void taskOne(){
    int32_t a = 0xAABBCCDD;
    constexpr uint32_t expected = 0xAAEECCDD;
    uint8_t b = 0xEE;
    a = (a & 0xFF00FFFF) | (b << 16);
    assert(a == expected);
} 

inline uint8_t extractByte(uint32_t value, uint8_t index){
    return (value >> (index * 8)) & 0xFF;
}

inline uint32_t setByte(uint32_t value, uint8_t byte, uint8_t index){
    uint32_t mask = ~(0xFF << (index * 8));
    return (value & mask) | (byte << (index * 8));
}

int main(){
    constexpr uint32_t a = 0xAABBCCDD;
    constexpr uint32_t expected = 0xAAEECCDD;
    uint32_t result = setByte(a, 0xEE, 2);
    assert(result  == expected);    
    return 0;
}