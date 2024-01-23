class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, maj_int ;
        for (int i = 0; i<nums.size() ; i++){
            if (count == 0)
                maj_int = nums[i] ;
            if (maj_int == nums[i])
                count++;
            else 
                count-- ;
        }
        return maj_int ;
    }
};