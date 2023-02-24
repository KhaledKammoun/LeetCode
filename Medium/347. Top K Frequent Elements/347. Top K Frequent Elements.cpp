class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m ;
        for (auto c : nums)
            m[c]++ ;
        vector <int> v ;
        int n = nums.size() ;
        vector<vector<int>> tab(n+1);
        for (auto it = m.begin() ; it!=m.end() ;it++)
            tab[it->second].push_back(it->first) ;
        for (int i = n ; i>0 ;i--){
            if (!tab[i].empty()) {
                for (int j = 0 ;j<tab[i].size() && v.size()<k; j++)
                    v.push_back(tab[i][j]) ;
            }
            if (v.size()==k)
                break ;
        }
        return v ;
    }
};
