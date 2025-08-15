
/*
    342. Power of Four
*/

#include <iostream>

constexpr bool isPowerOfFour(int32_t n) {
    return n > 0 && (n & (n - 1)) == 0 && (n & 0x55555555) != 0;  
}

int main (){
    std::cout<< isPowerOfFour(16)<<std::endl;
    return 0;
}