class Solution {
public:
    vector<vector<int>> result ;
    void dfs (vector<int> nums,vector<int> subset, int start){
        result.push_back(subset) ;
        int nums_size = nums.size() ;
        if (start >= nums_size)
            return ;
        bool t_pos[11] = {false}, t_neg[11] = {false} ;
        for (int i = start ; i < nums_size ; i++){
            if ((nums[i]>=0 && !t_pos[nums[i]]) || (nums[i]<0 && !t_neg[-nums[i]])){
                subset.push_back(nums[i]) ;
                if (nums[i]>=0)
                    t_pos[nums[i]] = true ;
                else
                    t_neg[-nums[i]] = true ;
                dfs(nums, subset, i + 1) ;
                subset.pop_back() ;
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // sort the array nums
        int t_pos[11] = {0}, t_neg[11] = {0} ;
        for (auto x : nums){
          if (x>=0)
            t_pos[x]++ ;
          else
            t_neg[-x]++ ;
        }
        nums.clear() ;
        for (int i = -10 ; i<=10 ; i++){
          if (i>=0 && t_pos[i]>0){
            for (int j = 0 ; j < t_pos[i] ; j++)
              nums.push_back(i) ;
          }
          if (i<0 && t_neg[-i]>0){
            for (int j = 0 ; j < t_neg[-i] ; j++)
              nums.push_back(i) ;
          }
        }

        dfs(nums, {}, 0) ;
        return result ;
    }
};