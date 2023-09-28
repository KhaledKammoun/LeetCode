class Solution {
public:
    vector<vector<int>> result ;
    void dfs(vector<int> nums, vector<int> subset, bool t[7]){
        int nums_size = nums.size() ; 
        if (nums_size == subset.size()){
            result.push_back(subset) ;
            return ;
        }
        for (int i =0 ; i< nums_size ; i++){
            if (!t[i]){
                subset.push_back(nums[i]) ;
                t[i] = true ;
                dfs(nums, subset, t) ;
                t[i] = false ;
                subset.pop_back() ;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        bool t[7]= {false} ;
        dfs(nums, {}, t) ;
        return result ;
    }
};