class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end()) ;
        vector<vector<int>>v ;
        int n = nums.size() ;
        for (int i = 0 ; i<n-2 ; i++){
            if (i>0 && nums[i-1]==nums[i])
                continue ;
            int j = i+1 , k=n-1;
            while (j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if (sum<0)
                    j++;
                else if (sum>0)
                    k--;
                else {
                    v.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (j<n-1 && nums[j]==nums[j-1])
                        j++ ;
                }
            }
        }
        return v ;
    }
};
