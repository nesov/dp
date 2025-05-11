//1550. Three Consecutive Odds

#include <iostream>

bool threeConsecutiveOdds2(std::vector<int>& arr) {
    std::vector<int>::iterator iter = arr.begin();
    while ((iter+2) != arr.end()){
        if ((*iter % 2 == 1) && (*(iter+1) % 2 == 1) && (*(iter+2) % 2 == 1)){
            return true;
        }
        iter++;
    }
    return false;
}


bool threeConsecutiveOdds1(std::vector<int>& arr){
    for (size_t i = 0; i + 2 < arr.size(); ++i) {
        if (arr[i] % 2 == 1 && arr[i + 1] % 2 == 1 && arr[i + 2] % 2 == 1) {
            return true;
        }
    }
    return false;
}


int main() {
    std::vector<int> arr {2,6,4,1};
    std::vector<int> arr1 {1,2,34,3,4,5,7,23,12};

    bool result = threeConsecutiveOdds1(arr);
    std::cout << std::boolalpha << result << std::endl;
	return 0;
}
