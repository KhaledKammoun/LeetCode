class Solution {
public:
    vector<vector<int>> subsets(vector<int>& v) {
        int n = v.size() ;
        vector <vector <int>> v1 ;
        for (int i = 0 ;i< pow(2,n) ; i++){
            vector <int> cum;
            for (int j = 0; j<n; j++){
                if ((i >> j) & 1) {
                    cum.push_back(v[j]);
                }
            }
            v1.push_back(cum) ;
        }
        return v1 ;
    }
};