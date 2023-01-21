class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& v) {
        for (int i = 0 ;i<v.size() ; i++){
            reverse(v[i].begin(),v[i].end()) ;
            for (int j = 0 ;j<v[i].size() ;j++)
                v[i][j]=!v[i][j] ;
        }
        return v ;
    }
};