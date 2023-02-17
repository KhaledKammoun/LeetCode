class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        int n = nums.size() ;
        for (int i = 0 ; i<n ;i++){
            s.insert(nums[i]) ;
            if ((i+1)!=s.size())
                return true ;
        }
        return false ;
    }
};