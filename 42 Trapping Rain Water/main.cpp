#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
// this method's time consuming too much
//    int trap(int A[], int n) {
//        int total = 0;
//        bool isFlat = true;
//        for (int i = 0; i < n; i++) {
//            if (A[i] > 0) {
//                isFlat = false;
//                break;
//            }
//        }
//        
//        while (!isFlat) {
//            int temp = 0;
//            bool shouldAddTemp = false;
//            isFlat = true;
//            for (int i = 0; i < n; i++) {
//                if (A[i] == 0 && !shouldAddTemp) {
//                    continue;
//                } else if (A[i] > 0 && !shouldAddTemp) {
//                    shouldAddTemp = true;
//                    A[i]--;
//                } else if (A[i] == 0 && shouldAddTemp) {
//                    temp++;
//                } else if (A[i] > 0 && shouldAddTemp && temp != 0) {
//                    total += temp;
//                    temp = 0;
//                    A[i]--;
//                }
//                
//                if (A[i] > 0) {
//                    isFlat = false;
//                }
//            }
//        }
//        return total;
//    }
    int trap(int A[], int n) {
        int total = 0;
        int black = 0;
        int highest = 0;
        for (int i = 0; i < n; i++) { // find the highest
            black += A[i];
            highest = max(highest, A[i]);
        }
        
        int highestStart = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] < highest) {
                for (int j = i + 1; j < n; j++) {
                    if (A[j] > A[i]) {
                        total += A[i] * (j-i);
                        i = j-1;
                        break;
                    }
                }
            } else {
                highestStart = i;
                break; // front Traversal
            }
        }
        
        int highestEnd = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (A[i] < highest) {
                for (int j = i - 1; j >= 0; j--) {
                    if (A[j] > A[i]) {
                        total += A[i] * (i-j);
                        i = j+1;
                        break;
                    }
                }
            } else {
                highestEnd = i;
                break; // back Traversal
            }
        }
        
        total += highest * (highestEnd-highestStart+1);
        
        return total - black;
    }
};

int main() {
    int a[12] = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution s;
    cout << s.trap(a, 12) << endl;
    return 0;
}
