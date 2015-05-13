#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n < 1) {
            return "";
        }
        string str = "1";
        for (int i = 1; i != n; i++) {
            string temp = "";
            int count = 1;
            for (int j = 1; j <= str.length(); j++) {
                if (j == str.length()) {
                    temp += toString(count) + str[j-1];
                    break;
                }
                
                if (str[j] == str[j-1]) {
                    count++;
                } else {
                    temp += toString(count) + str[j-1];
                    count = 1;
                }
            }
            str = temp;
        }
        return str;
    }
    
    string toString(int i) {
        stringstream ss;
        ss << i;
        return ss.str();
    }
};

#define COUNT 1
int main() {
    Solution s;
    cout << s.countAndSay(5) << endl;
}
