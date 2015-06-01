#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.resize(m + n);
        int a = m-1, b = n-1;
        for (int i = m+n-1; i >= 0; i--) {
            if (a < 0) {
                nums1[i] = nums2[b];
                b--;
                continue;
            }
            if (b < 0) {
                nums1[i] = nums1[a];
                a--;
                continue;
            }
            if (nums1[a] > nums2[b]) {
                nums1[i] = nums1[a];
                a--;
            } else {
                nums1[i] = nums2[b];
                b--;
            }
        }
    }
};

#define COUNT 3
int main() {
    int num1[COUNT] = {1,1,5};
    vector<int> v1(num1, &num1[COUNT]);
    int num2[COUNT] = {2,4,6};
    vector<int> v2(num2, &num2[COUNT]);
    
    Solution s;
    s.merge(v1, COUNT, v2, COUNT);
    
    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] << ",";
    }
    
    cout << endl;
    
    return 0;
}
