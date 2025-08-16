
/*
    1323. Maximum 69 Number
*/

#include <iostream>

int maximum69Number (int num) {  
   std::string str = std::to_string(num);
    for (char &c : str) {
        if (c == '6') {
            c = '9';
            break;
        }
    }
    return std::stoi(str);
}


int main (){
    std::cout << maximum69Number(9669)<<std::endl;
    return 0;
}