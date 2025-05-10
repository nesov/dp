//66. Plus One

#include <iostream>
#include <vector>


std::vector<int> plusOne(std::vector<int>& digits) {
    int n = digits.size();
    for (int i = n - 1; i >= 0; --i) {
        if (digits[i] < 9) {
            digits[i] += 1;
            return digits;
        }
        digits[i] = 0;
    }
    digits.insert(digits.begin(), 1);
    return digits;
}


int main() {
    std::vector<int> data {9,9};
    data = plusOne(data);
    for(auto& item : data) std::cout << item << ", ";
	return 0;
}
