class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }
        unordered_set<int> s(nums.begin(), nums.end());
        int max_len=1;
        for (auto c : s){
            if (!s.count(c-1)){
                int curr=c , count=1;

                while (s.count(++curr)){
                    count++;
                }
                max_len=max(max_len,count) ;
            }
        }
        return max_len ;
    }
};