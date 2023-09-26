class Solution {
public:
    vector<vector<int>> result ;
    void dfs(vector<int> candidates, vector<int> &subset, int target, int start,int total){
        if (total == target){
            result.push_back(subset) ; 
            return ;
        }
        if (start >= candidates.size() || total > target) {
            return ;
        }
        
        subset.push_back(candidates[start]) ;
        dfs(candidates, subset, target,start,total + candidates[start]) ;
        subset.pop_back() ;
        dfs(candidates, subset, target,start+1,total) ;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> subset ;
        dfs(candidates, subset, target,0,0) ;
        return result ;
    }
}; 