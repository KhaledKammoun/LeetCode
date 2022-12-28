class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l=nums.size();
        int i = 0;
        while(i< l ){
            int j = 0 ;
            while(j< l){
                if( ((nums[j]+nums[i])==target) && j !=i){
                    return {i,j} ;
                }
                j++ ;
            }
            i++ ;
        }
        return {0,0} ;
    }
};