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
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        if(E>=C||G<=A||B>=H||F>=D)
            return (C-A)*(D-B)+(G-E)*(H-F);
        else
            return (C-A)*(D-B)+(G-E)*(H-F)-abs(max(A,E)-min(C,G))*abs(max(B,F)-min(D,H));
    }
};

int main() {
    Solution s;
}