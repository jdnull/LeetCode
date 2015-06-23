#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    // not my code, permutation generation
//    bool nextPermutation(vector<int> &num) {
//        int len=num.size()-1;
//        for(int pos=len-1;pos>=0;--pos){
//            if(num[pos]<num[pos+1]){
//                int smallNum=num[pos];
//                int lastPosBiggerThanSmallNum=
//                len-(find_if(num.rbegin(),
//                             num.rend(),(bind2nd(greater<int>(),smallNum)))-
//                     num.rbegin());
//                swap(num[pos],num[lastPosBiggerThanSmallNum]);
//                sort(num.begin()+pos+1,num.end());
//                return true;
//            }
//        }
//        return false;
//    }
//    vector<vector<int> > permuteUnique(vector<int> &num){
//        vector<vector<int> > res;
//        if(num.empty())
//            return res;
//        sort(num.begin(),num.end());
//        res.push_back(num);
//        while(nextPermutation(num)){
//            res.push_back(num);
//        }
//        return res;
//    }
    
    // not my code, faster
    void recursion(vector<int> num, int i, vector<vector<int> > &res) {
        if (i == num.size()-1) {
            res.push_back(num);
            return;
        }
        for (int k = i; k < num.size(); k++) {
            if (i != k && num[i] == num[k]) continue;
            swap(num[i], num[k]);
            recursion(num, i+1, res);
        }
    }
    
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> >res;
        recursion(num, 0, res);
        return res;
    }
    
    // my code, too slow
//    vector<vector<int>> vv;
//    
//    vector<vector<int>> permuteUnique(vector<int>& nums) {
//        sort(nums.begin(), nums.end());
//        vector<int> v;
//        vector<bool> isVisited(nums.size(), false);
//        dfs(nums, v, isVisited);
//        return vv;
//    }
//    
//    void dfs(vector<int> &nums, vector<int> v, vector<bool> isVisited) {
//        if (v.size() == nums.size()) {
//            vv.push_back(v);
//            return;
//        }
//        
//        for (int i = 0; i < nums.size(); i++) {
//            if (!isVisited[i]) {
//                isVisited[i] = true;
//                v.push_back(nums[i]);
//                dfs(nums, v, isVisited);
//                v.pop_back();
//                isVisited[i] = false;
//                while(i < nums.size()-1 && nums[i] == nums[i+1]) {
//                    i++;
//                }
//            }
//        }
//    }
};

int main() {
    return 0;
}
