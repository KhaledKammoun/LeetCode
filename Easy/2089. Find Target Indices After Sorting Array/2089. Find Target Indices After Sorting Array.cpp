class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector <int>v1 ;
        int l=nums.size() ;
        sort(nums.begin(),nums.end()) ;
        auto it = std::find(nums.begin(), nums.end(), target);
        int ind = std::distance(nums.begin(), it);
        while(ind<l && nums[ind]==target){
            v1.push_back(ind) ;
            ind++ ;
        }
        return v1 ;
    }
};