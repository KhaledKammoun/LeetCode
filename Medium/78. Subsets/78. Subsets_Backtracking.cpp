class Solution {
public:
    vector<vector<int>> res ;
    void dfs(vector<int>& nums, int i, vector<int>& subset) {
        if (i>=nums.size()){
            res.push_back(subset) ;
            return ;
        }
        
        // include nums[i]
        subset.push_back(nums[i]) ;
        dfs(nums, i+1, subset) ;

        // not include nums[i]
        subset.pop_back() ;
        dfs(nums, i+1, subset) ;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset ;
        dfs(nums, 0, subset)  ;
        return res ;
    }
};