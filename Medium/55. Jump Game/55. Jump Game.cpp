class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0;
        while (i<nums.size()-1 && nums[i]!=0){
            if (i + nums[i] >= nums.size()-1)
                return true ;
            i = std::max_element(nums.begin() + i + 1, nums.begin() + i + nums[i] + 1) - nums.begin();
        }
        return i >=nums.size() - 1 ;
    }
};