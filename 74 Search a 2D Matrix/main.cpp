#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // search from most up right number
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        
        int rowNum = matrix.size();
        int columnNum = matrix[0].size();
        int total = rowNum * columnNum;
        int indexOfMostDownLeft = total - columnNum;
        int index = columnNum - 1;
        while (index != indexOfMostDownLeft) {
            int t = matrix[index/columnNum][index%columnNum];
            if (t == target) {
                break;
            } else if (t < target) {
                if (index + columnNum > total) {
                    break;
                }
                index += columnNum;
            } else {
                if (index % columnNum - 1 < 0) {
                    break;
                }
                index--;
            }
        }
        
        if (matrix[index/columnNum][index%columnNum] == target) {
            return true;
        } else {
            return false;
        }
    }
};

#define COUNT 2
int main() {
    int a[COUNT] = {1,1};
    vector<int> v(a, &a[COUNT]);
    vector<vector<int> > vv;
    vv.push_back(v);
//    v[0] = 3;
//    vv.push_back(v);

    Solution s;
    cout << s.searchMatrix(vv, 0) << endl;
    return 0;
}
