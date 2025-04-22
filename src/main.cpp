//26. Remove Duplicates from Sorted Arra

#include <iostream>
#include <vector>
#include <algorithm>

int removeDuplicates(std::vector<int>& nums) {
	auto it = std::unique(nums.begin(), nums.end());
    nums.erase(it, nums.end()); 
	return nums.size();
}


int main(){
	// std::vector<int> nums{1,1,2};
	std::vector<int> nums{0,0,1,1,1,2,2,3,3,4};
	removeDuplicates(nums);
	return 0;
}
