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
        
        int profit = 0;
        int min, max;
        int isBuy = false;
        
        for (int i = 0; i < prices.size()-1; i++) {
            if (i == 0) {
                if (prices[0] < prices[1]) {
                    min = prices[0];
                    isBuy = true;
                }
            } else {
                if (isBuy) {
                    if (prices[i-1] < prices[i] && prices[i] >= prices[i+1]) {
                        max = prices[i];
                        profit += max - min;
                        isBuy = false;
                    }
                } else {
                    if (prices[i-1] >= prices[i] && prices[i] < prices[i+1]) {
                        min = prices[i];
                        isBuy = true;
                    }
                }
            }
        }
        
        if (isBuy && prices[prices.size()-1] > prices[prices.size()-2]) {
            max = prices[prices.size()-1];
            profit += max - min;
            isBuy = false;
        }
        
        
        return profit;
    }
};

int main() {
    
    
    return 0;
}
