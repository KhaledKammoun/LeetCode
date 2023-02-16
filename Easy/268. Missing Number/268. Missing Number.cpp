class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int s1=0 , n=nums.size() ;
        for (int i = 0 ; i<n ;i++){
            s1+=nums[i] ;
        }
        int sum = n*(n+1)/2 ;
        return sum-s1 ; 
    }
};