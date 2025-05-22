// Find non double element in arr 

#include <iostream>
#include <vector>
#include <assert.h>

int findUnique(const std::vector<int>& nums) {
    int result = 0;
    for (int num : nums) result ^= num;
    return result;
}

int main (){
    std::vector<int> data = {5, 3, 2, 3, 5, -1, 2, 9, 9};
    int actual = findUnique(data) ;
    assert (actual == -1);

    std::cout << actual;
	return 0; 
}
