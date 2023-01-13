class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int max_len = 0, sum = 0;
        unordered_map<int,int> m ;
        m[0]=-1 ;
        for (int i = 0 ; i<nums.size() ; i++){
            sum+= (nums[i]==0) ? -1 : 1 ;
            if (m.count(sum))
                max_len = max(max_len , i - m[sum]) ;
            else 
                m[sum] = i ;
        }
        return max_len ;
    }
};