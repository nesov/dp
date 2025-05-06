// 1920. Build Array from Permutation

#include <iostream>


std::vector<int> buildArray(std::vector<int>& nums) {
	std::vector<int> res;
	res.reserve(nums.size());
	for (int i = 0; i < nums.size(); i++) res.push_back(nums[nums[i]]);
	return res;
}


int main(){

	// std::vector<int> nums {0,2,1,5,3,4}; // 0, 1, 2, 4, 5, 3,
	std::vector<int> nums {5,0,1,2,3,4}; //4,5,0,1,2,3
	std::vector<int> result = buildArray(nums);

	for(int& i: result){
		std::cout << i <<", ";
	}
	
	return 0;
}
