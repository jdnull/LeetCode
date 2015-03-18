#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string::reverse_iterator aIt = a.rbegin();
        string::reverse_iterator bIt = b.rbegin();
        string sum = "";
        bool addOne = false;
        for ( ; aIt != a.rend() && bIt != b.rend(); aIt++, bIt++) {
            if (*aIt == '1' && *bIt == '1') {
                if (addOne) {
                    sum = "1" + sum;
                } else {
                    sum = "0" + sum;
                }
                
                addOne = true;
            } else if (*aIt == '1' && *bIt == '0') {
                if (addOne) {
                    sum = "0" + sum;
                } else {
                    sum = "1" + sum;
                }
            } else if (*aIt == '0' && *bIt == '1') {
                if (addOne) {
                    sum = "0" + sum;
                } else {
                    sum = "1" + sum;
                }
            } else if (*aIt == '0' && *bIt == '0') {
                if (addOne) {
                    sum = "1" + sum;
                    addOne = false;
                } else {
                    sum = "0" + sum;
                }
            }
        }
        
        while (aIt != a.rend()) {
            if (*aIt == '1') {
                if (addOne) {
                    sum = "0" + sum;
                } else {
                    sum = "1" + sum;
                }
            } else if (*aIt == '0') {
                if (addOne) {
                    sum = "1" + sum;
                    addOne = false;
                } else {
                    sum = "0" + sum;
                }
            }
            aIt++;
        }
        
        while (bIt != b.rend()) {
            if (*bIt == '1') {
                if (addOne) {
                    sum = "0" + sum;
                } else {
                    sum = "1" + sum;
                }
            } else if (*bIt == '0') {
                if (addOne) {
                    sum = "1" + sum;
                    addOne = false;
                } else {
                    sum = "0" + sum;
                }
            }
            bIt++;
        }
        
        if (addOne) {
            sum = "1" + sum;
        }
        
        return sum;
    }
};

int main() {
    Solution s;
    
    cout << s.addBinary("11", "1") << endl;
    
    return 0;
}
