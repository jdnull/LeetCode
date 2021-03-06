#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v;
        v.resize(rowIndex+1, 1);
        
        for (int i = 1; i < rowIndex; i++) {
            for (int j = i; j > 0; j--) {
                v[j] = v[j] + v[j-1];
            }
        }
        
        return v;
    }
};

int main() {
    Solution s;
    vector<int> v = s.getRow(4);
    
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ",";
    }
    
    cout << endl;
    
    return 0;
}
