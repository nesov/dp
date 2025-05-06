//4. Median of Two Sorted Arrays

#include <iostream>

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
	std::vector<int> dst;
	dst.reserve(nums1.size() + nums2.size());
	std::merge(nums1.begin(),nums1.end(), nums2.begin(), nums2.end(), std::back_inserter(dst));

	int size = dst.size();
	if (size % 2 == 0){
        return (dst[size/2] + dst[size/2 - 1]) / 2.00;
	}
	return dst[size / 2];    
}


int main(){

	// std::vector<int> nums1 {1,3}, nums2{2};
	std::vector<int> nums1 {1, 2}, nums2 {3, 4};

	double result = findMedianSortedArrays(nums1, nums2);
	std::cout << result <<std::endl;
	
	return 0;
}


/*
double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
        return findMedianSortedArrays(nums2, nums1); // гарантируем, что nums1 короче
    }

    int x = nums1.size();
    int y = nums2.size();
    int low = 0, high = x;

    while (low <= high) {
        int partitionX = (low + high) / 2;
        int partitionY = (x + y + 1) / 2 - partitionX;

        int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];

        int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];

        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            if ((x + y) % 2 == 0) {
                return (std::max(maxLeftX, maxLeftY) + std::min(minRightX, minRightY)) / 2.0;
            } else {
                return std::max(maxLeftX, maxLeftY);
            }
        } else if (maxLeftX > minRightY) {
            high = partitionX - 1;
        } else {
            low = partitionX + 1;
        }
    }

    throw std::invalid_argument("Input arrays are not sorted or invalid input");
}
*/