vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> v;
    vector<int> save;

    //must sort first! then even though there's same element in candidates, 
    //it will not produce duplicate combination
    sort(candidates.begin(), candidates.end());

    dfs(candidates, candidates.size(), 0, 0, target, save, v);

    return v;
}

/*
 dfs to find all combination
 var n: candidates
 var size: candidates' length
 var start: because I sort candidates first, dfs() just need to start permunate from "start".
            don't need to start from every element. Then prevent duplicate combination.
 var now: sum of present numbers
 var target: just target
 var save: to save the combination of candidates
 var v: the final return vector
*/
void dfs(vector<int> n, int size, int start, int now, int target, vector<int> &save, vector<vector<int>> &v){
    if(now == target){
        v.push_back(save);
        return;
    }

    for(int i =  start; i < size; i++){
        if(now + n[i] > target)//above the target value, so the rest(bigger) value are impossible
            return;
        save.push_back(n[i]);
        dfs(n, size, i, now + n[i], target, save, v);
        save.pop_back();
    }
    return;
}