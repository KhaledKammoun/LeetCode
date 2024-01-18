class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, k = nums.size() - 1 ;
        while (i<=k){
            if (nums[i] == val){
                copy(nums.begin() + i + 1, nums.begin() + k + 1, nums.begin() + i); 
                k-- ;
            }
            else{
                i++ ;
            }
        }
        return k + 1;
        
    }
};