class Solution {
public:
    vector<vector<int>> result ;
    void backtracking(vector<int> candidates, int target, vector<int> subset, int start, int sum){
        int candidates_size = candidates.size() ;
        if (sum == target)
            result.push_back(subset) ;
        if (start>=candidates_size || sum > target){
            return ;
        }
        for (int i = start ; i < candidates_size ; i++){
            if (target - sum >= candidates[i]){
                subset.push_back(candidates[i]) ;
                backtracking(candidates, target, subset, i + 1, sum + candidates[i]) ;
                subset.pop_back() ;
            }
            while (i+1 < candidates_size && candidates[i] == candidates[i+1])
                i++ ;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // sort(candidates.begin(), candidates.end()) ;
        // or :
        int t[51] = {0} ;
        for (auto x : candidates)
            t[x]++ ;

        candidates.clear() ;
        for (int i = 0 ; i<=50 ; i++){
            if (i>=0 && t[i]>0){
                for (int j = 0 ; j < t[i] ; j++)
                    candidates.push_back(i) ;
            }
        }
        backtracking(candidates, target, {}, 0, 0) ;
        return result ;
    }
};