
/*
    392. Is Subsequence
*/

#include <iostream>


bool isSubsequence(const std::string& s, const std::string& t) {
    int i = 0, j = 0;
    int ssize = s.size();
    int tsize = t.size();

    while (i < ssize && j < tsize) {
        if (s[i] == t[j]) {
            i++;
        }
        j++;
    }
    return i == ssize;
}


int main (){
    std::cout << isSubsequence("abc", "ahbgdc") << std::endl;
    return 0;
}