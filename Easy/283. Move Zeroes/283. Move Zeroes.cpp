class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 1, n = nums.size();
        while (j < n) {
            if (nums[i] == 0 && nums[j]!=0) {
                swap(nums[i], nums[j]);
                j++;i++;
            }else if (nums[i] == 0 && nums[j]==0)
                j++ ;
            else {
                i++;j++;
            }
        }
    }
};
