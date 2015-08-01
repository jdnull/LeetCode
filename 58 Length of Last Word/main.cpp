#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int end = s.length() - 1;
        while (end >= 0 && s[end] == ' ') {
            end--;
        }
        int start = end;
        while (start >= 0 && s[start] != ' ') {
            start--;
        }
        return end - start;
    }
};

int main() {
    Solution s;
    cout << s.lengthOfLastWord(" asf as  ") << endl;
}