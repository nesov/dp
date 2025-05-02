// 7. Reverse Integer

#include <iostream>
#include <string>
#include <cassert>

int reverse(int x) {
	if (x == INT32_MIN) return 0;
	int32_t sign{1};
	if (x < 0){
		sign = -1;
		x *= -1;
	}

	int32_t result{0};
	while (x != 0){
		if (result > (INT32_MAX - (x % 10)) / 10) return 0;
		result = result * 10 + (x % 10);
		x /= 10;
	}
	return result * sign;
}

int main(){
	assert(-21 == reverse(-120));
	assert(321 == reverse(123));
	assert(-123 == reverse(-321));
	assert(0 == reverse(1534236469));
	return 0;
}
