class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr_length = nums.size() ;
        int int_count = 1;
        for (int i = 1; i < nums.size() ; i++){
            if (nums[i] == nums[i-1])
                int_count++;
            else
                int_count = 1 ;

            if (int_count > 2){
                nums.erase(nums.begin() + i);
                curr_length-- ;
                i-- ;   
            }
        }
        return curr_length ;
    }
};