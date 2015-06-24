#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        int total = 0;
        int ret = 0;
        for (int i = 0; i < gas.size(); i++) {
            sum += gas[i] - cost[i];
            if (sum < 0) {
                ret = i+1;
                sum = 0;
            }
            total += gas[i] - cost[i];
        }
        
        return total < 0 ? -1 : ret;
    }
};

int main() {
    return 0;
}
