class Solution {
public:
    vector<vector<int>> result ;
    bool isNewSubsetInResult(const vector<vector<int>>& result, const vector<int>& newSubset) {
        for (const vector<int>& subset : result) {
            if (subset == newSubset) {
                return false; // newSubset is already in result
            }
        }
        return true; // newSubset is not in result
    }
    void dfsMultipleElements(vector<int>v, vector<int>& newSubset, int target, int i){
        int sum = 0 ;
        for (auto c : newSubset)
            sum+=c ;
        if (i>=v.size() || sum>target)
            return ;
        if (sum == target){
            if (isNewSubsetInResult(result, newSubset))
                result.push_back(newSubset) ;
        }

        for (int j = i; j < v.size(); j++) {
            newSubset.push_back(v[j]);
            dfsMultipleElements(v, newSubset, target, j);
            newSubset.pop_back();
        }
    }
    void dfs(vector<int> v, vector<int>&subset, int target, int i){
        if (i >= v.size()){
            int sum = 0 ;
            for (auto c : subset)
                sum+=c ;
            if (sum<target) {
                vector<int> newSubset ;
                dfsMultipleElements(subset, newSubset, target, 0) ;
                
            }
            else if (sum == target && isNewSubsetInResult(result, subset)) 
                result.push_back(subset) ;
            return ;
        }

        subset.push_back(v[i]) ;
        dfs(v,subset,target,i+1) ;
        subset.pop_back() ;
        dfs(v,subset,target,i+1) ;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> subset;
        dfs(candidates, subset, target, 0) ;
        return result ;
    }
};