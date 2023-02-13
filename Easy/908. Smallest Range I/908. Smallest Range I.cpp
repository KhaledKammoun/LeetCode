class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int mx = nums[0], mn = nums[0];
        for (int x : nums) {
            mx = max(mx, x) ;
            mn = min(mn, x) ;
        }
        return max(0, mx - mn - 2 * k);
    }
};