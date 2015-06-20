#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        
        int minPrice = prices[0];
        int profit = prices[0] - prices[1];
        
        for (int i = 2; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i-1]);
            profit = max(profit, prices[i]-minPrice);
        }
        
        if (profit < 0) {
            return 0;
        }
        
        return profit;
    }
};

int main() {
    
    
    return 0;
}
