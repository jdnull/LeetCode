#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.size() == 0 || triangle[0].size() == 0) {
            return 0;
        }
        
        vector<int> v;
        v.resize(triangle[triangle.size()-1].size(), 0);
        v[0] = triangle[0][0];
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = triangle[i].size()-1; j >= 0; j--) {
                if (j-1 < 0) {
                    v[j] += triangle[i][j];
                } else if (j == triangle[i].size()-1) {
                    v[j] = v[j-1] + triangle[i][j];
                } else {
                    v[j] = triangle[i][j] + min(v[j], v[j-1]);
                }
            }
        }
        
        int ret = v[0];
        for (int i = 0; i < v.size(); i++) {
            ret = min(ret, v[i]);
        }
        
        
        return ret;
    }
};

int main() {
    int a[] = {-1};
    int b[] = {2,3};
    int c[] = {1,-1,-1};
    
    vector<int> v1(a, &a[1]);
    vector<int> v2(b, &b[2]);
    vector<int> v3(c, &c[3]);
    
    vector<vector<int>> vv;
    vv.push_back(v1);
    vv.push_back(v2);
    vv.push_back(v3);
    
    Solution s;
    cout << s.minimumTotal(vv) << endl;
    
    return 0;
}
