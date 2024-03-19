class Solution {
public:
    int rob_1(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> dp(n+1, 0) ;
        dp[1] = nums[0] ;
        for(int i= 2; i <= n; i++) {
            dp[i] = max(dp[i-1], nums[i-1] + dp[i-2]) ;
        }
        return dp[n] ;
    }
    int rob(vector<int>& nums) {
        if (nums.size() == 1) 
            return nums[0] ;
        vector<int> nums_1(nums.begin(), nums.end() - 1);
        vector<int> nums_2(nums.begin() + 1, nums.end());
        return max(rob_1(nums_1), rob_1(nums_2)) ;
    }
};