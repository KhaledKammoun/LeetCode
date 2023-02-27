class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> v{1} ;
        for (int i = 1 ; i<nums.size() ; i++)
            v.push_back(nums[i-1]*v[i-1]) ;
        int suf = 1 ;
        for (int i = nums.size()-1 ; i>=0 ; i--){
            v[i]*=suf ;
            suf*=nums[i] ;
        }
        return v ;
    }
};