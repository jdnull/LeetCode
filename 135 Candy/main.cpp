#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candy;
        candy.resize(ratings.size(), 1);
        
        for (int i = 1; i < candy.size(); i++) {
            if (ratings[i] > ratings[i-1]) {
                candy[i] = candy[i-1]+1;
            }
        }
        
        for (int i = candy.size()-2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1] && candy[i] <= candy[i+1]) {
                candy[i] = candy[i+1] + 1;
            }
        }
        
        int ret = 0;
        for (int i = 0; i < candy.size(); i++) {
            ret += candy[i];
        }
        return ret;
    }
};

int main() {
    return 0;
}
