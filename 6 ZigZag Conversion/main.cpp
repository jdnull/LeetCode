#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        if (s.length() < nRows || nRows <= 1) {
            return s;
        }
        
        string retS = "";
        int i = 0, j = 0;
        while (i < nRows) {
            int idx = 0;
            int firstIdx = i+(2*nRows-2)*idx;
            while (firstIdx < s.length()) {
                retS += s[firstIdx];
                
                if (i != 0 && i != nRows-1) {
                    int otherIdx = (2*nRows-4-2*j) + i + (2*nRows-2)*idx;
                    if (otherIdx < s.length()) {
                        retS += s[otherIdx];
                    }
                }
                
                idx++;
                firstIdx = i+(2*nRows-2)*idx;
            }
            
            if (i != 0 && i != nRows-1) {
                j++;
            }
            
            i++;
        }
        
        return retS;
    }
};

int main() {
    // 3: "PAYPALISHIRING" => "PAHNAPLSIIGYIR"
    // 3: "0123456789" => "0481357926"
    string str = "0123456789";
    Solution s;
    cout << s.convert(str, 1) << endl;
    return 0;
}
