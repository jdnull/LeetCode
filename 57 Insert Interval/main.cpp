#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Definition for an interval.
struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    // this is not my code
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        int m = intervals.size();
        int idx1=0, idx2=0;
        for(int i=0; i<m; i++){
            if(newInterval.end<intervals[i].start){
                idx2 = i;
                break;
            }else if(newInterval.start>intervals[i].end){
                idx1 = i+1;
            }else{
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
                idx2 = i+1;
            }
        }
        if(idx1<idx2)
            intervals.erase(intervals.begin()+idx1, intervals.begin()+idx2);
        intervals.insert(intervals.begin()+idx1, newInterval);
        return intervals;
    }
};

int main() {
    vector<Interval> intervals;
    
    // [1,5]
    intervals.push_back(Interval(1, 5));
    Solution s;
    vector<Interval> res = s.insert(intervals, Interval(2, 3));
    
    // [1,3],[6,9]
//    intervals.push_back(Interval(1, 2));
//    intervals.push_back(Interval(6, 9));
//    Solution s;
//    vector<Interval> res = s.insert(intervals, Interval(2, 5));
    
    // [1,2],[3,5],[6,7],[8,10],[12,16]
//    intervals.push_back(Interval(1, 2));
//    intervals.push_back(Interval(3, 5));
//    intervals.push_back(Interval(6, 7));
//    intervals.push_back(Interval(8, 10));
//    intervals.push_back(Interval(12, 16));
//    Solution s;
//    vector<Interval> res = s.insert(intervals, Interval(4, 9));
    
    for (vector<Interval>::iterator it = res.begin(); it != res.end(); it++) {
        cout << "[" << it->start << "," << it->end << "]" << endl;
    }
    return 0;
}
