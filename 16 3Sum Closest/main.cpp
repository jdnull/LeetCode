#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        
        std::sort(num.begin(), num.end());
        
        int res = num[0] + num[1] + num[num.size()-1];
        
        for (int i = 0; i < num.size(); i++) {
            
            int tempTarget = target - num[i];
            int front = i + 1;
            int back = num.size() - 1;
            
            while (front < back) {
                
                int sum = num[front] + num[back];
                
                if (sum < tempTarget) {
                    front++;
                    
                    if (abs(sum + num[i] - target) < abs(res - target)) { // overflow when target is negetive, if res is set to INFINITY initually
                        res = sum + num[i];
                    }
                } else if (sum > tempTarget) {
                    back--;
                    if (abs(sum + num[i] - target) < abs(res - target)) {
                        res = sum + num[i];
                    }
                } else {
                    return target;
                }
            }
        }
        
        return res;
    }
};

#define COUNT 5

int main() {
    int a[COUNT] = {-3, -2, -5, 3, -4};
    vector<int> num(a, &a[COUNT]);
    Solution s;
    cout << s.threeSumClosest(num, -1) << endl;
    return 0;
}
