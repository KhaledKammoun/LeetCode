class Solution {
public:
    vector<vector<int>> result ;
    void dfs(vector<int> candidates, vector<int> subset, int target, int start){
        int sum = 0 ;
        for (auto c : subset)
            sum += c ;
        if (sum > target) {
            return ;
        }
        if (sum == target){
            result.push_back(subset) ;
            return ;
        }
        for (int i = start ; i<candidates.size() ; i++){
            if (target - sum >= candidates[i]){
                subset.push_back(candidates[i]) ;
                dfs(candidates, subset, target,i) ;
                subset.pop_back() ;
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, {}, target,0) ;
        return result ;
    }
};