//1. Two Sum

#include <iostream>
#include <vector>

	std::vector<int> twoSum(std::vector<int>& nums, int target) {
		std::vector<int> res;
		size_t size = nums.size();
		bool isDone {false};

		for (int i = 0; i < size; i++){
			if (!isDone){
				for (int j = i + 1; j < size; j++){	
					if (nums[i] + nums[j] == target){
						res.push_back(i);
						res.push_back(j);
						isDone = true;
						break;
					}	
				}	
			} else {
				break;
			}
		}
		return res;
    }


int main()
{
	// std::vector<int> vec {2,7,11,15};
	// std::vector<int> vec {3,2,4};
	// std::vector<int> vec {3,3};
	std::vector<int> vec {2,5,5,1};

	std::vector<int> res =  twoSum(vec,10);


	for (auto i : res){
		std::cout << i << ", "; 
	}
	std::cout<<std::endl;
	return 0;
}
