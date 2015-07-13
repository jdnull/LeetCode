#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // not my code
    /*
         1, main idea is using hash map to check previous and next element in the sequence
         2, hash map holds length of consecutive sequence for start of sequence and end of sequence
         3, we updating that values when joining intervals
         4, longest sequence is calculated during joining intervals
     */
    int longestConsecutive(vector<int> &num) {
        if ( num.size() < 2 ) return num.size();
        unordered_map<int,int> m;
        int longest = 1;
        for ( int i: num ){
            if ( m.find(i) != m.end() ) continue;
            m[i] = 1;
            if ( m.find(i-1) != m.end() ){
                int len = m[i] + m[i-1];
                m[i] = len; // length of sequence
                m[i-len+1] ++; // update start of range by new length of sequence
                longest = max( longest, len );
            }
            if ( m.find(i+1) != m.end() ){
                int len   = m[i+m[i+1]] + m[i];
                int start = i-m[i]+1;
                int end   = i+m[i+1];
                m[start] = len;
                m[end]   = len;
                longest = max( longest, len );
            }
        }
        return longest;
    }
};

int main() {
    
}