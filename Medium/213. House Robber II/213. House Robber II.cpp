class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> new_nums(n+1, 0) ;
        new_nums[1] = nums[0] ;
        for (int i = 2; i <= nums.size() ; i++) {
            int max_val = max(new_nums[i-1], new_nums[i-2] + nums[i-1]) ;
            new_nums[i] =  max_val;
            if (i == 2 && max_val == new_nums[i-1] && nums[i-1] != 0){
                n-- ;
            }
        }
        return max(new_nums[n-1], nums[nums.size()-1]) ;
    }
};