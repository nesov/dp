//29. Divide Two Integers

#include <iostream>
#include <cassert>
#include <vector>
#include <tuple>


int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;
    if (divisor == 0) return -1;
    if (divisor == 1) return dividend;
    if (dividend == divisor) return 1;
    if (dividend < divisor && dividend >= 0) return 0;

    unsigned long long u_dividend = dividend < 0 ? -(long long)dividend : dividend;
    unsigned long long u_divisor  = divisor  < 0 ? -(long long)divisor  : divisor;
    unsigned long long result {0};
    unsigned long long temp {0};

    for (int i = 31; i >= 0; --i) {
        if (temp + (u_divisor << i) <= u_dividend) {
            temp += u_divisor << i;
            result |= 1ULL << i;
        }
    }
    return (dividend < 0) ^ (divisor < 0) ? -static_cast<int>(result) : static_cast<int>(result);
}

#define TESTS1

int main(){

    using DataSet =  std::vector<std::tuple<int,int,int,const char*> >;

    DataSet data{
        {10,3, 3, "Test1"},
        {7,-3, -2,"Test2"},
        {1, 2, 0, "Test3"},
        {5, 2, 2,"Test4"},
        {-2147483648, -1, 2147483647,"Test5"},
        {-1, 1, -1,"Test6"},
        {-2147483648, 2, -1073741824, "Test7"}
    };

    for (auto&i : data){
        int res = divide(std::get<0>(i),std::get<1>(i));
#ifdef TESTS
        assert((std::get<2>(i) == res));
#endif
        std::cout<<std::get<3>(i)<<": "<< res <<std::endl;  
    }
	return 0;
}
