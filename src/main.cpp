
/*
    231. Power of Two
*/

#include <iostream>


bool isPowerOfTwo(int n) {
    if (n <= 0) return false;
    while (n > 1){
        if (n % 2 != 0) return false;
        else n >>=1;
    }
    return true;
}


int main (){
    std::cout << isPowerOfTwo(16) << std::endl;
    return 0;
}
