//2094. Finding 3-Digit Even Numbers

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <assert.h>

std::vector<int> findValidNumbers1(std::vector<int> digits) {
    std::unordered_set<int> uniqueNumbers;
    std::sort(digits.begin(), digits.end());

    do {
        if (digits.size() < 3) break;
        int d1 = digits[0], d2 = digits[1], d3 = digits[2];
        if (d1 == 0) continue;    
        if (d3 % 2 != 0) continue; 
        int num = d1 * 100 + d2 * 10 + d3;
        uniqueNumbers.insert(num);
    } while (std::next_permutation(digits.begin(), digits.end()));
    std::vector<int> result(uniqueNumbers.begin(), uniqueNumbers.end());
    std::sort(result.begin(), result.end());
    return result;
}


std::vector<int> findEvenNumbers2(std::vector<int>& digits) {
    std::unordered_set<int> nums;
    int n = digits.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (i == j || j == k || i == k) {
                    continue;
                }
                int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                if (num >= 100 && num % 2 == 0) {
                    nums.insert(num);
                }
            }
        }
    }
    std::vector<int> res;
    for (const int num : nums) {
        res.push_back(num);
    }
    std::sort(res.begin(), res.end());
    return res;
}


void run(){
    std::vector<int> data {2,1,3,0};
    std::vector<int> expected {102,120,130,132,210,230,302,310,312,320};
    std::vector<int> actual = findEvenNumbers2(data);

    assert(actual.size() == expected.size());
    int size = expected.size();

    for (int i = 0; i < size; i++){
        assert(actual[i] == expected[i]);
    }
    std::cout <<"ok\n"; 
}

#define TEST

int main() {
#ifdef TEST
    run();
#endif
    return 0;
}
