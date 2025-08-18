
/*
    3. Longest Substring Without Repeating Characters
*/

#include <iostream>
#include <string>
#include <unordered_set>

int lengthOfLongestSubstring(const std::string& str) {
    std::unordered_set<char> seen;
    int left = 0, right = 0, maxLen = 0;
    int strSize = static_cast<int>(str.size());

    while (right < strSize) {
        char c = str[right];
        if (!seen.count(c)) {
            seen.insert(c);
            maxLen = std::max(maxLen, right - left + 1);
            right++;
        } else {
            seen.erase(str[left]);
            left++;
        }
    }
    return maxLen;
}


int main (){
    std::cout << lengthOfLongestSubstring("au") << std::endl;
    return 0;
}