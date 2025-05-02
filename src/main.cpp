//8. String to Integer (atoi)
#include <iostream>
#include <string>
#include <cassert>


int myAtoi (std::string s){
	const char* str = s.c_str(); 
	int result {0};
	int sign {1};

	if (!str) return -1;

	while(*str ==' ') str++;

	if(*str == '-'){
		sign = -1;
		str++;
	} else if (*str == '+'){
		sign = 1;
		str++;
	} else if (*str == '0'){
		str++;
	} 

	while (*str >= '0' && *str <= '9'){
		int dig = *str - '0';
		if (result > (INT_MAX - dig) / 10) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }
		result = result * 10 + dig;
		str++;
	}
	return result * sign;
}

	
int main(){
	assert(42 == myAtoi("42"));
	assert(-42 == myAtoi("-042"));
	assert(1337 == myAtoi("1337c0d3"));
	return 0;
}
