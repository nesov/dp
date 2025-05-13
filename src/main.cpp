//3335. Total Characters in String After Transformations I

#include <iostream>
#include <assert.h>

static constexpr int mod = 1000000007;

int lengthAfterTransformations1(std::string s, int t) {
    int count{0};
    int size = s.size();
    std::string result{""};
    std::string temp{""};

    for (int i = t; i > 0; i--){
        result.clear();
        for (int j = 0; j < size; j++) {
            if (s[j]++ == 'z'){
                result += "ab";
            } else {
                result += s[j];
            }
        }
        temp = result;
    }
    count = result.size();
    return count;
}


int lengthAfterTransformation2(std::string s, int t) {
    std::vector<int> cnt(26);
    for (char ch : s) {
        ++cnt[ch - 'a'];
    }
    for (int round = 0; round < t; ++round) {
        std::vector<int> nxt(26);
        nxt[0] = cnt[25];
        nxt[1] = (cnt[25] + cnt[0]) % mod;
        for (int i = 2; i < 26; ++i) {
            nxt[i] = cnt[i - 1];
        }
        cnt = std::move(nxt);
    }

    int ans {0};
    for (int i = 0; i < 26; ++i) {
        ans = (ans + cnt[i]) % mod;
    }
    return ans;
}


int main() {
    std::string s = "v"; 
    int t = 7;  

    int result = lengthAfterTransformation2(s,t);
    std::cout <<"The result is : "<< result <<std::endl;
    assert (result == 2);
    return 0;
}
