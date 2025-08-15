
/*
    326. Power of Three
*/

#include <iostream>

constexpr int32_t maxp {1162261467};

constexpr bool isPowerOfThree(int32_t n) {
    return n > 0 && maxp % n == 0;    
}

int main (){
    std::cout<< isPowerOfThree(28)<<std::endl;
    return 0;
}