class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int size = nums.size() ,l = 0;
        vector<int>v ;
        if (k>size)
            return v ;
        multiset<int>s ; 
        for (int r = 0 ;r<size ; r++){
            if (r<k)
                s.insert(nums[r]) ;
            else {
                v.push_back(*s.rbegin()) ;
                auto it = s.find(nums[l]);
                if (it != s.end()) {
                    s.erase(it);
                }
                s.insert(nums[r]) ;
                l++;
            }
        }
        v.push_back(*s.rbegin()) ;
        return v ;
    }
};