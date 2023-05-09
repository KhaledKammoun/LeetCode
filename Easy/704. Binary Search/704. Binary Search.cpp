class Solution {
public:
    int search(vector<int>& nums, int target) {
            int l = 0, r = nums.size()-1 ;
            while (l<=r){
                int m = l + (r-l)/2 ; //r+l : overflow
                if (nums[m]>target)
                    r = m-1 ;
                else if (nums[m]<target)
                    l = m+1 ;
                else
                    return m ;
            }
            return -1 ;
        }
};