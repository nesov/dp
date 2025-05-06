//27. Remove Element

#include <iostream>
#include <string>
#include <cassert>

int removeElement(std::vector<int>& nums, int val) {
	nums.erase(std::remove(nums.begin(),nums.end(), val), nums.end());
	return static_cast<int>(nums.size());  
}

int main(){
	std::vector<int> a{3,2,2,3};
	std::vector<int> b{0,1,2,2,3,0,4,2};
	assert(2 == removeElement(a, 3));
	assert(5 == removeElement(b, 2));
	return 0;
}
