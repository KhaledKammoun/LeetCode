class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> m ;
        int n= 0 ;
        for (int i = 0 ;i<nums.size() ; i++){
            m[nums[i]]++ ;
        }
        for (int i = 0 ;i<nums.size() ; i++){
            if (m[nums[i]]==1){
                n=nums[i] ;
                break ;}
        }
        return n ;
    }
};