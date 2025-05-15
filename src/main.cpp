//1475. Final Prices With a Special Discount in a Shop

#include <iostream>
#include <assert.h>
#include <vector>
#include <stack>
#include <algorithm>


std::vector<int> finalPrices(std::vector<int>& prices) {
    int size = prices.size();
    std::stack<int> stk;
    for (int i = 0; i < size; ++i) {
        while (!stk.empty() && prices[i] <= prices[stk.top()]) {
            int j = stk.top();
            stk.pop();
            prices[j] -= prices[i];
        }
        stk.push(i);
    }
    return prices;
}


int main() {
    std::vector<int> data {8,4,6,2,3};
    std::vector<int> expected {4,2,4,2,3};

    std::vector<int> result = finalPrices(data);

    for (int i = 0; i < data.size(); i++){
        assert(data[i] == expected[i]);
    }

    std::for_each(result.begin(),result.end(),[](int i){ std::cout <<i <<", ";});

    return 0;
}
