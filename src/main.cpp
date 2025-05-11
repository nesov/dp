//509. Fibonacci Number

#include <iostream>


int fib(int n) {
    if (n == 1 ) return 1;
    if (n == 0 ) return 0;  
    return fib(n - 1) + fib(n - 2);
}


int main() {
    std::cout << fib(4);
	return 0;
}
