//58. Length of Last Word

#include <iostream>
#include <string>

int lengthOfLastWord(std::string s) {
    std::string::reverse_iterator rev = s.rbegin();
    int count {0};
    while (rev != s.rend()){
        if (*rev == ' ' && count == 0) {
            rev++;
        } else if (*rev == ' ' && count > 0){
            break;
        } else {
            count++;
            rev++;
        }
    }
    return count;
}


int main() {
    std::string s {"   fly me   to   the moon  "};
    std::cout << lengthOfLastWord(s)<<std::endl;
    return 0;
}
