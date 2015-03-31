#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int> &num) {
        if (num.size() == 0) {
            return 0;
        }
        if (num.size() == 1) {
            return num[0];
        }
        
        vector<int> s(num.size(), 0);
        s[0] = num[0];
        s[1] = num[0] > num[1] ? num[0] : num[1];
        for (int i = 2; i < num.size(); i++) {
            bool isFound = false;
            int max = 0;
            for (int j = 0; j < i-1; j++) {
                int temp = s[j]+num[i];
                if (s[i-1] < temp && max < temp) {
                    max = temp;
                    isFound = true;
                }
            }
            if (isFound) {
                s[i] = max;
            } else {
                s[i] = s[i-1];
            }
        }
        
        return s[num.size()-1];
    }
};

#define COUNT 3
int main() {
    int a[COUNT] = {1,3,1};
    vector<int> num(a, &a[COUNT]);
    
    Solution s;
    cout << s.rob(num) << endl;
    
    return 0;
}
