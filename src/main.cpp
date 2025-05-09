//3343. Count Number of Balanced Permutations

#include <iostream>
#include <cassert>
#include <string>
#include <chrono>

constexpr static long long MOD = 1e9 + 7;

class Timer {
 public: 
    Timer(){start = clock.now();}
    ~Timer(){std::cout <<"Time: "<< duration_cast<std::chrono::milliseconds> (clock.now() - start) <<std::endl;}
 private: 
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
    std::chrono::high_resolution_clock clock;
};

int countBalancedPermutations(std::string num) {
    int tot = 0, n = num.size();
    std::vector<int> cnt(10);
    for (char ch : num) {
        int d = ch - '0';
        cnt[d]++;
        tot += d;
    }
    if (tot % 2 != 0) {
        return 0;
    }

    int target = tot / 2;
    int maxOdd = (n + 1) / 2;
    std::vector<std::vector<long long>> comb(maxOdd + 1, std::vector<long long>(maxOdd + 1));
    std::vector<std::vector<long long>> f(target + 1, std::vector<long long>(maxOdd + 1));
    for (int i = 0; i <= maxOdd; i++) {
        comb[i][i] = comb[i][0] = 1;
        for (int j = 1; j < i; j++) {
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
        }
    }
    f[0][0] = 1;
    int psum = 0, totSum = 0;
    for (int i = 0; i <= 9; i++) {
        psum += cnt[i];
        totSum += i * cnt[i];
        for (int oddCnt = std::min(psum, maxOdd); oddCnt >= std::max(0, psum - (n - maxOdd)); oddCnt--) {
            int evenCnt = psum - oddCnt;
            for (int curr = std::min(totSum, target); curr >= std::max(0, totSum - target); curr--) {
                long long res = 0;
                for (int j = std::max(0, cnt[i] - evenCnt); j <= std::min(cnt[i], oddCnt) && i * j <= curr; j++) {
                    long long ways = comb[oddCnt][j] * comb[evenCnt][cnt[i] - j] % MOD;
                    res = (res + ways * f[curr - i * j][oddCnt - j] % MOD) % MOD;
                }
                f[curr][oddCnt] = res % MOD;
            }
        }
    }
    return f[target][maxOdd];
}

#pragma region 
void run() { 
    std::vector<std::pair<std::string, int>> data {
        {"123", 2},
        {"112", 1},
        {"12345",0},
        {"523", 2},
        {"9823935411945", 0}
    };

    for (auto& item : data){
        int res {0};
        std::cout <<"Test data: "<<item.first <<std::endl; 
        std::cout <<"Start running...\n";
        {
            Timer t;
            res = countBalancedPermutations(item.first); 
        }
        std::cout <<"Finished.\n\n";
        assert(item.second == res);
    }

}
#pragma endregion

#define TESTS

int main() {
#ifdef TESTS
    run();
#else
    {
        Timer t;
        std::cout <<  "countBalancedPermutations is : "<< countBalancedPermutations("0593136364172")<<std::endl;
    }
#endif
	return 0;
}
