class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int count[102]={0}  ;
        for (auto c : nums)
            count[c+1]+=1 ;
        for (int i = 1 ; i<102 ; i++)
            count[i]+=count[i-1] ;
        vector<int> result;
        for (auto c : nums) {
            result.push_back(count[c]);
        }
        return result;
    }
};