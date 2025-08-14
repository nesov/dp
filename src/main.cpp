
/*
    2264. Largest 3-Same-Digit Number in String
*/

#include <iostream>
#include <string>



std::string largestGoodInteger(std::string num) {
    std::string result {""}, cand{""};
    if (num.length() < 3) return result;
    for(int i = 0; i < num.length() - 2; i++){
        if (num[i] == num[i+1] && num[i+1] == num[i+2]){
            cand = num.substr(i, 3);
            if (cand > result) {
                result = cand;
            }
        }
    }
    return result;
}

int main (){
    std::cout<< largestGoodInteger("3200014888")<<std::endl;
    return 0;
}