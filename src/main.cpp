//69. Sqrt(x)

#include <iostream>


int mySqrt(int x) {
    if (x == 0) return 0;
    double epsilon = 1e-6;
    double x1 = x / 2.0;
    while (true) {
        double next = 0.5 * (x1 + x / x1);
        if (std::abs(next - x1) < epsilon)
            break;
        x1 = next;
    }
    return x1;
}


int main() {
    std::cout <<  mySqrt(0) <<'\n';
    return 0;
}
