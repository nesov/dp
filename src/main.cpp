//1295. Find Numbers with Even Number of Digits

#include <iostream>
#include <vector>
#include <string>

int findNumbers(std::vector<int>& nums) {
	int count {0};
	for (auto&i : nums) {
		int digits {0};
		int temp = i;
		while (temp > 0) {
			temp/= 10;
			digits++;
		}

		if (digits % 2 == 0){
			count++;
		}
	}
	return count;
}


int main(){
	std::vector<int> nums {12,345,2,6,7896};
	// std::vector<int> nums {555,901,482,1771};

	int res = findNumbers(nums);

	std::cout << res << std::endl;

	return 0;
}
