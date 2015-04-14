#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <math.h>

using namespace std;



class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> v;
        
        if (digits.length() < 1) { // need to check if character is not in '2'-'9'
            return v;
        }
        
        map<char, string> table;
        table['2'] = "abc";
        table['3'] = "def";
        table['4'] = "ghi";
        table['5'] = "jkl";
        table['6'] = "mno";
        table['7'] = "pqrs";
        table['8'] = "tuv";
        table['9'] = "wxyz";
        
        queue<char> q;
        q.push('\0'); // for the first time for the queue to pop
        for (string::iterator it = digits.begin(); it != digits.end(); it++) {
            q.push(*it);
        }
        
        string s = "";
        
        recursiveCombine(table, v, q, s);
        
        return v;
    }
    
    void recursiveCombine(map<char, string> &t, vector<string> &v, queue<char> q, string s) {
        q.pop();
        if (q.empty()) {
            v.push_back(s);
            return;
        }
        
        char c = q.front();
        string tStr = t[c];
        for (string::iterator it = tStr.begin(); it != tStr.end(); it++) {
            string tempS = s + (*it);
            recursiveCombine(t, v, q, tempS);
        }
    }
};

#define COUNT 5

int main() {
    Solution s;
    vector<string> res = s.letterCombinations("23");
    
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}
