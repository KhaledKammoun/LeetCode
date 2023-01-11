class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0 , e = nums.size() -1;
        int index = -1 ;
        while (s<=e){
            int m =  s+ (e-s)/2 ;
            if (target>nums[m])
                s = m+1 ;
            else
                e = m -1;
            if (target==nums[m])
                index = m ;
        }
        return index ;
        }
};