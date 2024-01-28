class Solution {
public:
    int jump(vector<int>& nums) {
        int max_jump = 0, total = 0, length = nums.size();
        for (int i = 0; i<length; i++){
            if (i >= length-1)
                return total ;
            int m = i + 1;
            total++ ;
            if (i + nums[i] >= length-1)
                return total ;
            for (int j = i + 1; j< i + nums[i] + 1; j++){
                if (nums[m]+m < nums[j]+j)
                    m = j ;
            }
            i = m - 1 ;
            
        }
        return total ;
    }
};