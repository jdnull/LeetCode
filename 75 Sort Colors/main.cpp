#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // not my code, sweep all 0s to the left and all 2s to the right, then all 1s are left in the middle.
//    void sortColors(int A[], int n) {
//        int second=n-1, zero=0;
//        for (int i=0; i<=second; i++) {
//            while (A[i]==2 && i<second) swap(A[i], A[second--]);
//            while (A[i]==0 && i>zero) swap(A[i], A[zero++]);
//        }
//    }
    
    void sortColors(vector<int>& nums) {
        vector<int> count(3,0);
        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
        }
        
        int t = 0;
        for (int i = 0; i < count.size(); i++) {
            for (int j = 0; j < count[i]; j++) {
                nums[t] = i;
                t++;
            }
        }
    }
};

int main() {
    
    return 0;
}

