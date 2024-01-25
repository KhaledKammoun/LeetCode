class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int length = nums.size() ;
        int n = k % length ;
        for (int i = 0;i < length / 2; i++){
            swap(nums[i], nums[length - i - 1]) ;
        }
        for (int i = 0; i<n/2;i++){
            swap(nums[i], nums[n - i - 1]) ;
        }
        for (int i = 0; i<((length - n)/2);i++){
            swap(nums[i + n], nums[length - i - 1]) ;
        }
    }
};