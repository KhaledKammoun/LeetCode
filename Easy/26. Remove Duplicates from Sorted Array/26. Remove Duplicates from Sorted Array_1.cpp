class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1 ;
        for (int i = nums.size() - 2 ; i>=0 ; i--){
            if (nums[i] != nums[i+1]){
                k++ ;
            }
            else{
                copy(nums.begin() + i +1, nums.begin() +i+1+k, nums.begin() + i) ;
            }
        }
        return k ;
    }
};