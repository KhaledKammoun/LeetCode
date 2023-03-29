class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end()) ;
        vector<vector<int>>v ;
        unordered_map<string, bool> m;
        int n = nums.size() ;
        for (int i = 0 ; i<n-2 ; i++){
            int j = i+1 , k=n-1;
            while (j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if (sum<0)
                    j++;
                else if (sum>0)
                    k--;
                else {
                    string key = to_string(nums[i]) + "," + to_string(nums[j]) + "," + to_string(nums[k]);
                    if (!m[key]){
                    v.push_back({nums[i], nums[j], nums[k]});
                    m[key] = true;}
                    j++;
                    k--;
                }
            }
        }
        // Remove duplicates
        v.erase(unique(v.begin(), v.end()), v.end());
        return v ;
    }
};
