class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_jump = 0;
        for (int i = 0; i<nums.size(); i++){
            if (i<=max_jump){
                max_jump = max(max_jump, i + nums[i]) ;
            }
            else{
                return false ;
            }
        }
        return true ;
    }
};